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
		void SetGround(class R2Ground* gr) { mGround = gr; }
		class R2Ground* GetGround() { return mGround; }

		void SetDestroy(bool destroy) { Destroy = destroy; }
		bool GetDestroy() { return Destroy; }

		void SetBoomBros(class BoomBros* bb) { mBoomBros = bb; }

		//void SetExplosion(class Explosion* exp) { mExplosion = exp; }


	private:
		Animator* mAnimator;
		Collider* mCollider;
		class Kirby* mkirby;
		class RigidBody* mRigidBody;
		class R2Ground* mGround;
		class Explosion* mExplosion;
		class BoomBros* mBoomBros;
		bool Destroy;
	};
}
