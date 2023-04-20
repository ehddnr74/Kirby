#include "TreeHP.h"
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
#include "TreeBoss.h"

namespace My
{
	TreeHP::TreeHP()
		:firstsearch(true)
	{

	}
	TreeHP::~TreeHP()
	{

	}

	void My::TreeHP::Initialize()
	{

		hp = Resources::Load<Image>(L"TreeHP", L"..\\Resources\\BossHP1.bmp");
		hp2 = Resources::Load<Image>(L"TreeHP2", L"..\\Resources\\BossHP2.bmp");
		hp3 = Resources::Load<Image>(L"TreeHP3", L"..\\Resources\\BossHP3.bmp");
		hp4 = Resources::Load<Image>(L"TreeHP4", L"..\\Resources\\BossHP4.bmp");
		hp5 = Resources::Load<Image>(L"TreeHP5", L"..\\Resources\\BossHP5.bmp");
		hp6 = Resources::Load<Image>(L"TreeHP6", L"..\\Resources\\BossHP6.bmp");
		hp7 = Resources::Load<Image>(L"TreeHP7", L"..\\Resources\\BossHP7.bmp");
		hp8 = Resources::Load<Image>(L"TreeHP8", L"..\\Resources\\BossHP8.bmp");
		hp9 = Resources::Load<Image>(L"TreeHP9", L"..\\Resources\\BossHP9.bmp");
		//hp10 = Resources::Load<Image>(L"HP10", L"..\\Resources\\KirbyUI10.bmp");
		//hp11 = Resources::Load<Image>(L"HP11", L"..\\Resources\\KirbyUI11.bmp");

		GameObject::Initialize();
	}

	void My::TreeHP::Update()
	{

	}

	void My::TreeHP::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		GameObject::Update();
		Transform* kr = mKirby->GetComponent<Transform>();
		Vector2 krPos = kr->GetPos();

		Transform* tr = mTree->GetComponent<Transform>();
		Vector2 trPos = tr->GetPos();

		if (mTree->GetHP() == 135 && trPos.y - krPos.y <= 500.0f)
		{
			TransparentBlt(hdc, 330, 335
				, hp->GetWidth()
				, hp->GetHeight()
				, hp->GetHdc()
				, 0, 0
				, hp->GetWidth()
				, hp->GetHeight()
				, RGB(72, 104, 112));
		}
		if (mTree->GetHP() == 120)
		{
			TransparentBlt(hdc, 330, 335
				, hp2->GetWidth()
				, hp2->GetHeight()
				, hp2->GetHdc()
				, 0, 0
				, hp2->GetWidth()
				, hp2->GetHeight()
				, RGB(72, 104, 112));
		}

			if (mTree->GetHP() == 105)
			{
				TransparentBlt(hdc, 330, 335
					, hp3->GetWidth()
					, hp3->GetHeight()
					, hp3->GetHdc()
					, 0, 0
					, hp3->GetWidth()
					, hp3->GetHeight()
					, RGB(72, 104, 112));
			}
			if (mTree->GetHP() == 90)
			{
				TransparentBlt(hdc, 330, 335
					, hp4->GetWidth()
					, hp4->GetHeight()
					, hp4->GetHdc()
					, 0, 0
					, hp4->GetWidth()
					, hp4->GetHeight()
					, RGB(72, 104, 112));
			}
			if (mTree->GetHP() == 75)
			{
				TransparentBlt(hdc, 330, 335
					, hp5->GetWidth()
					, hp5->GetHeight()
					, hp5->GetHdc()
					, 0, 0
					, hp5->GetWidth()
					, hp5->GetHeight()
					, RGB(72, 104, 112));
			}
			if (mTree->GetHP() == 60)
			{
				TransparentBlt(hdc, 330, 335
					, hp6->GetWidth()
					, hp6->GetHeight()
					, hp6->GetHdc()
					, 0, 0
					, hp6->GetWidth()
					, hp6->GetHeight()
					, RGB(72, 104, 112));
			}
			if (mTree->GetHP() == 45)
			{
				TransparentBlt(hdc, 330, 335
					, hp7->GetWidth()
					, hp7->GetHeight()
					, hp7->GetHdc()
					, 0, 0
					, hp7->GetWidth()
					, hp7->GetHeight()
					, RGB(72, 104, 112));
			}
			if (mTree->GetHP() == 30)
			{
				TransparentBlt(hdc, 330, 335
					, hp8->GetWidth()
					, hp8->GetHeight()
					, hp8->GetHdc()
					, 0, 0
					, hp8->GetWidth()
					, hp8->GetHeight()
					, RGB(72, 104, 112));
			}
			if (mTree->GetHP() == 15)
			{
				TransparentBlt(hdc, 330, 335
					, hp9->GetWidth()
					, hp9->GetHeight()
					, hp9->GetHdc()
					, 0, 0
					, hp9->GetWidth()
					, hp9->GetHeight()
					, RGB(72, 104, 112));
			}
		//	if (mTree->GetHP() == 105)
		//	{
		//		BitBlt(hdc, 0, 400, hp8->GetWidth(), hp8->GetHeight(), hp8->GetHdc(), 0, 0, SRCCOPY);
		//	}
		//	if (mKirby->GetHP() == 30)
		//	{
		//		BitBlt(hdc, 0, 400, hp9->GetWidth(), hp9->GetHeight(), hp9->GetHdc(), 0, 0, SRCCOPY);
		//	}
		//	if (mKirby->GetHP() == 20)
		//	{
		//		BitBlt(hdc, 0, 400, hp10->GetWidth(), hp10->GetHeight(), hp10->GetHdc(), 0, 0, SRCCOPY);
		//	}
		//	if (mKirby->GetHP() == 10)
		//	{
		//		BitBlt(hdc, 0, 400, hp11->GetWidth(), hp11->GetHeight(), hp11->GetHdc(), 0, 0, SRCCOPY);
		//	}
		//	if (mKirby->GetHP() <= 0)
		//	{
		//		BitBlt(hdc, 0, 400, hp->GetWidth(), hp11->GetHeight(), hp11->GetHdc(), 0, 0, SRCCOPY);
		//	}
		//}
	}

	void My::TreeHP::Release()
	{
		GameObject::Release();
	}

	
}