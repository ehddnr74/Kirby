#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class RightBoomb : public GameObject
	{
	public:
		RightBoomb();
		~RightBoomb();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetKirby(class Kirby* player) { mkirby = player; }

	private:
		Animator* mAnimator;
		Collider* mCollider;
		class Kirby* mkirby;
		class RigidBody* mRigidBody;
	};
}
