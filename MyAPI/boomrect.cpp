#include "boomrect.h"
#include "MySceneManager.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "Stage1_1.h"
#include "MyCamera.h"
#include "RightBoomb.h"
#include "LeftBoomb.h"

namespace My
{
	boomrect::boomrect()
	{
	}
	boomrect::~boomrect()
	{
	}
	void boomrect::Initialize()
	{
		GameObject::Initialize();
	}
	void boomrect::Update()
	{
		Transform* playerTr = LeftBoomb->GetComponent<Transform>();

		playerTr->GetPos();

		GameObject::Update();
	}
	void boomrect::Render(HDC hdc)
	{

		Transform* playerTr = LeftBoomb->GetComponent<Transform>();
		Vector2 Pos = playerTr->GetPos();

		HPEN pen = NULL;
		pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));


		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Vector2 pos = Camera::CalculatePos(Pos);

		Rectangle(hdc, Pos.x -60, Pos.y-100, Pos.x -50, Pos.y - 90);

		(HPEN)SelectObject(hdc, oldPen);
		(HBRUSH)SelectObject(hdc, oldBrush);
		DeleteObject(pen);

		GameObject::Render(hdc);
	}
	void boomrect::Release()
	{
		GameObject::Release();
	}

}