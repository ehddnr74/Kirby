#include "Stage3Pt.h"
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
	Stage3Pt::Stage3Pt()
		:Portal(false)
	{

	}
	Stage3Pt::~Stage3Pt()
	{

	}
	void Stage3Pt::Initialize()
	{
		GameObject::Initialize();

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(50.0f, -20.0f));
		collider->SetSize(Vector2(50.0f, 80.0f));


	}
	void Stage3Pt::Update()
	{
		GameObject::Update();
	}
	void Stage3Pt::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Stage3Pt::Release()
	{
		GameObject::Release();
	}
	void Stage3Pt::OnCollisionEnter(Collider* other)
	{
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			Portal = true;
		}

	}
	void Stage3Pt::OnCollisionStay(Collider* other)
	{
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			Portal = true;
		}
	}
	void Stage3Pt::OnCollisionExit(Collider* other)
	{
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			Portal = false;
		}
	}
}
