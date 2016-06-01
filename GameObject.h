#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <list>

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

void GameObject::Translate(MathFuncs::Vector2 pos);
void GameObject::Rotate(float deg);
void GameObject::Scale(MathFuncs::Vector2 scale);

Texture*		m_texture;
private:
};