#pragma once
#include "MyGameObject.h"


namespace My
{
	class Rectangle1 : public GameObject
	{
	public:

		Rectangle1();
		~Rectangle1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetPlayer(class Kirby* player) { mKirby = player; }


	private:
		Collider* mCollider;
		class Kirby* mKirby;
	};
}
