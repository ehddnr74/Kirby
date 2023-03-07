#pragma once
#include "MyGameObject.h"
#include "Mytime.h"

namespace My
{
	class Animator;
	class Waddle : public GameObject
	{
	public:
		enum class WaddleState
		{
			LeftMove,
			RightMove,
			LeftBoomb,
			RightBoomb
		};

		Waddle();
		~Waddle();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
			void leftmove();
			void rightmove();
			void leftboomb();
			void rightboomb();

	private:
		WaddleState mState;
		Animator* mAnimator;
		double waddletime;
		int waddledir;
	};
}

