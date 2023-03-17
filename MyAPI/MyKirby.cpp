#include "MyKirby.h"
#include "MyTime.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"
#include "AbsorbEffect.h"
#include "AbsorbLeftEffect.h"
#include "MyRigidBody.h"

namespace My
{
	Kirby::Kirby()
		: kirbytime(0.0f)
		, KeyCheck(false)
		, Kirbydir(0)
		, AbsorbCheck(false)
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(30.0f, 310.0f));
		//tr->SetScale(Vector2(2.0f, 2.0f));


		Image* mKirby = Resources::Load<Image>(L"Kirby", L"..\\Resources\\KirbyState.bmp");



		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mKirby, Vector2(240.0f, 0.0f), 16, 16, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftWalk", mKirby, Vector2(0.0f, 80.0f), 16, 16, 10, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftAbsorbing", mKirby, Vector2(80.0f, 120.0f), 16, 16, 3, Vector2::Zero, 0.07);
		mAnimator->CreateAnimation(L"LeftDash", mKirby, Vector2(0.0f, 160.0f), 16, 16, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftCrouch", mKirby, Vector2(240.0f, 200.0f), 16, 16, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftSliding", mKirby, Vector2(480.0f, 200.0f), 16, 16, 1, Vector2::Zero, 0.5);




		mAnimator->CreateAnimation(L"RightIdle", mKirby, Vector2::Zero, 16, 16, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightWalk", mKirby, Vector2(0.0f, 40.0f), 16, 16, 10, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightAbsorbing", mKirby, Vector2(400.0f, 120.0f), 16, 16, 3, Vector2::Zero, 0.07);
		mAnimator->CreateAnimation(L"RightDash", mKirby, Vector2(320.0f, 160.0f), 16, 16, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightCrouch", mKirby, Vector2(0.0f, 200.0f), 16, 16, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightSliding", mKirby, Vector2(520.0f, 200.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightJumpFirst", mKirby, Vector2(0.0f, 240.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightJump", mKirby, Vector2(0.0f, 240.0f), 16, 16, 8, Vector2::Zero, 0.05);

		mAnimator->Play(L"RightIdle", true);

		//mAnimator->GetCompleteEvent(L"RightIdle") = std::bind(&Kirby::idleCompleteEvent,this);


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-5.0f, -24.0f));
		collider->SetSize(Vector2(50.0f, 46.0f));

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);
		//mRigidBody->SetGround(false);

		mState = eKirbyState::RightIdle;

		GameObject::Initialize();
	}
	void Kirby::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case My::Kirby::eKirbyState::LeftMove:
			leftmove();
			break;
		case My::Kirby::eKirbyState::RightMove:
			rightmove();
			break;
		case My::Kirby::eKirbyState::LeftIdle:
			leftidle();
			break;
		case My::Kirby::eKirbyState::RightIdle:
			rightidle();
		case My::Kirby::eKirbyState::Death:
			death();
			break;
		case My::Kirby::eKirbyState::LeftAbsorb:
			leftabsorb();
			break;
		case My::Kirby::eKirbyState::RightAbsorb:
			rightabsorb();
			break;
		case My::Kirby::eKirbyState::LeftDash:
			leftdash();
			break;
		case My::Kirby::eKirbyState::RightDash:
			rightdash();
			break;
		case My::Kirby::eKirbyState::LeftCrouch:
			leftcrouch();
			break;
		case My::Kirby::eKirbyState::RightCrouch:
			rightcrouch();
			break;
		case My::Kirby::eKirbyState::LeftSliding:
			leftsliding();
			break;
		case My::Kirby::eKirbyState::RightSliding:
			rightsliding();
			break;
		case My::Kirby::eKirbyState::LeftJump:
			leftjump();
			break;
		case My::Kirby::eKirbyState::RightJump:
			rightjump();
			break;
		default:
			break;
		}
	}
	void Kirby::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Kirby::Release()
	{
		GameObject::Release();
	}

	void Kirby::OnCollisionEnter(Collider* other)
	{
		
	}

	void Kirby::OnCollisionStay(Collider* other)
	{
		
	}

	void Kirby::OnCollisionExit(Collider* other)
	{

	}


	void Kirby::leftmove()
	{
		KeyCheck = true;
		kirbytime += Time::DeltaTime();

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
			kirbytime = 0.0f;
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 35, pos.y + 52), Vector2(1.0f, 1.0f), eLayerType::Effect);
			mState = eKirbyState::LeftAbsorb;
			mAnimator->Play(L"LeftAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
			if (Input::GetKey(eKeyCode::Right))
			{
				mState = eKirbyState::RightMove;
				mAnimator->Play(L"RightWalk", true);
			}
			if (Input::GetKey(eKeyCode::Down))
			{
				mState = eKirbyState::LeftCrouch;
				mAnimator->Play(L"LeftCrouch", true);
			}

			//if (Input::GetKey(eKeyCode::Left))
			//{
			//	mState = eKirbyState::LeftDash;
			//	mAnimator->Play(L"LeftDash", true);
			//}
		}

		tr->SetPos(pos);
	}
	void Kirby::rightmove()
	{
		
		KeyCheck = true;
			kirbytime += Time::DeltaTime();

		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			kirbytime = 0.0f;
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


		//if (KeyCheck)
		//{
		//	if(GetKeyState(VK_RIGHT))
		//	{
		//		mState = eKirbyState::RightDash;
		//		mAnimator->Play(L"RightDash", true);
		//	}
		if (Input::GetKeyDown(eKeyCode::Z))
		{
			object::Instantiate<AbsorbEffect>(Vector2(pos.x + 85, pos.y + 50), Vector2(1.0f, 1.0f), eLayerType::Effect);
			mState = eKirbyState::RightAbsorb;
			mAnimator->Play(L"RightAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
		//mRigidBody->AddForce(Vector2(200.0f, 0.0f));
				pos.x += 100.0f * Time::DeltaTime();
				if (Input::GetKey(eKeyCode::Left))
				{
					mState = eKirbyState::LeftMove;
					mAnimator->Play(L"LeftWalk", true);
				}
				if (Input::GetKey(eKeyCode::Down))
				{
					mState = eKirbyState::RightCrouch;
					mAnimator->Play(L"RightCrouch", true);
				}
			}
		tr->SetPos(pos);

	}

	void Kirby::leftidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		kirbytime += Time::DeltaTime();
		if (Input::GetKey(eKeyCode::Left))
		{	
			mState = eKirbyState::LeftMove;
			mAnimator->Play(L"LeftWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightMove;
			mAnimator->Play(L"RightWalk", true);
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 35, pos.y + 52), Vector2(1.0f, 1.0f), eLayerType::Effect);
			mState = eKirbyState::LeftAbsorb;
			mAnimator->Play(L"LeftAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::LeftCrouch;
			mAnimator->Play(L"LeftCrouch", true);
		}

		if (kirbytime <= 0.15f && KeyCheck && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mState = eKirbyState::LeftDash;
			mAnimator->Play(L"LeftDash", true);
		}
	}
	void Kirby::rightidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		//if (Input::GetKeyDown(eKeyCode::A))
		//{
		//	mState = eKirbyState::RightJump;
		//}
		kirbytime += Time::DeltaTime();
		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftMove;
			mAnimator->Play(L"LeftWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightMove;
			mAnimator->Play(L"RightWalk", true);
		}
		if (Input::GetKeyDown(eKeyCode::Z))
		{
		  object::Instantiate<AbsorbEffect>(Vector2(pos.x + 85, pos.y + 50), Vector2(1.0f, 1.0f), eLayerType::Effect);
			
			mState = eKirbyState::RightAbsorb;
			mAnimator->Play(L"RightAbsorbing", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::RightCrouch;
			mAnimator->Play(L"RightCrouch", true);
		}

		if (kirbytime<=0.15f && KeyCheck && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mState = eKirbyState::RightDash;
			mAnimator->Play(L"RightDash", true);
		}
		//tr->SetPos(pos);

	}
	void Kirby::death()
	{

	}
	void Kirby::leftabsorb()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
	}
	void Kirby::rightabsorb()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			 
			//AbsorbCheck = true;
		}

		////if (AbsorbCheck)
		////{
			//KeyCheck = false;
			//kirbytime += Time::DeltaTime();

			//if (kirbytime >= 1.0f)
			//{
			//	AbsorbCheck = false;
			//	mState = eKirbyState::RightIdle;
			//	mAnimator->Play(L"RightIdle", true);
			//}
			//if (AbsorbCheck == false)
			//{
			//	kirbytime = 0.0f;
			//}
	}
	void Kirby::leftdash()
	{
		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 150.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::rightdash()
	{
		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle",true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 150.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
		
	}

	void Kirby::leftcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mAnimator->Play(L"LeftCrouch", true);

			if (Input::GetKeyDown(eKeyCode::Left))
			{
				mState = eKirbyState::LeftMove;
				mAnimator->Play(L"LeftMove", true);
			}
		}
		
			if (Input::GetKeyDown(eKeyCode::X))
			{
				mState = eKirbyState::LeftSliding;
				mAnimator->Play(L"LeftSliding", true);
			}

	}

	void Kirby::rightcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mAnimator->Play(L"RightCrouch", true);
			{
				if (Input::GetKeyDown(eKeyCode::Right))
				{
					mState = eKirbyState::RightMove;
					mAnimator->Play(L"RightMove", true);
				}
			}
		}
		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = eKirbyState::RightSliding;
			mAnimator->Play(L"RightSliding", true);
		}
	}
	void Kirby::leftsliding()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		
		kirbytime += Time::DeltaTime();

		if (kirbytime < 0.5f)
		{
			mAnimator->Play(L"LeftSliding", true);
			pos.x -= 150.f * Time::DeltaTime();
		}
		if (0.5f < kirbytime < 0.8f)
		{
			mAnimator->Play(L"LeftSliding", true);
			pos.x -= 10.f * Time::DeltaTime();
		}
		if (kirbytime > 0.8f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		
		tr->SetPos(pos);

	}

	void Kirby::rightsliding()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		kirbytime += Time::DeltaTime();

		if (kirbytime < 0.5f)
		{
			//mAnimator->Play(L"RightSliding", true);
			pos.x += 150.f * Time::DeltaTime();
		}
		if (0.5f < kirbytime < 0.8f)
		{
			//mAnimator->Play(L"RightSliding", true);
			pos.x += 10.f * Time::DeltaTime();
		}
		if (kirbytime > 0.8f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		tr->SetPos(pos);

	}

	void Kirby::leftjump()
	{
	}

	void Kirby::rightjump()
	{
		
		//kirbytime += Time::DeltaTime();

		//if (kirbytime < 1.0f)
		//{
		//	
		//}
	}

	//void Kirby::idleCompleteEvent()
	//{
	//		
	//}

}
