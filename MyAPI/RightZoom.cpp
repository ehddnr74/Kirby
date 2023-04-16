#include "RightZoom.h"
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
#include "MyRigidBody.h"
#include "Explosion.h"

namespace My
{
	RightZoom::RightZoom()
	{

	}
	RightZoom ::~RightZoom()
	{

	}
	void RightZoom::Initialize()
	{
		Image* RZoom = Resources::Load<Image>(L"Zoom", L"..\\Resources\\Zoom.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Zoom", RZoom, Vector2(0.0f, 0.0f), 1, 1, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"Zoom", false);


		GameObject::Initialize();
	}
	void RightZoom::Update()
	{
		GameObject::Update();
	}
	void RightZoom::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void RightZoom::Release()
	{
		GameObject::Release();
	}
	void RightZoom::OnCollisionEnter(Collider* other)
	{
	}
	void RightZoom::OnCollisionStay(Collider* other)
	{
	}
	void RightZoom::OnCollisionExit(Collider* other)
	{
	}
}