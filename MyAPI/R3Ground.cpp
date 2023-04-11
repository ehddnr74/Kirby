#include "R3Ground.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"
#include "MyInput.h"
#include "MyCamera.h"
#include "MyCappy.h"

namespace My
{
	R3Ground::R3Ground()
	{
	}

	R3Ground::~R3Ground()
	{
	}

	void R3Ground::Initialize()
	{
		mImage = Resources::Load<Image>(L"stage1_3GR", L"..\\Resources\\s3gr.bmp");

		GameObject::Initialize();
	}

	void R3Ground::Update()
	{
		GameObject::Update();

		if (mCappy != nullptr)
		{
			Transform* CappyTr = mCappy->GetComponent<Transform>();
			COLORREF Cappy = mImage->GetPixel(CappyTr->GetPos().x, CappyTr->GetPos().y - 20);
			RigidBody* cb = mCappy->GetComponent<RigidBody>();

			if (Cappy == RGB(255, 0, 255))
			{
				cb->SetGround(true);
			}
			else
			{
				cb->SetGround(false);
			}
		}

		Transform* playerTr = mKirby->GetComponent<Transform>();
		float x = playerTr->GetPos().x;
		float y = playerTr->GetPos().y;

		COLORREF basecolor = mImage->GetPixel(x, y - 20);
		COLORREF color = mImage->GetPixel(x + 27, y - 20); // 오른쪽 아래 
		COLORREF color3 = mImage->GetPixel(x - 23, y - 20); // 왼쪽 아래 
		COLORREF color1 = mImage->GetPixel(x + 27, y - 40); //오른쪽 가운데 
		COLORREF color2 = mImage->GetPixel(x - 23, y - 40); // 왼쪽 가운데 
		COLORREF color5 = mImage->GetPixel(x, y); // 
		COLORREF colorup = mImage->GetPixel(x, y - 70);//위쪽 가운데

		COLORREF rcolorup = mImage->GetPixel(x+27, y - 65);// 위쪽 가장 오른쪽
		COLORREF lcolorup = mImage->GetPixel(x - 23, y - 65);// 위쪽 가장 왼쪽


		RigidBody* rb = mKirby->GetComponent<RigidBody>();



		if (colorup == RGB(100, 100, 100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.y += 5;
			playerTr->SetPos(pos);
		}

		if (colorup == RGB(100, 50, 100) || rcolorup == RGB(100,50,100) || lcolorup == RGB(100,50,100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.y += 5;
			playerTr->SetPos(pos);
		}


		if (color1 == RGB(200, 0, 200) || rcolorup == RGB(200,0,200) || color == RGB(200,0,200))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x -= 5;
			playerTr->SetPos(pos);
		}

		if (color2 == RGB(100, 0, 100) || lcolorup == RGB(100, 0, 100) || color3 ==RGB(100,0,100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x += 5;
			playerTr->SetPos(pos);
		}

		if (basecolor == RGB(255, 0, 255) || color3 == RGB(255, 0, 255) || color == RGB(255, 0, 255))
		{
			rb->SetGround(true);

			if (mKirby->GetJump())
			{
				rb->SetGround(false);
			}
			if (mKirby->GetJump() == false)
			{
				rb->SetGround(true);
			}
		}

		else
		{
			rb->SetGround(false);
		}
	}


	void R3Ground::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		//Transform* tr = GetComponent<Transform>();

		//TransparentBlt(hdc, tr->GetPos().x, tr->GetPos().y
		//	, mImage->GetWidth(), mImage->GetHeight()
		//	, mImage->GetHdc()
		//	, 0, 0
		//	, mImage->GetWidth(), mImage->GetHeight()
		//	, RGB(255, 255, 255));

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);


	}

	void R3Ground::Release()
	{

	}

	void R3Ground::OnCollisionEnter(Collider* other)
	{

	}



	void R3Ground::OnCollisionStay(Collider* other)
	{


	}

	void R3Ground::OnCollisionExit(Collider* other)
	{

	}

}
