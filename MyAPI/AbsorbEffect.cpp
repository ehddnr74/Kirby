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
#include "MyWaddle.h"
#include "MyKirby.h"

namespace My
{
	AbsorbEffect::AbsorbEffect()
		: mTime(0.0f)
		, Check(false)
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
		collider->SetCenter(Vector2(-30.0f, -90.0f));
		collider->SetSize(Vector2(60.0f, 70.0f));


		GameObject::Initialize();
	}
	void AbsorbEffect::Update()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(this);
		}

		//	Check = true;
		//}
		//if (Check)
		//{
		//	mTime += Time::DeltaTime();

		//	if (mTime >= 0.5f)
		//	{
		//		object::Destroy(this);
		//		Check = false;
		//	}
		//	if (Check == false)
		//	{
		//		mTime = 0.0f;
		//	}

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
	void AbsorbEffect::OnCollisionEnter(Collider* other)
	{
	}
	void AbsorbEffect::OnCollisionStay(Collider* other)
	{
		
		Transform * tr = other->GetOwner()->GetComponent<Transform>();

		Vector2 otherPos = tr->GetPos();
		
		Transform* Effecttr = GetComponent<Transform>();

		Vector2 EffectPos = Effecttr->GetPos();

		mTime += Time::DeltaTime();
		if(mTime <=0.3f)
			otherPos.x -= 20.0f * Time::DeltaTime();

		if (mTime >= 0.3f)
		{
			otherPos.x -= 150.0f * Time::DeltaTime();
		}
		if (mTime >= 1.0f)
		{
			mTime = 0.0f;
		}

			if (EffectPos.x > otherPos.x)
				object::Destroy(other->GetOwner());
			

		tr->SetPos(otherPos);
		
			
	}
	void AbsorbEffect::OnCollisionExit(Collider* other)
	{
	}
}