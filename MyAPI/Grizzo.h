#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class Grizzo : public GameObject
	{
	public:
		enum class GrizzoState
		{
			LeftMove,
			RightMove,
			Death,
			HitBoom,
			HitKirbyBase,
			LeftHitKirbyBase,
			HitSliding,
			HitSlidingLeft,
			HitStar,
		};

		Grizzo();
		~Grizzo();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		void SetDamage(int damage) { GrizzoHP -= damage; }
		int GetHP() { return GrizzoHP; }

		void SetGround(class R2Ground* gr) { mGround = gr; }
		class R2Ground* GetGround() { return mGround; }

		void SetGround3(class R3Ground* gg) { gr3 = gg; }
		class R3Ground* GetGround3() { return gr3; }
		//void SetDie(bool Die) { die = Die; }
		//bool GetDie() { return die; }


	private:
		void leftmove();
		void rightmove();
		void death();
		void hitkirbybase();
		void lefthitkirbybase();
		void hitsliding();
		void hitslidingleft();
		void hitstar();
		void hitboom();





	private:

		Animator* mAnimator;
		GrizzoState mState;
		class Collider* mCollider;
		class Air* mAir;
		class AirLeft* mAirLeft;
		class Kirby* mkirby;
		class Star* mStar;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;
		//class RigidBody* mRigidBody;
		//double Grizzotime;
		//double Gjumptime;
		int grizzodir;
		int GrizzoHP;


		double hitairtime;
		double hitstartime;

		double hitkirbybasetime;
		double hitslidingtime;

		double deathtime;

		class R2Ground* mGround;
		class R3Ground* gr3;
		class kirbyRightBoom* mKrb;
		class kirbyLeftBoom* mKlb;
		class AttackEffect* mAttackEffect;

		double grizzotime;
		class AbsorbEffect* mAbsorbEffect;
		class AbsorbLeftEffect* mLeftAbsorbEffect;

		int a;
		int b;


	};
}
