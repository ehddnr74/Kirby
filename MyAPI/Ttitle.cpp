#include "Room1.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "Ttitle.h"

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

		mTitle = Resources::Load<Image>(L"Title", L"..\\Resources\\Title.bmp");


		GameObject::Initialize();
	}

	void My::Title::Update()
	{
		GameObject::Update();
	}

	void My::Title::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		BitBlt(hdc, 0, 0, mTitle->GetWidth(), mTitle->GetHeight(), mTitle->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::Title::Release()
	{
		GameObject::Release();
	}

}
