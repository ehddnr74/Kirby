#include "KirbyLeftBoom.h"
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
	kirbyLeftBoom::kirbyLeftBoom()
	{

	}
	kirbyLeftBoom ::~kirbyLeftBoom()
	{

	}
	void kirbyLeftBoom::Initialize()
	{
		Image* lboom = Resources::Load<Image>(L"LeftBoom", L"..\\Resources\\KirbyBoom.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"LeftBoom", lboom, Vector2(0.0f, 0.0f), 4, 2, 4, Vector2::Zero, 0.03);

		mAnimator->Play(L"LeftBoom", true);

		//Collider* collider = AddComponent<Collider>();
		//collider->SetCenter(Vector2(-17.0f, -35.0f));
		//collider->SetSize(Vector2(32.0f, 35.0f));

		GameObject::Initialize();
	}
	void kirbyLeftBoom::Update()
	{
		GameObject::Update();
	}
	void kirbyLeftBoom::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void kirbyLeftBoom::Release()
	{
		GameObject::Release();
	}
	void kirbyLeftBoom::OnCollisionEnter(Collider* other)
	{
	}
	void kirbyLeftBoom::OnCollisionStay(Collider* other)
	{
	}
	void kirbyLeftBoom::OnCollisionExit(Collider* other)
	{
	}
}

