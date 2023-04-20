#include "AbsorbEffect.h"
#include "myTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyWaddle.h"
#include "MyKirby.h"
#include "Stage1_1.h"
#include "MyCamera.h"
#include "Bros.h"
#include "MyCappy.h"
#include "BoomBros.h"
#include "TreeBoss.h"
#include "Apple.h"

namespace My
{
	AbsorbEffect::AbsorbEffect()
		: mTime(0.0f)
		, Collision(0)
	{
	}
	AbsorbEffect::~AbsorbEffect()
	{
	}
	void AbsorbEffect::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(pos);
		//tr->SetScale(Vector2(1.8f,2.0f));

		Image * AbsorbEffect = Resources::Load<Image>(L"AbsorbEffect", L"..\\Resources\\AbsorbEffect.bmp");
		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"RightEffect", AbsorbEffect, Vector2::Zero, 2, 1, 2, Vector2::Zero, 0.3);

		//SetCollision(false);

		mAnimator->Play(L"RightEffect", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-40.0f, -60.0f));
		collider->SetSize(Vector2(100.0f, 60.0f));

		



		GameObject::Initialize();
	}
	void AbsorbEffect::Update()
	{
		GameObject::Update();

		if (mKirby != nullptr)
		{
			if (mKirby->GetJumpAbsorbing())
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 BeamPos = tr->GetPos();
				Transform* kr = mKirby->GetComponent<Transform>();
				Vector2 KirbyPos = kr->GetPos();

				BeamPos.x = KirbyPos.x + 70;
				BeamPos.y = KirbyPos.y + -15;

				tr->SetPos(BeamPos);
			}
		}
	}
	void AbsorbEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void AbsorbEffect::Release()
	{
		GameObject::Release();
	}
	void AbsorbEffect::OnCollisionEnter(Collider* other)
	{
		Waddle* mWaddle = dynamic_cast<Waddle*>(other->GetOwner());
		Bros* mBros = dynamic_cast<Bros*>(other->GetOwner());
		BoomBros* mBoomBros = dynamic_cast<BoomBros*>(other->GetOwner());
		TreeBoss* mTree = dynamic_cast<TreeBoss*>(other->GetOwner());
		//Apple* mApple = dynamic_cast<Apple*>(other->GetOwner());

		//if (other->GetOwner() == mApple)
		//{
		//	Collision = 1;
		//}
		if (other->GetOwner() != mTree)
		{
			if (other->GetOwner() == mWaddle)
			{
				Collision = 2;
			}
			else if (other->GetOwner() == mBros || other->GetOwner() == mBoomBros)
			{
				Collision = 3;
			}
			else
			{
				Collision = 1;
			}
		}
		//Dt = true;
		//mKirby->SetState(Kirby::eKirbyState::RightColAbsorb);
		//mKirby = object::Instantiate<Kirby>(Vector2(krpos.x, krpos.y), Vector2(2.0f, 2.0f), (eLayerType::Player));
	}

	void AbsorbEffect::OnCollisionStay(Collider* other)
	{
		TreeBoss* mTree = dynamic_cast<TreeBoss*>(other->GetOwner());
		if (other->GetOwner() != mTree)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();

			Vector2 otherPos = tr->GetPos();

			Transform* Effecttr = GetComponent<Transform>();

			Vector2 EffectPos = Effecttr->GetPos();

			mTime += Time::DeltaTime();
			//if (otherPos.x - EffectPos.x >= 50.0f)
			//{
			//	otherPos.x -= 1000.0f * Time::DeltaTime();
			//}
			//else {
			//	otherPos.x -= 500.0f * Time::DeltaTime();
			// 
			//}
			otherPos.x -= 400.f * Time::DeltaTime();
			tr->SetPos(otherPos);

			if (EffectPos.x > otherPos.x) //&& EffectPos.x - 25.0f > otherPos.x)
			{

				if (BoomBros* mBoomBros = dynamic_cast<BoomBros*>(other->GetOwner()))
				{
					mBoomBros->SetDamage(100);
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
				else if (Bros* mBros = dynamic_cast<Bros*>(other->GetOwner()))
				{
					mBros->SetDamage(100);
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
				else if (Cappy* mCappy = dynamic_cast<Cappy*>(other->GetOwner()))
				{
					mCappy->SetDamage(100);
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
				else
				{
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
			}
			//if (other->GetOwner()->GetState() == eState::Death)
			//{
			//	//mKirby->SetState(Kirby::eKirbyState::RightAbsorb);
			//}
		}
	}
	void AbsorbEffect::OnCollisionExit(Collider* other)
	{
		
	}

}