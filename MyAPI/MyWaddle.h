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
			RightBoomb,
			HitAir,
			HitLeftAir,
			WaddleDeath,
			HitSliding,
			HitSlidingLeft,
			HitStar
		};

		Waddle();
		~Waddle();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		void SetState(WaddleState mstate) { mState = mstate; }
		WaddleState GetState() { return mState; }
		void SetDamage(int damage) { WaddleHP -= damage; }
		void SetPlayer(class Kirby* player) { mkirby = player; }

	private:
			void leftmove();
			void rightmove();
			void leftboomb();
			void rightboomb();
			void hitair();
			void hitleftair();
			void waddleDeath();
			void hitsliding();
			void hitslidingleft();
			void hitstar();

	private:
		WaddleState mState;
		Animator* mAnimator;
		double waddletime;
		int waddledir;
		int Damage;
		int WaddleHP;
		class Air* mAir;
		double hitairtime;
		class AirLeft* mAirLeft;
		class Kirby* mkirby;
		class Star* mStar;
		double hitslidingtime;
		double hitstartime;
	};
}

