#include "Room2.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyCamera.h"

namespace My
{
	Room2::Room2()
	{

	}
	Room2::~Room2()
	{

	}

	void My::Room2::Initialize()
	{
		mroom2 = Resources::Load<Image>(L"Stage1_2", L"..\\Resources\\stage1_2.bmp");


		GameObject::Initialize();
	}

	void My::Room2::Update()
	{
		GameObject::Update();
	}

	void My::Room2::Render(HDC hdc)
	{
		GameObject::Render(hdc);


		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		TransparentBlt(hdc, pos.x, pos.y
			, mroom2->GetWidth()
			, mroom2->GetHeight()
			, mroom2->GetHdc()
			, 0, 0
			, mroom2->GetWidth()
			, mroom2->GetHeight()
			, RGB(72, 104, 112));


		//BitBlt(hdc, 0, 0, mroom2->GetWidth(), mroom2->GetHeight(), mroom2->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Room2::Release()
	{
		GameObject::Release();
	}

}