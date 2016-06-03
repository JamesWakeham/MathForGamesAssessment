#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <iostream>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	test1.SetParent(&root);
	test2.SetParent(&test1);
	test3.SetParent(&test2);

	objects.push_back(&test1);
	objects.push_back(&test2);
	objects.push_back(&test3);

	test1.Scale(MathFuncs::Vector2(0.5f, 0.5f));
	test2.Scale(MathFuncs::Vector2(0.5f, 0.5f));
	test3.Scale(MathFuncs::Vector2(0.5f, 0.5f));

	test1.Translate(MathFuncs::Vector2(300, 300));
	test2.Translate(MathFuncs::Vector2(300, 300));
	test3.Translate(MathFuncs::Vector2(300, 300));

	//save.Write(&test1, &test2, &test3);
	save.Read(&test1, &test2, &test3);

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
	{
		save.Write(&test1, &test2, &test3);
		return false;
	}


	if (isKeyPressed(GLFW_KEY_W)) {
		test1.Translate(MathFuncs::Vector2(0, 3));
	}
	else if (isKeyPressed(GLFW_KEY_S)) {
		test1.Translate(MathFuncs::Vector2(0, -3));
	}

	if (isKeyPressed(GLFW_KEY_D)) {
		test1.Translate(MathFuncs::Vector2(3, 0));
	}
	else if (isKeyPressed(GLFW_KEY_A)) {
		test1.Translate(MathFuncs::Vector2(-3, 0));
	}


	if (isKeyPressed(GLFW_KEY_LEFT)) {
		test1.Rotate(0.05f);
	}	if (isKeyPressed(GLFW_KEY_RIGHT)) {
		test2.Rotate(0.05f);
	}
	//else if (isKeyPressed(GLFW_KEY_RIGHT)) {
	//	testObj1.Rotate(-0.05f);
	//}
	//if (isKeyPressed(GLFW_KEY_UP)) {
	//	testScale.x += 0.1f; 
	//	testScale.y += 0.1f;
	//	testObj1.Scale(testScale);
	//}
	//else if (isKeyPressed(GLFW_KEY_DOWN)) {
	//	testScale.x += -0.1f;
	//	testScale.y += -0.1f;
	//	testObj1.Scale(testScale);
	//}

	root.UpdateTransforms();
	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	for each (GameObject* var in objects)
	{
		m_spriteBatch->drawSpriteTransformed3x3(m_texture, *var->globalTransform.value);
	}


	/*
	m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	m_spriteBatch->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f);

	m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);*/

	// done drawing sprites
	m_spriteBatch->end();	
}


