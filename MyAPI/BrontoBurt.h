#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class BrontoBurt : public GameObject
	{
	public:
		enum class BrontoBurtState
		{
			None,
			LeftFly,
			Charging,
			HitAir,
			LeftHitAir,
			HitStar,
			HitKirbyBase,
			LeftHitKirbyBase,
			Death

		};

		BrontoBurt();
		~BrontoBurt();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDamage(int damage) { brontoburtHP -= damage; }


		void SetPlayer(class Kirby* Player) { mkirby = Player; }

	private:
		void none();
		void leftfly();
		void charging();
		void hitair();
		void hitleftair();
		void hitstar();
		void hitkirbybase();
		void lefthitkirbybase();
		void death();

		



	private:
		Animator* mAnimator;
		BrontoBurtState mState;




		double brontoburttime;
		double chargindtime;
		double deathtime;
		double hitkirbybasetime;
		double hitairtime;
		double hitstartime;


		bool Check;
	

		int brontoburtdir;
		int brontoburtHP;



		class RigidBody* mRigidBody;
		class Air* mAir;
		class AirLeft* mAirLeft;
		class Star* mStar;
		class Kirby* mkirby;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;

	};
}