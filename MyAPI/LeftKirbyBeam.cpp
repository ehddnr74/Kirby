#include "LeftKirbyBeam.h"
#include "MyImage.h"
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

namespace My
{
	LeftKirbyBeam::LeftKirbyBeam()
		:beamtime(0.f)
	{

	}
	LeftKirbyBeam::~LeftKirbyBeam()
	{

	}
	void LeftKirbyBeam::Initialize()
	{

		Image* LeftKirbyBeam = Resources::Load<Image>(L"LeftKirbyBeam", L"..\\Resources\\LeftBeam.bmp");

		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"LeftKirbyBeam", LeftKirbyBeam, Vector2(0.0f,0.0f), 22, 1, 17, Vector2::Zero, 0.02);

		mAnimator->Play(L"LeftKirbyBeam", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -130.0f));
		collider->SetSize(Vector2(140.0f, 100.0f));

		GameObject::Initialize();
	}
	void LeftKirbyBeam::Update()
	{
		beamtime += Time::DeltaTime();

		if (beamtime >= 0.34f)
		{
			object::Destroy(this);
		}

		if (mkirby != nullptr)
		{
			if (mkirby->GetJumpingBeam() == true)
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 BeamPos = tr->GetPos();
				Transform* kr = mkirby->GetComponent<Transform>();
				Vector2 KirbyPos = kr->GetPos();

				BeamPos.x = KirbyPos.x - 100;
				BeamPos.y = KirbyPos.y + 80;

				tr->SetPos(BeamPos);
			}
		}

		GameObject::Update();
	}
	void LeftKirbyBeam::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LeftKirbyBeam::Release()
	{
		GameObject::Release();
	}
	void LeftKirbyBeam::OnCollisionEnter(Collider* other)
	{
	}
	void LeftKirbyBeam::OnCollisionStay(Collider* other)
	{
	}
	void LeftKirbyBeam::OnCollisionExit(Collider* other)
	{
	}
};