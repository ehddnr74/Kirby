#include "TreeStage.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyTransform.h"
#include "MyCamera.h"

namespace My
{
	TreeStage::TreeStage()
	{

	}
	TreeStage::~TreeStage()
	{

	}

	void My::TreeStage::Initialize()
	{

		mtreeroom = Resources::Load<Image>(L"TreeStage", L"..\\Resources\\TreeStage.bmp");


		GameObject::Initialize();
	}

	void My::TreeStage::Update()
	{
		GameObject::Update();
	}

	void My::TreeStage::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		TransparentBlt(hdc, pos.x, pos.y
			, mtreeroom->GetWidth()
			, mtreeroom->GetHeight()
			, mtreeroom->GetHdc()
			, 0, 0
			, mtreeroom->GetWidth()
			, mtreeroom->GetHeight()
			, RGB(72, 104, 112));

		//StretchBlt(hdc, pos.x, pos.y, mroom1->GetWidth() , mroom1->GetHeight()  , mroom1->GetHdc() , 0, 0, mroom1->GetWidth(), mroom1->GetHeight(), SRCCOPY);
		//BitBlt(hdc, pos.x, pos.y, mroom1->GetWidth(), mroom1->GetHeight(), mroom1->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::TreeStage::Release()
	{
		GameObject::Release();
	}

}
