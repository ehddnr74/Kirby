#include "Portion1.h"
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

namespace My
{
	Portion1::Portion1()
	{

	}
	Portion1 ::~Portion1()
	{

	}
	void Portion1::Initialize()
	{
		Image* mCherry = Resources::Load<Image>(L"Cherry", L"..\\Resources\\Cheery.bmp");

		mAnimator = AddComponent<Animator>();
		
		mAnimator->CreateAnimation(L"Cherry", mCherry, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.05);

		mAnimator->Play(L"Cherry", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-17.0f, -35.0f));
		collider->SetSize(Vector2(32.0f, 35.0f));

		GameObject::Initialize();
	}
	void Portion1::Update()
	{
		GameObject::Update();
	}
	void Portion1::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Portion1::Release()
	{
		GameObject::Release();
	}
	void Portion1::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetHP() < 90)
			{
				mkirby->SetHill(20);
			}
			if (mkirby->GetHP() >= 90)
			{
				mkirby->SetHP(110);
			}
			object::Destroy(this);
		}
	}
	void Portion1::OnCollisionStay(Collider* other)
	{
	}
	void Portion1::OnCollisionExit(Collider* other)
	{
	}
}
