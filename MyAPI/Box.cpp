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
		:Destroy(false)
		, BoxCol(false)
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

		SetGround(ground);

		GameObject::Initialize();


	}
	void Box::Update()
	{
		if (BoxCol == true)
		{
			Transform* tr = this->GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			pos.y += 700 * Time::DeltaTime();

			tr->SetPos(pos);
		}
		if (GetDestroy() == true)
		{
			SetGround(nullptr);
			object::Destroy(this);
		}
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
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mKirby == nullptr)
				return;

			BoxCol = true;
		}
	}
	void Box::OnCollisionStay(Collider* other)
	{

	}
	void Box::OnCollisionExit(Collider* other)
	{

	}
}
