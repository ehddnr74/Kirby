#include "LeftZoom.h"
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
	LeftZoom::LeftZoom()
	{

	}
	LeftZoom ::~LeftZoom()
	{

	}
	void LeftZoom::Initialize()
	{
		Image* LZoom = Resources::Load<Image>(L"Zoom", L"..\\Resources\\Zoom.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Zoom", LZoom, Vector2(0.0f, 0.0f), 1, 1, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"Zoom", false);


		GameObject::Initialize();
	}
	void LeftZoom::Update()
	{
		GameObject::Update();
	}
	void LeftZoom::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LeftZoom::Release()
	{
		GameObject::Release();
	}
	void LeftZoom::OnCollisionEnter(Collider* other)
	{
	}
	void LeftZoom::OnCollisionStay(Collider* other)
	{
	}
	void LeftZoom::OnCollisionExit(Collider* other)
	{
	}
}
