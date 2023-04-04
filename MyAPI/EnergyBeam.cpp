#include "EnergyBeam.h"
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
	EnergyBeam::EnergyBeam()
		:energybeamtime(0.f)
	{

	}
	EnergyBeam::~EnergyBeam()
	{

	}
	void EnergyBeam::Initialize()
	{

		Image* EnergyBeam = Resources::Load<Image>(L"EnergyBeam", L"..\\Resources\\EnergyBeam.bmp");

		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"RightEnergyBeam", EnergyBeam, Vector2::Zero, 20, 1, 1, Vector2::Zero, 0.05);

		//mAnimator->CreateAnimation(L"RightKirbyBeam", KirbyBeam, Vector2(300.0f,0.0f), 20, 1, 1, Vector2::Zero, 0.05);

		mAnimator->Play(L"RightEnergyBeam", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-55.0f, -128.0f));
		collider->SetSize(Vector2(40.0f, 83.0f));

		GameObject::Initialize();
	}
	void EnergyBeam::Update()
	{
		energybeamtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 Pos = tr->GetPos();

		Pos.x += 400.0f * Time::DeltaTime();

		if (energybeamtime >= 0.7f)
		{
			object::Destroy(this);
		}

		tr->SetPos(Pos);


		GameObject::Update();
	}
	void EnergyBeam::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void EnergyBeam::Release()
	{
		GameObject::Release();
	}
	void EnergyBeam::OnCollisionEnter(Collider* other)
	{
	}
	void EnergyBeam::OnCollisionStay(Collider* other)
	{
	}
	void EnergyBeam::OnCollisionExit(Collider* other)
	{
	}
};