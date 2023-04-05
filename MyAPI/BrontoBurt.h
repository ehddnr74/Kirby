#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class BrontoBurt : public GameObject
	{
	public:
		enum class BrontoBurtState
		{
			LeftFly,
			Charging
		};

		BrontoBurt();
		~BrontoBurt();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDamage(int damage) { brontoburtHP -= damage; }


	private:
		void leftfly();
		void charging();



	private:

		Animator* mAnimator;
		BrontoBurtState mState;
		double brontoburttime;
		int brontoburtdir;
		int brontoburtHP;


	};
}