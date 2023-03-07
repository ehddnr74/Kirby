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

	private:
		TwizzyState mState;
		Animator* mAnimator;
		double twizzytime;
		int twizzydir;
	};
}