#include "R1Ground.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"
#include "MyInput.h"
#include "MyWaddle.h"
#include "MyCamera.h"
#include "MyTwizzy.h"
#include "MyCappy.h"
#include "MyComponent.h"
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
		mImage = Resources::Load<Image>(L"stage1_1GR", L"..\\Resources\\Stagegr.bmp");

		GameObject::Initialize();
	}

	void Ground::Update()
	{
		GameObject::Update();
		


		if(mCappy != nullptr)
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
		COLORREF colorup = mImage->GetPixel(x, y - 70); //위쪽 가운데


		RigidBody* rb = mKirby->GetComponent<RigidBody>();



		if (colorup == RGB(100, 100, 100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.y += 1;
			playerTr->SetPos(pos);
		}


		if (color1 == RGB(200, 0, 200))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x -= 2;
			playerTr->SetPos(pos);
		}

		if (color2 == RGB(100, 0, 100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x += 2;
			playerTr->SetPos(pos);
		}


		if (basecolor == RGB(255, 0, 255) || color3 == RGB(255, 0, 255) || color == RGB(255, 0, 255))
		{
			rb->SetGround(true);
			if (x >= 896 && x <= 1010)
			{
				Vector2 pos = playerTr->GetPos();
				pos.y -= 1;
				playerTr->SetPos(pos);
			}

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
	


	void Ground::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		//Transform* tr = GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//pos = Camera::CalculatePos(pos);

		//TransparentBlt(hdc, pos.x  , pos.y
		//	, mImage->GetWidth(), mImage->GetHeight()
		//	, mImage->GetHdc()
		//	, 0, 0
		//	, mImage->GetWidth(), mImage->GetHeight()
		//	, RGB(255, 255, 255));

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);
		

		BitBlt(hdc,  pos.x , pos.y , mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);

		
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
