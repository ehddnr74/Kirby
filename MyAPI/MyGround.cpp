#include "MyGround.h"
#include "MyCollider.h"
#include "MyKirby.h"
#include "MyRigidbody.h"
#include "MyTransform.h"

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
		mCollider = AddComponent<Collider>();
		mCollider->SetSize(Vector2(1600.0f, 50.0f));
		GameObject::Initialize();
	}

	void Ground::Update()
	{
		GameObject::Update();
	}

	void Ground::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Ground::Release()
	{
	}

	void Ground::OnCollisionEnter(Collider* other)
	{
		Kirby* mKirby = dynamic_cast<Kirby*>(other->GetOwner());
		if (mKirby == nullptr)
			return;

		RigidBody* rb = mKirby->GetComponent<RigidBody>();
		rb->SetGround(true);

		Collider* kirbycol = mKirby->GetComponent<Collider>();
		Vector2 kirbypos = kirbycol->GetPos();

		Collider* groundcol = this->GetComponent<Collider>();
		Vector2 groundpos = groundcol->GetPos();

		float flen = fabs(kirbypos.y - groundpos.y);
		float fsize = (kirbycol->GetSize().y / 2.0f) + (groundcol->GetSize().y / 2.0f);

		if (flen < fsize)
		{
			Transform* kirbytr = mKirby->GetComponent<Transform>();
			Transform* grtr = this->GetComponent<Transform>();

			Vector2 kirpos = kirbytr->GetPos();
			Vector2 grpos = grtr->GetPos();

			kirpos -= (fsize - flen) - 1.0f;
			kirbytr->SetPos(kirpos);
		}
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
	}

}
