#pragma once
#include "MyGameObject.h"

namespace My
{
	class TreeGround : public GameObject
	{
	public:
		TreeGround();
		virtual ~TreeGround();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		void SetPlayer(class Kirby* player) { mKirby = player; }


	private:
		class Collider* mCollider;
		class Image* mImage;
		class Kirby* mKirby;

	};
}