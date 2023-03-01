#include "MyTransform.h"


namespace My
{
	Transform::Transform()
		:Component(eComponentType::Transform)
		, mPos(Vector2::Zero)
		, mScale(Vector2::Two)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
	void Transform::Release()
	{
	}
}