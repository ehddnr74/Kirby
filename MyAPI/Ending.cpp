#include "Ending.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyCamera.h"
#include "MyAnimator.h"

namespace My
{
	Ending::Ending()
	{

	}
	Ending::~Ending()
	{

	}

	void My::Ending::Initialize()
	{

		mEnding = Resources::Load<Image>(L"EndingScene", L"..\\Resources\\EndingScene.bmp");
		//Image* mEnding = Resources::Load<Image>(L"Title", L"..\\Resources\\TitleScene.bmp");

		//mAnimator = AddComponent<Animator>();

		//mAnimator->CreateAnimation(L"Title", mTtitle, Vector2::Zero, 15, 1, 10, Vector2::Zero, 0.13);

		//mAnimator->Play(L"Title", true);

		GameObject::Initialize();
	}

	void My::Ending::Update()
	{
		GameObject::Update();
	}

	void My::Ending::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		//TransparentBlt(hdc, 0, 0
		//	, mbg1->GetWidth() 
		//	, mbg1->GetHeight() 
		//	, mbg1->GetHdc()
		//	, 0, 0
		//	, 673,217 
		//	, RGB(72, 104, 112));

		BitBlt(hdc, pos.x, pos.y, mEnding->GetWidth(), mEnding->GetHeight(), mEnding->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Ending::Release()
	{
		GameObject::Release();
	}

}