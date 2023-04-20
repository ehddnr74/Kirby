#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class TreeBoss : public GameObject
	{
	public:
		enum class TreeState
		{
			None,
			Apple,
			Breath,
			Death,
		};

		TreeBoss();
		~TreeBoss();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		void SetDamage(int damage) { TreeHP -= damage; }
		int GetHP() { return TreeHP; }

		void SetGround(class TreeGround* tg) { mTreeGround = tg; }

		void SetKirby(class Kirby* kirby) { mKirby = kirby; }




	private:
		void none();
		void apple();
		void breath();
		void death();






	private:

		Animator* mAnimator;
		TreeState mState;
		class Collider* mCollider;
		class kirbyRightBoom* mkrb;
		class kirbyLeftBoomb* mklb;
		class TreeGround* mTreeGround;
		class Star* mStar;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;
		class Breath* mBreath;
		class Apple* mApple;
		class Apple* mApple2;
		class Kirby* mKirby;
		int TreeHP;

		double breathtime;
		double hittime;

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


		class kirbyRightBoom* mKrb;
		class kirbyLeftBoom* mKlb;
		double treetime;
		bool hit;
		double breathreleasetime;
		int BreathCount;

		double appletime;
		double airtime;


		int AppleCount;
		double applet;
		double applereleasetime;

		bool AppleUse;
	};
}
