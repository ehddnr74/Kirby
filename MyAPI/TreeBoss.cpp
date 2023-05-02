#include "TreeBoss.h"
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
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "TreeGround.h"
#include "Breath.h"
#include "Apple.h"
#include "AttackEffect.h"
#include "MyWaddle.h"
#include "BoomBros.h"
#include "Endingstar.h"
#include "MySound.h"
#include "MyResources.h"

namespace My
{
	TreeBoss::TreeBoss()
		: treetime(0.f)
		, TreeHP(135)
		, breathtime(0.f)
		, hit(false)
		, hittime(0.f)
		, BreathCount(0)
		, breathreleasetime(0.f)
		, appletime(0.f)
		, airtime(0.f)
		, AppleCount(0)
		, applet(0.f)
		, applereleasetime(0.f)
		, AppleUse(true)
		, WaddleRespawn(true)
		, BoomBrosRespawn(false)
		, ending(true)
		, endingtime(0.0f)
	{
	}
	TreeBoss::~TreeBoss()
	{
	}
	void TreeBoss::Initialize()
	{
		Image* mTree = Resources::Load<Image>(L"Tree", L"..\\Resources\\TreeBoss.bmp");
		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"None", mTree, Vector2::Zero, 10, 10, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"Blink", mTree, Vector2::Zero, 10, 10, 5, Vector2::Zero, 0.08);
		mAnimator->CreateAnimation(L"DoubleBlink", mTree, Vector2::Zero, 10, 10, 9, Vector2::Zero, 0.08);
		mAnimator->CreateAnimation(L"Hit", mTree, Vector2(0.0f,80.0f),10, 10, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"Breath", mTree, Vector2(0.0f, 160.0f), 10, 10, 3, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"Death", mTree, Vector2(0.0f, 240.0f), 10, 10, 4, Vector2::Zero, 0.1);


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-30.0f, -220.0f));
		collider->SetSize(Vector2(130.0f, 300.0f));

		//mState = TreeState::None;
		//mAnimator->Play(L"None", false);

		GameObject::Initialize();
	}
	void TreeBoss::Update()
	{
		GameObject::Update();

		if (TreeHP <= 0)
		{
			endingtime += Time::DeltaTime();

			if (ending == true && endingtime>=3.0f)
			{
				Sound* mSound2 = Resources::Load<Sound>(L"00b8 - SE_WARPSTAR2", L"..\\Resources\\Sound\\00b8 - SE_WARPSTAR2.wav");
				mSound2->Play(true);
				ending = false;
				object::Instantiate<EndingStar>(Vector2(200.f, 1400.f), Vector2(1.5f, 1.5f), eLayerType(eLayerType::Portal));
			}
		}

		

		if (mState != TreeState::Death)
		{
			if (TreeHP <= 0)
			{
				Sound* mSound = Resources::Load<Sound>(L"05.-Battle-with-the-Boss", L"..\\Resources\\Sound\\05.-Battle-with-the-Boss.wav");
				mSound->Stop(false);
				Sound* mSound2 = Resources::Load<Sound>(L"00b2 - SE_BOSSDEAD1", L"..\\Resources\\Sound\\00b2 - SE_BOSSDEAD1.wav");
				mSound2->Play(false);
				mState = TreeState::Death;
				mAnimator->Play(L"Death", false);

			}
		}

		Transform* kr = mKirby->GetComponent<Transform>();
		Vector2 krPos = kr->GetPos();

		Transform* tr = this->GetComponent<Transform>();
		Vector2 trPos = tr->GetPos();

		if (mState != TreeState::Death)
		{
			if (trPos.y - krPos.y <= 500.0f)
			{
				appletime += Time::DeltaTime();

				if (AppleUse == true && mState != TreeState::Breath && mState != TreeState::Apple)
				{
					if (appletime >= 5.0f)
					{
						AppleUse = false;
						appletime = 0.0f;
						mState = TreeState::Apple;
					}
				}

				if (mState != TreeState::Breath && mState != TreeState::Apple)
				{
					airtime += Time::DeltaTime();
					if (airtime >= 6.f)
					{
					 airtime = 0.0f;
					 mState = TreeState::Breath;
					}
				}
			}

			treetime += Time::DeltaTime();

			if (treetime >= 2.0f && treetime <= 2.1f)
			{
				mAnimator->Play(L"Blink", false);
			}

			if (treetime >= 4.0f)
			{
				treetime = 0.0f;
				mAnimator->Play(L"DoubleBlink", false);
			}
		}


		switch (mState)
		{
		case TreeState::None:
			none();
			break;
		case TreeState::Apple:
			apple();
			break;
		case TreeState::Breath:
			breath();
			break;
		case TreeState::Death:
			death();
			break;
		}
	}
	void TreeBoss::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void TreeBoss::Release()
	{
		GameObject::Release();
	}
	void TreeBoss::OnCollisionEnter(Collider* other)
	{
            if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
        	{
				hit = true;
				mAnimator->Play(L"Hit", false);
        		mTreeGround->SetKirBoomb(nullptr);
        		SetDamage(15);
        		//mState = GrizzoState::HitBoom;
        	}
            if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
        	{
				hit = true;
				mAnimator->Play(L"Hit", false);
				mTreeGround->SetKirLeftBoomb(nullptr);
        		SetDamage(15);
        		//mState = GrizzoState::HitBoom;
        	}
			if (mStar = dynamic_cast<Star*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 150), Vector2(3.0f, 3.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Attack);
				mAnimator->Play(L"Hit", false);
				SetDamage(15);
				//mState = BrosState::HitStar;
			}
			if (mKirbyBeam = dynamic_cast<KirbyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 150), Vector2(3.0f, 3.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				mAnimator->Play(L"Hit", false);
				SetDamage(15);
				//mState = BrosState::BrosDeath;
			}
			if (mLeftKirbyBeam = dynamic_cast<LeftKirbyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 150), Vector2(3.0f, 3.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				mAnimator->Play(L"Hit", false);
				SetDamage(15);
				//mState = BrosState::BrosDeath;
			}
			if (mEnergyBeam = dynamic_cast<EnergyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 150), Vector2(3.0f, 3.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				mAnimator->Play(L"Hit", false);
				SetDamage(15);
				//mState = BrosState::BrosDeath;
			}
			if (mLeftEnergyBeam = dynamic_cast<LeftEnergyBeam*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 thispos = tr->GetPos();
				AttackEffect* mAttackEffect = object::Instantiate<AttackEffect>(Vector2(thispos.x - 10, thispos.y + 150), Vector2(3.0f, 3.0f), eLayerType(eLayerType::Effect));
				mAttackEffect->SetEffectState(AttackEffect::AttackState::Beam);
				mAnimator->Play(L"Hit", false);
				SetDamage(15);
				//mState = BrosState::BrosDeath;
			}




		//if (GetGround() != nullptr)
		//{
		//	if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
		//	{
		//		GetGround()->SetKirBoomb(nullptr);
		//		SetDamage(100);
		//		mState = GrizzoState::HitBoom;
		//	}
		//	if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
		//	{
		//		GetGround()->SetKirLeftBoomb(nullptr);
		//		SetDamage(100);
		//		mState = GrizzoState::HitBoom;
		//	}
		//}


		//if (GetGround3() != nullptr)
		//{
		//	if (mKrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
		//	{
		//		GetGround3()->SetKirBoomb(nullptr);
		//		SetDamage(100);
		//		mState = GrizzoState::HitBoom;
		//	}
		//	if (mKlb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
		//	{
		//		GetGround3()->SetKirLeftBoomb(nullptr);
		//		SetDamage(100);
		//		mState = GrizzoState::HitBoom;
		//	}
		//}
	}
	void TreeBoss::OnCollisionStay(Collider* other)
	{
	}
	void TreeBoss::OnCollisionExit(Collider* other)
	{
	}
	void TreeBoss::none()
	{
	}
	void TreeBoss::apple()
	{

		applet += Time::DeltaTime();
		Transform* kr = mKirby->GetComponent<Transform>();
		Vector2 krPos = kr->GetPos();

		Transform* tr = this->GetComponent<Transform>();
		Vector2 trPos = tr->GetPos();

		if (AppleCount == 0 && applet >= 0.8f)
		{
			Apple* mApple = object::Instantiate<Apple>(Vector2(krPos.x, krPos.y - 250), Vector2(2.f, 2.f), (eLayerType::Apple));
			mApple->SetGround(mTreeGround);
			mTreeGround->SetApple(mApple);
			AppleCount++;
		}

		applereleasetime += Time::DeltaTime();

		if (applereleasetime >= 0.5f && AppleCount == 1 && applet >= 1.7f)
		{
			applereleasetime = 0.0f;
			AppleCount++;
			Apple* mApple = object::Instantiate<Apple>(Vector2(krPos.x + 100, krPos.y - 250), Vector2(2.f, 2.f), (eLayerType::Apple));
			mApple->SetGround(mTreeGround);
			mTreeGround->SetApple(mApple);
		}


		if (applereleasetime >= 0.5f && AppleCount == 2 && applet >= 2.7f)
		{
			applereleasetime = 0.0f;
			AppleCount++;
			applet = 0.0f;
			Apple* mApple2 = object::Instantiate<Apple>(Vector2(krPos.x + 200, krPos.y - 250), Vector2(2.f, 2.f), (eLayerType::Apple));
			mApple2->SetGround(mTreeGround);
			mApple2->Setnum(4);
			mTreeGround->SetApple2(mApple2);
		}


		if (applereleasetime >= 0.5f && AppleCount == 3 && applet >= 0.5f)
		{
			applereleasetime = 0.0f;
			AppleCount = 0;
			applet = 0.0f;
			mState = TreeState::None;
			mAnimator->Play(L"Blink", false);
		}

	}
	void TreeBoss::breath()
	{
		breathtime += Time::DeltaTime();


		if (BreathCount == 0 && breathtime >= 0.8f)
		{
			mAnimator->Play(L"Breath", false);
			Breath* mBreath = object::Instantiate<Breath>(Vector2(330.f,1450.f),Vector2(2.f,2.f),(eLayerType::BossSkill));
			BreathCount++;
		}

		breathreleasetime += Time::DeltaTime();

		if (breathreleasetime >= 0.5f && BreathCount == 1 && breathtime >= 1.7f)
		{
			breathreleasetime = 0.0f;
			BreathCount++;
			mAnimator->Play(L"Breath", false);
			Breath* mBreath = object::Instantiate<Breath>(Vector2(330.f, 1450.f), Vector2(2.f, 2.f), (eLayerType::BossSkill));
		}


		if (breathreleasetime >= 0.5f && BreathCount == 2 && breathtime >= 2.7f)
		{
			breathreleasetime = 0.0f;
			BreathCount++;
			breathtime = 0.0f;
			mAnimator->Play(L"Breath", false);
			Breath* mBreath = object::Instantiate<Breath>(Vector2(330.f, 1450.f), Vector2(2.f, 2.f), (eLayerType::BossSkill));
		}


		if (breathreleasetime >= 0.5f && BreathCount == 3 && breathtime>=0.5f)
		{
			breathreleasetime = 0.0f;
			BreathCount = 0;
			breathtime = 0.0f;
			mState = TreeState::None;
			AppleUse = true;
			mAnimator->Play(L"Blink", false);
		}
	}
	void TreeBoss::death()
	{
	}
};