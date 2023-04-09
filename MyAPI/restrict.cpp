#include "restrict.h"
#include "R1Ground.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"
#include "MyInput.h"
#include "MyCamera.h"
namespace My
{
	Restrict::Restrict()
	{
	}

	Restrict::~Restrict()
	{
	}

	void Restrict::Initialize()
	{
		mImage = Resources::Load<Image>(L"Restrict", L"..\\Resources\\Restrict.bmp");

		GameObject::Initialize();
	}

	void Restrict::Update()
	{
		//if (mKirby->GetState() != Kirby::eKirbyState::Death)
		//{

		Transform* playerTr = mKirby->GetComponent<Transform>();
		float x = playerTr->GetPos().x;
		float y = playerTr->GetPos().y;


		COLORREF basecolor = mImage->GetPixel(x, y - 20);
		COLORREF color = mImage->GetPixel(x + 27, y - 20); // 오른쪽 아래 
		COLORREF color3 = mImage->GetPixel(x - 23, y - 20); // 왼쪽 아래 
		COLORREF color1 = mImage->GetPixel(x + 27, y - 40); //오른쪽 가운데 
		COLORREF color2 = mImage->GetPixel(x - 23, y - 40); // 왼쪽 가운데 
		COLORREF color5 = mImage->GetPixel(x, y); // 


		RigidBody* rb = mKirby->GetComponent<RigidBody>();



		if (color1 == RGB(200, 0, 200))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x -= 5;
			playerTr->SetPos(pos);
		}

		if (color2 == RGB(100, 0, 100))
		{
			Vector2 pos = playerTr->GetPos();
			pos.x += 5;
			playerTr->SetPos(pos);
		}

	}

	void Restrict::Render(HDC hdc)
	{

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);


		BitBlt(hdc, -50 ,  -50 , mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);

		GameObject::Render(hdc);
	}

	void Restrict::Release()
	{
	}

	void Restrict::OnCollisionEnter(Collider* other)
	{
	}



	void Restrict::OnCollisionStay(Collider* other)
	{


	}

	void Restrict::OnCollisionExit(Collider* other)
	{

	}

}
