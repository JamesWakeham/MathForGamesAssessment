#include "GameObject.h"

GameObject::GameObject()
{
globalTransform = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
localTransform = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

GameObject::~GameObject()
{

}

void GameObject::SetParent(GameObject *gameObject)
{
pTransform = gameObject;
gameObject->Children.push_back(this);
}

void GameObject::Translate(MathFuncs::Vector2 pos)
{

}

void GameObject::Rotate(float deg)
{
MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
temp.SetRotateZ(deg);
localTransform * temp;
}

void GameObject::Scale(MathFuncs::Vector2 scale)
{

}