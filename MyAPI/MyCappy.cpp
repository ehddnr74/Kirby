#include "MyCappy.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"

namespace My
{
	Cappy::Cappy()
	{
	}
	Cappy::~Cappy()
	{
	}
	void Cappy::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(580,255));
		//tr->SetScale(Vector2(1.8f,2.0f));


		Image* mCappy = Resources::Load<Image>(L"Cappy", L"..\\Resources\\Cappy.bmp");
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"Move", mCappy, Vector2::Zero, 16, 16, 2, Vector2::Zero, 0.3);

		mAnimator->Play(L"Move", true);

		GameObject::Initialize();
	}
	void Cappy::Update()
	{
		GameObject::Update();
	}
	void Cappy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Cappy::Release()
	{
		GameObject::Release();
	}
}