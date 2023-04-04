#include "R2Ground.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"
#include "MyInput.h"
namespace My
{
	R2Ground::R2Ground()

	{
	}

	R2Ground::~R2Ground()
	{
	}

	void R2Ground::Initialize()
	{
		mImage = Resources::Load<Image>(L"stage1_2GR", L"..\\Resources\\stagr12grrr.bmp");

		GameObject::Initialize();
	}

	void R2Ground::Update()
	{
		Transform* playerTr = mKirby->GetComponent<Transform>();

		Collider* kirbycol = mKirby->GetComponent<Collider>();

		float x = playerTr->GetPos().x;
		float y = playerTr->GetPos().y;


		COLORREF basecolor = mImage->GetPixel(x, y - 20);
		COLORREF color = mImage->GetPixel(x + 27, y - 20); // 오른쪽 아래 
		COLORREF color3 = mImage->GetPixel(x - 23, y - 20); // 왼쪽 아래 
		COLORREF color1 = mImage->GetPixel(x + 27, y - 40); //오른쪽 가운데 
		COLORREF color2 = mImage->GetPixel(x - 23, y - 40); // 왼쪽 가운데 
		COLORREF color5 = mImage->GetPixel(x, y); // 


		RigidBody* rb = mKirby->GetComponent<RigidBody>();
		if (color3 != RGB(255, 0, 255) && basecolor != RGB(255, 0, 255) && color == RGB(255, 0, 255))
		{
			rb->SetGround(true);

			Vector2 pos = playerTr->GetPos();
			pos.y -= 1;
			playerTr->SetPos(pos);


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


		if (color3 == RGB(255, 0, 255) && basecolor != RGB(255, 0, 255) && color != RGB(255, 0, 255))
		{
			rb->SetGround(true);

			Vector2 pos = playerTr->GetPos();
			pos.y -= 1;
			playerTr->SetPos(pos);


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

		if (basecolor == RGB(255, 0, 255) || color3 == RGB(255, 0, 255) || color == RGB(255, 0, 255))
		{
			rb->SetGround(true);

			Vector2 pos = playerTr->GetPos();
			pos.y -= 1;
			playerTr->SetPos(pos);


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


	void R2Ground::Render(HDC hdc)
	{

		Transform* tr = GetComponent<Transform>();

		TransparentBlt(hdc, tr->GetPos().x, tr->GetPos().y
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc()
			, 0, 0
			, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

		GameObject::Render(hdc);
	}

	void R2Ground::Release()
	{

	}

	void R2Ground::OnCollisionEnter(Collider* other)
	{

	}



	void R2Ground::OnCollisionStay(Collider* other)
	{
		

	}

	void R2Ground::OnCollisionExit(Collider* other)
	{

	}

}
