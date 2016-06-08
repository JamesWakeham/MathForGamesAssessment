#include "GameObject.h"

GameObject::GameObject()
{
	pTransform = nullptr;
	globalTransform = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	localTransform = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

GameObject::~GameObject()
{

}

void GameObject::SetParent(GameObject *gameObject)
{
pTransform = gameObject;
gameObject->children.push_back(this);
}

void GameObject::Translate(MathFuncs::Vector2 newPos)
{
	pos.x += newPos.x;
	pos.y += newPos.y;
	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		1,0, newPos.x,
		0,1, newPos.y,
		0, 0,1);
	localTransform = tempVec * localTransform;
}

void GameObject::Rotate(float deg)
{
	rot += deg;
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = temp.SetRotateZ(deg);
	localTransform = temp *localTransform;// *temp;
}

void GameObject::Scale(MathFuncs::Vector2 newScale)
{
	scale.x = newScale.x;
	scale.y = newScale.y;

	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		newScale.x, 0, 0,
		0, newScale.y, 0,
		0, 0, 1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = tempVec * temp;
	localTransform = temp*localTransform;
}

void GameObject::GTranslate(MathFuncs::Vector2 newPos)
{
	MathFuncs::Matrix3 tempVec = MathFuncs::Matrix3(
		1, 0, newPos.x,
		0, 1, newPos.y,
		0, 0, 1);
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, GetPos().x, 0, 1, GetPos().y, 0, 0, 1);
	globalTransform = globalTransform* tempVec * temp;
}

void GameObject::GRotate(float parentRot)
{
	MathFuncs::Matrix3 temp = MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	temp = temp.SetRotateZ(parentRot + rot);
	globalTransform = temp *globalTransform;// *temp;
}

void GameObject::GScale(MathFuncs::Vector2 newScale)
{
	MathFuncs::Matrix3 tempParentScale = MathFuncs::Matrix3(
		newScale.x, 0, 0,
		0, newScale.y, 0,
		0, 0, 1);
	globalTransform = localTransform * tempParentScale;// *localTransform;
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
	localTransform = MathFuncs::Matrix3(scale.x, 0, 0, 0, scale.y, 0, 0, 0, 1);
	localTransform = localTransform * MathFuncs::Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1).SetRotateZ(rot);
	localTransform = localTransform * MathFuncs::Matrix3(1, 0, pos.x, 0, 1, pos.y, 0, 0, 1);

	globalTransform = localTransform * pTransform->globalTransform;

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

void GameObject::UpdateTransforms()
{
	if (pTransform != nullptr)
		UpdateGlobalTransform();
	else
		globalTransform = localTransform;

	for (int i = 0; i < children.size(); ++i)
	{
		children[i]->UpdateTransforms();
	}
}