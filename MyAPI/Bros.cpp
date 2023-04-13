#include "Bros.h"
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
#include "MyKirby.h"
#include "Myobject.h"
#include "MyRigidBody.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"


namespace My
{
	Bros::Bros()
		: brostime(0.f)
		, rightbrostime(0.f)
		, brosdir(0)
		, brosHP(100)
		, hitairtime(0.f)
		, hitstartime(0.f)
		, hitkirbybasetime(0.f)
		, hitslidingtime(0.f)
		, brostimetwo(0.f)
		, death(false)
		, deathtime(0.f)
	{
	}
	Bros::~Bros()
	{
	}
	void Bros::Initialize()
	{
		Image* mBros = Resources::Load<Image>(L"Bros", L"..\\Resources\\Bros.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mBros, Vector2(0.f, 0.f), 16, 16, 2, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftHit", mBros, Vector2(0.f, 40.f), 16, 16, 1, Vector2::Zero, 0.1);

		mAnimator->CreateAnimation(L"RightIdle", mBros, Vector2(0.f, 80.f), 16, 16, 2, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightHit", mBros, Vector2(40.0f, 40.0f), 16, 16, 1, Vector2::Zero, 0.1);


		mState = BrosState::LeftIdle;
		mAnimator->Play(L"LeftIdle", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-22.0f, -55.0f));
		collider->SetSize(Vector2(46.0f, 40.0f));

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);


