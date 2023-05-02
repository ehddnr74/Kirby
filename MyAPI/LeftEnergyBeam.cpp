#include "LeftEnergyBeam.h"
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
	LeftEnergyBeam::LeftEnergyBeam()
		:energybeamtime(0.f)
	{

	}
	LeftEnergyBeam::~LeftEnergyBeam()
	{

	}
	void LeftEnergyBeam::Initialize()
	{

		Image* LeftEnergyBeam = Resources::Load<Image>(L"LeftEnergyBeam", L"..\\Resources\\EnergyBeam.bmp");

		mAnimator = AddComponent<Animator>();


		mAnimator->CreateAnimation(L"LeftEnergyBeam", LeftEnergyBeam, Vector2(100.0f,0.0f), 20, 1, 1, Vector2::Zero, 0.05);

		//mAnimator->CreateAnimation(L"RightKirbyBeam", KirbyBeam, Vector2(300.0f,0.0f), 20, 1, 1, Vector2::Zero, 0.05);

		mAnimator->Play(L"LeftEnergyBeam", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(15.0f, -128.0f));
		collider->SetSize(Vector2(40.0f, 83.0f));

		GameObject::Initialize();
	}
	void LeftEnergyBeam::Update()
	{
		energybeamtime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 Pos = tr->GetPos();

		Pos.x -= 400.0f * Time::DeltaTime();

		if (energybeamtime >= 0.7f)
		{
			object::Destroy(this);
		}

		tr->SetPos(Pos);


		GameObject::Update();
	}
	void LeftEnergyBeam::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LeftEnergyBeam::Release()
	{
		GameObject::Release();
	}
	void LeftEnergyBeam::OnCollisionEnter(Collider* other)
	{
		Sound* mSound = Resources::Load<Sound>(L"hit3", L"..\\Resources\\Sound\\hit3.wav");
		mSound->Play(false);
	}
	void LeftEnergyBeam::OnCollisionStay(Collider* other)
	{
	}
	void LeftEnergyBeam::OnCollisionExit(Collider* other)
	{
	}
};