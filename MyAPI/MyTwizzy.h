#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class Twizzy : public GameObject
	{
	public:
		enum class TwizzyState
		{
			LeftIdle,
			RightIdle,
			LeftFly,
			RightFly
		};

		Twizzy();
		~Twizzy();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		void leftidle();
		void rightidle();
		void leftfly();
		void rightfly();

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDamage(int damage) { twizzyHP -= damage; }

	private:
		TwizzyState mState;
		Animator* mAnimator;
		double twizzytime;
		int twizzydir;
		int twizzyHP;
	};
}