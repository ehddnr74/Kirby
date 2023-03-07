#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Animator;
	class Kirby : public GameObject
	{
	public:
		enum class eKirbyState
		{
			LeftMove,
			RightMove,
			LeftIdle,
			RightIdle,
			LeftSliding,
			RightSliding,
			Death,
			LeftAbsorb,
			RightAbsorb,
			LeftDash,
			RightDash,
			LeftCrouch,
			RightCrouch,
		};

		Kirby();
		~Kirby();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		void leftmove();
		void rightmove();
		void leftidle();
		void rightidle();
		void death();
		void sliding();
		void leftabsorb();
		void rightabsorb();
		void leftdash();
		void rightdash();
		void leftcrouch();
		void rightcrouch();
		void leftsliding();
		void rightsliding();

		void idleCompleteEvent();

	private:
		eKirbyState mState;
		Animator* mAnimator;
		double kirbytime;
		bool KeyCheck;
	};
}

