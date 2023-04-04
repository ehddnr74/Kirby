#include "MyCappy.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyRigidBody.h"

namespace My
{
	Cappy::Cappy()
		:cappytime(0.0f)
		, cappydir(0)
		, CappyHP(0)
	{
	}
	Cappy::~Cappy()
	{
	}
	void Cappy::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(580,255));
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* mCappy = Resources::Load<Image>(L"Cappy", L"..\\Resources\\Cappy.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"Move", mCappy, Vector2::Zero, 16, 16, 2, Vector2::Zero, 0.3);

		mAnimator->Play(L"Move", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-20.0f, -65.0f));
		collider->SetSize(Vector2(43.0f, 47.0f));;

		mState = CappyState::LeftMove;

		GameObject::Initialize();
	}
	void Cappy::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case Cappy::CappyState::LeftMove:
			leftmove();
			break;
		case Cappy::CappyState::RightMove:
			rightmove();
			break;
		}
	}

	void Cappy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Cappy::Release()
	{
		GameObject::Release();
	}

	void Cappy::leftmove()
	{
		Transform* cappytr = GetComponent<Transform>();
		Vector2 CappyPos = cappytr->GetPos();

		cappytime += Time::DeltaTime();

		if (cappytime <= 1.0f)
		{
			CappyPos.x -= 10.0f * Time::DeltaTime();
		}

		cappytr->SetPos(CappyPos);

		if (cappytime >= 1.5f)
		{
			cappytime = 0.0f;
			mState = CappyState::RightMove;
		}
	}


	void Cappy::rightmove()
	{
		Transform* cappytr = GetComponent<Transform>();
		Vector2 CappyPos = cappytr->GetPos();

		cappytime += Time::DeltaTime();

		if (cappytime <= 1.0f)
		{
			CappyPos.x += 10.0f * Time::DeltaTime();
		}
		cappytr->SetPos(CappyPos);

		if (cappytime >= 1.5f)
		{
			cappytime = 0.0f;
			mState = CappyState::LeftMove;
		}

		
	}
	void Cappy::OnCollisionEnter(Collider* other)
	{
	}
	void Cappy::OnCollisionStay(Collider* other)
	{
	}
	void Cappy::OnCollisionExit(Collider* other)
	{
	}
}