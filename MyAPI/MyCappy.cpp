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
#include "MyRigidBody.h"
#include "MyObject.h"
#include "R3Ground.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "AttackEffect.h"
#include "MySound.h"
#include "MyResources.h"

#include "AbsorbEffect.h"
#include "AbsorbLeftEffect.h"


namespace My
{
	Cappy::Cappy()
		:cappytime(0.0f)
		, cappydir(0)
		, CappyHP(100)
		, die(false)
		, cjumptime(0.f)
		, hitairtime(0.f)
	    , hitstartime(0.f)
	    , hitkirbybasetime(0.f)
	    , hitslidingtime(0.f)
		, deathtime(0.f)
		, a(1)
		, b(1)

	{
	}
	Cappy::~Cappy()
	{
	}
	void Cappy::Initialize()
	{
		Image* mCappy = Resources::Load<Image>(L"Cappy", L"..\\Resources\\Cappy.bmp");
		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"Move", mCappy, Vector2::Zero, 16, 16, 2, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"Jump", mCappy, Vector2(0.0f, 40.0f), 16, 16, 2, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftHit", mCappy, Vector2(40.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightHit", mCappy, Vector2(0.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.3);



		mState = CappyState::LeftMove;
		mAnimator->Play(L"Move", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-20.0f, -65.0f));
		collider->SetSize(Vector2(43.0f, 47.0f));


		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);

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
		case Cappy::CappyState::LeftJump:
			leftjump();
			break;
		case Cappy::CappyState::RightJump:
			rightjump();
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
		case Cappy::CappyState::HitBoom:
			hitboom();
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

	void Cappy::OnCollisionEnter(Collider* other)
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
					mState = CappyState::LeftHitKirbyBase;
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
					mState = CappyState::HitKirbyBase;
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
					mState = CappyState::LeftHitKirbyBase;
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
					mState = CappyState::HitKirbyBase;
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
					mState = CappyState::LeftHitKirbyBase;
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
					mState = CappyState::HitKirbyBase;
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
					mState = CappyState::LeftHitKirbyBase;
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
					mState = CappyState::HitKirbyBase;
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
					mState = CappyState::LeftHitKirbyBase;
				}
				if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
				{
					Transform* tr = GetComponent<Transform>();
					Vector2 thispos = tr->GetPos();
					AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
					mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
					SetDamage(50);			if (this->GetHP() > 0 && this->GetHP() <= 99)
					{
						Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
						mSound->Play(false);
					}
					if (this->GetHP() <= 0)
					{
						Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
						mSound->Play(false);
					}
					mState = CappyState::HitKirbyBase;
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
					mState = CappyState::LeftHitKirbyBase;
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
					mState = CappyState::HitKirbyBase;
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
				mState = CappyState::LeftHitKirbyBase;
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
					mState = CappyState::HitKirbyBase;
				}

				if (mkirby->GetSliding())
				{
					Transform* tr = GetComponent<Transform>();
					Vector2 thispos = tr->GetPos();
					AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
					mAttackEffect->SetEffectState(AttackEffect::AttackState::Attack);
					SetDamage(100);
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
					mState = CappyState::HitSliding;
				}
				if (mkirby->GetLeftSliding())
				{
					Transform* tr = GetComponent<Transform>();
					Vector2 thispos = tr->GetPos();
					AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
					mAttackEffect->SetEffectState(AttackEffect::AttackState::Attack);
					SetDamage(100);
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
					mState = CappyState::HitSlidingLeft;
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
				mState = CappyState::HitAir;
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
				mState = CappyState::LeftHitAir;
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
				mState = CappyState::HitStar;
			}
			if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				SetDamage(100);
				mState = CappyState::CappyDeath;
			}
			if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				SetDamage(100);
				mState = CappyState::CappyDeath;
			}
			if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				SetDamage(100);
				mState = CappyState::CappyDeath;
			}
			if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				SetDamage(100);
				mState = CappyState::CappyDeath;
			}
			if (GetGround3() != nullptr)
			{
				if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
				{
					GetGround3()->SetKirBoomb(nullptr);
					SetDamage(100);
					mState = CappyState::HitBoom;
				}
				if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
				{
					GetGround3()->SetKirLeftBoomb(nullptr);
					SetDamage(100);
					mState = CappyState::HitBoom;
				}
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

	void Cappy::leftmove()
	{
		cappydir = 0;

		Transform* cappytr = GetComponent<Transform>();
		Vector2 CappyPos = cappytr->GetPos();

		cappytime += Time::DeltaTime();

		if (cappytime <= 2.0f)
		{
			CappyPos.x -= 10.0f * Time::DeltaTime();
		}

		if (cappytime >= 2.0f)
		{
			cappytime = 0.0;
			mState = CappyState::RightMove;
			mAnimator->Play(L"Move", true);
		}

		cappytr->SetPos(CappyPos);

		//if (cappytime >= 1.5f)
		//{
		//	cappytime = 0.0f;
		//	mState = CappyState::RightMove;
		//}
	}


	void Cappy::rightmove()
	{
		cappydir = 1;
		Transform* cappytr = GetComponent<Transform>();
		Vector2 CappyPos = cappytr->GetPos();

		cappytime += Time::DeltaTime();

		if (cappytime <= 2.0f)
		{
			CappyPos.x += 10.0f * Time::DeltaTime();
		}
		if (cappytime >= 2.0f)
		{
			cappytime = 0.0;
			mState = CappyState::LeftJump;
			mAnimator->Play(L"Jump", true);
		}

		cappytr->SetPos(CappyPos);

	}
	void Cappy::leftjump()
	{
		cappydir = 0;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		cjumptime += Time::DeltaTime();

		if (cjumptime <= 2.0f)
		{
			pos.x -= 10.0f * Time::DeltaTime();
			pos.y -= 150.0f * Time::DeltaTime();
		}

		if (cjumptime >= 2.0f)
		{
			cjumptime = 0.0f;
			mState = CappyState::RightJump;
			mAnimator->Play(L"Jump", true);
		}
		tr->SetPos(pos);
	}
	void Cappy::rightjump()
	{
		cappydir = 1;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		cjumptime += Time::DeltaTime();

		if (cjumptime <= 2.0f)
		{
			pos.x += 10.0f * Time::DeltaTime();
			pos.y -= 150.0f * Time::DeltaTime();
		}

		if (cjumptime >= 2.0f)
		{
			cjumptime = 0.0f;
			mState = CappyState::LeftMove;
			mAnimator->Play(L"Move", true);
		}

		tr->SetPos(pos);
	}
	void Cappy::hitair()
	{
		hitairtime += Time::DeltaTime();

		if (CappyHP > 0 && cappydir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x += 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = CappyState::LeftMove;
				mAnimator->Play(L"Move", true);
			}
		}
			if (CappyHP > 0 && cappydir == 1)
			{

				Transform* tr = GetComponent<Transform>();
				Vector2 tzPos = tr->GetPos();

				tzPos.x += 200.0f * Time::DeltaTime();

				tr->SetPos(tzPos);

				if (hitairtime >= 0.2f)
				{
					hitairtime = 0.0f;
					mState = CappyState::RightMove;
					mAnimator->Play(L"Move", true);
				}
			}

			if (CappyHP <= 0)
			{
				hitairtime += Time::DeltaTime();

				Transform* tr = GetComponent<Transform>();
				Vector2 tzPos = tr->GetPos();

				tzPos.x += 100.0f * Time::DeltaTime();

				tr->SetPos(tzPos);

				if (hitairtime >= 0.1f)
					mState = CappyState::CappyDeath;
			}
	}
	void Cappy::hitleftair()
	{
		hitairtime += Time::DeltaTime();

		if (CappyHP > 0 && cappydir == 0)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = CappyState::LeftMove;
				mAnimator->Play(L"Move", true);
			}

		}

		if (CappyHP > 0 && cappydir == 1)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 200.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.2f)
			{
				hitairtime = 0.0f;
				mState = CappyState::RightMove;
				mAnimator->Play(L"Move", true);
			}
		}

		if (CappyHP <= 0)
		{
			hitairtime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 tzPos = tr->GetPos();

			tzPos.x -= 100.0f * Time::DeltaTime();

			tr->SetPos(tzPos);

			if (hitairtime >= 0.1f)
			mState = CappyState::CappyDeath;
		
		}
	}
	void Cappy::hitstar()
	{
		hitstartime += Time::DeltaTime();

		if (hitstartime >= 0.2f)
		{
			object::Destroy(mStar);
			object::Destroy(this);
		}
	}
	void Cappy::cappydeath()
	{
		deathtime += Time::DeltaTime();

		if (deathtime >= 0.2f)
		{
			deathtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Cappy::hitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x += 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && cappydir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = CappyState::LeftMove;
			mAnimator->Play(L"Move", true);
		}
		if (hitkirbybasetime >= 0.2f && cappydir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = CappyState::RightMove;
			mAnimator->Play(L"Move", true);
		}

		if (CappyHP <= 0 && cappydir == 0)
		{

			tzPos.x += 2000.0f * Time::DeltaTime();

			mState = CappyState::CappyDeath;
		}

		if (CappyHP <= 0 && cappydir == 1)
		{

			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = CappyState::CappyDeath;
		}

		tr->SetPos(tzPos);
	}
	void Cappy::lefthitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();


		tzPos.x -= 100.0f * Time::DeltaTime();

		if (hitkirbybasetime >= 0.2f && cappydir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = CappyState::LeftMove;
			mAnimator->Play(L"Move", true);
		}
		if (hitkirbybasetime >= 0.2f && cappydir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = CappyState::RightMove;
			mAnimator->Play(L"Move", true);
		}

		if (CappyHP <= 0 && cappydir == 0)
		{
			tzPos.x -= 2000.0f * Time::DeltaTime();

			mState = CappyState::CappyDeath;
		}

		tr->SetPos(tzPos);
	}
	void Cappy::hitsliding()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x += 1000.0f * Time::DeltaTime();

		tr->SetPos(tzPos);

		if (hitslidingtime >= 0.3f && CappyHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Cappy::hitslidingleft()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 tzPos = tr->GetPos();

		tzPos.x -= 1000.0f * Time::DeltaTime();

		tr->SetPos(tzPos);

		if (hitslidingtime >= 0.2f && CappyHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Cappy::hitboom()
	{
		object::Destroy(this);
	}
}