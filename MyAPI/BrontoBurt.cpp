#include "BrontoBurt.h"
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
#include "MyObject.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"



namespace My
{
	BrontoBurt::BrontoBurt()
		:brontoburttime(0.f)
		, chargindtime(0.f)
		, brontoburtdir(0)
		, brontoburtHP(100)
		, deathtime(0.f)
		, hitkirbybasetime(0.f)
		, Check(true)
	{

	}
	BrontoBurt::~BrontoBurt()
	{

	}
	void BrontoBurt::Initialize()
	{
		Image* mBrontoBurt = Resources::Load<Image>(L"BrontoBurt", L"..\\Resources\\BrontoBurt.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"None", mBrontoBurt, Vector2(0.0f, 0.0f), 16, 16, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftFly", mBrontoBurt, Vector2(0.0f,0.0f), 16, 16, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"Charging", mBrontoBurt, Vector2(40.0f, 0.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"Hit", mBrontoBurt, Vector2(0.0f, 80.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"Death", mBrontoBurt, Vector2(40.0f, 80.0f), 16, 16, 1, Vector2::Zero, 0.1);

		mState = BrontoBurtState::None;
		mAnimator->Play(L"None", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-25.0f, -65.0f));
		collider->SetSize(Vector2(45.0f, 47.0f));;

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);
		mRigidBody->SetGravity(Vector2::Zero);

		



		GameObject::Initialize();
	}
	void BrontoBurt::Update()
	{
		GameObject::Update();


			Transform* kirbytr = mkirby->GetComponent<Transform>();
			Transform* burttr = this->GetComponent<Transform>();

			float distance;

			distance = burttr->GetPos().x - kirbytr->GetPos().x;
			if (Check == true)
			{
				if (distance <= 400.0f)
		   	{
					Check = false;
				mState = BrontoBurtState::LeftFly;
				mAnimator->Play(L"LeftFly", false);
			}
		}

		switch (mState)
		{
		case BrontoBurt::BrontoBurtState::None:
			none();
			break;
		case BrontoBurt::BrontoBurtState::LeftFly:
			leftfly();
			break;
		case BrontoBurt::BrontoBurtState::Charging:
			charging();
			break;
		case BrontoBurt::BrontoBurtState::HitKirbyBase:
			hitkirbybase();
			break;
		case BrontoBurt::BrontoBurtState::LeftHitKirbyBase:
			lefthitkirbybase();
			break;
		case BrontoBurt::BrontoBurtState::Death:
			death();
			break;
		}
	}
	void BrontoBurt::Render(HDC hdc)
	{

		GameObject::Render(hdc);

	}
	void BrontoBurt::Release()
	{

		GameObject::Release();

	}
	void BrontoBurt::OnCollisionEnter(Collider* other)
	{
		//if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		//{
		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamBaseHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightBeamBaseHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamJumpHitRelease)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightBeamJumpHitRelease)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamPigHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightBeamPigHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}

		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftPigJumpHitRelease)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightPigJumpHitRelease)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftPigBaseHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::LeftAbsorbPigHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::RightAbsorbPigHit)
		//	{
		//		SetDamage(50);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
		//	{
		//		SetDamage(40);
		//		mState = BrontoBurtState::LeftHitKirbyBase;
		//	}
		//	if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
		//	{
		//		SetDamage(40);
		//		mState = BrontoBurtState::HitKirbyBase;
		//	}
		//}



		if (mAir = dynamic_cast<Air*>(other->GetOwner()))
		{
			//SetDamage(50);
			//mState = BrontoBurtState::HitAir;
		}
		if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
		{
			SetDamage(100);
			mState = BrontoBurtState::Death;
			//mState = BrontoBurtState::LeftHitAir;
		}
		if (mStar = dynamic_cast<Star*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = BrontoBurtState::HitStar;
		}
		if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = BrontoBurtState::Death;
		}
		if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = BrontoBurtState::Death;
		}
		if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = BrontoBurtState::Death;
		}
		if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
		{
			//SetDamage(100);
			//mState = BrontoBurtState::Death;
		}

	}
	void BrontoBurt::OnCollisionStay(Collider* other)
	{
		 mAnimator->Play(L"Hit", false);
	}
	void BrontoBurt::OnCollisionExit(Collider* other)
	{

	}
	void BrontoBurt::none()
	{
	}
	void BrontoBurt::leftfly()
	{
		brontoburttime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 Pos = tr->GetPos();
		Pos.x -= 70.0f * Time::DeltaTime();
		mRigidBody->SetGravity(Vector2(0.0f, 75.0f));

		
		if (brontoburttime >= 0.8f)
		{
			brontoburttime = 0.0f;
			mRigidBody->SetGravity(Vector2::Zero);
			mRigidBody->SetVelocity(Vector2(0.0f, -50.0f));

			mState = BrontoBurtState::Charging;
			mAnimator->Play(L"Charging", false);
		}

		tr->SetPos(Pos);


	}
	void BrontoBurt::charging()
	{
		chargindtime += Time::DeltaTime();

		if (chargindtime >= 0.5f)
		{
			chargindtime = 0.0f;
			mRigidBody->SetVelocity(Vector2::Zero);
			mState = BrontoBurtState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}
	
	}

	void BrontoBurt::hitkirbybase()
	{
		//hitkirbybasetime += Time::DeltaTime();

		//Transform* tr = GetComponent<Transform>();
		//Vector2 bbPos = tr->GetPos();

		//mRigidBody->SetGround(true);

		//bbPos.x += 100.0f * Time::DeltaTime();

		//if (hitkirbybasetime >= 0.4f)
		//{
		//	mState = BrontoBurtState::LeftFly;
		//	mAnimator->Play(L"LeftFly", true);
		//}

		//if (brontoburtHP <= 0)
		//{
		//	mState = BrontoBurtState::BrontoBurtDeath;
		//}

		//tr->SetPos(bbPos);
	}
	void BrontoBurt::lefthitkirbybase()
	{

	}
	void BrontoBurt::death()
	{
		deathtime += Time::DeltaTime();

		if (deathtime >= 0.5f)
		{
			object::Destroy(this);
		}
	}
}