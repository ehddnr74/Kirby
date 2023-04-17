#include "LeftBoomb.h"
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
	LeftBoomb::LeftBoomb()
		: Destroy(false)
	{

	}
	LeftBoomb::~LeftBoomb()
	{

	}
	void LeftBoomb::Initialize()
	{
		Image* LeftBoom = Resources::Load<Image>(L"LeftBoomb", L"..\\Resources\\LeftBoom.bmp");

		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"LeftBoomb", LeftBoom, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);


		mAnimator->Play(L"LeftBoomb", false);

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetGravity(Vector2::Zero);
		mRigidBody->SetMass(1.0f);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-12.0f, -51.0f));
		collider->SetSize(Vector2(35.0f, 34.0f));



		GameObject::Initialize();
	}
	void LeftBoomb::Update()
	{
		//if (mBoomBros == nullptr)
		//{
		//	if (GetGround() != nullptr)
		//	{
		//		mGround = GetGround();
		//		mGround->SetBoomb(nullptr);
		//	}
		//}

		//if (GetGround() != nullptr)
		//{
		//	if (GetDestroy() == true)
		//	{
		//		class R2Ground* mGround = GetGround();
		//		mGround->SetLeftBoomb(nullptr);
		//	}
		//}

		//if (GetDestroy() == true)
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
		//	object::Destroy(this);
		//	Destroy = true;

		//	if (GetGround() != nullptr)
		//	{
		//		GetGround()->SetLeftBoomb(nullptr);
		//		SetGround(nullptr);
		//		Destroy = true;
		//	}
		//}



		GameObject::Update();
	}
	void LeftBoomb::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LeftBoomb::Release()
	{
		GameObject::Release();
	}
	void LeftBoomb::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()));
		{
			GetGround()->SetLeftBoomb(nullptr);
			SetDestroy(true);
		}
	}
	void LeftBoomb::OnCollisionStay(Collider* other)
	{
	}
	void LeftBoomb::OnCollisionExit(Collider* other)
	{
	}
};