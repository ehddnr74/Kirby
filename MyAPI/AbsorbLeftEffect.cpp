#include "AbsorbLeftEffect.h"
#include "myTime.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"

namespace My
{
	AbsorbLeftEffect::AbsorbLeftEffect()
		: mTime(0.0f)
	{
	}
	AbsorbLeftEffect::~AbsorbLeftEffect()
	{
	}
	void AbsorbLeftEffect::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(pos);
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* AbsorbLeftEffect = Resources::Load<Image>(L"AbsorbLeftEffect", L"..\\Resources\\AbsorbLeftEffect.bmp");
		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"LeftEffect", AbsorbLeftEffect, Vector2::Zero, 4, 1, 4, Vector2::Zero, 0.1);

		mAnimator->Play(L"LeftEffect", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(15.0f, 17.0f));
		collider->SetSize(Vector2(65.0f, 65.0f));


		GameObject::Initialize();
	}
	void AbsorbLeftEffect::Update()
	{

		if (Input::GetKeyUp(eKeyCode::Z))
			object::Destroy(this);

		GameObject::Update();
	}
	void AbsorbLeftEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void AbsorbLeftEffect::Release()
	{
		GameObject::Release();
	}
}