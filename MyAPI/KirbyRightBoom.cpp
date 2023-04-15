#include "KirbyRightBoom.h"
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

namespace My
{
	kirbyRightBoom::kirbyRightBoom()
	{

	}
	kirbyRightBoom ::~kirbyRightBoom()
	{

	}
	void kirbyRightBoom::Initialize()
	{
		Image* rboom = Resources::Load<Image>(L"RBoom", L"..\\Resources\\KirbyBoom.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"RBoom", rboom, Vector2(0.0f,40.0f), 4, 2, 4, Vector2::Zero, 0.03);

		mAnimator->Play(L"RBoom", true);

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetGravity(Vector2::Zero);
		mRigidBody->SetMass(1.0f);

		//Collider* collider = AddComponent<Collider>();
		//collider->SetCenter(Vector2(-17.0f, -35.0f));
		//collider->SetSize(Vector2(32.0f, 35.0f));

		GameObject::Initialize();
	}
	void kirbyRightBoom::Update()
	{
		GameObject::Update();
	}
	void kirbyRightBoom::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void kirbyRightBoom::Release()
	{
		GameObject::Release();
	}
	void kirbyRightBoom::OnCollisionEnter(Collider* other)
	{
	}
	void kirbyRightBoom::OnCollisionStay(Collider* other)
	{
	}
	void kirbyRightBoom::OnCollisionExit(Collider* other)
	{
	}
}


