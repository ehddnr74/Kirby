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
#include "AbsorbLeftEffect.h"
#include "MyCamera.h"
#include "Air.h"
#include "AirLeft.h"
#include "Star.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "Beam.h"
#include "LeftBeam.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "R3Ground.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "AttackEffect.h"
#include "MySound.h"
#include "MyResources.h"
namespace My
{
	Waddle::Waddle()
		:waddletime(0.f)
		, waddledir(0)
		, WaddleHP(100)
		, hitairtime(0.f)
		, hitslidingtime(0.f)
		, hitstartime(0.f)
		, hitkirbybasetime(0.f)
		, rightwaddletime(0.f)
		, beamtime(0.f)
		, boombtime(0.f)
		, beamuse(false)
		, a(1)
		, b(1)
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
		mAnimator->CreateAnimation(L"LeftBeam", mWaddle, Vector2(0.0f, 200.f), 16, 16, 1, Vector2::Zero, 0.01);



		mAnimator->CreateAnimation(L"RightMove", mWaddle, Vector2(0.0f, 40.0f), 16, 16, 4, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBoomb", mWaddle, Vector2(0.0f, 80.0f), 16, 16, 2, Vector2::Zero, 0.5);
		mAnimator->CreateAnimation(L"RightHit", mWaddle, Vector2(40.0f, 160.f), 16, 16, 1, Vector2::Zero, 0.01);
		mAnimator->CreateAnimation(L"RightBeam", mWaddle, Vector2(40.0f, 200.f), 16, 16, 1, Vector2::Zero, 0.01);

		mAnimator->Play(L"LeftMove", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-22.0f, -70.0f));
		collider->SetSize(Vector2(45.0f, 50.0f));

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
			break;
		case My::Waddle::WaddleState::LeftBoomb:
			leftboomb();
			break;
		case My::Waddle::WaddleState::RightBoomb:
			rightboomb();
			break;
		case My::Waddle::WaddleState::LeftBeam:
			leftbeam();
			break;
		case My::Waddle::WaddleState::RightBeam:
			rightbeam();
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
		case My::Waddle::WaddleState::HitKirbyBase: 
			hitkirbybase();
			break;
		case My::Waddle::WaddleState::LeftHitKirbyBase:
			lefthitkirbybase();
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
		case My::Waddle::WaddleState::HitBoom:
			hitboom();
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
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigJumpHitRelease)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigJumpHitRelease)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftPigBaseHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightPigBaseHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::LeftAbsorbPigHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightJumpHitRelease || mkirby->GetState() == Kirby::eKirbyState::RightAbsorbPigHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::HitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::LeftHit)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::LeftHitKirbyBase;
			}
			if (mkirby->GetState() == Kirby::eKirbyState::RightHit)
			{

				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Base);
				SetDamage(30);
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
				mState = WaddleState::HitKirbyBase;
			}

			if (mkirby->GetSliding())
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
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
				mState = WaddleState::HitSliding;
			}
			if (mkirby->GetLeftSliding())
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
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
				mState = WaddleState::HitSlidingLeft;
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
			mState = WaddleState::HitKirbyBase;
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
			mState = WaddleState::LeftHitKirbyBase;
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
			mState = WaddleState::HitStar;
		}
		if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
		{
			GetGround()->SetKirBoomb(nullptr);
			SetDamage(100);
			mState = WaddleState::HitBoom;
		}
		if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
		{
			GetGround()->SetKirLeftBoomb(nullptr);
			SetDamage(100);
			mState = WaddleState::HitBoom;
		}
		if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = WaddleState::WaddleDeath;
		}
		if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = WaddleState::WaddleDeath;
		}
		if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = WaddleState::WaddleDeath;
		}
		if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();
			AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 50), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
			SetDamage(100);
			mState = WaddleState::WaddleDeath;
		}
		if (mAbsorbEffect = dynamic_cast<AbsorbEffect*>(other->GetOwner()))
		{
			int a = 0;
		}
		if (mLeftAbsorbEffect = dynamic_cast<AbsorbLeftEffect*>(other->GetOwner()))
		{
			int b = 0;
		}
		/*if (a != 0)
		{
			if (this->GetHP() >= 0 && this->GetHP() <= 99)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
				mSound->Play(false);
			}
			if (this->GetHP() <= 0)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
				mSound->Play(false);
			}
		}

			if(b !=0)
			{
			if (this->GetHP() >= 0 && this->GetHP() <= 99)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit2", L"..\\Resources\\Sound\\hit2.wav");
				mSound->Play(false);
			}
			if (this->GetHP() <= 0)
			{
				Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
				mSound->Play(false);
			}
		}*/
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

		//if (WdPos.x >= 442.f)
		//{
		//	WdPos.x = 442.f;
		//}
		//if (WdPos.x <= 288.f)
		//{
		//	WdPos.x = 288.f;
		//}

		if (waddletime >= 3.0f)
		{
			waddletime = 0.0f;
			mState = WaddleState::LeftBoomb;
			mAnimator->Play(L"LeftBoomb", false);
		}

		tr->SetPos(WdPos);
	}



	void Waddle::rightmove()
	{
		waddledir = 1;

		Transform* tr = GetComponent<Transform>();

		rightwaddletime += Time::DeltaTime();

		Vector2 WdPos = tr->GetPos();

		WdPos.x += 20.f * Time::DeltaTime();

		//if (WdPos.x >= 442.f)
		//{
		//	WdPos.x = 442.f;
		//}
		//if (WdPos.x <= 288.f)
		//{
		//	WdPos.x = 288.f;
		//}

		if (rightwaddletime >= 3.0f)
		{
			rightwaddletime = 0.0f;
			mState = WaddleState::RightBoomb;
			mAnimator->Play(L"RightBoomb", false);
		}

		tr->SetPos(WdPos);
	}

	void Waddle::leftboomb()
	{
		beamuse = true;
		waddledir = 0;
		boombtime += Time::DeltaTime();

		if (boombtime >= 1.5f)
		{
			boombtime = 0.0f;
			mState = WaddleState::LeftBeam;
			mAnimator->Play(L"LeftBeam", false);
		}
	}

	void Waddle::rightboomb()
	{
		beamuse = true;
		waddledir = 1;
		boombtime += Time::DeltaTime();

		if (boombtime >= 1.5f)
		{
			boombtime = 0.0f;
			mState = WaddleState::RightBeam;
			mAnimator->Play(L"RightBeam", true);
		}

	}
	void Waddle::leftbeam()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
	
		if (beamuse == true)
		{
			beamuse = false;
			mLeftBeam = object::Instantiate<LeftBeam>(Vector2(pos.x - 90, pos.y + 75), Vector2(1.2f, 1.2f), (eLayerType::MonsterSkill));
		}
		    beamtime += Time::DeltaTime();

		if (beamtime >= 1.2f)
		{
			beamtime = 0.0f;
			
			mState = WaddleState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

	}
	void Waddle::rightbeam()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (beamuse == true)
		{
			beamuse = false;
			mBeam = object::Instantiate<Beam>(Vector2(pos.x + 90, pos.y + 70), Vector2(1.2f, 1.2f), (eLayerType::MonsterSkill));
		}
		beamtime += Time::DeltaTime();

		if (beamtime >= 1.2f)
		{
			beamtime = 0.0f;

			mState = WaddleState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}

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

	void Waddle::hitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();


		WaddlePos.x += 100.0f * Time::DeltaTime();
		
		

		if (hitkirbybasetime >= 0.2f && waddledir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = WaddleState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}
		if (hitkirbybasetime >= 0.2f && waddledir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = WaddleState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

		if (WaddleHP <= 0 && waddledir == 0)
		{
			
			WaddlePos.x += 2000.0f * Time::DeltaTime();

				mState = WaddleState::WaddleDeath;
		}

		if (WaddleHP <= 0 && waddledir == 1)
		{

			WaddlePos.x -= 2000.0f * Time::DeltaTime();

			mState = WaddleState::WaddleDeath;
		}
	
		tr->SetPos(WaddlePos);


	}

	void Waddle::lefthitkirbybase()
	{
		hitkirbybasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 WaddlePos = tr->GetPos();


		WaddlePos.x -= 100.0f * Time::DeltaTime();



		if (hitkirbybasetime >= 0.2f && waddledir == 0)
		{
			hitkirbybasetime = 0.0f;
			mState = WaddleState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}
		if (hitkirbybasetime >= 0.2f && waddledir == 1)
		{
			hitkirbybasetime = 0.0f;
			mState = WaddleState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

		if (WaddleHP <= 0 && waddledir == 0)
		{
			WaddlePos.x -= 2000.0f * Time::DeltaTime();

			mState = WaddleState::WaddleDeath;
		}

		tr->SetPos(WaddlePos);




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
	void Waddle::hitboom()
	{
		object::Destroy(this);
	}
}


