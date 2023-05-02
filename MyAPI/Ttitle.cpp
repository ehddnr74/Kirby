#include "Room1.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "Ttitle.h"
#include "MyCamera.h"
#include "MyAnimator.h"

namespace My
{
	Title::Title()
		:time(0.f)
		,Check(true)
		,Check2(true)
	{

	}
	Title::~Title()
	{

	}

	void My::Title::Initialize()
	{
		//mTitle = Resources::Load<Image>(L"Title", L"..\\Resources\\KirbyTitle.bmp");
		Image* mtitle = Resources::Load<Image>(L"Title1", L"..\\Resources\\Title1.bmp");
		Image* mtitle2 = Resources::Load<Image>(L"Title2", L"..\\Resources\\Title2.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"Title1", mtitle, Vector2::Zero, 50, 1, 25, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"Title2", mtitle2, Vector2::Zero, 50, 1, 38, Vector2::Zero, 0.05);
		
		mAnimator->Play(L"Title1", true);

		GameObject::Initialize();
	}

	void My::Title::Update()
	{
		time += Time::DeltaTime();

		//if (Check2 == true && time >= 2.5f)
		//{
		//	Check2 = false;
		//	mAnimator->Play(L"Title2", true);
		//}
		GameObject::Update();
	}

	void My::Title::Render(HDC hdc)
	{
	    GameObject::Render(hdc);

		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//pos = Camera::CalculatePos(pos);

		//TransparentBlt(hdc, 0, 0
		//	, mbg1->GetWidth() 
		//	, mbg1->GetHeight() 
		//	, mbg1->GetHdc()
		//	, 0, 0
		//	, 673,217 
		//	, RGB(72, 104, 112));

		//BitBlt(hdc, pos.x, pos.y, mTitle->GetWidth(), mTitle->GetHeight(), mTitle->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Title::Release()
	{
		GameObject::Release();
	}

}
