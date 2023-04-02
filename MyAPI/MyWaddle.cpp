#include "MyWaddle.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "Mytime.h"
#include "AbsorbEffect.h"
#include "MyCamera.h"
#include "Air.h"
#include "AirLeft.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "Star.h"

namespace My
{
	Waddle::Waddle()
		:waddletime(0.f)
		, waddledir(0)
		, WaddleHP(100)
		, hitairtime(0.f)
		, hitslidingtime(0.f)
		, hitstartime(0.f)
	{
	}
	Waddle::~Waddle()
	{
	}
	void Waddle::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(320, 300));
		//tr->SetScale(Vector2(2.2f, 2.2f));



		Image* mWaddle = Resources::Load<Image>(L"Waddle", L"..\\Resources\\Waddle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftMove", mWaddle, Vector2::Zero, 16, 16, 4, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftBoomb", mWaddle, Vector2(0.0f, 120.0f), 16, 16, 2, Vector2::Zero, 0.5);
		mAnimator->CreateAnimation(L"LeftHit", mWaddle, Vector2(0.0f, 160.f), 16, 16, 1, Vector2::Zero, 0.01);



		mAnimator->CreateAnimation(L"RightMove", mWaddle, Vector2(0.0f, 40.0f), 16, 16, 4, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBoomb", mWaddle, Vector2(0.0f, 80.0f), 16, 16, 2, Vector2::Zero, 0.5);
		mAnimator->CreateAnimation(L"RightHit", mWaddle, Vector2(40.0f, 160.f), 16, 16, 1, Vector2::Zero, 0.01);
		mAnimator->Play(L"LeftMove", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-22.0f, -65.0f));
		collider->SetSize(Vector2(45.0f, 45.0f));

		mState = WaddleState::LeftMove;

		GameObject::Initialize();
	}
	void Waddle::Update()
	{

		GameObject::Update();

		switch (mState)
		{
		case My::Waddle::WaddleState::LeftMove:
			leftmove();
			break;
		case My::Waddle::WaddleState::RightMove:
			rightmove();
		case My::Waddle::WaddleState::LeftBoomb:
			leftboomb();
			break;
		case My::Waddle::WaddleState::RightBoomb:
			rightboomb();
			break;
		case My::Waddle::WaddleState::HitAir:
			hitair();
			break;
		case My::Waddle::WaddleState::WaddleDeath:
			waddleDeath();
			break;
		case My::Waddle::WaddleState::HitLeftAir:
			hitleftair();
			break;
		case My::Waddle::WaddleState::HitSliding:
			hitsliding();
			break;
		case My::Waddle::WaddleState::HitSlidingLeft:
			hitslidingleft();
			break;
		case My::Waddle::WaddleState::HitStar:
			hitstar();
			break;
		}
	}

	void Waddle::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Waddle::Release()
	{
		GameObject::Release();
	}

	void Waddle::OnCollisionEnter(Collider* other)
	{
		if (dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetSliding())
			{
				SetDamage(100);
				mState = WaddleState::HitSliding;
			}
			if (mkirby->GetLeftSliding())
			{
				SetDamage(100);
				mState = WaddleState::HitSlidingLeft;
			}
		}

		if (mAir = dynamic_cast<Air*>(other->GetOwner()))
		{
			SetDamage(35);
			mState = WaddleState::HitAir;
		}
		if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
		{
			SetDamage(35);
			mState = WaddleState::HitLeftAir;
		}
		if (mStar = dynamic_cast<Star*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = WaddleState::HitStar;
		}
	}

	void Waddle::OnCollisionStay(Collider* other)
	{

		if (waddledir == 0)
		{
			mAnimator->Play(L"LeftHit", false);
		}
		if (waddledir == 1)
		{
			mAnimator->Play(L"RightHit", false);
		}
	}

	void Waddle::OnCollisionExit(Collider* other)
	{

	}

	void Waddle::leftmove()
	{
		waddledir = 0;
		Transform* tr = GetComponent<Transform>();
		waddletime += Time::DeltaTime();

		Vector2 WdPos = tr->GetPos();

		WdPos.x -= 20.0f * Time::DeltaTime();


		if (waddletime >= 3.0f)
		{
			waddletime = 0.0f;
			mState = WaddleState::LeftBoomb;
			mAnimator->Play(L"LeftBoomb", false);
			//	mAnimator->Play(L"RightMove", true);
			//	//mAnimator->Play(L"LeftBoomb", true);
			//}
			//if (waddletime >= 4.0f)
			//{
			//	waddletime = 0.0f;
			//	mState = WaddleState::RightMove;
			//	mAnimator->Play(L"RightMove", true);
		}

		tr->SetPos(WdPos);
	}



	void Waddle::rightmove()
	{
		waddledir = 1;

		Transform* tr = GetComponent<Transform>();

		waddletime += Time::DeltaTime();

		Vector2 WdPos = tr->GetPos();

		WdPos.x += 20.f * Time::DeltaTime();

		//if (waddletime >= 2.0f)
		//{
		//	waddletime = 0.0f;
		//	mState = WaddleState::LeftMove;
		//	mAnimator->Play(L"LeftMove", true);
		//}






		tr->SetPos(WdPos);
	}

	void Waddle::leftboomb()
	{
		waddletime += Time::DeltaTime();

		if (waddletime >= 2.0f)
		{
			waddletime = 0.0f;
			mState = WaddleState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}
	}

	void Waddle::rightboomb()
	{

	}
	void Waddle::hitair()
	{
		hitairtime += Time::DeltaTime();

		if (WaddleHP > 0 && waddledir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 WaddlePos = tr->GetPos();

			WaddlePos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(WaddlePos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = WaddleState::LeftMove();
				mAnimator->Play(L"LeftMove", true);
			}

		}

		if (WaddleHP > 0 && waddledir == 1)
		{

			Transform* tr = GetComponent<Transform>();
			Vector2 WaddlePos = tr->GetPos();

			WaddlePos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(WaddlePos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = WaddleState::RightMove;
				mAnimator->Play(L"RightMove", true);
			}
		}

		if (WaddleHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 WaddlePos = tr->GetPos();

			WaddlePos.x += 100.0f * Time::DeltaTime();

			tr->SetPos(WaddlePos);

			if (hitairtime >= 0.5f)
			{
				mState = WaddleState::WaddleDeath;
			}
		}
	}

	void Waddle::hitleftair()
	{
		hitairtime += Time::DeltaTime();

		if (WaddleHP > 0 && waddledir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 WaddlePos = tr->GetPos();

			WaddlePos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(WaddlePos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = WaddleState::LeftMove();
				mAnimator->Play(L"LeftMove", true);
			}

		}

		if (WaddleHP > 0 && waddledir == 1)
		{

			Transform* tr = GetComponent<Transform>();
			Vector2 WaddlePos = tr->GetPos();

			WaddlePos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(WaddlePos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = WaddleState::RightMove;
				mAnimator->Play(L"RightMove", true);
			}
		}

		if (WaddleHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 WaddlePos = tr->GetPos();

			WaddlePos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(WaddlePos);

			if (hitairtime >= 0.5f)
			{
				mState = WaddleState::WaddleDeath;
			}
		}
	}

	void Waddle::waddleDeath()
	{
		hitairtime += Time::DeltaTime();

		if (hitairtime >= 0.5f)
		{
			hitairtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Waddle::hitsliding()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();

		WaddlePos.x += 1000.0f * Time::DeltaTime();

		tr->SetPos(WaddlePos);

		if (hitslidingtime >= 0.3f && WaddleHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}

	void Waddle::hitslidingleft()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();

		WaddlePos.x -= 1000.0f * Time::DeltaTime();

		tr->SetPos(WaddlePos);

		if (hitslidingtime >= 0.2f && WaddleHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}

	}
	void Waddle::hitstar()
	{
		hitstartime += Time::DeltaTime();

		if (hitstartime >= 0.2f)
		{
			object::Destroy(mStar);
			object::Destroy(this);
		}
	}
}


