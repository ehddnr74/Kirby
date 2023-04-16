#include "R2Ground.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"
#include "MyInput.h"
#include "MyCamera.h"
#include "Bros.h"
#include "BoomBros.h"
#include "Box.h"
#include "RightBoomb.h"
#include "LeftBoomb.h"
#include "Explosion.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"

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
		mImage = Resources::Load<Image>(L"stage1_2GR", L"..\\Resources\\Stage2gr.bmp");

		GameObject::Initialize();
	}

	void R2Ground::Update()
	{
		GameObject::Update();

		if (mKirby != nullptr)
		{
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



			RigidBody* rb = mKirby->GetComponent<RigidBody>();

			if (mBoomBros != nullptr)
			{
				//if (mBros->GetDeath() == false)
				if (mBoomBros->GetHP() >= 1)
				{
					Transform* BoomBrosTr = mBoomBros->GetComponent<Transform>();
					COLORREF mboombros = mImage->GetPixel(BoomBrosTr->GetPos().x, BoomBrosTr->GetPos().y - 20);
					RigidBody* Boomb = mBoomBros->GetComponent<RigidBody>();

					if (mboombros == RGB(255, 0, 255))
					{
						Boomb->SetGround(true);
					}
					else
					{
						Boomb->SetGround(false);
					}
				}
			}

			if (mBoomBros != nullptr)
			{
				if (GetBoomb() != nullptr)
				{
					if (GetBoomb()->GetDestroy() == false)
					{
						Transform* boomTr = GetBoomb()->GetComponent<Transform>();
						COLORREF colorboom = mImage->GetPixel(boomTr->GetPos().x, boomTr->GetPos().y - 20);
						COLORREF colorboomr = mImage->GetPixel(boomTr->GetPos().x + 15, boomTr->GetPos().y - 20);
						COLORREF colorbooml = mImage->GetPixel(boomTr->GetPos().x - 10, boomTr->GetPos().y - 20);

						if (colorboom == RGB(255, 0, 255) || colorbooml == RGB(255, 0, 255) || colorboomr == RGB(255, 0, 255))
						{
							GetBoomb()->SetDestroy(true);
							//class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(boomTr->GetPos().x, boomTr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
							//object::Destroy(GetBoomb());
							//SetBoomb(nullptr);
						}
					}
				}
			}

			if (mkrb != nullptr)
			{
				Transform* mkrbtr = mkrb->GetComponent<Transform>();
				COLORREF colorkrboom = mImage->GetPixel(mkrbtr->GetPos().x, mkrbtr->GetPos().y - 20);
				COLORREF colorkrboomr = mImage->GetPixel(mkrbtr->GetPos().x + 15, mkrbtr->GetPos().y - 20);
				COLORREF colorkrbooml = mImage->GetPixel(mkrbtr->GetPos().x - 10, mkrbtr->GetPos().y - 20);

				if (colorkrboom == RGB(255, 0, 255) || colorkrbooml == RGB(255, 0, 255) || colorkrboomr == RGB(255, 0, 255))
				{
					object::Destroy(mkrb);
					class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mkrbtr->GetPos().x, mkrbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
					SetKirBoomb(nullptr);
				}
				if (colorkrboom == RGB(100, 0, 100) || colorkrbooml == RGB(100, 0, 100) || colorkrboomr == RGB(100, 0, 100))
				{
					object::Destroy(mkrb);
					class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mkrbtr->GetPos().x, mkrbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
					SetKirBoomb(nullptr);
				}
				if (colorkrboom == RGB(200, 0, 200) || colorkrbooml == RGB(200, 0, 200) || colorkrboomr == RGB(200, 0, 200))
				{
					object::Destroy(mkrb);
					class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mkrbtr->GetPos().x, mkrbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
					SetKirBoomb(nullptr);
				}

			}
			if (mklb != nullptr)
			{

				Transform* mklbtr = mklb->GetComponent<Transform>();
				COLORREF klboom = mImage->GetPixel(mklbtr->GetPos().x, mklbtr->GetPos().y - 40);
				COLORREF krboomr = mImage->GetPixel(mklbtr->GetPos().x + 15, mklbtr->GetPos().y - 40);
				COLORREF krbooml = mImage->GetPixel(mklbtr->GetPos().x - 10, mklbtr->GetPos().y - 40);

				if (klboom == RGB(255, 0, 255) || krbooml == RGB(255, 0, 255) || krboomr == RGB(255, 0, 255))
				{
					object::Destroy(mklb);
					class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mklbtr->GetPos().x, mklbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
					SetKirLeftBoomb(nullptr);
				}
				if (klboom == RGB(100, 0, 100) || krbooml == RGB(100, 0, 100) || krboomr == RGB(100, 0, 100))
				{
					object::Destroy(mklb);
					class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mklbtr->GetPos().x, mklbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
					SetKirLeftBoomb(nullptr);
				}
				if (klboom == RGB(200, 0, 200) || krbooml == RGB(200, 0, 200) || krboomr == RGB(200, 0, 200))
				{
					object::Destroy(mklb);
					class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mklbtr->GetPos().x, mklbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
					SetKirLeftBoomb(nullptr);
				}

			}


			if (mBoomBros != nullptr)
			{
				if (GetLeftBoomb() != nullptr)
				{
					if (GetLeftBoomb()->GetDestroy() == false)
					{
						Transform* LboomTr = GetLeftBoomb()->GetComponent<Transform>();
						COLORREF lcolorboom = mImage->GetPixel(LboomTr->GetPos().x, LboomTr->GetPos().y - 40);
						COLORREF lcolorboomr = mImage->GetPixel(LboomTr->GetPos().x + 15, LboomTr->GetPos().y - 40);
						COLORREF lcolorbooml = mImage->GetPixel(LboomTr->GetPos().x - 10, LboomTr->GetPos().y - 40);

						//if (lcolorboom == RGB(100, 0, 100) && lcolorbooml == RGB(100, 0, 100) && lcolorboomr == RGB(100, 0, 100))
						//{
						//	GetLeftBoomb()->SetDestroy(true);
						//	class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(LboomTr->GetPos().x, LboomTr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
						//	object::Destroy(GetLeftBoomb());
						//}


						if (lcolorboom == RGB(255, 0, 255) || lcolorbooml == RGB(255, 0, 255) || lcolorboomr == RGB(255, 0, 255))
						{
							GetLeftBoomb()->SetDestroy(true);
							//class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(LboomTr->GetPos().x, LboomTr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
							//object::Destroy(GetLeftBoomb());
							//SetLeftBoomb(nullptr);
						}
					}
				}
			}





			if (mBox != nullptr)
			{
				if (mBox->GetDestroy() == false)
				{
					Transform* BoxTr = mBox->GetComponent<Transform>();
					COLORREF colorbox = mImage->GetPixel(BoxTr->GetPos().x, BoxTr->GetPos().y);

					if (colorbox == RGB(255, 0, 255))
					{
						mBox->SetDestroy(true);
						object::Destroy(mBox);
					}
				}
			}



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

				if (x >= 1150.f && x <= 1380.f)
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

			if (mBros != nullptr)
			{
				//if (mBros->GetDeath() == false)
				if (mBros->GetHP() >= 1)
				{
					Transform* BrosTr = mBros->GetComponent<Transform>();
					COLORREF bros = mImage->GetPixel(BrosTr->GetPos().x, BrosTr->GetPos().y - 20);
					RigidBody* bb = mBros->GetComponent<RigidBody>();

					if (bros == RGB(255, 0, 255))
					{
						bb->SetGround(true);
					}
					else
					{
						bb->SetGround(false);
					}
				}
			}
		}

	
		

	void R2Ground::Render(HDC hdc)
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
