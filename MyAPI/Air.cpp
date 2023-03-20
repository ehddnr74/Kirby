#include "Air.h"
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
	Air::Air()
		: mtime(0.0f)
	{
	}
	Air::~Air()
	{
	}
	void Air::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(pos);
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* Air = Resources::Load<Image>(L"Air", L"..\\Resources\\Air.bmp");
		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"RightAir", Air, Vector2::Zero, 1,1,1, Vector2::Zero, 0.1);

		mAnimator->Play(L"RightAir", true);

		GameObject::Initialize();
	}
	void Air::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

			mtime += Time::DeltaTime();

			if (0.0f <= mtime && mtime <= 0.5f)
			{
				pos.x += 300.0f * Time::DeltaTime();
			}
			if (0.5f <= mtime)
			{
				object::Destroy(this);
				mtime = 0.0f;
			}

			tr->SetPos(pos);

		GameObject::Update();
	}
	void Air::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Air::Release()
	{
		GameObject::Release();
	}
	void Air::OnCollisionEnter(Collider* other)
	{

	}
	void Air::OnCollisionStay(Collider* other)
	{
	}
	void Air::OnCollisionExit(Collider* other)
	{
	}
}