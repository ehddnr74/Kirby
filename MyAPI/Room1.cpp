#include "Room1.h"
#include "MyResources.h"

namespace My
{
	Room1::Room1()
	{

	}
	Room1::~Room1()
	{

	}

	void My::Room1::Initialize()
	{
		
		room1 = Resources::Load<Image>(L"stage1", L"..\\Resources\\Stage1_1.bmp");

		GameObject::Initialize();
	}

	void My::Room1::Update()
	{

		
	}

	void My::Room1::Render(HDC hdc)
	{
		BitBlt(hdc, 50, 50, room1->GetWidth(), room1->GetHeight(), room1->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Room1::Release()
	{
	}

}
