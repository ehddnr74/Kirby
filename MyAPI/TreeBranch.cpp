#include "TreeBranch.h"
#include "MyTime.h"
#include "MySceneManager.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyCamera.h"
namespace My
{
	TreeBranch::TreeBranch()
	{
	}
	TreeBranch::~TreeBranch()
	{
	}
	void TreeBranch::Initialize()
	{
		mbranch = Resources::Load<Image>(L"Branch", L"..\\Resources\\Branch.bmp");
		//mAnimator = AddComponent<Animator>();


		//mAnimator->CreateAnimation(L"zz", mTreebranch, Vector2::Zero, 1, 1, 1, Vector2::Zero, 0.1);

		//Collider* collider = AddComponent<Collider>();
		//collider->SetCenter(Vector2(-40.0f, -100.0f));
		//collider->SetSize(Vector2(80.0f, 70.0f));

		//mAnimator->Play(L"zz", false);

		GameObject::Initialize();
	}
	void TreeBranch::Update()
	{
		GameObject::Update();

	}
	void TreeBranch::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		TransparentBlt(hdc, pos.x, pos.y
			, mbranch->GetWidth() * 2.0f
			, mbranch->GetHeight() * 2.0f
			, mbranch->GetHdc()
			, 0, 0
			, mbranch->GetWidth()
			, mbranch->GetHeight()
			, RGB(50, 97, 168));
	}
	void TreeBranch::Release()
	{
		GameObject::Release();
	}
	void TreeBranch::OnCollisionEnter(Collider* other)
	{
	}
	void TreeBranch::OnCollisionStay(Collider* other)
	{
	}
	void TreeBranch::OnCollisionExit(Collider* other)
	{
	}

};