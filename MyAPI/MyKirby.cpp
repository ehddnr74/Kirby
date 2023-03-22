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
#include "Air.h"
#include "AirLeft.h"
#include "Stage1_1.h"

namespace My
{
	Kirby::Kirby()
		: kirbytime(0.0f)
		, KeyCheck(false)
		, Kirbydir(0)
		, AbsorbCheck(false)
		, jumptime(0.0f)
		, IsJump(false)
		, DoubleJump(false)
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
		mAnimator->CreateAnimation(L"LeftJumpFirst", mKirby, Vector2(0.0f, 360.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftJump", mKirby, Vector2(0.0f, 360.0f), 16, 16, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftJumpRelease", mKirby, Vector2(160.0f, 320.0f), 16, 16, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftDoubleJump", mKirby, Vector2(0.0f, 320.0f), 16, 16, 7, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftAir", mKirby, Vector2(0.0f, 440.0f), 16, 16, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftDashRelease", mKirby, Vector2(320.0f, 280.0f), 16, 16, 1, Vector2::Zero, 0.05);


		mAnimator->CreateAnimation(L"RightIdle", mKirby, Vector2::Zero, 16, 16, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightWalk", mKirby, Vector2(0.0f, 40.0f), 16, 16, 10, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightAbsorbing", mKirby, Vector2(400.0f, 120.0f), 16, 16, 3, Vector2::Zero, 0.07);
		mAnimator->CreateAnimation(L"RightDash", mKirby, Vector2(320.0f, 160.0f), 16, 16, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightCrouch", mKirby, Vector2(0.0f, 200.0f), 16, 16, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightSliding", mKirby, Vector2(520.0f, 200.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightJumpFirst", mKirby, Vector2(0.0f, 240.0f), 16, 16, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightJump", mKirby, Vector2(0.0f, 240.0f), 16, 16, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightJumpAbsorb", mKirby, Vector2(0.0f, 280.0f), 16, 16, 4, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightJumpRelease", mKirby, Vector2(160.0f, 280.0f), 16, 16, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightDoubleJump", mKirby, Vector2(0.0f, 280.0f), 16, 16, 7, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightAir", mKirby, Vector2(0.0f, 400.0f), 16, 16, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightDashRelease", mKirby, Vector2(280.0f, 280.0f), 16, 16, 1, Vector2::Zero, 0.3);

		//mAnimator->CreateAnimation(L"RightAirRelease", mKirby, Vector2(160.0f, 400.0f), 16, 16, 8, Vector2::Zero, 0.05);
		


		mAnimator->Play(L"RightIdle", true);

		//mAnimator->GetCompleteEvent(L"RightJumpAbsorb") = std::bind(&Kirby::JumpCompleteEvent,this);


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-5.0f, -24.0f));
		collider->SetSize(Vector2(50.0f, 46.0f));

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);
		//mRigidBody->SetGravity(Vector2(0.0f, 70.0f));

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
		case My::Kirby::eKirbyState::RightColAbsorb:
			rightcolabsorb();
			break;
		case My::Kirby::eKirbyState::LeftDash:
			leftdash();
			break;
		case My::Kirby::eKirbyState::RightDash:
			rightdash();
			break;
		case My::Kirby::eKirbyState::LeftDashRelease:
			leftdashrelease();
			break;
		case My::Kirby::eKirbyState::RightDashRelease:
			rightdashrelease();
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
		case My::Kirby::eKirbyState::LeftDoubleJump:
			leftdoublejump();
			break;
		case My::Kirby::eKirbyState::RightDoubleJump:
			rightdoublejump();
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
		//int a = 0;
	}


	void Kirby::leftmove()
	{
		KeyCheck = true;
		kirbytime += Time::DeltaTime();

		if (Input::GetKeyDown(eKeyCode::A))
		{
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftJump;

			mAnimator->Play(L"LeftJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

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
			AbsorbLeftEffect * LeftAbEffect = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 35, pos.y + 52), Vector2(1.0f, 1.0f), eLayerType::Effect);
			mState = eKirbyState::LeftAbsorb;
			mAnimator->Play(L"LeftAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			//mRigidBody->AddForce(Vector2(-200.0f, 0.0f));
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

			if (Input::GetKeyDown(eKeyCode::A))
			{
				mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
				mState = eKirbyState::RightJump;

				mAnimator->Play(L"RightJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x += 100.0f;
				velocity.y -= 400.0f;


				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);
			}

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
			Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 85, pos.y + 50), Vector2(1.0f, 1.0f), eLayerType::Effect);
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

