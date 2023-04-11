#include "TreeBK.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyCamera.h"

namespace My
{
	TreeBk::TreeBk()
	{

	}
	TreeBk::~TreeBk()
	{

	}

	void My::TreeBk::Initialize()
	{

		treebk = Resources::Load<Image>(L"TreeBk", L"..\\Resources\\treebk.bmp");



		GameObject::Initialize();
	}

	void My::TreeBk::Update()
	{
		GameObject::Update();
	}

	void My::TreeBk::Render(HDC hdc)
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

		BitBlt(hdc, pos.x, pos.y, treebk->GetWidth(), treebk->GetHeight(), treebk->GetHdc(), 0, 0, SRCCOPY);
	}

	void My::TreeBk::Release()
	{
		//GameObject::Release();
	}

}