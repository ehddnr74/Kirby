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

		//	Collider* kirbyCol = mKirby->GetComponent<Collider>();
		//	Vector2 kirbyPos = kirbyCol->GetPos();

		//	Collider* groundCol = this->GetComponent<Collider>();
		//	Vector2 groundPos = groundCol->GetPos();

		//	float fLen = fabs(kirbyPos.y - groundPos.y);
		//	float fSize = (kirbyCol->GetSize().y / 2.0f) + (groundCol->GetSize().y / 2.0f);

		//	if (fLen < fSize)
		//	{
		//		Transform* kirbyTr = mKirby->GetComponent<Transform>();
		//		Transform* grTr = this->GetComponent<Transform>();

		//		Vector2 kirPos = kirbyTr->GetPos();
		//		Vector2 grPos = grTr->GetPos();

		//		kirPos -= (fSize - fLen) - 1.0f;
		//		kirbyTr->SetPos(kirPos);
		//	}
		//}
	}

	void Ground::OnCollisionStay(Collider* other)
	{

	}

	void Ground::OnCollisionExit(Collider* other)
	{
	}

}
