#include "AirLeft.h"
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
	AirLeft::AirLeft()
		: mtime(0.0f)
	{
	}
	AirLeft::~AirLeft()
	{
	}
	void AirLeft::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(pos);
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* AirLeft = Resources::Load<Image>(L"AirL", L"..\\Resources\\AirLeft.bmp");
		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"AirL", AirLeft, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);

		mAnimator->Play(L"AirL", true);

		GameObject::Initialize();
	}
	void AirLeft::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		mtime += Time::DeltaTime();

		if (0.0f <= mtime && mtime <= 0.5f)
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		if (0.5f <= mtime)
		{
			object::Destroy(this);
			mtime = 0.0f;
		}

		tr->SetPos(pos);

		GameObject::Update();
	}
	void AirLeft::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void AirLeft::Release()
	{
		GameObject::Release();
	}
	void AirLeft::OnCollisionEnter(Collider* other)
	{

	}
	void AirLeft::OnCollisionStay(Collider* other)
	{
	}
	void AirLeft::OnCollisionExit(Collider* other)
	{
	}
}