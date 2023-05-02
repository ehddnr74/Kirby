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
#include "AttackEffect.h"
#include "MySound.h"
#include "MyResources.h"
#include "AbsorbEffect.h"
#include "AbsorbLeftEffect.h"


namespace My
{
	BrontoBurt::BrontoBurt()
		:brontoburttime(0.f)
		, chargindtime(0.f)
		, brontoburtdir(0)
		, brontoburtHP(100)
		, deathtime(0.f)
		, hitkirbybasetime(0.f)
		, hitairtime(0.f)
		, hitstartime(0.f)
		, Check(true)
		, a(1)
		, b(1)
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

			
			if (mkirby != nullptr)
			{ 
			Transform* kirbytr = mkirby->GetComponent<Transform>();
			float distance;
			Transform* burttr = this->GetComponent<Transform>();
			distance = burttr->GetPos().x - kirbytr->GetPos().x;
			if (Check == true)
			{
				if (distance <= 480.0f)
				{
					Check = false;
					mState = BrontoBurtState::LeftFly;
					mAnimator->Play(L"LeftFly", false);
				}
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
		case BrontoBurt::BrontoBurtState::HitAir:
			hitair();
			break;
		case BrontoBurt::BrontoBurtState::LeftHitAir:
			hitleftair();
			break;
		case BrontoBurt::BrontoBurtState::HitStar:
			hitstar();
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
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamBaseHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamBaseHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamJumpHitRelease)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamJumpHitRelease)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftBeamPigHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightBeamPigHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}

			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigJumpHitRelease)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigJumpHitRelease)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigBaseHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::LeftAbsorbPigHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::RightAbsorbPigHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(50);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(40);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(40);
				if (this->GetHP() > 0 && this->GetHP() <= 99)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
					mSound->Play(false);
				}
				if (this->GetHP() <= 0)
				{
					Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
					mSound->Play(false);
				}
				mState = BrontoBurtState::HitKirbyBase;
			}
		}



		if (mAir = dynamic_cast<Air*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Air);
			SetDamage(50);
			if (this->GetHP() > 0 && this->GetHP() <= 99)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
				mSound->Play(false);
			}
			if (this->GetHP() <= 0)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
				mSound->Play(false);
			}
			mState = BrontoBurtState::HitAir;
		}
		if (mAirLeft = dynamic_cast<AirLeft*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Air);
			SetDamage(50);
			if (this->GetHP() > 0 && this->GetHP() <= 99)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
				mSound->Play(false);
			}
			if (this->GetHP() <= 0)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
				mSound->Play(false);
			}
			mState = BrontoBurtState::LeftHitAir;
		}
		if (mStar = dynamic_cast<Star*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Attack);
			SetDamage(100);
			Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
			mSound->Play(false);
			mState = BrontoBurtState::HitStar;
		}
		if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = BrontoBurtState::Death;
		}
		if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = BrontoBurtState::Death;
		}
		if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = BrontoBurtState::Death;
		}
		if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = BrontoBurtState::Death;
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

	void BrontoBurt::hitair()
	{
		hitairtime += Time::DeltaTime();

		if (brontoburtHP > 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = BrontoBurtState::LeftFly;
				mAnimator->Play(L"LeftFly", true);
			}

		}

		if (brontoburtHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.1f)
			{
				mState = BrontoBurtState::Death;
			}
		}
	}

	void BrontoBurt::hitleftair()
	{
		hitairtime += Time::DeltaTime();

		if (brontoburtHP > 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = BrontoBurtState::LeftFly;
				mAnimator->Play(L"LeftFly", true);
			}
		}
		if (brontoburtHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.1f)
			{
				mState = BrontoBurtState::Death;
			}
		}
	}

	void BrontoBurt::hitstar()
	{
	}

	void BrontoBurt::hitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x += 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f)
		{
			hitkirbybasetime = 0.0f;
			mState = BrontoBurtState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}

		if (brontoburtHP <= 0)
		{
			tzPos.x += 2000.0f * Time::DeltaTime();

			mState = BrontoBurtState::Death;
		}

		tr->SetPos(tzPos);
	}
	void BrontoBurt::lefthitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x -= 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f)
		{
			hitkirbybasetime = 0.0f;
			mState = BrontoBurtState::LeftFly;
			mAnimator->Play(L"LeftFly", true);
		}

		if (brontoburtHP <= 0)
		{
			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = BrontoBurtState::Death;
		}
		tr->SetPos(tzPos);
	}
	void BrontoBurt::death()
	{
		mRigidBody->SetGravity(Vector2(0.0f, 800.0f));

		deathtime += Time::DeltaTime();

		if (deathtime >= 0.5f)
		{
			object::Destroy(this);
		}
	}
}