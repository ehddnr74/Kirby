#include "Explosion.h"
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
#include "LeftBoomb.h"
#include "RightBoomb.h"

namespace My
{
	Explosion::Explosion()
		:Explosiontime(0.f)
	{

	}
	Explosion ::~Explosion()
	{

	}
	void Explosion::Initialize()
	{
		Image* explosion = Resources::Load<Image>(L"Explosion", L"..\\Resources\\Explosion.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Explosion", explosion, Vector2(0.f,200.f), 10, 2, 8, Vector2::Zero, 0.04);

		mAnimator->Play(L"Explosion", false);

		GameObject::Initialize();
	}
	void Explosion::Update()
	{
		Explosiontime += Time::DeltaTime();

		if (Explosiontime >= 0.32f)
		{
			Explosiontime = 0.0f;
			object::Destroy(this);
		}

		GameObject::Update();
	}
	void Explosion::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Explosion::Release()
	{
		GameObject::Release();
	}
	void Explosion::OnCollisionEnter(Collider* other)
	{
	}
	void Explosion::OnCollisionStay(Collider* other)
	{
	}
	void Explosion::OnCollisionExit(Collider* other)
	{
	}
}
