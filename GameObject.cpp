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

void GameObject::Translate(MathFuncs::Vector2 newPos)
{
	pos.x += newPos.x;
	pos.y += newPos.y;
	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		1,0, newPos.x,
		0,1, newPos.y,
		0, 0,1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = tempVec * temp;
	localTransform = temp * localTransform;
}

void GameObject::Rotate(float deg)
{
	rot += deg;
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = temp.SetRotateZ(deg);
	localTransform = temp*localTransform;
}

void GameObject::Scale(MathFuncs::Vector2 newScale)
{
	scale.x += newScale.x;
	scale.y += newScale.y;

	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		newScale.x, 0, 0,
		0, newScale.y, 0,
		0, 0, 1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = tempVec * temp;
	localTransform = localTransform*temp;
}

void GameObject::GTranslate(MathFuncs::Vector2 newPos)
{
	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		1, 0, newPos.x,
		0, 1, newPos.y,
		0, 0, 1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, GetPos().x, 0, 1, GetPos().y, 0, 0, 1);
	globalTransform = tempVec * temp;
}

void GameObject::GRotate(float deg)
{
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = temp.SetRotateZ(deg);
	temp = temp.SetRotateZ(rot);
	std::cout << deg << std::endl;
	globalTransform = temp*globalTransform;
}

void GameObject::GScale(MathFuncs::Vector2 newScale)
{
	MathFuncs::Matrix3 tempParentScale = MathFuncs::Matrix3(
		newScale.x, 0, 0,
		0, newScale.y, 0,
		0, 0, 1);
	MathFuncs::Matrix3 tempLocalScale = MathFuncs::Matrix3(GetScale().x, 0, 0, 0, GetScale().y, 0, 0, 0, 1);
	globalTransform = tempParentScale * tempLocalScale;
}

MathFuncs::Matrix3 GameObject::IfTranslate(MathFuncs::Vector2 newPos)
{
	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		1, 0, newPos.x,
		0, 1, newPos.y,
		0, 0, 1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = tempVec * temp;
	return temp * localTransform;
}

MathFuncs::Matrix3 GameObject::IfRotate(float deg)
{
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = temp.SetRotateZ(deg);
	return temp*localTransform;
}

MathFuncs::Matrix3 GameObject::IfScale(MathFuncs::Vector2 newScale)
{
	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		newScale.x, 0, 0,
		0, newScale.y, 0,
		0, 0, 1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = tempVec * temp;
	return localTransform*temp;
}

void GameObject::UpdateGlobalTransform()
{
	GScale(pTransform->GetScale());
	GRotate(pTransform->GetRot());
	GTranslate(pTransform->GetPos());
}

float GameObject::GetRot()
{
	return rot;
}

MathFuncs::Vector2 GameObject::GetScale()
{
	return scale;
}

MathFuncs::Vector2 GameObject::GetPos()
{
	return pos;
}
