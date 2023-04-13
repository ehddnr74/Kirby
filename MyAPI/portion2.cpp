#include "Portion2.h"
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
	Portion2::Portion2()
	{

	}
	Portion2 ::~Portion2()
	{

	}
	void Portion2::Initialize()
	{
		//Image* StarMap = Resources::Load<Image>(L"StarMap", L"..\\Resources\\StarMap.bmp");

		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		//mAnimator->CreateAnimation(L"Star", StarMap, Vector2::Zero, 11, 1, 11, Vector2::Zero, 0.05);

		//mAnimator->Play(L"Star", true);

		/*Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-17.0f, -55.0f));
		collider->SetSize(Vector2(32.0f, 35.0f));*/

		GameObject::Initialize();
	}
	void Portion2::Update()
	{
		GameObject::Update();
	}
	void Portion2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Portion2::Release()
	{
		GameObject::Release();
	}
	void Portion2::OnCollisionEnter(Collider* other)
	{
		if (mkirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			if (mkirby->GetHP() <= 100)
			{
				mkirby->SetHill(20);
			}
			object::Destroy(this);
		}
	}
	void Portion2::OnCollisionStay(Collider* other)
	{
	}
	void Portion2::OnCollisionExit(Collider* other)
	{
	}
}