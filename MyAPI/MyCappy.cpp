#include "MyCappy.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyRigidBody.h"
#include "Air.h"
#include "AirLeft.h"
#include "Star.h"
#include "MyKirby.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"


namespace My
{
	Cappy::Cappy()
		:cappytime(0.0f)
		, cappydir(0)
		, CappyHP(0)
	{
	}
	Cappy::~Cappy()
	{
	}
	void Cappy::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(580,255));
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* mCappy = Resources::Load<Image>(L"Cappy", L"..\\Resources\\Cappy.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"Move", mCappy, Vector2::Zero, 16, 16, 2, Vector2::Zero, 0.3);

		mAnimator->Play(L"Move", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-20.0f, -65.0f));
		collider->SetSize(Vector2(43.0f, 47.0f));;

		mState = CappyState::LeftMove;

		GameObject::Initialize();
	}
	void Cappy::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Cappy::CappyState::LeftMove:
			leftmove();
			break;
		case Cappy::CappyState::RightMove:
			rightmove();
			break;
		case Cappy::CappyState::HitAir:
			hitair();
			break;
		case Cappy::CappyState::LeftHitAir:
			hitleftair();
			break;
		case Cappy::CappyState::HitStar:
			hitstar();
			break;
		case Cappy::CappyState::CappyDeath:
			cappydeath();
			break;
		case Cappy::CappyState::HitKirbyBase:
			hitkirbybase();
			break;
		case Cappy::CappyState::LeftHitKirbyBase:
			lefthitkirbybase();
			break;
		case Cappy::CappyState::HitSliding:
			hitsliding();
			break;
		case Cappy::CappyState::HitSlidingLeft:
			hitslidingleft();
			break;
		}
	}

	void Cappy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Cappy::Release()
	{
		GameObject::Release();
	}

	void Cappy::leftmove()
	{
		Transform* cappytr = GetComponent<Transform>();
		Vector2 CappyPos = cappytr->GetPos();

		cappytime += Time::DeltaTime();

		if (cappytime <= 1.0f)
		{
			CappyPos.x -= 10.0f * Time::DeltaTime();
		}

		cappytr->SetPos(CappyPos);

		if (cappytime >= 1.5f)
		{
			cappytime = 0.0f;
			mState = CappyState::RightMove;
		}
	}


	void Cappy::rightmove()
	{
		Transform* cappytr = GetComponent<Transform>();
		Vector2 CappyPos = cappytr->GetPos();

		cappytime += Time::DeltaTime();

		if (cappytime <= 1.0f)
		{
			CappyPos.x += 10.0f * Time::DeltaTime();
		}
		cappytr->SetPos(CappyPos);

		if (cappytime >= 1.5f)
		{
			cappytime = 0.0f;
			mState = CappyState::LeftMove;
		}

		
	}
	void Cappy::hitair()
	{
	}
	void Cappy::hitleftair()
	{
	}
	void Cappy::hitstar()
	{
	}
	void Cappy::cappydeath()
	{
	}
	void Cappy::hitkirbybase()
	{
	}
	void Cappy::lefthitkirbybase()
	{
	}
	void Cappy::hitsliding()
	{
	}
	void Cappy::hitslidingleft()
	{
	}
	void Cappy::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamBaseHit)
			{
				SetDamage(50);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamBaseHit)
			{
				SetDamage(50);
				mState = CappyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamJumpHitRelease)
			{
				SetDamage(50);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamJumpHitRelease)
			{
				SetDamage(50);
				mState = CappyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamPigHit)
			{
				SetDamage(50);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamPigHit)
			{
				SetDamage(50);
				mState = CappyState::HitKirbyBase;
			}

			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigJumpHitRelease)
			{
				SetDamage(50);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigJumpHitRelease)
			{
				SetDamage(50);
				mState = CappyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigBaseHit)
			{
				SetDamage(50);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
			{
				SetDamage(50);
				mState = CappyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::LeftAbsorbPigHit)
			{
				SetDamage(50);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::RightAbsorbPigHit)
			{
				SetDamage(50);
				mState = CappyState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
			{
				SetDamage(40);
				mState = CappyState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
			{
				SetDamage(40);
				mState = CappyState::HitKirbyBase;
			}

			if (mkirby->GetSliding())
			{
				SetDamage(100);
				mState = CappyState::HitSliding;
			}
			if (mkirby->GetLeftSliding())
			{
				SetDamage(100);
				mState = CappyState::HitSlidingLeft;
			}
		}

		if (mAir = dynamic_cast<Air*>(other->GetOwner()))
		{
			SetDamage(50);
			mState = CappyState::HitAir;
		}
		if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
		{
			SetDamage(50);
			mState = CappyState::LeftHitAir;
		}
		if (mStar = dynamic_cast<Star*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = CappyState::HitStar;
		}
		if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = CappyState::CappyDeath;
		}
		if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = CappyState::CappyDeath;;
		}
		if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = CappyState::CappyDeath;;
		}
		if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = CappyState::CappyDeath;;
		}
	}
	void Cappy::OnCollisionStay(Collider* other)
	{
		if (cappydir == 0)
		{
			mAnimator->Play(L"LeftHit", false);
		}
		if (cappydir == 1)
		{
			mAnimator->Play(L"RightHit", false);
		}
	}
	void Cappy::OnCollisionExit(Collider* other)
	{
	}
}