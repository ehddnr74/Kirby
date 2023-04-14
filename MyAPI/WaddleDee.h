#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class WaddleDee : public GameObject
	{
	public:
		enum class WaddleDeeState
		{
			LeftMove,
			RightMove,
		};

		WaddleDee();
		~WaddleDee();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		//void SetDamage(int damage) { WaddleDeeHP -= damage; }
		//int GetHP() { return WaddleDeeHP; }

		//void SetDie(bool Die) { die = Die; }
		//bool GetDie() { return die; }


	private:
		void leftmove();
		void rightmove();





	private:

		Animator* mAnimator;
		WaddleDeeState mState;
		//class RigidBody* mRigidBody;
		//double waddledeetime;
		//double Wjumptime;
		//int WaddleDeedir;
		//int WaddleDeeHP;


		//double hitairtime;
		//double hitstartime;

		//double hitkirbybasetime;
		//double hitslidingtime;

		//double deathtime;


		//class Air* mAir;
		//class AirLeft* mAirLeft;
		//class Star* mStar;
		//class Kirby* mkirby;
		//class KirbyBeam* mKirbyBeam;
		//class LeftKirbyBeam* mLeftKirbyBeam;
		//class EnergyBeam* mEnergyBeam;
		//class LeftEnergyBeam* mLeftEnergyBeam;
		//class LeftBooomb* mLeftBoomb;
		//class RightBoomb* mRightBoomb;

		//bool die;


	};
}