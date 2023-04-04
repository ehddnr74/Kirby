#include "MyTwizzy.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "Air.h"
#include "AirLeft.h"
#include "Star.h"
#include "Myobject.h"
#include "MyKirby.h"

namespace My
{
	Twizzy::Twizzy()
		:twizzytime(0.f)
		, righttiwzzytime(0.f)
		, twizzydir(0)
		, twizzyHP(100)
		, hitairtime(0.f)
		, hitstartime(0.f)
		, hitkirbybasetime(0.f)
	    , hitslidingtime(0.f)
	{
	}
	Twizzy::~Twizzy()
	{
	}
	void Twizzy::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(900, 310));
		//tr->SetScale(Vector2(2.0f, 2.0f));


		Image* mTwizzy = Resources::Load<Image>(L"Twizzy", L"..\\Resources\\Twizzy.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mTwizzy, Vector2(80.f,80.f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftFly", mTwizzy, Vector2(120.f, 0.f), 16, 16, 3, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftHit", mTwizzy, Vector2(120.0f, 80.0f), 16, 16, 1, Vector2::Zero, 0.1);

		mAnimator->CreateAnimation(L"RightIdle", mTwizzy, Vector2(80.f, 40.f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightFly", mTwizzy, Vector2::Zero, 16, 16, 3, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightHit", mTwizzy, Vector2(120.0f,40.0f), 16, 16, 1, Vector2::Zero, 0.1);


		mState = TwizzyState::LeftFly;
		mAnimator->Play(L"LeftFly", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-22.0f, -55.0f));
		collider->SetSize(Vector2(46.0f, 40.0f));


		GameObject::Initialize();
	}
	void Twizzy::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		//case Twizzy::TwizzyState::LeftIdle:
		//	leftidle();
		//	break;
		//case Twizzy::TwizzyState::RightIdle:
		//	rightidle();
		case Twizzy::TwizzyState::LeftFly:
			leftfly();
			break;
		case Twizzy::TwizzyState::RightFly:
			rightfly();
			break;
		case Twizzy::TwizzyState::HitAir:
			hitair();
			break;
		case Twizzy::TwizzyState::LeftHitAir:
			hitleftair();
			break;
		case Twizzy::TwizzyState::HitStar:
			hitstar();
			break;
		case Twizzy::TwizzyState::TwizzyDeath:
			twizzydeath();
			break;
		case Twizzy::TwizzyState::HitKirbyBase:
			hitkirbybase();
			break;
		case Twizzy::TwizzyState::LeftHitKirbyBase:
			lefthitkirbybase();
			break;
		case Twizzy::TwizzyState::HitSliding:
			hitsliding();
			break;
		case Twizzy::TwizzyState::HitSlidingLeft:
			hitslidingleft();
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

	//void My::Twizzy::leftidle()
	//{
	//	twizzydir = 0;
	//	twizzytime += Time::DeltaTime();
	//	Transform* tr = GetComponent<Transform>();
	//	Vector2 tzPos = tr->GetPos();

	//	tzPos.x -= 20.0f * Time::DeltaTime();

	//	if (twizzytime >= 0.2f)
	//	{
	//		twizzytime = 0.0f;
	//		mState = TwizzyState::LeftFly;
	//		mAnimator->Play(L"LeftFly", true);
	//	}

	//	tr->SetPos(tzPos);
	//}
	//void My::Twizzy::rightidle()
	//{
	//	twizzydir = 1;
	//	righttiwzzytime += Time::DeltaTime();
	//	Transform* tr = GetComponent<Transform>();
	//	Vector2 tzPos = tr->GetPos();

	//	tzPos.x += 20.0f * Time::DeltaTime();

	//	if (righttiwzzytime >= 0.2f)
	//	{
	//		righttiwzzytime = 0.0f;
	//		mState = TwizzyState::RightFly;
	//		mAnimator->Play(L"RightFly", true);
	//	}

	//	tr->SetPos(tzPos);

	//	
	//}
	void My::Twizzy::leftfly()
	{
		twizzydir = 0;
		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x -= 40.0f * Time::DeltaTime();

		twizzytime += Time::DeltaTime();

		if (twizzytime >= 1.5f)
		{
			twizzytime = 0.0f;
			mState = TwizzyState::RightFly;
			mAnimator->Play(L"RightFly", true);
		}


		tr->SetPos(tzPos);
	}
	void My::Twizzy::rightfly()
	{
		twizzydir = 1;
		righttiwzzytime += Time::DeltaTime();
		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x += 40.0f * Time::DeltaTime();

		if (righttiwzzytime >= 1.5f)
		{
			righttiwzzytime = 0.0f;
			mState = TwizzyState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}

		tr->SetPos(tzPos);
	}
	void Twizzy::hitair()
	{
		hitairtime += Time::DeltaTime();

		if (twizzyHP > 0 && twizzydir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = TwizzyState::LeftFly;
				mAnimator->Play(L"LeftFly", true);
			}

		}

		if (twizzyHP > 0 && twizzydir == 1)
		{

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = TwizzyState::RightFly;
				mAnimator->Play(L"RightFly", true);
			}
		}

		if (twizzyHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.5f)
			{
				mState = TwizzyState::TwizzyDeath;
			}
		}
	}
	void Twizzy::hitleftair()
	{
		hitairtime += Time::DeltaTime();

		if (twizzyHP > 0 && twizzydir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = TwizzyState::LeftFly;
				mAnimator->Play(L"LeftFly", true);
			}

		}

		if (twizzyHP > 0 && twizzydir == 1)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = TwizzyState::RightFly;
				mAnimator->Play(L"RightFly", true);
			}
		}

		if (twizzyHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.5f)
			{
				mState = TwizzyState::TwizzyDeath;
			}
		}
	}
	void Twizzy::hitstar()
	{
		hitstartime += Time::DeltaTime();

		if (hitstartime >= 0.2f)
		{
			object::Destroy(mStar);
			object::Destroy(this);
		}
	}
	void Twizzy::twizzydeath()
	{
		hitairtime += Time::DeltaTime();

		if (hitairtime >= 0.5f)
		{
			hitairtime = 0.0f;
			object::Destroy(this);
		}

	}
	void Twizzy::hitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x += 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && twizzydir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = TwizzyState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}
		if (hitkirbybasetime >= 0.2f && twizzydir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = TwizzyState::RightFly;
			mAnimator->Play(L"RightFly", true);
		}

		if (twizzyHP <= 0 && twizzydir == 0)
		{

			tzPos.x += 2000.0f * Time::DeltaTime();

			mState = TwizzyState::TwizzyDeath;
		}

		if (twizzyHP <= 0 && twizzydir == 1)
		{

			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = TwizzyState::TwizzyDeath;
		}

		tr->SetPos(tzPos);
	}
	void Twizzy::lefthitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x -= 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && twizzydir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = TwizzyState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}
		if (hitkirbybasetime >= 0.2f && twizzydir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = TwizzyState::RightFly;
			mAnimator->Play(L"RightFly", true);
		}

		if (twizzyHP <= 0 && twizzydir == 0)
		{
			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = TwizzyState::TwizzyDeath;
		}

		tr->SetPos(tzPos);
	}
	void Twizzy::hitsliding()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x += 1000.0f * Time::DeltaTime();

		tr->SetPos(tzPos);

		if (hitslidingtime >= 0.3f && twizzyHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Twizzy::hitslidingleft()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x -= 1000.0f * Time::DeltaTime();

		tr->SetPos(tzPos);

		if (hitslidingtime >= 0.2f && twizzyHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Twizzy::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamBaseHit)
			{
				SetDamage(50);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamBaseHit)
			{
				SetDamage(50);
				mState = TwizzyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamJumpHitRelease)
			{
				SetDamage(50);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamJumpHitRelease)
			{
				SetDamage(50);
				mState = TwizzyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamPigHit)
			{
				SetDamage(50);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamPigHit)
			{
				SetDamage(50);
				mState = TwizzyState::HitKirbyBase;
			}

			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigJumpHitRelease)
			{
				SetDamage(50);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigJumpHitRelease)
			{
				SetDamage(50);
				mState = TwizzyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigBaseHit)
			{
				SetDamage(50);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
			{
				SetDamage(50);
				mState = TwizzyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::LeftAbsorbPigHit)
			{
				SetDamage(50);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::RightAbsorbPigHit)
			{
				SetDamage(50);
				mState = TwizzyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
			{
				SetDamage(40);
				mState = TwizzyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
			{
				SetDamage(40);
				mState = TwizzyState::HitKirbyBase;
			}

			if (mkirby->GetSliding())
			{
				SetDamage(100);
				mState = TwizzyState::HitSliding;
			}
			if (mkirby->GetLeftSliding())
			{
				SetDamage(100);
				mState = TwizzyState::HitSlidingLeft;
			}
		}
	
		if (mAir = dynamic_cast<Air*>(other->GetOwner()))
		{
			SetDamage(50);
			mState = TwizzyState::HitAir;
		}
		if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
		{
			SetDamage(50);
			mState = TwizzyState::LeftHitAir;
		}
		if (mStar = dynamic_cast<Star*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = TwizzyState::HitStar;
		}
	}
	void Twizzy::OnCollisionStay(Collider* other)
	{
		if (twizzydir == 0)
		{
			mAnimator->Play(L"LeftHit", false);
		}
		if (twizzydir == 1)
		{
			mAnimator->Play(L"RightHit", false);
		}
	}
	void Twizzy::OnCollisionExit(Collider* other)
	{
	}
}