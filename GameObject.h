#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <list>
#include <iostream>

#include "MathFuncs.h"


class Texture;
class GameObject
{
public:
GameObject();
~GameObject();

GameObject *pTransform;
std::list<GameObject*> Children;

void GameObject::SetParent(GameObject *gameObject);

MathFuncs::Matrix3 globalTransform;
MathFuncs::Matrix3 localTransform;

void GameObject::Translate(MathFuncs::Vector2);
void GameObject::Rotate(float);
void GameObject::Scale(MathFuncs::Vector2); 

void GameObject::GTranslate(MathFuncs::Vector2);
void GameObject::GRotate(float);
void GameObject::GScale(MathFuncs::Vector2);

MathFuncs::Matrix3 GameObject::IfTranslate(MathFuncs::Vector2);
MathFuncs::Matrix3 GameObject::IfRotate(float);
MathFuncs::Matrix3 GameObject::IfScale(MathFuncs::Vector2);

void GameObject::UpdateGlobalTransform();

float GameObject::GetRot();
MathFuncs::Vector2 GameObject::GetScale();
MathFuncs::Vector2 GameObject::GetPos();

Texture*		m_texture;
private:
	//Do Not Set these manually
	MathFuncs::Vector2 pos = MathFuncs::Vector2(1, 1);
	MathFuncs::Vector2 scale = MathFuncs::Vector2(1, 1);
	float rot = 0;
};