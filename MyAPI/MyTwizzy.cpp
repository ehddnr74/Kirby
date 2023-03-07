#include "MyTwizzy.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"

namespace My
{
	Twizzy::Twizzy()
		:twizzytime(0.f)
		, twizzydir(1)
	{
	}
	Twizzy::~Twizzy()
	{
	}
	void Twizzy::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(900, 310));
		tr->SetScale(Vector2(2.0f, 2.0f));


		Image* mTwizzy = Resources::Load<Image>(L"Twizzy", L"..\\Resources\\Twizzy.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mTwizzy, Vector2(0.f,80.f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftFly", mTwizzy, Vector2(120.f, 0.f), 16, 16, 3, Vector2::Zero, 0.3);

		mAnimator->CreateAnimation(L"RightIdle", mTwizzy, Vector2(0.f, 40.f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightFly", mTwizzy, Vector2::Zero, 16, 16, 3, Vector2::Zero, 0.3);

		mAnimator->Play(L"LeftIdle", true);
		GameObject::Initialize();
	}
	void Twizzy::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Twizzy::TwizzyState::LeftIdle:
			leftidle();
			break;
		case Twizzy::TwizzyState::RightIdle:
			rightidle();
		case Twizzy::TwizzyState::LeftFly:
			leftfly();
			break;
		case Twizzy::TwizzyState::RightFly:
			rightfly();
			break;
		}
	}
	void Twizzy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Twizzy::Release()
	{
		GameObject::Release();
	}

	void My::Twizzy::leftidle()
	{
		twizzytime += Time::DeltaTime();

		if (twizzytime <= 3.0f)
		{
			mState = TwizzyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		if (3.0 <= twizzytime <= 5.5f)
		{
			mState = TwizzyState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}
		
	}
	void My::Twizzy::rightidle()
	{
	}
	void My::Twizzy::leftfly()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();
		twizzytime += Time::DeltaTime();

		if (3.0<=twizzytime <= 5.5f)
		{
			tzPos.x -= 20.0f * Time::DeltaTime();
		}
		if (5.5f <= twizzytime)
		{
			mState = TwizzyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		if (5.5f <= twizzytime)
		{
			twizzytime = 0.f;
		}
		
		tr->SetPos(tzPos);
	}
	void My::Twizzy::rightfly()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 tzpos = tr->GetPos();
		twizzytime += Time::DeltaTime();

		if (0.5<=twizzytime <= 1.0f)
		{
			tzpos.x -= 20.0f * Time::DeltaTime();
		}

		tr->SetPos(tzpos);
	}
}