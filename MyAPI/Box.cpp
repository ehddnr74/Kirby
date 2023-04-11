#include "Box.h"
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
#include "MyAnimator.h"
#include "MyRigidBody.h"

namespace My
{
	Box::Box()
	{

	}
	Box::~Box()
	{

	}
	void Box::Initialize()
	{

		Image* Box = Resources::Load<Image>(L"Box", L"..\\Resources\\Box.bmp");

		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"Box", Box, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"Box", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-25.0f, -75.0f));
		collider->SetSize(Vector2(50.0f, 70.0f));


		GameObject::Initialize();


	}
	void Box::Update()
	{
		GameObject::Update();
	}
	void Box::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Box::Release()
	{
		GameObject::Release();
	}
	void Box::OnCollisionEnter(Collider* other)
	{

	}
	void Box::OnCollisionStay(Collider* other)
	{

	}
	void Box::OnCollisionExit(Collider* other)
	{

	}
}
