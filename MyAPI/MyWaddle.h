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
			LeftBeam,
			RightBeam,
			HitAir,
			HitLeftAir,
			WaddleDeath,
			HitKirbyBase, // Idle, Move, Dash에 맞았을때 !
			LeftHitKirbyBase,
			HitSliding,
			HitSlidingLeft,
			HitStar,
			HitBoom,
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

		void SetGround(class R3Ground* gr) { mGround = gr; }
		class R3Ground* GetGround() { return mGround; }

		int GetHP() { return WaddleHP; }


	private:
			void leftmove();
			void rightmove();
			void leftboomb();
			void rightboomb();
			void leftbeam();
			void rightbeam();
			void hitair();
			void hitleftair();
			void waddleDeath();
			void hitkirbybase();
			void lefthitkirbybase();
			void hitsliding();
			void hitslidingleft();
			void hitstar();
			void hitboom();
	private:
		WaddleState mState;
		Animator* mAnimator;

		double rightwaddletime;
		double waddletime;
		double hitairtime;
		double hitslidingtime;
		double hitstartime;
		double hitkirbybasetime;

		double boombtime;
		double beamtime;



		int waddledir;
		int Damage;
		int WaddleHP;

		bool beamuse;

		class Air* mAir;
		class AirLeft* mAirLeft;
		class Kirby* mkirby;
		class Star* mStar;
		class Beam* mBeam;
		class LeftBeam* mLeftBeam;
		class kirbyRightBoom* mKrb;
		class kirbyLeftBoom* mKlb;
		class R3Ground* mGround;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;
		class AttackEffect* mAttackEffect;
		class AbsorbEffect* mAbsorbEffect;
		class AbsorbLeftEffect* mLeftAbsorbEffect;


		int a;
		int b;

	};
}

