#include "R1Ground.h"
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
	Ground::Ground()
	{
	}

	Ground::~Ground()
	{
	}

	void Ground::Initialize()
	{
		//mCollider = AddComponent<Collider>();
		//Transform* m1tr = GetComponent<Transform>();
		//m1tr->SetPos(Vector2(0.0f, 370.0f));

		//mCollider->SetSize(Vector2(300.0f, 50.0f));


		
		

		




		mImage = Resources::Load<Image>(L"stage1_1GR", L"..\\Resources\\stage11grrr.bmp");

		GameObject::Initialize();
	}

	void Ground::Update()
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


		//if (color2 == RGB(150, 0, 60))
		//{
		//	Vector2 pos = playerTr->GetPos();
		//	pos.x += 10;
		//	playerTr->SetPos(pos);
		//}
		//
		//if (color1 == RGB(60, 0, 150) || color == RGB(60,0,150))
		//{
		//	Vector2 pos = playerTr->GetPos();
		//	pos.x -= 10;
		//	playerTr->SetPos(pos);
		//}
		////if (color1 != RGB(60, 0, 150))
		////{
		////	check = false;
		////}

		if (color3 == RGB(255, 0, 255) && basecolor != RGB(255, 0, 255) && color != RGB(255, 0, 255))
		{
			rb->SetGround(true);
		

			Vector2 pos = playerTr->GetPos();
			pos.y -= 2;
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

		//if (basecolor == RGB(255, 0, 255) && color3 == RGB(255, 0, 255) && color == RGB(255, 0, 255))
		//{
		//	rb->SetGround(true);
		//	if (mKirby->GetJump())
		//	{
		//		rb->SetGround(false);
		//	}
		//	if (mKirby->GetJump() == false)
		//	{
		//		rb->SetGround(true);
		//	}
		//}
		//else
		//{
		//	rb->SetGround(false);
		//}


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

			//	else
			//	{

			//		rb->SetGround(false);
			//		nakha = true;
			//		//rb->SetGravity(Vector2(0.0f, 1000.0f));
			//		if (color5 == RGB(50, 160, 0))
			//		{
			//			rb->SetGround(true);

			//			if (mKirby->GetJump())
			//			{
			//				rb->SetGround(false);
			//			}
			//			if (mKirby->GetJump() == false)
			//			{
			//				rb->SetGround(true);
			//			}
			//			Vector2 pos = playerTr->GetPos();
			//			pos.y -= 1;
			//			playerTr->SetPos(pos);

			//			if (color != RGB(50, 160, 0))
			//			{
			//				rb->SetGround(false);
			//			}
			//		}
		}

		//if (color != RGB(50, 160, 0))
		//{
		//	rb->SetGround(false);
		//}


	void Ground::Render(HDC hdc)
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

	void Ground::Release()
	{
	}

	void Ground::OnCollisionEnter(Collider* other)
	{
			//Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner());
			//if (mKirby == nullptr)
			//	return;

			//RigidBody* rb = mKirby->GetComponent<RigidBody>();
			//rb->SetGround(true);

			//Collider* kirbycol = mKirby->GetComponent<Collider>();
			//Vector2 kirbypos = kirbycol->GetPos();

			//Collider* groundcol = this->GetComponent<Collider>();
			//Vector2 groundpos = groundcol->GetPos();

			//float flen = fabs(kirbypos.y - groundpos.y);
			//float fsize = (kirbycol->GetSize().y / 2.0f) + (groundcol->GetSize().y / 2.0f);

			//if (flen < fsize)
			//{
			//	Transform* kirbytr = mKirby->GetComponent<Transform>();
			//	Transform* grtr = this->GetComponent<Transform>();

			//	Vector2 kirpos = kirbytr->GetPos();
			//	Vector2 grpos = grtr->GetPos();

			//	kirpos -= (fsize - flen) - 1.0f;
			//	kirbytr->SetPos(kirpos);
			//}
		}
	


	void Ground::OnCollisionStay(Collider* other)
	{
		//Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner());
		//if (mKirby == nullptr)
		//	return;

		//RigidBody* rb = mKirby->GetComponent<RigidBody>();
		//rb->SetGround(true);

		//Collider* kirbycol = mKirby->GetComponent<Collider>();
		//Vector2 kirbypos = kirbycol->GetPos();

		//Collider* groundcol = this->GetComponent<Collider>();
		//Vector2 groundpos = groundcol->GetPos();

		//float flen = fabs(kirbypos.y - groundpos.y);
		//float fsize = (kirbycol->GetSize().y / 2.0f) + (groundcol->GetSize().y / 2.0f);

		//if (flen < fsize)
		//{
		//	Transform* kirbytr = mKirby->GetComponent<Transform>();
		//	Transform* grtr = this->GetComponent<Transform>();

		//	Vector2 kirpos = kirbytr->GetPos();
		//	Vector2 grpos = grtr->GetPos();

		//	kirpos -= (fsize - flen) - 1.0f;
		//	kirbytr->SetPos(kirpos);
		//}

	}

	void Ground::OnCollisionExit(Collider* other)
	{
		//Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner());
		//if (other->GetOwner() == mKirby)
		//{
		//	RigidBody* rb = mKirby->GetComponent<RigidBody>();
		//	rb->SetGround(false);
		//}
	}

}
