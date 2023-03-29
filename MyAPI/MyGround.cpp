#include "MyGround.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"
#include "MyResources.h"
#include "MyImage.h"
#include "MyObject.h"

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


		
		

		




		mImage = Resources::Load<Image>(L"stage1_1GR", L"..\\Resources\\stage1_1Ground.bmp");

		GameObject::Initialize();
	}

	void Ground::Update()
	{
		Transform* playerTr = mKirby->GetComponent<Transform>();

		COLORREF color = mImage->GetPixel(playerTr->GetPos().x, playerTr->GetPos().y);

		RigidBody* rb = mKirby->GetComponent<RigidBody>();

		if (color == RGB(255, 0, 255))
		{
			rb->SetGround(true);

				Vector2 pos = playerTr->GetPos();
				pos.y -= 1;
				playerTr->SetPos(pos);
			}
			else
			{
				rb->SetGround(false);
			}
	}
	

	void Ground::Render(HDC hdc)
	{

		Transform* tr = GetComponent<Transform>();

		TransparentBlt(hdc, tr->GetPos().x, tr->GetPos().y
			, mImage->GetWidth(), mImage->GetHeight()
			, mImage->GetHdc()
			, 0, 0
			, mImage->GetWidth(), mImage->GetHeight()
			, RGB(72, 104, 112));

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
