#include "AbsorbEffect.h"
#include "myTime.h"
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
	AbsorbEffect::AbsorbEffect()
		: mTime(0.0f)
	{
	}
	AbsorbEffect::~AbsorbEffect()
	{
	}
	void AbsorbEffect::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(pos);
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* AbsorbEffect = Resources::Load<Image>(L"AbsorbEffect", L"..\\Resources\\AbsorbEffect.bmp");
		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"RightEffect",AbsorbEffect, Vector2::Zero, 4, 1, 4, Vector2::Zero, 0.1);

		mAnimator->Play(L"RightEffect", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(20.0f, 15.0f));
		collider->SetSize(Vector2(60.0f, 65.0f));


		GameObject::Initialize();
	}
	void AbsorbEffect::Update()
	{

	if(Input::GetKeyUp(eKeyCode::Z))
			object::Destroy(this);

		GameObject::Update();
	}
	void AbsorbEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void AbsorbEffect::Release()
	{
		GameObject::Release();
	}
}