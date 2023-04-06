#include "MyCamera.h"
#include "MyApplication.h"
#include "MyGameObject.h"
#include "MyTransform.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyImage.h"
#include "MyKirby.h"

extern My::Application application;

namespace My
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	Vector2 Camera::mCenterPos = Vector2::Zero;

	GameObject* Camera::mTarget = nullptr;
	Camera::eCameraEffectType Camera::mType = Camera::eCameraEffectType::None;
	class Image* Camera::mCutton = nullptr;
	float Camera::mCuttonAlpha = 1.0f;
	float Camera::mAlphaTime = 0.0f;
	float Camera::mEndTime = 5.0f;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mCenterPos = {-137.0f, -10.0f };

		mType = eCameraEffectType::None;
		mCutton = Image::Create(L"Cutton", mResolution.x, mResolution.y, RGB(0, 0, 0));
	}

	void Camera::Update()
	{

		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->GetPos() - mCenterPos;

			if (mLookPosition.x <= 266.0f)
			{
				mLookPosition.x = 266.0f;
			}
			if (mLookPosition.y <= 404.0f)
			{
				mLookPosition.y = 404.0f;
			}
			if (mLookPosition.x >= 1334.f)
			{
				mLookPosition.x = 1330.f;
			}
			if (mLookPosition.y >= 480.0f)
			{
				mLookPosition.y = 480.0f;
			}
		}
		//CalculatePos(mDistance);

		//if (mAlphaTime < mEndTime)
		//{
		//	//255 - > 1
		//	mAlphaTime += Time::DeltaTime();
		//	float ratio = (mAlphaTime / mEndTime);

		//	if (mType == eCameraEffectType::FadeIn)
		//	{
		//		mCuttonAlpha = 1.0f - ratio;
		//	}
		//	else if (mType == eCameraEffectType::FadeOut)
		//	{
		//		mCuttonAlpha = ratio;
		//	}
		//	else
		//	{

		//	}
		   // mLookPosition = (mResolution / 2.0f);
		      mDistance = mLookPosition - (mResolution / 2.0f);
		}



		//mDistance = mLookPosition - ((mResolution / 2.0f));
		//mDistance.x = mLookPosition.x - (mResolution.x / 2.0f);
		//mDistance.y = mLookPosition.y  -(mResolution.y / 2.0f);


	void Camera::Render(HDC hdc)
{
	if (mAlphaTime < mEndTime
		&& mType == eCameraEffectType::FadeIn)
	{
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

		AlphaBlend(hdc, 0, 0
			, mResolution.x, mResolution.y
			, mCutton->GetHdc()
			, 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, func);
	}
}

void Camera::Clear()
{
	mResolution.x = application.GetWidth();
	mResolution.y = application.GetHeight();
	mLookPosition = (mResolution / 2.0f);
	mDistance = Vector2::Zero;
}
}