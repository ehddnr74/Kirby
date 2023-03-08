#include "MyWaddle.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "Mytime.h"

namespace My
{
	Waddle::Waddle()
		:waddletime(0.f)
		, waddledir(1)
	{
	}
	Waddle::~Waddle()
	{
	}
	void Waddle::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		tr->SetPos(Vector2(320, 300));
		tr->SetScale(Vector2(2.2f, 2.2f));



		Image* mWaddle = Resources::Load<Image>(L"Waddle", L"..\\Resources\\Waddle.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftMove", mWaddle, Vector2::Zero, 16, 16, 4, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBoomb", mWaddle, Vector2(0.0f, 80.0f), 16, 16, 2, Vector2::Zero, 0.5);



		mAnimator->CreateAnimation(L"RightMove", mWaddle, Vector2(0.0f, 40.0f), 16, 16, 4, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBoomb", mWaddle, Vector2(0.0f, 80.0f), 16, 16, 2, Vector2::Zero, 0.1);
		mAnimator->Play(L"LeftMove", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(20.0f, 22.0f));
		collider->SetSize(Vector2(50.0f, 45.0f));

		mState = WaddleState::LeftMove;

		GameObject::Initialize();
	}
	void Waddle::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case My::Waddle::WaddleState::LeftMove:
			leftmove();
			break;
		case My::Waddle::WaddleState::RightMove:
			rightmove();
		case My::Waddle::WaddleState::LeftBoomb:
			leftboomb();
			break;
		case My::Waddle::WaddleState::RightBoomb:
			rightboomb();
			break;
		}
	}

	void Waddle::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Waddle::Release()
	{
		GameObject::Release();
	}

	void Waddle::leftmove()
	{
		Transform* tr = GetComponent<Transform>();
		waddletime += Time::DeltaTime();

		Vector2 WdPos = tr->GetPos();

		WdPos.x -= 20.0f * Time::DeltaTime();

		if (waddletime >= 2.0f)
		{
			waddletime = 0.0f;
			mState = WaddleState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}
		tr->SetPos(WdPos);
	}


	void Waddle::rightmove()
	{
		Transform* tr = GetComponent<Transform>();

		waddletime += Time::DeltaTime();

		Vector2 WdPos = tr->GetPos();

		WdPos.x += 20.f * Time::DeltaTime();

		if (waddletime >= 2.0f)
		{
			waddletime = 0.0f;
			mState = WaddleState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}


	

		tr->SetPos(WdPos);
	}

	void Waddle::leftboomb()
	{

	}

	void Waddle::rightboomb()
	{
		mAnimator->Play(L"RightBoomb", true);
	}
}


