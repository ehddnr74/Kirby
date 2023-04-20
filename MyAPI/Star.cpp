#include "Star.h"
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
	Star::Star()
		:startime(0.f)
	{

	}
	Star::~Star()
	{

	}
	void Star::Initialize()
	{
		Image* Star = Resources::Load<Image>(L"Star", L"..\\Resources\\Star.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"StarShot", Star, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"StarShot", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-25.0f, -50.0f));
		collider->SetSize(Vector2(50.0f, 50.0f));

		GameObject::Initialize();
	}
	void Star::Update()
	{

		if (mkirby->GetLeftStar())
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 Pos = tr->GetPos();

			startime += Time::DeltaTime();

			if (0.0f <= startime && startime <= 1.0f)
			{
				Pos.x -= 300.0f * Time::DeltaTime();
			}
			if (1.0f <= startime)
			{
				object::Destroy(this);
				startime = 0.0f;
				mkirby->SetLeftStar(false);
			}
			tr->SetPos(Pos);
		}

		if (mkirby->GetStar())
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 Pos = tr->GetPos();

			startime += Time::DeltaTime();

			if (0.0f <= startime && startime <= 1.0f)
			{
				Pos.x += 300.0f * Time::DeltaTime();
			}
			if (1.0f <= startime)
			{
				object::Destroy(this);
				startime = 0.0f;
				mkirby->SetStar(false);
			}
			tr->SetPos(Pos);
		}

		
		
		GameObject::Update();
	}
	void Star::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Star::Release()
	{
		GameObject::Release();
	}
	void Star::OnCollisionEnter(Collider* other)
	{
		object::Destroy(this);
	}
	void Star::OnCollisionStay(Collider* other)
	{

	}
	void Star::OnCollisionExit(Collider* other)
	{

	}
}