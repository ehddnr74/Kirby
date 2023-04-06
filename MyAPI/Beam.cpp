#include "Beam.h"
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
	Beam::Beam()
		:beamtime(0.f)
	{

	}
	Beam::~Beam()
	{

	}
	void Beam::Initialize()
	{
		Image* WaddleBeam = Resources::Load<Image>(L"WaddleBeam", L"..\\Resources\\Beam.bmp");

		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"WaddleBeam", WaddleBeam, Vector2::Zero, 22, 1, 17, Vector2::Zero, 0.05);

		mAnimator->Play(L"WaddleBeam", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-65.0f, -200.0f));
		collider->SetSize(Vector2(140.0f, 100.0f));



		GameObject::Initialize();
	}
	void Beam::Update()
	{
		beamtime += Time::DeltaTime();

		if (beamtime >= 0.85f)
		{
			object::Destroy(this);
		}


		GameObject::Update();
	}
	void Beam::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Beam::Release()
	{
		GameObject::Release();
	}
	void Beam::OnCollisionEnter(Collider* other)
	{
	}
	void Beam::OnCollisionStay(Collider* other)
	{
	}
	void Beam::OnCollisionExit(Collider* other)
	{
	}
};