		if (Input::GetKeyDown(eKeyCode::A))
		{
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftJump;

			mAnimator->Play(L"LeftJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

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

		if (Input::GetKeyDown(eKeyCode::A))
		{
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightJump;
		
			mAnimator->Play(L"RightJump", false);



			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;
			

			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

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
			Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 85, pos.y + 50), Vector2(1.0f, 1.0f), eLayerType::Effect);

			mState = eKirbyState::RightAbsorb;
			mAnimator->Play(L"RightAbsorbing", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::RightCrouch;
			mAnimator->Play(L"RightCrouch", true);
		}

		if (kirbytime <= 0.15f && KeyCheck && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mState = eKirbyState::RightDash;
			mAnimator->Play(L"RightDash", true);
		}
	}
		//tr->SetPos(pos);

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

		

		if (/*Absorb->GetDt() == false && */Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(Absorb);
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}
		

		//if (Absorb->GetCollision() == 1)
		//{
		//	mState = eKirbyState::RightColAbsorb;
		//}




		//if (Absorb->GetDt() == true)
		//{
		//	mState = eKirbyState::RightCrouch;
		//	mAnimator->Play(L"RightCrouch", true);
		//}

		//if (Absorb->GetCollision() == 0)
		//{
		//	mState = eKirbyState::RightIdle;
		//	mAnimator->Play(L"RightIdle", true);
		//}



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
	void Kirby::rightcolabsorb()
	{
		if (Absorb->GetState() == eState::Death)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}
		//if (Absorb->GetCollision() == 2)
		//{
		//	mState = eKirbyState::RightIdle;
		//	mAnimator->Play(L"RightIdle", true);
		//}
	}
	void Kirby::leftdash()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			kirbytime += Time::DeltaTime();

			if (0.0f <= kirbytime && kirbytime <= 0.3f)
			{
				mState = eKirbyState::LeftDashRelease;
				mAnimator->Play(L"LeftDashRelease", false);
				kirbytime = 0.0f;
			}
		}
		//if (Input::GetKeyUp(eKeyCode::Left))
		//{
		//	mState = eKirbyState::LeftIdle;
		//	mAnimator->Play(L"LeftIdle", true);
		//}


			if (Input::GetKeyDown(eKeyCode::A))
			{
				mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
				mState = eKirbyState::LeftJump;

				mAnimator->Play(L"LeftJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x -= 100.0f;
				velocity.y -= 400.0f;


				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);
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
		//if (Input::GetKeyUp(eKeyCode::Right))
		//{
		//	mState = eKirbyState::RightIdle;
		//	mAnimator->Play(L"RightIdle",true);
		//	KeyCheck = false;
		//	kirbytime = 0.0f;
		//}

		if (Input::GetKeyDown(eKeyCode::Left))
		{
			kirbytime += Time::DeltaTime();

			if (0.0f <= kirbytime && kirbytime <= 0.3f)
			{
				mState = eKirbyState::RightDashRelease;
				mAnimator->Play(L"RightDashRelease", false);
				kirbytime = 0.0f;
			}
		}

		//if (Input::GetKeyUp(eKeyCode::Right))
		//{
		//	mState = eKirbyState::RightIdle;
		//	mAnimator->Play(L"RightIdle", true);
		//}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightJump;

			mAnimator->Play(L"RightJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 150.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
		
	}

	void Kirby::leftdashrelease()
	{

		kirbytime += Time::DeltaTime();

		if (kirbytime >= 0.2f && Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
	}

	void Kirby::rightdashrelease()
	{
		kirbytime += Time::DeltaTime();

		if (kirbytime>=0.2f &&Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle",true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}


	}

	void Kirby::leftcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		if (DoubleJump)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
			DoubleJump = false;
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

		if (DoubleJump)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			DoubleJump = false;
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
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		jumptime += Time::DeltaTime();

		IsJump = true;

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}


		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		tr->SetPos(pos);


		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);

			//jumptime = 0.0f;
			IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

	}

	void Kirby::rightjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		jumptime += Time::DeltaTime();

		IsJump = true;

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 50.0f * Time::DeltaTime();
		}


		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{	
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		tr->SetPos(pos);


		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);

			//jumptime = 0.0f;
			IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

	}

	void Kirby::leftdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		IsJump = false;
		DoubleJump = true;

		if (DoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			mAnimator->Play(L"LeftJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;



			mRigidBody->SetVelocity(velocity);
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"LeftAir", false);
			object::Instantiate<AirLeft>(Vector2(pos.x - 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			//mState = eKirbyState::LeftIdle;
			//mAnimator->Play(L"LeftIdle", true);

			mAnimator->Play(L"LeftCrouch", true);
			mState = eKirbyState::LeftCrouch;

			jumptime = 0.0f;
			DoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}

	void Kirby::rightdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		IsJump = false;
		DoubleJump = true;

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"RightAir", false);
			object::Instantiate<Air>(Vector2(pos.x + 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		}


		if (DoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			mAnimator->Play(L"RightJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 50.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			//mState = eKirbyState::RightIdle;
			
			mAnimator->Play(L"RightCrouch", true);
			mState = eKirbyState::RightCrouch;
			//mAnimator->Play(L"RightIdle", true);

			jumptime = 0.0f;
			DoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}
}
