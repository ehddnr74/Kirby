#pragma once
#include "MyGameObject.h"
namespace My
{
	class Kirby;
	class Stage2Pt : public GameObject
	{
	public:
		Stage2Pt();
		~Stage2Pt();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		bool GetPortal() { return Portal; }

		void SetKirby(class Kirby* mkir) { mkirby = mkir; }

	private:
		Collider* mCollider;
		class Kirby* mkirby;

		bool Portal;


	};
}