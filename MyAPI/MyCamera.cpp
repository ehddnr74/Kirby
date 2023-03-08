#include "MyCamera.h"
#include "MyApplication.h"
#include "MyGameObject.h"
#include "MyTransform.h"

extern My::Application application;

namespace My
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
	}
	void Camera::Update()
	{
		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->GetPos();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}