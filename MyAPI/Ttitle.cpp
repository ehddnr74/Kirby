#include "Room1.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "Ttitle.h"
#include "MyCamera.h"

namespace My
{
	Title::Title()
	{

	}
	Title::~Title()
	{

	}

	void My::Title::Initialize()
	{

		mTitle = Resources::Load<Image>(L"Title", L"..\\Resources\\KirbyTitle.bmp");


		GameObject::Initialize();
	}

	void My::Title::Update()
	{
		GameObject::Update();
	}

	void My::Title::Render(HDC hdc)
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

		BitBlt(hdc, pos.x, pos.y, mTitle->GetWidth(), mTitle->GetHeight(), mTitle->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Title::Release()
	{
		GameObject::Release();
	}

}
