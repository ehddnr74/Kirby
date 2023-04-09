#include "stage1_1bk.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyCamera.h"

namespace My
{
	Stage11bk::Stage11bk()
	{

	}
	Stage11bk::~Stage11bk()
	{

	}

	void My::Stage11bk::Initialize()
	{

		mbg1 = Resources::Load<Image>(L"Stage11bk", L"..\\Resources\\Stage1_1Bk.bmp");



		GameObject::Initialize();
	}

	void My::Stage11bk::Update()
	{
		GameObject::Update();
	}

	void My::Stage11bk::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		//TransparentBlt(hdc, pos.x, pos.y
		//	, mbg1->GetWidth() 
		//	, mbg1->GetHeight()
		//	, mbg1->GetHdc()
		//	, 0, 0
		//	, 673,217 
		//	, RGB(72, 104, 112));

	     BitBlt(hdc, pos.x, pos.y, mbg1->GetWidth(), mbg1->GetHeight(), mbg1->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Stage11bk::Release()
	{
		//GameObject::Release();
	}

}