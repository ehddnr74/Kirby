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


namespace My
{
	BrontoBurt::BrontoBurt()
	{

	}
	BrontoBurt::~BrontoBurt()
	{

	}
	void BrontoBurt::Initialize()
	{
		Image* mBrontoBurt = Resources::Load<Image>(L"BrontoBurt", L"..\\Resources\\BrontoBurt.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftFly", mBrontoBurt, Vector2::Zero, 16, 16, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"LeftFly", false);

		//Collider* collider = AddComponent<Collider>();
		//collider->SetCenter(Vector2(-20.0f, -65.0f));
		//collider->SetSize(Vector2(43.0f, 47.0f));;

		mState = BrontoBurtState::LeftFly;


		GameObject::Initialize();
	}
	void BrontoBurt::Update()
	{

		GameObject::Update();

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

	}
	void BrontoBurt::OnCollisionStay(Collider* other)
	{

	}
	void BrontoBurt::OnCollisionExit(Collider* other)
	{

	}
}