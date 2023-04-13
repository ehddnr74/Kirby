#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class BoomBros : public GameObject
	{
	public:
		enum class BrosState
		{
			LeftIdle,
			RightIdle,
			HitAir,
			LeftHitAir,
			HitStar,
			BrosDeath,
			HitKirbyBase,
			LeftHitKirbyBase,
			HitSliding,
			HitSlidingLeft,
			RightBoomRelease,
			RightBoomShot,
		};


		BoomBros();
		~BoomBros();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDamage(int damage) { brosHP -= damage; }
		int GetHP() { return brosHP; }

		void SetDeath(bool die) { death = die; }
		bool GetDeath() { return death; }

		void SetKirby(class Kirby* kirby) { mkirby = kirby; }

		void SetLeftBoomb(class LeftBoomb* lb) { mLeftBoomb = lb; }
		void SetBoomb(class RightBoomb* rb) { mRightBoomb = rb; }





	private:
		void leftidle();
		void rightidle();
		void hitair();
		void hitleftair();
		void hitstar();
		void brosdeath();
		void hitkirbybase();
		void lefthitkirbybase();
		void hitsliding();
		void hitslidingleft();

		//ÆøÅº ¹ß»ç 

		void rightboomrelease();
		void rightboomshot();


	private:
		BrosState mState;
		Animator* mAnimator;



		double brostime;
		double rightbrostime;
		double hitairtime;
		double hitstartime;

		double hitkirbybasetime;
		double hitslidingtime;

		int brosdir;
		int brosHP;


		class RigidBody* mRigidBody;
		class Air* mAir;
		class AirLeft* mAirLeft;
		class Star* mStar;
		class Kirby* mkirby;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;
		class RightBoomb* mRightBoomb;
		class LeftBoomb* mLeftBoomb;


		double brostimetwo;

		double deathtime;
		bool death;

		bool boomcreate;
		double boomreleasetime;
		bool BoomShot;
	};
}
