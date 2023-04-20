#include "HP.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyTransform.h"
#include "MyCamera.h"
#include "MyAnimator.h"
#include "MyKirby.h"

namespace My
{
	HP::HP()
	{

	}
	HP::~HP()
	{

	}

	void My::HP::Initialize()
	{

		hp = Resources::Load<Image>(L"HP", L"..\\Resources\\KirbyUI.bmp");
		hp2 = Resources::Load<Image>(L"HP2", L"..\\Resources\\KirbyUI2.bmp");
		hp3 = Resources::Load<Image>(L"HP3", L"..\\Resources\\KirbyUI3.bmp");
		hp4 = Resources::Load<Image>(L"HP4", L"..\\Resources\\KirbyUI4.bmp");
		hp5 = Resources::Load<Image>(L"HP5", L"..\\Resources\\KirbyUI5.bmp");
		hp6 = Resources::Load<Image>(L"HP6", L"..\\Resources\\KirbyUI6.bmp");
		hp7 = Resources::Load<Image>(L"HP7", L"..\\Resources\\KirbyUI7.bmp");
		hp8 = Resources::Load<Image>(L"HP8", L"..\\Resources\\KirbyUI8.bmp");
		hp9 = Resources::Load<Image>(L"HP9", L"..\\Resources\\KirbyUI9.bmp");
		hp10 = Resources::Load<Image>(L"HP10", L"..\\Resources\\KirbyUI10.bmp");
		hp11 = Resources::Load<Image>(L"HP11", L"..\\Resources\\KirbyUI11.bmp");

		GameObject::Initialize();
	}

	void My::HP::Update()
	{
		GameObject::Update();


	}

	void My::HP::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		if (mKirby != nullptr)
		{
			if (mKirby->GetHP() == 110)
			{
				BitBlt(hdc, 0, 400, hp->GetWidth(), hp->GetHeight(), hp->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 100)
			{
				BitBlt(hdc, 0, 400, hp2->GetWidth(), hp2->GetHeight(), hp2->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 90)
			{
				BitBlt(hdc, 0, 400, hp3->GetWidth(), hp3->GetHeight(), hp3->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 80)
			{
				BitBlt(hdc, 0, 400, hp4->GetWidth(), hp4->GetHeight(), hp4->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 70)
			{
				BitBlt(hdc, 0, 400, hp5->GetWidth(), hp5->GetHeight(), hp5->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 60)
			{
				BitBlt(hdc, 0, 400, hp6->GetWidth(), hp6->GetHeight(), hp6->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 50)
			{
				BitBlt(hdc, 0, 400, hp7->GetWidth(), hp7->GetHeight(), hp7->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 40)
			{
				BitBlt(hdc, 0, 400, hp8->GetWidth(), hp8->GetHeight(), hp8->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 30)
			{
				BitBlt(hdc, 0, 400, hp9->GetWidth(), hp9->GetHeight(), hp9->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 20)
			{
				BitBlt(hdc, 0, 400, hp10->GetWidth(), hp10->GetHeight(), hp10->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() == 10)
			{
				BitBlt(hdc, 0, 400, hp11->GetWidth(), hp11->GetHeight(), hp11->GetHdc(), 0, 0, SRCCOPY);
			}
			if (mKirby->GetHP() <= 0)
			{
				BitBlt(hdc, 0, 400, hp->GetWidth(), hp11->GetHeight(), hp11->GetHdc(), 0, 0, SRCCOPY);
			}
		}
	}

	void My::HP::Release()
	{
		GameObject::Release();
	}

	//void HP::ui1()
	//{
	//	mAnimator->Play(L"HP", false);
	//}

	//void HP::ui2()
	//{
	//	mAnimator->Play(L"HP2", false);
	//}

	//void HP::ui3()
	//{
	//	mAnimator->Play(L"HP3", false);
	//}

	//void HP::ui4()
	//{
	//	mAnimator->Play(L"HP4", false);
	//}

	//void HP::ui5()
	//{
	//	mAnimator->Play(L"HP5", false);
	//}

	//void HP::ui6()
	//{
	//	mAnimator->Play(L"HP6", false);
	//}

	//void HP::ui7()
	//{
	//	mAnimator->Play(L"HP7", false);
	//}

	//void HP::ui8()
	//{
	//	mAnimator->Play(L"HP8", false);
	//}

	//void HP::ui9()
	//{
	//	mAnimator->Play(L"HP9", false);
	//}

	//void HP::ui10()
	//{
	//	mAnimator->Play(L"HP10", false);
	//}

	//void HP::ui11()
	//{
	//	mAnimator->Play(L"HP11", false);
	//}

}