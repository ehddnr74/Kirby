#include "RightBoomb.h"
#include "MyImage.h"
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
#include "MyRigidBody.h"
#include "Explosion.h"
#include "R2Ground.h"

namespace My
{
	RightBoomb::RightBoomb()
		:Destroy(false)
	{

	}
	RightBoomb::~RightBoomb()
	{

	}
	void RightBoomb::Initialize()
	{
		Image* RightBoom = Resources::Load<Image>(L"RightBoomb", L"..\\Resources\\RightBoom.bmp");

		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"RightBoomb", RightBoom, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);


		mAnimator->Play(L"RightBoomb", false);

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetGravity(Vector2::Zero);
		mRigidBody->SetMass(1.0f);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-22.0f, -51.0f));
		collider->SetSize(Vector2(35.0f, 34.0f));



		GameObject::Initialize();
	}
	void RightBoomb::Update()
	{
		if (mBoomBros == nullptr)
		{
			if (GetGround() != nullptr)
			{
				mGround = GetGround();
				mGround->SetBoomb(nullptr);
			}
		}

		if (GetGround() != nullptr)
		{
			if (GetDestroy() == true)
			{
			  class R2Ground* mGround = GetGround();
			  mGround->SetBoomb(nullptr);
			}
		}

		//if (GetDestroy() == true)
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y+50), Vector2(1.f, 1.f), eLayerType::Effect);
		//	object::Destroy(this);
		//	SetGround(nullptr);
		//}

		

		GameObject::Update();
	}
	void RightBoomb::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void RightBoomb::Release()
	{
		GameObject::Release();
	}
	void RightBoomb::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()));
		{
			//SetDestroy(true);	
		}
	}
	void RightBoomb::OnCollisionStay(Collider* other)
	{
	}
	void RightBoomb::OnCollisionExit(Collider* other)
	{
	}
};