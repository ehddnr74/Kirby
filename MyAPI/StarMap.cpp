#include "StarMap.h"
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
	StarMap::StarMap()
	{

	}
	StarMap::~StarMap()
	{

	}
	void StarMap::Initialize()
	{
		Image* StarMap = Resources::Load<Image>(L"StarMap", L"..\\Resources\\StarMap.bmp");

		mAnimator = AddComponent<Animator>();
		//mAnimator = CreateAnimation(L"Left")
		mAnimator->CreateAnimation(L"Star", StarMap, Vector2::Zero, 11, 1, 11, Vector2::Zero, 0.05);

		mAnimator->Play(L"Star", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-17.0f, -55.0f));
		collider->SetSize(Vector2(32.0f, 35.0f));

		GameObject::Initialize();
	}
	void StarMap::Update()
	{
		GameObject::Update();
	}
	void StarMap::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void StarMap::Release()
	{
		GameObject::Release();
	}
	void StarMap::OnCollisionEnter(Collider* other)
	{

	}
	void StarMap::OnCollisionStay(Collider* other)
	{
	}
	void StarMap::OnCollisionExit(Collider* other)
	{
	}
}
