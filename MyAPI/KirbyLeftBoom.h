#pragma once
#include "MyGameObject.h"
namespace My
{
	class Animator;
	class kirbyLeftBoom : public GameObject
	{
	public:
		kirbyLeftBoom();
		~kirbyLeftBoom();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetGround(class R2Ground* gr) { mGround = gr; }
		class R2Ground* GetGround() { return mGround; }

	private:
		Animator* mAnimator;
		Collider* mCollider;
		class Kirby* mkirby;
		class RigidBody* mRigidBody;
		class Explosion* mExplosion;

		class R2Ground* mGround;
	};
}