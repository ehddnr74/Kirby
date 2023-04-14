#include "WaddleDee.h"
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
	WaddleDee::WaddleDee()
	{
	}
	WaddleDee::~WaddleDee()
	{
	}
	void WaddleDee::Initialize()
	{
		//Image* mWaddleDee = Resources::Load<Image>(L"WaddleDee", L"..\\Resources\\WaddleDee.bmp");
		//mAnimator = AddComponent<Animator>();


		//mAnimator->CreateAnimation(L"LeftMove", mWaddleDee, Vector2::Zero, 16, 16, 2, Vector2::Zero, 0.3);
		//mAnimator->CreateAnimation(L"RightMove", mWaddleDee, Vector2(0.0f, 40.0f), 16, 16, 2, Vector2::Zero, 0.3);
		//mAnimator->CreateAnimation(L"LeftHit", mWaddleDee, Vector2(40.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.3);
		//mAnimator->CreateAnimation(L"RightHit", mWaddleDee, Vector2(0.0f, 120.0f), 16, 16, 1, Vector2::Zero, 0.3);



		mState = WaddleDeeState::LeftMove;
		mAnimator->Play(L"Move", true);

		GameObject::Initialize();
	}
	void WaddleDee::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case WaddleDeeState::LeftMove:
			leftmove();
			break;
		case WaddleDeeState::RightMove:
			rightmove();
			break;
		}
	}
	void WaddleDee::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void WaddleDee::Release()
	{
		GameObject::Release();
	}
	void WaddleDee::OnCollisionEnter(Collider* other)
	{
	}
	void WaddleDee::OnCollisionStay(Collider* other)
	{
	}
	void WaddleDee::OnCollisionExit(Collider* other)
	{
	}
	void WaddleDee::leftmove()
	{
	}
	void WaddleDee::rightmove()
	{
	}
}