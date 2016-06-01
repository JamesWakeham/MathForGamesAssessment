#pragma once

#include "BaseApplication.h"
#include "GameObject.h"

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:
	GameObject testObj1;

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

	float test = 0;
};