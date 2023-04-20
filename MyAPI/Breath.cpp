#include "Breath.h"
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
	Breath::Breath()
	{

	}
	Breath ::~Breath()
	{

	}
	void Breath::Initialize()
	{
		Image* breath = Resources::Load<Image>(L"Breath", L"..\\Resources\\Breath.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Breath", breath, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"Breath", false);


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-20.0f, -57.0f));
		collider->SetSize(Vector2(40.0f, 35.0f));

		GameObject::Initialize();
	}
	void Breath::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 Pos = tr->GetPos();
		
		Pos.x -= 150.f * Time::DeltaTime();

		tr->SetPos(Pos);
	}
	void Breath::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Breath::Release()
	{
		GameObject::Release();
	}
	void Breath::OnCollisionEnter(Collider* other)
	{
	}
	void Breath::OnCollisionStay(Collider* other)
	{
	}
	void Breath::OnCollisionExit(Collider* other)
	{
	}
}
