#include "BoomBros.h"
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
#include "RightBoomb.h"
#include "LeftBoomb.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "R2Ground.h"

namespace My
{
	BoomBros::BoomBros()
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
		, boomcreate(false)
		, boomreleasetime(0.f)
		, BoomShot(false)
		, enemyfind(0.f)
		, boomshotend(0.f)
		, boomwaiting(0.f)
		, find(false)
		, leftboomshotend(0.f)
	    , leftboomwaiting(0.f)
	    , leftboomreleasetime(0.f)
		, leftfind(false)
		, leftBoomShot(false)
		, leftBoomCreate(false)
	{
	}
	BoomBros::~BoomBros()
	{
	}
	void BoomBros::Initialize()
	{
		Image* mBros = Resources::Load<Image>(L"Bros", L"..\\Resources\\Bros.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mBros, Vector2(0.f, 0.f), 16, 16, 2, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftHit", mBros, Vector2(0.f, 40.f), 16, 16, 1, Vector2::Zero, 0.1);

		mAnimator->CreateAnimation(L"RightIdle", mBros, Vector2(0.f, 80.f), 16, 16, 2, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightHit", mBros, Vector2(40.0f, 40.0f), 16, 16, 1, Vector2::Zero, 0.1);
		
		mAnimator->CreateAnimation(L"RightBoomRelease", mBros, Vector2(0.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBoomShot", mBros, Vector2(0.0f, 160.0f), 16, 16, 1, Vector2::Zero, 0.1);

		mAnimator->CreateAnimation(L"LeftBoomRelease", mBros, Vector2(0.0f, 200.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBoomShot", mBros, Vector2(0.0f, 240.0f), 16, 16, 1, Vector2::Zero, 0.1);




		mState = BrosState::LeftIdle;
		mAnimator->Play(L"LeftIdle", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-22.0f, -55.0f));
		collider->SetSize(Vector2(46.0f, 40.0f));

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);


		GameObject::Initialize();
	}
	void BoomBros::Update()
	{
		GameObject::Update();
		
		switch (mState)
		{
		case BoomBros::BrosState::LeftIdle:
			leftidle();
			break;
		case BoomBros::BrosState::RightIdle:
			rightidle();
			break;
		case BoomBros::BrosState::HitAir:
			hitair();
			break;
		case BoomBros::BrosState::LeftHitAir:
			hitleftair();
			break;
		case BoomBros::BrosState::HitStar:
			hitstar();
			break;
		case BoomBros::BrosState::BrosDeath:
			brosdeath();
			break;
		case BoomBros::BrosState::HitKirbyBase:
			hitkirbybase();
			break;
		case BoomBros::BrosState::LeftHitKirbyBase:
			lefthitkirbybase();
			break;
		case BoomBros::BrosState::HitSliding:
			hitsliding();
			break;
		case BoomBros::BrosState::HitSlidingLeft:
			hitslidingleft();
			break;
		case BoomBros::BrosState::RightBoomRelease:
			rightboomrelease();
			break;
		case BoomBros::BrosState::RightBoomShot:
			rightboomshot();
			break;
		case BoomBros::BrosState::LeftBoomRelease:
			leftboomrelease();
			break;
		case BoomBros::BrosState::LeftBoomShot:
			leftboomshot();
			break;
		case BoomBros::BrosState::HitBoom:
			hitboom();
			break;
		}
	}
	

	void BoomBros::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void BoomBros::Release()
	{
		GameObject::Release();
	}
	void BoomBros::OnCollisionEnter(Collider* other)
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

		if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
		{
			GetGround()->SetKirBoomb(nullptr);
			SetDamage(100);
			mState = BrosState::HitBoom;
		}
		if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
		{
			GetGround()->SetKirLeftBoomb(nullptr);
			SetDamage(100);
			mState = BrosState::HitBoom;
		}
			//	if (mAir = dynamic_cast<Air*>(other->GetOwner()))
			//	{
			//		SetDamage(50);
			//		mState = BrosState::HitAir;
			//	}
			//	if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
			//	{
			//		SetDamage(50);
			//		mState = BrosState::LeftHitAir;
			//	}
			//	if (mStar = dynamic_cast<Star*>(other->GetOwner()))
			//	{
			//		SetDamage(100);
			//		mState = BrosState::HitStar;
			//	}
			//	if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
			//	{
			//		SetDamage(100);
			//		mState = BrosState::BrosDeath;
			//	}
			//	if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
			//	{
			//		SetDamage(100);
			//		mState = BrosState::BrosDeath;
			//	}
			//	if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
			//	{
			//		SetDamage(100);
			//		mState = BrosState::BrosDeath;
			//	}
			//	if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
			//	{
			//		SetDamage(100);
			//		mState = BrosState::BrosDeath;
			//	}
			//}
	}
	void BoomBros::OnCollisionStay(Collider* other)
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
	void BoomBros::OnCollisionExit(Collider* other)
	{
	}
	void BoomBros::leftidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		brostimetwo += Time::DeltaTime();
		leftboomwaiting += Time::DeltaTime();

		brosdir = 0;

		pos.x -= 30.0f * Time::DeltaTime();
		pos.y -= 150.0f * Time::DeltaTime();

		if (brostimetwo >= 2.0f)
		{
			brostimetwo = 0.0f;
			leftboomwaiting = 0.0f;
			mState = BrosState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (mkirby != nullptr)
		{
			Transform* kirbytr = mkirby->GetComponent<Transform>();
			Vector2 kirbypos = kirbytr->GetPos();

			Transform* brostr = this->GetComponent<Transform>();
			Vector2 brospos = brostr->GetPos();

			if (brosdir == 0 && kirbypos.x - brospos.x <= 0 && kirbypos.x - brospos.x >= -150.0f) //&& fabs(kirbypos.y - brospos.y) <= 10.0f)
			{
				leftfind = true;
			}

			if (leftfind == true && leftboomwaiting >= 1.5f)
			{
				leftboomwaiting = 0.0f;
				leftBoomCreate = true;
				leftfind = false;
				mState = BrosState::LeftBoomRelease;
				mAnimator->Play(L"LeftBoomRelease", false);
			}
		}


		tr->SetPos(pos);
	}
	void BoomBros::rightidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		brostime += Time::DeltaTime();
		boomwaiting += Time::DeltaTime();

		brosdir = 1;

		pos.x += 30.0f * Time::DeltaTime();
		pos.y -= 150.0f * Time::DeltaTime();

		if (brostime >= 2.0f)
		{
			boomwaiting = 0.0f;
			brostime = 0.0f;
			mState = BrosState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		if (mkirby != nullptr)
		{
			Transform* kirbytr = mkirby->GetComponent<Transform>();
			Vector2 kirbypos = kirbytr->GetPos();

			Transform* brostr = this->GetComponent<Transform>();
			Vector2 brospos = brostr->GetPos();

			if (brosdir == 1 && kirbypos.x - brospos.x >= 0 && kirbypos.x - brospos.x <= 150.0f) //&& fabs(kirbypos.y - brospos.y) <= 10.0f)
			{
				find = true;
			}

			if (find == true && boomwaiting >= 1.5f)
			{
				boomwaiting = 0.0f;
				boomcreate = true;
				find = false;
				mState = BrosState::RightBoomRelease;
				mAnimator->Play(L"RightBoomRelease", false);
			}
		}

		tr->SetPos(pos);
	}
	void BoomBros::hitair()
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
	void BoomBros::hitleftair()
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
	void BoomBros::hitstar()
	{
		hitstartime += Time::DeltaTime();

		if (hitstartime >= 0.2f)
		{
			object::Destroy(mStar);
			object::Destroy(this);
		}
	}
	void BoomBros::brosdeath()
	{
		deathtime += Time::DeltaTime();

		if (deathtime >= 0.2f)
		{
			object::Destroy(this);
		}
	}
	void BoomBros::hitkirbybase()
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
	void BoomBros::lefthitkirbybase()
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
	void BoomBros::hitsliding()
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
	void BoomBros::hitslidingleft()
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
	void BoomBros::rightboomrelease()
	{
		BoomShot = true;
		boomreleasetime += Time::DeltaTime();
		boomwaiting += Time::DeltaTime();

		Transform* brostr = this->GetComponent<Transform>();
		Vector2 brospos = brostr->GetPos();


		if (boomcreate == true && boomwaiting >= 0.5f)
		{
			boomwaiting = 0.0f;
			boomcreate = false;
			RightBoomb* mRightBoomb = object::Instantiate<RightBoomb>(Vector2(brospos.x + 30, brospos.y - 15), Vector2(2.0f, 2.0f), eLayerType::MonsterSkill);
			SetBoomb(mRightBoomb);
			mRightBoomb->SetBoomBros(this);

			if (GetGround() != nullptr)
			{
				mGround = GetGround();
				mGround->SetBoomb(mRightBoomb);
				mRightBoomb->SetGround(mGround);
			}
		}

		if (boomreleasetime >= 0.6f)
		{
			boomwaiting = 0.0f;
			boomreleasetime = 0.0f;
			mState = BrosState::RightBoomShot;
			mAnimator->Play(L"RightBoomShot", false);
		}
	}

	void BoomBros::rightboomshot()
	{
		//boomwaiting += Time::DeltaTime();
		if (BoomShot == true)
		{
			//boomwaiting = 0.0f;
			BoomShot = false;
			if (mRightBoomb->GetDestroy() == false)
			{
				RigidBody* bb = mRightBoomb->GetComponent<RigidBody>();
				bb->SetGravity(Vector2(0.0f, 500.f));
				bb->SetVelocity(Vector2(100.f, -400.f));
			}
		}
		if (BoomShot == false)
		{
			boomshotend += Time::DeltaTime();
		}
		if (boomshotend >= 1.1f)
		{
			boomshotend = 0.0f;
			mState = BrosState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		//if (BoomShot ==false && find == false)
		//{
		//	mState = BrosState::RightIdle;
		//	mAnimator->Play(L"RightIdle", true);
		//}
	}

	void BoomBros::leftboomrelease()
	{
		leftBoomShot = true;
		leftboomreleasetime += Time::DeltaTime();
		leftboomwaiting += Time::DeltaTime();

		Transform* brostr = this->GetComponent<Transform>();
		Vector2 brospos = brostr->GetPos();


		if (leftBoomCreate == true && leftboomwaiting >= 0.5f)
		{
			leftboomwaiting = 0.0f;
			leftBoomCreate = false;
			LeftBoomb* mLeftBoomb = object::Instantiate<LeftBoomb>(Vector2(brospos.x + 30, brospos.y - 15), Vector2(2.0f, 2.0f), eLayerType::MonsterSkill);
			SetLeftBoomb(mLeftBoomb);
			mLeftBoomb->SetBoomBros(this);

			if (GetGround() != nullptr)
			{
				mGround = GetGround();
				mGround->SetLeftBoomb(mLeftBoomb);
				mLeftBoomb->SetGround(mGround);
			}
		}

		if (leftboomreleasetime >= 0.6f)
		{
			leftboomwaiting = 0.0f;
			leftboomreleasetime = 0.0f;
			mState = BrosState::LeftBoomShot;
			mAnimator->Play(L"LeftBoomShot", false);
		}
	}

	void BoomBros::leftboomshot()
	{
		//boomwaiting += Time::DeltaTime();
		if (leftBoomShot == true)
		{
			//boomwaiting = 0.0f;
			leftBoomShot = false;
			if (mLeftBoomb->GetDestroy() == false)
			{
				RigidBody* lbb = mLeftBoomb->GetComponent<RigidBody>();
				lbb->SetGravity(Vector2(0.0f, 400.f));
				lbb->SetVelocity(Vector2(-150.f, -300.f));
			}
		}
		if (leftBoomShot == false)
		{
			leftboomshotend += Time::DeltaTime();
		}
		if (leftboomshotend >= 1.1f)
		{
			leftboomshotend = 0.0f;
			mState = BrosState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
	}

	void BoomBros::hitboom()
	{
		object::Destroy(this);
	}
	
}
