#include "TreeGround.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"
#include "MyInput.h"
#include "MyCamera.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "Explosion.h"
#include "Apple.h"
namespace My
{
	TreeGround::TreeGround()

	{
	}

	TreeGround::~TreeGround()
	{
	}

	void TreeGround::Initialize()
	{
		mImage = Resources::Load<Image>(L"TreeGround", L"..\\Resources\\treegr.bmp");

		GameObject::Initialize();
	}

	void TreeGround::Update()
	{
		GameObject::Update();

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

		COLORREF rcolorup = mImage->GetPixel(x + 27, y - 65);// 위쪽 가장 오른쪽
		COLORREF lcolorup = mImage->GetPixel(x - 23, y - 65);// 위쪽 가장 왼쪽


		RigidBody* rb = mKirby->GetComponent<RigidBody>();

		if (mApple != nullptr)
		{
			Transform* ar = mApple->GetComponent<Transform>();

			COLORREF Apple = mImage->GetPixel(ar->GetPos().x, ar->GetPos().y - 20);

			if (Apple == RGB(255, 0, 255))
			{
				mApple->Setnum(1);
				SetApple(nullptr);
			}
		}

		if (mApple2 != nullptr)
		{
			Transform* ar2 = mApple2->GetComponent<Transform>();

			COLORREF Apple2 = mImage->GetPixel(ar2->GetPos().x, ar2->GetPos().y - 20);

			if (Apple2 == RGB(255, 0, 255))
			{
				mApple2->Setnum(2);
				SetApple(nullptr);
			}
		}

		if (mkrb != nullptr)
		{
			Transform* mkrbtr = mkrb->GetComponent<Transform>();
			COLORREF colorkrboom = mImage->GetPixel(mkrbtr->GetPos().x, mkrbtr->GetPos().y - 20);
			COLORREF colorkrboomr = mImage->GetPixel(mkrbtr->GetPos().x + 15, mkrbtr->GetPos().y - 20);
			COLORREF colorkrbooml = mImage->GetPixel(mkrbtr->GetPos().x - 10, mkrbtr->GetPos().y - 20);

			if (colorkrboom == RGB(255, 0, 255) || colorkrbooml == RGB(255, 0, 255) || colorkrboomr == RGB(255, 0, 255)
				|| colorkrboom == RGB(100, 0, 100) || colorkrbooml == RGB(100, 0, 100) || colorkrboomr == RGB(100, 0, 100)
				|| colorkrboom == RGB(200, 0, 200) || colorkrbooml == RGB(200, 0, 200) || colorkrboomr == RGB(200, 0, 200))
			{
				object::Destroy(mkrb);
				class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mkrbtr->GetPos().x, mkrbtr->GetPos().y + 150), Vector2(2.f, 2.f), eLayerType::Effect);
				SetKirBoomb(nullptr);
			}
			/*if (colorkrboom == RGB(100, 0, 100) || colorkrbooml == RGB(100, 0, 100) || colorkrboomr == RGB(100, 0, 100))
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
			}*/
		}
		if (mklb != nullptr)
		{
			Transform* mklbtr = mklb->GetComponent<Transform>();
			COLORREF klboom = mImage->GetPixel(mklbtr->GetPos().x, mklbtr->GetPos().y - 40);
			COLORREF krboomr = mImage->GetPixel(mklbtr->GetPos().x + 15, mklbtr->GetPos().y - 40);
			COLORREF krbooml = mImage->GetPixel(mklbtr->GetPos().x - 10, mklbtr->GetPos().y - 40);

			if (klboom == RGB(255, 0, 255) || krbooml == RGB(255, 0, 255) || krboomr == RGB(255, 0, 255)
				|| klboom == RGB(100, 0, 100) || krbooml == RGB(100, 0, 100) || krboomr == RGB(100, 0, 100)
					|| klboom == RGB(200, 0, 200) || krbooml == RGB(200, 0, 200) || krboomr == RGB(200, 0, 200))
			{
				object::Destroy(mklb);
				class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mklbtr->GetPos().x, mklbtr->GetPos().y + 150), Vector2(2.f, 2.f), eLayerType::Effect);
				SetKirLeftBoomb(nullptr);
			}
			//if (klboom == RGB(100, 0, 100) || krbooml == RGB(100, 0, 100) || krboomr == RGB(100, 0, 100))
			//{
			//	object::Destroy(mklb);
			//	class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mklbtr->GetPos().x, mklbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
			//	SetKirLeftBoomb(nullptr);
			//}
			//if (klboom == RGB(200, 0, 200) || krbooml == RGB(200, 0, 200) || krboomr == RGB(200, 0, 200))
			//{
			//	object::Destroy(mklb);
			//	class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(mklbtr->GetPos().x, mklbtr->GetPos().y + 50), Vector2(1.f, 1.f), eLayerType::Effect);
			//	SetKirLeftBoomb(nullptr);
			//}
		}

		if (colorup == RGB(100, 100, 100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.y += 5;
			playerTr->SetPos(pos);
		}

		if (colorup == RGB(100, 50, 100) || rcolorup == RGB(100, 50, 100) || lcolorup == RGB(100, 50, 100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.y += 5;
			playerTr->SetPos(pos);
		}


		if (color1 == RGB(200, 0, 200) || rcolorup == RGB(200, 0, 200) || color == RGB(200, 0, 200))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x -= 5;
			playerTr->SetPos(pos);
		}

		if (color2 == RGB(100, 0, 100) || lcolorup == RGB(100, 0, 100) || color3 == RGB(100, 0, 100))
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


	void TreeGround::Render(HDC hdc)
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

	void TreeGround::Release()
	{

	}

	void TreeGround::OnCollisionEnter(Collider* other)
	{

	}



	void TreeGround::OnCollisionStay(Collider* other)
	{


	}

	void TreeGround::OnCollisionExit(Collider* other)
	{

	}

}
