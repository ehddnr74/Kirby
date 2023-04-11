#include "Stage1_3bk.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyCamera.h"

namespace My
{
	Stage1_3bk::Stage1_3bk()
	{

	}
	Stage1_3bk::~Stage1_3bk()
	{

	}

	void My::Stage1_3bk::Initialize()
	{

		mbg3 = Resources::Load<Image>(L"Stage13bk", L"..\\Resources\\stage3bk.bmp");



		GameObject::Initialize();
	}

	void My::Stage1_3bk::Update()
	{
		GameObject::Update();
	}

	void My::Stage1_3bk::Render(HDC hdc)
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

		BitBlt(hdc, pos.x, pos.y, mbg3->GetWidth(), mbg3->GetHeight(), mbg3->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Stage1_3bk::Release()
	{
		//GameObject::Release();
	}

}