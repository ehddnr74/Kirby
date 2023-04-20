#include "Stage2Pt.h"
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
	Stage2Pt::Stage2Pt()
		:Portal(false)
	{

	}
	Stage2Pt::~Stage2Pt()
	{

	}
	void Stage2Pt::Initialize()
	{
		GameObject::Initialize();


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(50.0f, -20.0f));
		collider->SetSize(Vector2(50.0f, 80.0f));


	}
	void Stage2Pt::Update()
	{
		GameObject::Update();
	}
	void Stage2Pt::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Stage2Pt::Release()
	{
		GameObject::Release();
	}
	void Stage2Pt::OnCollisionEnter(Collider* other)
	{
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			Portal = true;
		}

	}
	void Stage2Pt::OnCollisionStay(Collider* other)
	{
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			Portal = true;
		}
	}
	void Stage2Pt::OnCollisionExit(Collider* other)
	{
		if (Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			Portal = false;
		}
	}
}