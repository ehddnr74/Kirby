#include "LeftBeam.h"
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
#include "MySound.h"
#include "MyResources.h"

namespace My
{
	LeftBeam::LeftBeam()
		:beamtime(0.f)
	{
		Sound* mSound2 = Resources::Load<Sound>(L"00b0 - SE_BEAM", L"..\\Resources\\Sound\\00b0 - SE_BEAM.wav");
		mSound2->Play(false);
	}
	LeftBeam::~LeftBeam()
	{

	}
	void LeftBeam::Initialize()
	{

		Image* WaddleLeftBeam = Resources::Load<Image>(L"WaddleLeftBeam", L"..\\Resources\\LeftBeam.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"LeftWaddleBeam", WaddleLeftBeam, Vector2(0.0f, 0.0f), 22, 1, 17, Vector2::Zero, 0.04);

		mAnimator->Play(L"LeftWaddleBeam", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -200.0f));
		collider->SetSize(Vector2(140.0f, 100.0f));

		GameObject::Initialize();
	}
	void LeftBeam::Update()
	{
		beamtime += Time::DeltaTime();

		if (beamtime >= 0.68f)
		{
			object::Destroy(this);
		}


		GameObject::Update();
	}
	void LeftBeam::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LeftBeam::Release()
	{
		GameObject::Release();
	}
	void LeftBeam::OnCollisionEnter(Collider* other)
	{
	}
	void LeftBeam::OnCollisionStay(Collider* other)
	{
	}
	void LeftBeam::OnCollisionExit(Collider* other)
	{
	}
};