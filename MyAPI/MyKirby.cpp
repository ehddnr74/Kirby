#include "MyKirby.h"
#include "MyTime.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyAnimator.h"


namespace My
{
	Kirby::Kirby()
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		Image* mImage = Resources::Load<Image>(L"Kirby", L"..\\Resources\\KirbyState.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mImage, Vector2(240.0f, 0.0f), 16, 16, 6, Vector2::Kirbytr, 0.3);
		mAnimator->CreateAnimation(L"LeftWalk", mImage, Vector2(0.0f, 80.0f), 16, 16, 10, Vector2::Kirbytr, 0.1);
		mAnimator->CreateAnimation(L"LeftAbsorbing", mImage, Vector2(80.0f, 120.0f), 16, 16, 3, Vector2::Kirbytr, 0.05);
		mAnimator->CreateAnimation(L"LeftDash", mImage, Vector2(0.0f, 160.0f), 16, 16, 8, Vector2::Kirbytr, 0.05);
		mAnimator->CreateAnimation(L"LeftCrouch", mImage, Vector2(240.0f, 200.0f), 16, 16, 6, Vector2::Kirbytr, 0.3);
		mAnimator->CreateAnimation(L"LeftSliding", mImage, Vector2(480.0f, 200.0f), 16, 16, 1, Vector2::Kirbytr, 0.5);
		
		


		mAnimator->CreateAnimation(L"RightIdle", mImage, Vector2::Zero, 16, 16, 6, Vector2::Kirbytr, 0.3);
		mAnimator->CreateAnimation(L"RightWalk", mImage, Vector2(0.0f, 40.0f), 16, 16, 10, Vector2::Kirbytr, 0.1);
		mAnimator->CreateAnimation(L"RightAbsorbing", mImage, Vector2(400.0f, 120.0f), 16, 16, 3, Vector2::Kirbytr, 0.05);
		mAnimator->CreateAnimation(L"RightDash", mImage, Vector2(320.0f, 160.0f), 16, 16, 8, Vector2::Kirbytr, 0.05);
		mAnimator->CreateAnimation(L"RightCrouch", mImage, Vector2(0.0f, 200.0f), 16, 16, 6, Vector2::Kirbytr, 0.3);
		mAnimator->CreateAnimation(L"RightSliding", mImage, Vector2(520.0f, 200.0f), 16, 16, 1, Vector2::Kirbytr, 0.1);

		mAnimator->Play(L"RightIdle", true);

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


	void Kirby::leftmove()
	{
		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
			if (Input::GetKey(eKeyCode::Right))
			{
				mState = eKirbyState::RightMove;
				mAnimator->Play(L"RightWalk", true);
			}
			if (Input::GetKey(eKeyCode::Z))
			{
				mState = eKirbyState::LeftAbsorb;
				mAnimator->Play(L"LeftAbsorbing", true);
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
		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();

			if (Input::GetKey(eKeyCode::Left))
			{
				mState = eKirbyState::LeftMove;
				mAnimator->Play(L"LeftWalk", true);
			}

			if (Input::GetKey(eKeyCode::Z))
			{
				mState = eKirbyState::RightAbsorb;
				mAnimator->Play(L"RightAbsorbing", true);
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
			mState = eKirbyState::LeftAbsorb;
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::LeftCrouch;
			mAnimator->Play(L"LeftCrouch", true);
		}
	}
	void Kirby::rightidle()
	{
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
			mState = eKirbyState::RightAbsorb;
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::RightCrouch;
			mAnimator->Play(L"RightCrouch", true);
		}

	}
	void Kirby::death()
	{

	}
	void Kirby::sliding()
	{

	}
	void Kirby::leftabsorb()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		if (Input::GetKey(eKeyCode::Z))
		{
			mAnimator->Play(L"LeftAbsorbing", true);
		}
	}
	void Kirby::rightabsorb()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (Input::GetKey(eKeyCode::Z))
		{
			mAnimator->Play(L"RightAbsorbing", true);
		}
	}
	void Kirby::leftdash()
	{
		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 200.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::rightdash()
	{
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
	}
	void Kirby::leftsliding()
	{
		if (Input::GetKeyUp(eKeyCode::X))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		//if (Input::GetKeyDown(eKeyCode::X))
		//{
		//	mAnimator->Play(L"LeftSliding", false);
		//}
	}

	void Kirby::rightsliding()
	{
	}

}

