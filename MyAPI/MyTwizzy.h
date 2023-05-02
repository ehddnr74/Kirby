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
			//LeftIdle,
			//RightIdle,
			LeftFly,
			RightFly,
			HitAir,
			LeftHitAir,
			HitStar,
			TwizzyDeath,
			HitKirbyBase,
			LeftHitKirbyBase,
			HitSliding,
			HitSlidingLeft
		};


		Twizzy();
		~Twizzy();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDamage(int damage) { twizzyHP -= damage; }
		TwizzyState GetState() { return mState; }

		int GetHP() { return twizzyHP; }
		


	private:
		//void leftidle();
		//void rightidle();
		void leftfly();
		void rightfly();
		void hitair();
		void hitleftair();
		void hitstar();
		void twizzydeath();
		void hitkirbybase();
		void lefthitkirbybase();
		void hitsliding();
		void hitslidingleft();


	private:
		TwizzyState mState;
		Animator* mAnimator;



		double twizzytime;
		double righttiwzzytime;
		double hitairtime;
		double hitstartime;

		double hitkirbybasetime;
		double hitslidingtime;

	




		int twizzydir;
		int twizzyHP;
		

		class RigidBody* mRigidBody;
		class Air* mAir;
		class AirLeft* mAirLeft;
		class Star* mStar;
		class Kirby* mkirby;
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