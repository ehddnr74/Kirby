#include "SecretRoom.h"
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
	SecretRoom::SecretRoom()
	{

	}
	SecretRoom ::~SecretRoom()
	{

	}

	void My::SecretRoom::Initialize()
	{

		//TreeStage = Resources::Load<Image>(L"Stage1_1", L"..\\Resources\\stage1_1.bmp");


		GameObject::Initialize();
	}

	void My::SecretRoom::Update()
	{
		GameObject::Update();
	}

	void My::SecretRoom::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		//TransparentBlt(hdc, pos.x, pos.y
		//	, mroom1->GetWidth()
		//	, mroom1->GetHeight()
		//	, mroom1->GetHdc()
		//	, 0, 0
		//	, mroom1->GetWidth()
		//	, mroom1->GetHeight()
		//	, RGB(72, 104, 112));

		//StretchBlt(hdc, pos.x, pos.y, mroom1->GetWidth() , mroom1->GetHeight()  , mroom1->GetHdc() , 0, 0, mroom1->GetWidth(), mroom1->GetHeight(), SRCCOPY);
		//BitBlt(hdc, pos.x, pos.y, mroom1->GetWidth(), mroom1->GetHeight(), mroom1->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::SecretRoom::Release()
	{
		GameObject::Release();
	}

}