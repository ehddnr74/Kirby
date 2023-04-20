#include "AbsorbLeftEffect.h"
#include "myTime.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "MyWaddle.h"
#include "Bros.h"
#include "MyCappy.h"
#include "BoomBros.h"
#include "TreeBoss.h"
namespace My
{
	AbsorbLeftEffect::AbsorbLeftEffect()
		: mTime(0.0f)
	{
	}
	AbsorbLeftEffect::~AbsorbLeftEffect()
	{
	}
	void AbsorbLeftEffect::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(pos);
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* AbsorbLeftEffect = Resources::Load<Image>(L"AbsorbLeftEffect", L"..\\Resources\\AbsorbLeftEffect.bmp");
		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"LeftEffect", AbsorbLeftEffect, Vector2::Zero, 2, 1, 2, Vector2::Zero, 0.3);
		mAnimator->Play(L"LeftEffect", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -60.0f));
		collider->SetSize(Vector2(100.0f, 70.0f));


		GameObject::Initialize();
	}
	void AbsorbLeftEffect::Update()
	{
		GameObject::Update();

		if (mKirby != nullptr)
		{
			if (mKirby->GetLeftJumpAbsorbing())
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 BeamPos = tr->GetPos();
				Transform* kr = mKirby->GetComponent<Transform>();
				Vector2 KirbyPos = kr->GetPos();

				BeamPos.x = KirbyPos.x - 70;
				BeamPos.y = KirbyPos.y - 10;

				tr->SetPos(BeamPos);
			}
		}
	}
	void AbsorbLeftEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void AbsorbLeftEffect::Release()
	{
		GameObject::Release();
	}
	void AbsorbLeftEffect::OnCollisionEnter(Collider* other)
	{
		Waddle* mWaddle = dynamic_cast<Waddle*>(other->GetOwner());
		Bros* mBros = dynamic_cast<Bros*>(other->GetOwner());

		BoomBros* mBoomBros = dynamic_cast<BoomBros*>(other->GetOwner()); 
		TreeBoss* mTree = dynamic_cast<TreeBoss*>(other->GetOwner());

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
	}
	void AbsorbLeftEffect::OnCollisionStay(Collider* other)
	{
		TreeBoss* mTree = dynamic_cast<TreeBoss*>(other->GetOwner());

		if (other->GetOwner() != mTree)
		{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();

			Vector2 otherPos = tr->GetPos();

			Transform* Effecttr = this->GetComponent<Transform>();

			Vector2 EffectPos = Effecttr->GetPos();

			mTime += Time::DeltaTime();

			otherPos.x += 250.0f * Time::DeltaTime();

			tr->SetPos(otherPos);

			if (EffectPos.x + 20.0f < otherPos.x)
			{
				if (BoomBros* mBoomBros = dynamic_cast<BoomBros*>(other->GetOwner()))
				{
					mBoomBros->SetDamage(100);
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
				else if (Cappy* mCappy = dynamic_cast<Cappy*>(other->GetOwner()))
				{
					mCappy->SetDamage(100);
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
				else if (Bros* mBros = dynamic_cast<Bros*>(other->GetOwner()))
				{
					mBros->SetDamage(100);
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}
				else
				{
					object::Destroy(other->GetOwner());
					object::Destroy(this);
				}

			}
		}
	}
	void AbsorbLeftEffect::OnCollisionExit(Collider* other)
	{
	}
}