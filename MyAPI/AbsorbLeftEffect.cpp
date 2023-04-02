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
#include "MyKirby.h"
#include "MyWaddle.h"

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
		mAnimator->CreateAnimation(L"LeftEffect", AbsorbLeftEffect, Vector2::Zero, 2, 1, 2, Vector2::Zero, 0.3);

		mAnimator->Play(L"LeftEffect", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -47.0f));
		collider->SetSize(Vector2(100.0f, 43.0f));


		GameObject::Initialize();
	}
	void AbsorbLeftEffect::Update()
	{
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
	void AbsorbLeftEffect::OnCollisionEnter(Collider* other)
	{
		Waddle* mWaddle = dynamic_cast<Waddle*>(other->GetOwner());

		if (other->GetOwner() == mWaddle)
		{
			Collision = 2;
		}
		else
		{
			Collision = 1;
		}
	}
	void AbsorbLeftEffect::OnCollisionStay(Collider* other)
	{
		Transform* tr = other->GetOwner()->GetComponent<Transform>();

		Vector2 otherPos = tr->GetPos();

		Transform* Effecttr = this->GetComponent<Transform>();

		Vector2 EffectPos = Effecttr->GetPos();

		mTime += Time::DeltaTime();

		otherPos.x += 250.0f * Time::DeltaTime();

		tr->SetPos(otherPos);

		if (EffectPos.x + 20.0f < otherPos.x )
		{
			object::Destroy(other->GetOwner());
			object::Destroy(this);
		}

	}
	void AbsorbLeftEffect::OnCollisionExit(Collider* other)
	{
	}
}