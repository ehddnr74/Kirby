#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class Cappy : public GameObject
	{
	public:
		enum class CappyState
		{
			LeftMove,
			RightMove,
			LeftJump,
			RightJump,
			HitAir,
			LeftHitAir,
			HitStar,
			CappyDeath,
			HitKirbyBase,
			LeftHitKirbyBase,
			HitSliding,
			HitSlidingLeft,
			HitBoom,
		};

	Cappy();
	~Cappy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		void SetDamage(int damage) { CappyHP -= damage; }
		int GetHP() { return CappyHP; }
 
		void SetDie(bool Die) { die = Die; }
		bool GetDie() { return die; }

		void SetGround3(class R3Ground* gg) { gr3 = gg; }
		class R3Ground* GetGround3() { return gr3; }


	private:
		void leftmove();
		void rightmove();
		void leftjump();
		void rightjump();

		void hitair();
		void hitleftair();
		void hitstar();
		void cappydeath();
		void hitkirbybase();
		void lefthitkirbybase();
		void hitsliding();
		void hitslidingleft();
		void hitboom();




	private:

		Animator* mAnimator;
		CappyState mState;
		class RigidBody* mRigidBody;
		double cappytime;
		double cjumptime;
		int cappydir;
		int CappyHP;


		double hitairtime;
		double hitstartime;

		double hitkirbybasetime;
		double hitslidingtime;

		double deathtime;


		class Air* mAir;
		class AirLeft* mAirLeft;
		class Star* mStar;
		class Kirby* mkirby;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;
		class R3Ground* gr3;
		class kirbyRightBoom* mKrb;
		class kirbyLeftBoom* mKlb;

		bool die;


	};
}
