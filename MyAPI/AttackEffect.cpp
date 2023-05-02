#include "AttackEffect.h"
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
	AttackEffect::AttackEffect()
		: attacktime(0.f)
		, BaseCheck(false)
		, AttackCheck(false)
		, BeamCheck(false)
		, AirCheck(false)
		, DashCheck(false)
		, DashReleaseCheck(false)
	{

	}
	AttackEffect ::~AttackEffect()
	{

	}
	void AttackEffect::Initialize()
	{
		Image* attackeffect = Resources::Load<Image>(L"AttackEffect", L"..\\Resources\\AttackEffect.bmp");

		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"Default", attackeffect, Vector2(0.f,100.f), 12, 10, 5, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"AttackEffect", attackeffect, Vector2::Zero, 12, 10, 10, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"Air", attackeffect, Vector2(0.f,200.f), 10, 12, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"Beam", attackeffect, Vector2(0.f,300.f), 12, 10, 11, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"Dash", attackeffect, Vector2(200.f, 400.f), 12, 10, 4, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"DashRelease", attackeffect, Vector2(0.f, 500.f), 12, 10, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftDashRelease", attackeffect, Vector2(100.f, 500.f), 12, 10, 1, Vector2::Zero, 0.05);
		mState = AttackState::Base;
		
		mAnimator->Play(L"Default", false);

		GameObject::Initialize();
	}
	void AttackEffect::Update()
	{
		GameObject::Update();

		if (BaseCheck == false && mState == AttackState::Base)
		{
			BaseCheck = true;
			mAnimator->Play(L"Default", false);
		}
		if (AttackCheck == false && mState == AttackState::Attack)
		{
			AttackCheck = true;
			mAnimator->Play(L"AttackEffect", false);
		}
		if (BeamCheck == false && mState == AttackState::Beam)
		{
			BeamCheck = true;
			mAnimator->Play(L"Beam", false);
		}
		if (AirCheck == false && mState == AttackState::Air)
		{
			AirCheck = true;
			mAnimator->Play(L"Air", false);
		}
		if (DashCheck == false && mState == AttackState::Dash)
		{
			DashCheck = true;
			mAnimator->Play(L"Dash", true);
		}

		if (DashReleaseCheck == false && mState == AttackState::DashRelease && mkirby->GetState() == Kirby::eKirbyState::RightDashRelease
			|| DashReleaseCheck == false && mState == AttackState::DashRelease && mkirby->GetState() == Kirby::eKirbyState::RightBeamDashRelease
			|| DashReleaseCheck == false && mState == AttackState::DashRelease && mkirby->GetState() == Kirby::eKirbyState::RightBoombDashRelease)
		{
			DashReleaseCheck = true;
			mAnimator->Play(L"DashRelease", false);
		}
		if (DashReleaseCheck == false && mState == AttackState::DashRelease && mkirby->GetState() == Kirby::eKirbyState::LeftDashRelease
	        || DashReleaseCheck == false && mState == AttackState::DashRelease && mkirby->GetState() == Kirby::eKirbyState::LeftBeamDashRelease
			|| DashReleaseCheck == false && mState == AttackState::DashRelease && mkirby->GetState() == Kirby::eKirbyState::LeftBoombDashRelease)
		{
			DashReleaseCheck = true;
			mAnimator->Play(L"LeftDashRelease", false);
		}



		switch (mState)
		{
			case AttackState::Base:
			base();
			break;
			case AttackState::Attack:
			attack();
			break;
			case AttackState::Beam:
			beam();
			break;
			case AttackState::Air:
			air();
			break;
			case AttackState::Dash:
			dash();
			break;
			case AttackState::DashRelease:
			dashrelease();
			break;
		}

	}
	void AttackEffect::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void AttackEffect::Release()
	{
		GameObject::Release();
	}
	void AttackEffect::OnCollisionEnter(Collider* other)
	{
	}
	void AttackEffect::OnCollisionStay(Collider* other)
	{
	}
	void AttackEffect::OnCollisionExit(Collider* other)
	{
	}
	void AttackEffect::base()
	{
		attacktime += Time::DeltaTime();

		if (attacktime >= 0.25f)
		{
			attacktime = 0.0f;
			object::Destroy(this);
		}
	}
	void AttackEffect::attack()
	{
		attacktime += Time::DeltaTime();

		if (attacktime >= 0.5f)
		{
			attacktime = 0.0f;
			object::Destroy(this);
		}
	}
	void AttackEffect::beam()
	{
		attacktime += Time::DeltaTime();

		if (attacktime >= 0.55f)
		{
			attacktime = 0.0f;
			object::Destroy(this);
		}
	}
	void AttackEffect::air()
	{
		attacktime += Time::DeltaTime();

		if (attacktime >= 0.3f)
		{
			attacktime = 0.0f;
			object::Destroy(this);
		}
	}
	void AttackEffect::dash()
	{
		if (mkirby->GetState() == Kirby::eKirbyState::RightDash ||
			mkirby->GetState() == Kirby::eKirbyState::RightBeamDash ||
			mkirby->GetState() == Kirby::eKirbyState::RightBoombDash)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();

			Transform* kr = mkirby->GetComponent<Transform>();
			thispos.x = kr->GetPos().x - 40;
			thispos.y = kr->GetPos().y + 100;

			tr->SetPos(thispos);
		}
		else if (mkirby->GetState() == Kirby::eKirbyState::LeftDash ||
			     mkirby->GetState() == Kirby::eKirbyState::LeftBeamDash ||
			     mkirby->GetState() == Kirby::eKirbyState::LeftBoombDash)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();

			Transform* kr = mkirby->GetComponent<Transform>();
			thispos.x = kr->GetPos().x + 40;
			thispos.y = kr->GetPos().y + 100;

			tr->SetPos(thispos);
		}
		else
		{
			object::Destroy(this);
		}
	


	}
	void AttackEffect::dashrelease()
	{
		if (mkirby->GetState() == Kirby::eKirbyState::RightDashRelease ||
			mkirby->GetState() == Kirby::eKirbyState::RightBeamDashRelease ||
			mkirby->GetState() == Kirby::eKirbyState::RightBoombDashRelease)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();

			Transform* kr = mkirby->GetComponent<Transform>();
			thispos.x = kr->GetPos().x + 40;
			thispos.y = kr->GetPos().y + 100;

			tr->SetPos(thispos);
		}
		else if (mkirby->GetState() == Kirby::eKirbyState::LeftDashRelease ||
			mkirby->GetState() == Kirby::eKirbyState::LeftBeamDashRelease ||
			mkirby->GetState() == Kirby::eKirbyState::LeftBoombDashRelease)
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 thispos = tr->GetPos();

			Transform* kr = mkirby->GetComponent<Transform>();
			thispos.x = kr->GetPos().x - 40;
			thispos.y = kr->GetPos().y + 100;

			tr->SetPos(thispos);
		}
		else
		{
			object::Destroy(this);
		}
	}
}
