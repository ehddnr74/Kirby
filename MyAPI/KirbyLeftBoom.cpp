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
#include "MyRigidBody.h"
#include "Explosion.h"

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

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetGravity(Vector2::Zero);
		mRigidBody->SetMass(1.0f);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-16.0f, -37.0f));
		collider->SetSize(Vector2(35.0f, 35.0f));

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
		Transform* tr = GetComponent<Transform>();
		object::Destroy(this);
		class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(tr->GetPos().x, tr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
	}
	void kirbyLeftBoom::OnCollisionStay(Collider* other)
	{
	}
	void kirbyLeftBoom::OnCollisionExit(Collider* other)
	{
	}
}

