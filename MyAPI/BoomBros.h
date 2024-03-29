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
			LeftBoomRelease,
			LeftBoomShot,


			// Hit Ani
			HitBoom,
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
		class LeftBoomb* GetLeftBoomb() { return mLeftBoomb; }

		void SetBoomb(class RightBoomb* rb) { mRightBoomb = rb; }
		class RightBoomb* GetBoomb() { return mRightBoomb; }

		

		void SetGround(class R2Ground* gr) { mGround = gr; }

		class R2Ground* GetGround() { return mGround; }


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

		//��ź �߻� 

		void rightboomrelease();
		void rightboomshot();
		void leftboomrelease();
		void leftboomshot();




		//Hit Ani
		void hitboom();


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
		class R2Ground* mGround;

		class kirbyRightBoom* mKrb;
		class kirbyLeftBoom* mKlb;

		class AttackEffect* mAttackEffect;


		double brostimetwo;

		double deathtime;
		bool death;

		bool find;
		bool boomcreate;
		bool BoomShot;

		double enemyfind;

		double boomreleasetime;
		double boomshotend;
		double boomwaiting;

		double leftboomshotend;
		double leftboomwaiting;
		double leftboomreleasetime;

		bool leftfind;
		bool leftBoomShot;
		bool leftBoomCreate;
		class AbsorbEffect* mAbsorbEffect;
		class AbsorbLeftEffect* mLeftAbsorbEffect;

		int a;
		int b;
	};
}
