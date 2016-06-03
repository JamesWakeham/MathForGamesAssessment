#pragma once

#include "BaseApplication.h"
#include "GameObject.h"
#include <ostream>
#include "SaveSystem.h"

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:
	std::vector<GameObject*> objects;
    GameObject root;

	GameObject test1;
	GameObject test2;
	GameObject test3;

	SaveSystem save;

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:

	SpriteBatch*	m_spriteBatch;
	Texture*		m_texture;
	Font*			m_font;

	MathFuncs::Vector2 testPos;
	MathFuncs::Vector2 testScale;
	float test = 0;
};