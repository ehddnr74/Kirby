#include "HP.h"
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
	HP::HP()
	{

	}
	HP::~HP()
	{

	}

	void My::HP::Initialize()
	{

		hp = Resources::Load<Image>(L"HP", L"..\\Resources\\kirbyUI.bmp");


		GameObject::Initialize();
	}

	void My::HP::Update()
	{
		GameObject::Update();
	}

	void My::HP::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		BitBlt(hdc, 0, 400, hp->GetWidth(), hp->GetHeight(), hp->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::HP::Release()
	{
		GameObject::Release();
	}

}