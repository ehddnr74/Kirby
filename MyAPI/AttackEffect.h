#pragma once
#include "MyGameObject.h"
namespace My
{
	class Animator;
	class AttackEffect : public GameObject
	{
	public:
		enum class AttackState
		{
			Base,
			Attack,
			Beam,	
			Air,
			Dash,
			DashRelease,
		};

		AttackEffect();
		~AttackEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetEffectState(AttackState attackstate) { mState = attackstate; }

		void SetKirby(class Kirby* mk) { mkirby = mk; }

	private:
		void base();
		void attack();
		void beam();
		void air();
		void dash();
		void dashrelease();

	private:
		AttackState mState;
		Animator* mAnimator;
		Collider* mCollider;
		class Kirby* mkirby;

		double attacktime;

		bool BaseCheck;
		bool AttackCheck;
		bool BeamCheck;
		bool AirCheck;
		bool DashCheck;
		bool DashReleaseCheck;
	};
}
