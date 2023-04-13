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

namespace My
{
	RightBoomb::RightBoomb()
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

		//Collider* collider = AddComponent<Collider>();
		//collider->SetCenter(Vector2(0.0f, 0.0f));
		//collider->SetSize(Vector2(50.0f, 50.0f));



		GameObject::Initialize();
	}
	void RightBoomb::Update()
	{
		//if (mkirby->GetJumpingBeam())
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	Vector2 BeamPos = tr->GetPos();
		//	Transform* kr = mkirby->GetComponent<Transform>();
		//	Vector2 KirbyPos = kr->GetPos();

		//	BeamPos.x = KirbyPos.x + 100;
		//	BeamPos.y = KirbyPos.y + 80;

		//	tr->SetPos(BeamPos);
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
	}
	void RightBoomb::OnCollisionStay(Collider* other)
	{
	}
	void RightBoomb::OnCollisionExit(Collider* other)
	{
	}
};