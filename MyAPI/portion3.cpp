#include "Portion3.h"
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
	Portion3::Portion3()
	{

	}
	Portion3 ::~Portion3()
	{

	}
	void Portion3::Initialize()
	{
		Image* mPizza = Resources::Load<Image>(L"Pizza", L"..\\Resources\\Pizza.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Pizza", mPizza, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.05);

		mAnimator->Play(L"Pizza", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-17.0f, -35.0f));
		collider->SetSize(Vector2(32.0f, 35.0f));

		GameObject::Initialize();
	}
	void Portion3::Update()
	{
		GameObject::Update();
	}
	void Portion3::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Portion3::Release()
	{
		GameObject::Release();
	}
	void Portion3::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetHP() <= 90)
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
	void Portion3::OnCollisionStay(Collider* other)
	{
	}
	void Portion3::OnCollisionExit(Collider* other)
	{
	}
}