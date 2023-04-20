#pragma once
#include "MyGameObject.h"
namespace My
{
	class Animator;
	class Apple : public GameObject
	{
	public:
		enum class AppleState
		{
			Gravity,
			RightRotation,
			LeftRotation,
		};

		Apple();
		~Apple();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetRotation(AppleState mstate) { mState = mstate; }

		void Setnum(int n) { num = n; }
		
		//void SetTree(TreeBoss* mtree) { mTree = mtree; }

		void SetGround(class TreeGround* mground) { mGround = mground; }

	private:
		void gravity();
		void rightrotation();
		void leftrotation();

	private:
		AppleState mState;
		Animator* mAnimator;
		Collider* mCollider;
		//class TreeBoss* mTree;
		class Kirby* mkirby;
		class RigidBody* mRigidBody;
		class TreeGround* mGround;
		class Explosion* mExplosion;
		class AbsorbEffect* mAbsorbEffect;
		class AbsorbLeftEffect* mAbsorbLeftEffect;


		int num;
		bool Check;
	};
}
