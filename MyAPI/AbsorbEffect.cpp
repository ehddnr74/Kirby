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
		, Collision(0)
		, Dt(false)
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

		//SetCollision(false);

		mAnimator->Play(L"RightEffect", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-30.0f, -90.0f));
		collider->SetSize(Vector2(60.0f, 70.0f));



		GameObject::Initialize();
	}
	void AbsorbEffect::Update()
	{
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
		//Dt = true;
		//mKirby->SetState(Kirby::eKirbyState::RightColAbsorb);
		//mKirby = object::Instantiate<Kirby>(Vector2(krpos.x, krpos.y), Vector2(2.0f, 2.0f), (eLayerType::Player));
	}

	void AbsorbEffect::OnCollisionStay(Collider* other)
	{
			Transform* tr = other->GetOwner()->GetComponent<Transform>();

			Vector2 otherPos = tr->GetPos();

			Transform* Effecttr = GetComponent<Transform>();

			Vector2 EffectPos = Effecttr->GetPos();

			mTime += Time::DeltaTime();

			otherPos.x -= 80.0f * Time::DeltaTime();

			tr->SetPos(otherPos);

			if (EffectPos.x - 20.0f > otherPos.x && EffectPos.x - 25.0f > otherPos.x)
			{
				object::Destroy(other->GetOwner());
				object::Destroy(this);
				//if (other->GetOwner()->GetState() == eState::Death)
				//{
				//	Dt = false;
				//}
			}
	}
	void AbsorbEffect::OnCollisionExit(Collider* other)
	{
		int a = 0;
	}

}