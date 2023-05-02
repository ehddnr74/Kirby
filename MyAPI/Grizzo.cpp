#include "Grizzo.h"
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
#include"LeftBoomb.h"
#include "RightBoomb.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "R2Ground.h"
#include "R3Ground.h"
#include "MyKirby.h"
#include "AttackEffect.h"
#include "MySound.h"
#include "MyResources.h"
#include "AbsorbEffect.h"
#include "AbsorbLeftEffect.h"


namespace My
{
	Grizzo::Grizzo()
		: grizzotime(0.f)
		, GrizzoHP(100)
		, grizzodir(0)
		, hitairtime(0.f)
		, hitstartime(0.f)
		, hitkirbybasetime(0.f)
		, hitslidingtime(0.f)
		, deathtime(0.f)
		, a(1)
		, b(1)
	{
	}
	Grizzo::~Grizzo()
	{
	}
	void Grizzo::Initialize()
	{
		Image* mGrizzo = Resources::Load<Image>(L"Grizzo", L"..\\Resources\\Grizzo.bmp");
		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"RightMove", mGrizzo, Vector2::Zero, 10, 10, 4, Vector2::Zero, 0.5);
		mAnimator->CreateAnimation(L"LeftMove", mGrizzo, Vector2(0.0f, 100.0f), 10, 10, 4, Vector2::Zero, 0.5);

		mAnimator->CreateAnimation(L"LeftHit", mGrizzo, Vector2(0.0f, 150.0f), 10, 10, 1, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightHit", mGrizzo, Vector2(0.0f, 50.0f), 10, 10, 1, Vector2::Zero, 0.3);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-40.0f, -100.0f));
		collider->SetSize(Vector2(80.0f, 70.0f));

		mState = GrizzoState::LeftMove;
		mAnimator->Play(L"LeftMove", true);

		GameObject::Initialize();
	}
	void Grizzo::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case GrizzoState::LeftMove:
			leftmove();
			break;
		case GrizzoState::RightMove:
			rightmove();
			break;
		case GrizzoState::Death:
			death();
			break;
		case GrizzoState::HitBoom:
			hitboom();
			break;
		case GrizzoState::HitKirbyBase:
			hitkirbybase();
			break;
		case GrizzoState::LeftHitKirbyBase:
			lefthitkirbybase();
			break;
		case GrizzoState::HitSliding:
			hitsliding();
			break;
		case GrizzoState::HitSlidingLeft:
			hitslidingleft();
			break;
		case GrizzoState::HitStar:
			hitstar();
			break;
		}
	}
	void Grizzo::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Grizzo::Release()
	{
		GameObject::Release();
	}
	void Grizzo::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
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
				mState = GrizzoState::LeftHitKirbyBase;
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
				mState = GrizzoState::HitKirbyBase;
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
				mState = GrizzoState::LeftHitKirbyBase;
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
				mState = GrizzoState::HitKirbyBase;
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
				mState = GrizzoState::LeftHitKirbyBase;
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
				mState = GrizzoState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
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
				mState = GrizzoState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
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
				mState = GrizzoState::HitKirbyBase;
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
				mState = GrizzoState::HitSliding;
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
				mState = GrizzoState::HitSlidingLeft;
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
			mState = GrizzoState::HitKirbyBase;
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
			mState = GrizzoState::LeftHitKirbyBase;
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
			mState = GrizzoState::HitStar;
		}
		if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = GrizzoState::Death;
		}
		if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = GrizzoState::Death;
		}
		if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = GrizzoState::Death;
		}
		if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = GrizzoState::Death;
		}
		if (GetGround() != nullptr)
		{
			if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
			{
				GetGround()->SetKirBoomb(nullptr);
				SetDamage(100);
				mState = GrizzoState::HitBoom;
			}
			if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
			{
				GetGround()->SetKirLeftBoomb(nullptr);
				SetDamage(100);
				mState = GrizzoState::HitBoom;
			}
		}


		if (GetGround3() != nullptr)
		{
			if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
			{
				GetGround3()->SetKirBoomb(nullptr);
				SetDamage(100);
				mState = GrizzoState::HitBoom;
			}
			if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
			{
				GetGround3()->SetKirLeftBoomb(nullptr);
				SetDamage(100);
				mState = GrizzoState::HitBoom;
			}
		}
	}
	void Grizzo::OnCollisionStay(Collider* other)
	{
		if (grizzodir == 0)
		{
			mAnimator->Play(L"LeftHit", false);
		}
		if (grizzodir == 1)
		{
			mAnimator->Play(L"RightHit", false);
		}
	}
	void Grizzo::OnCollisionExit(Collider* other)
	{
	}
	void Grizzo::leftmove()
	{
		grizzodir = 0;
		grizzotime += Time::DeltaTime();
		Transform* tr = GetComponent<Transform>();
		Vector2 gpos = tr->GetPos();

		gpos.x -= 40.0f * Time::DeltaTime();

		if (grizzotime >= 2.0f)
		{
			grizzotime = 0.0f;
			mState = GrizzoState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

		tr->SetPos(gpos);
	}
	void Grizzo::rightmove()
	{
		grizzodir = 1;
		grizzotime += Time::DeltaTime();
		Transform* tr = GetComponent<Transform>();
		Vector2 gpos = tr->GetPos();

		gpos.x += 40.0f * Time::DeltaTime();

		if (grizzotime >= 2.0f)
		{
			grizzotime = 0.0f;
			mState = GrizzoState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}

		tr->SetPos(gpos);
	}
	void Grizzo::death()
	{
		hitairtime += Time::DeltaTime();

		if (hitairtime >= 0.5f)
		{
			hitairtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Grizzo::hitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();


		WaddlePos.x += 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && grizzodir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = GrizzoState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}
		if (hitkirbybasetime >= 0.2f && grizzodir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = GrizzoState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

		if (GrizzoHP <= 0 && grizzodir == 0)
		{

			WaddlePos.x += 2000.0f * Time::DeltaTime();

			mState = GrizzoState::Death;
		}

		if (GrizzoHP <= 0 && grizzodir == 1)
		{

			WaddlePos.x -= 2000.0f * Time::DeltaTime();

			mState = GrizzoState::Death;
		}

		tr->SetPos(WaddlePos);
	}
	void Grizzo::lefthitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();


		WaddlePos.x -= 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && grizzodir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = GrizzoState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}
		if (hitkirbybasetime >= 0.2f && grizzodir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = GrizzoState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

		if (GrizzoHP <= 0 && grizzodir == 0)
		{
			WaddlePos.x -= 2000.0f * Time::DeltaTime();

			mState = GrizzoState::Death;
		}

		tr->SetPos(WaddlePos);
	}
	void Grizzo::hitsliding()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();

		WaddlePos.x += 1000.0f * Time::DeltaTime();

		tr->SetPos(WaddlePos);

		if (hitslidingtime >= 0.3f && GrizzoHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Grizzo::hitslidingleft()
	{
		hitslidingtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();

		WaddlePos.x -= 1000.0f * Time::DeltaTime();

		tr->SetPos(WaddlePos);

		if (hitslidingtime >= 0.2f && GrizzoHP <= 0)
		{
			hitslidingtime = 0.0f;
			object::Destroy(this);
		}
	}
	void Grizzo::hitstar()
	{
		hitstartime += Time::DeltaTime();

		if (hitstartime >= 0.2f)
		{
			object::Destroy(mStar);
			object::Destroy(this);
		}
	}
	void Grizzo::hitboom()
	{
		object::Destroy(this);
	}
};