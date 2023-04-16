#include "Grizzo.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyRigidBody.h"
#include "Air.h"
#include "AirLeft.h"
#include "Star.h"
#include "MyKirby.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "MyRigidBody.h"
#include "MyObject.h"
#include"LeftBoomb.h"
#include "RightBoomb.h"

namespace My
{
	Grizzo::Grizzo()
		: grizzotime(0.f)
	{
	}
	Grizzo::~Grizzo()
	{
	}
	void Grizzo::Initialize()
	{
		Image* mGrizzo = Resources::Load<Image>(L"Grizzo", L"..\\Resources\\Grizzo.bmp");
		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"RightMove", mGrizzo, Vector2::Zero, 10, 10, 4, Vector2::Zero, 0.5);
		mAnimator->CreateAnimation(L"LeftMove", mGrizzo, Vector2(0.0f, 100.0f), 10, 10, 4, Vector2::Zero, 0.5);

		//mAnimator->CreateAnimation(L"LeftHit", mGrizzo, Vector2(40.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.3);
		//mAnimator->CreateAnimation(L"RightHit", mCappy, Vector2(0.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.3);



		mState = GrizzoState::LeftMove;
		mAnimator->Play(L"LeftMove", true);

		GameObject::Initialize();
	}
	void Grizzo::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case GrizzoState::LeftMove:
			leftmove();
			break;
		case GrizzoState::RightMove:
			rightmove();
			break;
		}
	}
	void Grizzo::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Grizzo::Release()
	{
		GameObject::Release();
	}
	void Grizzo::OnCollisionEnter(Collider* other)
	{
	}
	void Grizzo::OnCollisionStay(Collider* other)
	{
	}
	void Grizzo::OnCollisionExit(Collider* other)
	{
	}
	void Grizzo::leftmove()
	{
		grizzotime += Time::DeltaTime();
		Transform* tr = GetComponent<Transform>();
		Vector2 gpos = tr->GetPos();

		gpos.x -= 40.0f * Time::DeltaTime();

		if (grizzotime >= 2.0f)
		{
			grizzotime = 0.0f;
			mState = GrizzoState::RightMove;
			mAnimator->Play(L"RightMove", true);
		}

		tr->SetPos(gpos);
	}
	void Grizzo::rightmove()
	{
		grizzotime += Time::DeltaTime();
		Transform* tr = GetComponent<Transform>();
		Vector2 gpos = tr->GetPos();

		gpos.x += 40.0f * Time::DeltaTime();

		if (grizzotime >= 2.0f)
		{
			grizzotime = 0.0f;
			mState = GrizzoState::LeftMove;
			mAnimator->Play(L"LeftMove", true);
		}

		tr->SetPos(gpos);
	}
};