		GameObject::Initialize();
	}
	void Bros::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Bros::BrosState::LeftIdle:
			leftidle();
			break;
		case Bros::BrosState::RightIdle:
			rightidle();
			break;
		case Bros::BrosState::HitAir:
			hitair();
			break;
		case Bros::BrosState::LeftHitAir:
			hitleftair();
			break;
		case Bros::BrosState::HitStar:
			hitstar();
			break;
		case Bros::BrosState::BrosDeath:
			brosdeath();
			break;
		case Bros::BrosState::HitKirbyBase:
			hitkirbybase();
			break;
		case Bros::BrosState::LeftHitKirbyBase:
			lefthitkirbybase();
			break;
		case Bros::BrosState::HitSliding:
			hitsliding();
			break;
		case Bros::BrosState::HitSlidingLeft:
			hitslidingleft();
			break;
		}
	}


	void Bros::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Bros::Release()
	{
		GameObject::Release();
	}
	void Bros::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamBaseHit)
			{
				SetDamage(50);
				mState = BrosState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamBaseHit)
			{
				SetDamage(50);
				mState = BrosState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamJumpHitRelease)
			{
				SetDamage(50);
				mState = BrosState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamJumpHitRelease)
			{
				SetDamage(50);
				mState = BrosState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamPigHit)
			{
				SetDamage(50);
				mState = BrosState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamPigHit)
			{
				SetDamage(50);
				mState = BrosState::HitKirbyBase;
			}

			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigJumpHitRelease)
			{
				SetDamage(50);
				mState = BrosState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigJumpHitRelease)
			{
				SetDamage(50);
				mState = BrosState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigBaseHit)
			{
				SetDamage(50);
				mState = BrosState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
			{
				SetDamage(50);
				mState = BrosState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::LeftAbsorbPigHit)
			{
				SetDamage(50);
				mState = BrosState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::RightAbsorbPigHit)
			{
				SetDamage(50);
				mState = BrosState::HitKirbyBase;
			}

			if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
			{
				SetDamage(40);
				object::Destroy(this);
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
			{
				SetDamage(40);
				mState = BrosState::HitKirbyBase;
			}

			if (mkirby->GetSliding())
			{
				SetDamage(100);
				mState = BrosState::HitSliding;
			}
			if (mkirby->GetLeftSliding())
			{
				SetDamage(100);
				mState = BrosState::HitSlidingLeft;
			}
		}

		if (mAir = dynamic_cast<Air*>(other->GetOwner()))
		{
			SetDamage(50);
			mState = BrosState::HitAir;
		}
		if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
		{
			SetDamage(50);
			mState = BrosState::LeftHitAir;
		}
		if (mStar = dynamic_cast<Star*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = BrosState::HitStar;
		}
		if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = BrosState::BrosDeath;
		}
		if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = BrosState::BrosDeath;
		}
		if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = BrosState::BrosDeath;
		}
		if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = BrosState::BrosDeath;
		}
	}
	void Bros::OnCollisionStay(Collider* other)
	{
		if (brosdir == 0)
		{
			mAnimator->Play(L"LeftHit", false);
		}
		if (brosdir == 1)
		{
			mAnimator->Play(L"RightHit", false);
		}
	}
	void Bros::OnCollisionExit(Collider* other)
	{
	}
	void Bros::leftidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		brosdir = 0;
		brostimetwo += Time::DeltaTime();

		pos.x -= 30.0f * Time::DeltaTime();
		pos.y -= 150.0f * Time::DeltaTime();

		if (brostimetwo >= 2.0f)
		{
			brostimetwo = 0.0f;
			mState = BrosState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}


		tr->SetPos(pos);
	}
	void Bros::rightidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		brostime += Time::DeltaTime();

		brosdir = 1;

		pos.x += 30.0f * Time::DeltaTime();
		pos.y -= 150.0f * Time::DeltaTime();

		if (brostime >= 2.0f)
		{
			brostime = 0.0f;
			mState = BrosState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}


		tr->SetPos(pos);
	}
	void Bros::hitair()
	{
		hitairtime += Time::DeltaTime();

		if (brosHP > 0 && brosdir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = BrosState::LeftIdle;
				mAnimator->Play(L"LeftIdle", true);
			}
		}
		if (brosHP > 0 && brosdir == 1)
		{

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = BrosState::RightIdle;
				mAnimator->Play(L"RightIdle", true);
			}
		}

		if (brosHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.1f)
				mState = BrosState::BrosDeath;
		}
	}
	void Bros::hitleftair()
	{
		hitairtime += Time::DeltaTime();

		if (brosHP > 0 && brosdir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = BrosState::LeftIdle;
				mAnimator->Play(L"LeftIdle", true);
			}

		}

		if (brosHP > 0 && brosdir == 1)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = BrosState::RightIdle;
				mAnimator->Play(L"RightIdle", true);
			}
		}

		if (brosHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.1f)
				mState = BrosState::BrosDeath;

		}
	}
	void Bros::hitstar()
	{
		hitstartime += Time::DeltaTime();

		if (hitstartime >= 0.2f)
		{
			object::Destroy(mStar);
			object::Destroy(this);
		}
	}
	void Bros::brosdeath()
	{
		deathtime += Time::DeltaTime();

		if (deathtime >= 0.2f)
		{
			object::Destroy(this);
		}
	}
	void Bros::hitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x += 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && brosdir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = BrosState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		if (hitkirbybasetime >= 0.2f && brosdir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = BrosState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (brosHP <= 0 && brosdir == 0)
		{

			tzPos.x += 2000.0f * Time::DeltaTime();

			mState = BrosState::BrosDeath;
		}

		if (brosHP <= 0 && brosdir == 1)
		{

			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = BrosState::BrosDeath;
		}

		tr->SetPos(tzPos);
	}
	void Bros::lefthitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x -= 100.0f * Time::DeltaTime();

		if (hitkirbybasetime >= 0.2f && brosdir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = BrosState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		if (hitkirbybasetime >= 0.2f && brosdir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = BrosState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (brosHP <= 0 && brosdir == 0)
		{
			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = BrosState::BrosDeath;
		}

		tr->SetPos(tzPos);
	}
	void Bros::hitsliding()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x += 1000.0f * Time::DeltaTime();

		tr->SetPos(tzPos);

		if (hitslidingtime >= 0.3f && brosHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Bros::hitslidingleft()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x -= 1000.0f * Time::DeltaTime();

		tr->SetPos(tzPos);

		if (hitslidingtime >= 0.2f && brosHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
}
