#include "MyRectangle1.h"
#include "MySceneManager.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "Stage1_1.h"
#include "MyCamera.h"
#include "MyCollider.h"

namespace My
{
	Rectangle1::Rectangle1()
	{
	}
	Rectangle1::~Rectangle1()
	{
	}
	void Rectangle1::Initialize()
	{
		GameObject::Initialize();
	}
	void Rectangle1::Update()
	{
		Transform* playerTr = mKirby->GetComponent<Transform>();

		playerTr->GetPos();

		GameObject::Update();
	}
	void Rectangle1::Render(HDC hdc)
	{
		Transform* playerTr = mKirby->GetComponent<Transform>();
		Vector2 Pos = playerTr->GetPos();
		
		//Collider* kirbycol = mKirby->GetComponent<Collider>();
       // Vector2 kirbypos = kirbycol->GetPos();

		

		

		HPEN pen = NULL;
		pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));


		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Vector2 pos = Camera::CalculatePos(Pos);

		Rectangle(hdc, pos.x+27, pos.y - 20, pos.x + 32, pos.y - 15);

		(HPEN)SelectObject(hdc, oldPen);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(pen);

		GameObject::Render(hdc);
	}
	void Rectangle1::Release()
	{
		GameObject::Release();
	}

}