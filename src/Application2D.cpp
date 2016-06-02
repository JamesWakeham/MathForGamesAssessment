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

	testObj1.m_texture = new Texture("./bin/textures/crate.png");
	testObj1.Scale(MathFuncs::Vector2(0.1, 0.1f));
	testObj2.Scale(MathFuncs::Vector2(0.05f, 0.05f));
	testObj1.Translate(MathFuncs::Vector2(640, 320));
	testObj2.Translate(MathFuncs::Vector2(800, 320));

	testObj2.SetParent(&testObj1);
	testObj1.SetParent(&root);

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
		return false;


	if (isKeyPressed(GLFW_KEY_W)) {
		testObj1.Translate(MathFuncs::Vector2(0, 3));
	}
	else if (isKeyPressed(GLFW_KEY_S)) {
		testObj1.Translate(MathFuncs::Vector2(0, -3));
	}

	if (isKeyPressed(GLFW_KEY_D)) {
		testObj1.Translate(MathFuncs::Vector2(3, 0));
	}
	else if (isKeyPressed(GLFW_KEY_A)) {
		testObj1.Translate(MathFuncs::Vector2(-3, 0));
	}


	if (isKeyPressed(GLFW_KEY_LEFT)) {
		testObj1.Rotate(0.05f);
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

	testObj1.UpdateGlobalTransform();
	testObj2.UpdateGlobalTransform();
	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();
	m_spriteBatch->drawSpriteTransformed3x3(testObj1.m_texture, *testObj2.globalTransform.value);
	m_spriteBatch->drawSpriteTransformed3x3(testObj1.m_texture, *testObj1.globalTransform.value);


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
