#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{	
	class Waddle;
	class RigidBody;
	class Animator;
	class Kirby : public GameObject
	{
	public:
		enum class eKirbyState
		{
			LeftMove,
			RightMove,
			LeftIdle,
			RightIdle,
			LeftSliding,
			RightSliding,
			Death,
			LeftAbsorb,
			RightAbsorb,
			LeftColAbsorb,
			RightColAbsorb,
			LeftAbsorbPig,
			RightAbsorbPig,
			LeftPigIdle,
			RightPigIdle,
			LeftPigWalk,
			RightPigWalk,
			LeftPigJump,
			RightPigJump,
			LeftPigDash,
			RightPigDash,
			LeftPigDashRelease,
			RightPigDashRelease,

			LeftPigClear,
			RightPigClear,
			LeftDash,
			RightDash,
			LeftDashRelease,
			RightDashRelease,
			LeftCrouch,
			RightCrouch,
			LeftJump,
			RightJump,
			LeftDoubleJump,
			RightDoubleJump,


			LeftBeamTransform,
			BeamTransform,
			LeftBeamIdle,
			RightBeamIdle,
			LeftBeamWalk,
			RightBeamWalk,
			LeftBeamCrouch,
			RightBeamCrouch,
			LeftBeamSliding,
			RightBeamSliding,
			LeftBeamJump,
			RightBeamJump,
			LeftBeamDoubleJump,
			RightBeamDoubleJump,
			LeftBeamDash,
			RightBeamDash,
			LeftBeamDashRelease,
			RightBeamDashRelease,

			LeftHit,
			RightHit,

			LeftJumpHitRelease,
			LeftJumpHit,
			RightJumpHitRelease,
			RightJumpHit,
			LeftSlidingHit,
			RightSlidingHit

		};

		Kirby();
		~Kirby();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


		void SetGround(class Ground* ground) { mGround = ground; }

		void SetState(eKirbyState mstate) { mState = mstate; }
		eKirbyState GetState() { return mState; }

		bool GetJump() { return JumpCheck; }

		void setSliding(bool slid) { sliding = slid; }
		bool GetSliding() { return sliding; }
		void setLeftSliding(bool sli) { Leftsliding = sli; }
		bool GetLeftSliding() { return Leftsliding; }

		void SetStar(bool Star) { star = Star; }
		bool GetStar() { return star; }
		void SetLeftStar(bool leftStar) { Leftstar = leftStar; }
		bool GetLeftStar() { return Leftstar; }

		bool GetStarCol() { return StarCol; }

	private:
		void leftmove();
		void rightmove();
		void leftidle();
		void rightidle();
		void death();
		void leftabsorb();
		void rightabsorb();
		void leftcolabsorb();
		void rightcolabsorb();



		void leftabsorbpig();
		void rightabsorbpig();
		void leftpigidle();
		void rightpigidle();
		void leftpigclear();
		void rightpigclear();
		void leftpigwalk();
		void rightpigwalk();
		void leftpigjump();
		void rightpigjump();
		void leftpigdash();
		void rightpigdash();
		void leftpigdashrelease();
		void rightpigdashrelease();


		void leftdash();
		void rightdash();
		void leftdashrelease();
		void rightdashrelease();
		void leftcrouch();
		void rightcrouch();
		void leftsliding();
		void rightsliding();
		void leftjump();
		void rightjump();
		void leftdoublejump();
		void rightdoublejump();
		

		void leftbeamtransform();
		void beamtransform();
		void leftbeamidle();
		void rightbeamidle();
		void leftbeamwalk();
		void rightbeamwalk();
		void leftbeamcrouch();
		void rightbeamcrouch();
		void leftbeamsliding();
		void rightbeamsliding();
		void leftbeamjump();
		void rightbeamjump();
		void leftbeamdoublejump();
		void rightbeamdoublejump();
		void leftbeamdash();
		void rightbeamdash();
		void leftbeamdashrelease();
		void rightbeamdashrelease();


		// Hit Animation
		void lefthit();
		void righthit();

		void leftjumphitrelease();
		void leftjumphit();
		void rightjumphitrelease();
		void rightjumphit();
		void leftslidinghit();
		void rightslidinghit();

		

	private:
		eKirbyState mState;
		Animator* mAnimator;
		double kirbytime;
		bool KeyCheck;
		bool PigKeyCheck;
		int Kirbydir;
		bool AbsorbCheck;
		RigidBody* mRigidBody;
		double jumptime;
		bool IsJump;
		bool JumpCheck;
		bool DoubleJump;
		class AbsorbEffect* Absorb;
		class Waddle* mWaddle;
		class AbsorbLeftEffect* LeftAbsorb;
		class Star* mStar;
		bool yamyam;
		double beamkirbytime;
		bool BeamIsJump;
		bool BeamDoubleJump;
		bool AirShot;
		bool BeamAirShot;
		bool BeamKeyCheck;
		double beamjumptime;
		double pigjumptime;
		class Ground* mGround;
		bool Leftsliding;
		bool sliding;
		bool Leftstar;
		bool star;
		double cleartime;
		bool GetMonster;
		bool starshot;
		double leftslidingtime;
		double slidingtime;
		class StarMap* mStarMap;


		double lefthittime;
		double righthittime;

		double jumphitreleasetime;
		double jumphittime;





		bool StarCol; // 별충돌->맵전환
	};
}

