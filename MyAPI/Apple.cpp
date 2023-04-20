#include "Apple.h"
#include "myTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "MyCollider.h"
#include "MyRigidBody.h"
#include "TreeGround.h"
#include "Explosion.h"
#include "AbsorbEffect.h"
#include "AbsorbLeftEffect.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"


namespace My
{
	Apple::Apple()
		:num(0)
		, Check(false)
	{

	}
	Apple ::~Apple()
	{

	}
	void Apple::Initialize()
	{
		Image* apple = Resources::Load<Image>(L"Apple", L"..\\Resources\\Apple.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Apple", apple, Vector2::Zero, 10, 10, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftRotation", apple, Vector2(40.f, 40.0f), 10, 10, 5, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightRotation", apple, Vector2(40.f, 0.f), 10, 10, 5, Vector2::Zero, 0.1);

		mState = AppleState::Gravity;
		mAnimator->Play(L"Apple", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-20.0f, -60.0f));
		collider->SetSize(Vector2(46.0f, 40.0f));

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetGravity(Vector2(0.f, 400.f));
		mRigidBody->SetMass(1.0f);

		GameObject::Initialize();
	}
	void Apple::Update()
	{
		GameObject::Update();

		//Transform* tr = GetComponent<Transform>();
		//Vector2 Pos = tr->GetPos();

		//

		//tr->SetPos(Pos);
		if (Check == false && num == 1)
		{
			Check = true;
			mState = AppleState::RightRotation;
			mAnimator->Play(L"RightRotation", true);
		}
		if (Check == false && num == 2)
		{
			Check = true;
			mState = AppleState::LeftRotation;
			mAnimator->Play(L"LeftRotation", true);
		}

		switch (mState)
		{
		case AppleState::Gravity:
			gravity();
			break;
		case AppleState::RightRotation:
			rightrotation();
			break;
		case AppleState::LeftRotation:
			leftrotation();
			break;
		}
	}
	void Apple::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Apple::Release()
	{
		GameObject::Release();
	}
	void Apple::OnCollisionEnter(Collider* other)
	{
		if (mkrb = dynamic_cast<kirbyRightBoom*>(other->GetOwner()))
		{
			mGround->SetKirBoomb(nullptr);
		}
		if (mklb = dynamic_cast<kirbyLeftBoom*>(other->GetOwner()))
		{
			mGround->SetKirLeftBoomb(nullptr);
		}


		if (num == 0)
		{
			if (mAbsorbEffect = dynamic_cast<AbsorbEffect*>(other->GetOwner()))
			{
				mGround->SetApple(nullptr);
			}
			if (mAbsorbLeftEffect = dynamic_cast<AbsorbLeftEffect*>(other->GetOwner()))
			{
				mGround->SetApple(nullptr);
			}
			if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y + 100), Vector2(1.f, 1.f), eLayerType::Effect);
				mGround->SetApple(nullptr);
				object::Destroy(this);
			}
		}
		if (num == 1)
		{
			if (mAbsorbEffect = dynamic_cast<AbsorbEffect*>(other->GetOwner()))
			{
				mGround->SetApple(nullptr);
			}
			if (mAbsorbLeftEffect = dynamic_cast<AbsorbLeftEffect*>(other->GetOwner()))
			{
				mGround->SetApple(nullptr);
			}
			if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y + 70), Vector2(1.f, 1.f), eLayerType::Effect);
				mGround->SetApple(nullptr);
				object::Destroy(this);
			}
		}
		if (num == 2)
		{
			if (mAbsorbEffect = dynamic_cast<AbsorbEffect*>(other->GetOwner()))
			{
				mGround->SetApple2(nullptr);
			}
			if (mAbsorbLeftEffect = dynamic_cast<AbsorbLeftEffect*>(other->GetOwner()))
			{
				mGround->SetApple2(nullptr);
			}
			if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y + 70), Vector2(1.f, 1.f), eLayerType::Effect);
				mGround->SetApple2(nullptr);
				object::Destroy(this);
			}
		}
		if (num == 4)
		{
			if (mAbsorbEffect = dynamic_cast<AbsorbEffect*>(other->GetOwner()))
			{
				mGround->SetApple2(nullptr);
			}
			if (mAbsorbLeftEffect = dynamic_cast<AbsorbLeftEffect*>(other->GetOwner()))
			{
				mGround->SetApple2(nullptr);
			}
			if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y + 70), Vector2(1.f, 1.f), eLayerType::Effect);
				mGround->SetApple2(nullptr);
				object::Destroy(this);
			}
		}
	}
	void Apple::OnCollisionStay(Collider* other)
	{
	}
	void Apple::OnCollisionExit(Collider* other)
	{
	}
	void Apple::gravity()
	{
		mRigidBody->SetGravity(Vector2(0.f, 400.f));
	}
	void Apple::rightrotation()
	{
		mRigidBody->SetGravity(Vector2::Zero);
		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* ar = GetComponent<Transform>();
		Vector2 pos = ar->GetPos();

		pos.x += 80.f * Time::DeltaTime();

		ar->SetPos(pos);
	}
	void Apple::leftrotation()
	{
		mRigidBody->SetGravity(Vector2::Zero);
		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* ar2 = GetComponent<Transform>();
		Vector2 pos2 = ar2->GetPos();

		pos2.x -= 120.f * Time::DeltaTime();

		ar2->SetPos(pos2);
	}
}
