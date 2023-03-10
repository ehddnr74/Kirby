#include "stage1_2bk.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"

namespace My
{
	Stage12bk::Stage12bk()
	{

	}
	Stage12bk::~Stage12bk()
	{

	}

	void My::Stage12bk::Initialize()
	{

		mbg2 = Resources::Load<Image>(L"Stage12bk", L"..\\Resources\\stage1_2bk.bmp");


		GameObject::Initialize();
	}

	void My::Stage12bk::Update()
	{
		GameObject::Update();
	}

	void My::Stage12bk::Render(HDC hdc)
	{
		GameObject::Render(hdc);


		//TransparentBlt(hdc, 0, 0
		//	, mbg1->GetWidth() 
		//	, mbg1->GetHeight() 
		//	, mbg1->GetHdc()
		//	, 0, 0
		//	, 673,217 
		//	, RGB(72, 104, 112));

		BitBlt(hdc, 0, 0, mbg2->GetWidth(), mbg2->GetHeight(), mbg2->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Stage12bk::Release()
	{
		//GameObject::Release();
	}

}