#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{	
	class LeftEnergyBeam;
	class EnergyBeam;
	class KirbyBeam;
	class LeftKirbyBeam;
	class Twizzy;
	class Cappy;
	class Waddle;
	class BrontoBurt;
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
			LeftBeam,
			RightBeam,

			LeftHit,
			RightHit,

			LeftJumpHitRelease,
			LeftJumpHit,
			RightJumpHitRelease,
			RightJumpHit,
			LeftSlidingHit,
			RightSlidingHit,


			LeftAbsorbPigHit,
			RightAbsorbPigHit,
			LeftPigBaseHit,
			RightPigBaseHit,
			LeftPigJumpHitRelease,
			RightPigJumpHitRelease,
			LeftPigJumpHit,
			RightPigJumpHit,


			LeftBeamBaseHit,
			RightBeamBaseHit,
			LeftBeamJumpHitRelease,
			RightBeamJumpHitRelease,
			LeftBeamJumpHit,
			RightBeamJumpHit,
			LeftBeamPigHit,
			RightBeamPigHit,

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
		void leftbeam();
		void rightbeam();


		// Hit Animation
		void lefthit();
		void righthit();
		void leftjumphitrelease();
		void leftjumphit();
		void rightjumphitrelease();
		void rightjumphit();
		void leftslidinghit();
		void rightslidinghit();

		void leftpigbasehit();
		void rightpigbasehit();
		void leftpigjumphit();
		void rightpigjumphit();
		void leftpigjumphitrelease();
		void rightpigjumphitrelease();
		void leftabsorbpighit();
		void rightabsorbpighit();


		void leftbeambasehit();
		void rightbeambasehit();
		void leftbeamjumphitrelease();
		void rightbeamjumphitrelease();
		void leftbeamjumphit();
		void rightbeamjumphit();
		void leftbeampighit();
		void rightbeampighit();
		

	private:
		eKirbyState mState;
		Animator* mAnimator;
		RigidBody* mRigidBody;



		bool KeyCheck;
		bool PigKeyCheck;
		bool AbsorbCheck;
		bool IsJump;
		bool JumpCheck;
		bool DoubleJump;
		bool yamyam;
		bool BeamIsJump;
		bool BeamDoubleJump;
		bool AirShot;
		bool BeamAirShot;
		bool BeamKeyCheck;
		bool leftbase; // Idle, Move, Dash 검사 
		bool base;
		bool Leftsliding;
		bool sliding;
		bool Leftstar;
		bool star;
		bool GetMonster;
		bool starshot;
		bool StarCol; // 별충돌->맵전환
		bool jumpabsolb; // 점프한 상태에서 몬스터를 먹었을때 true가 됨
		bool beamuse;
		bool beamcharging;

		int Kirbydir;

		class AbsorbEffect* Absorb;
		class Waddle* mWaddle;
		class AbsorbLeftEffect* LeftAbsorb;
		class Star* mStar;
		class Ground* mGround;
		class StarMap* mStarMap;
		class Cappy* mCappy;
		class Twizzy* mTwizzy;
		class BrontoBurt* mBrontoBurt;
		class KirbyBeam* mKirbyBeam;
		class LeftKirbyBeam* mLeftKirbyBeam;
		class EnergyBeam* mEnergyBeam;
		class LeftEnergyBeam* mLeftEnergyBeam;

		double kirbytime;
		double beamkirbytime;
		double jumptime;
		double beamjumptime;
		double pigjumptime;
		double cleartime;
		double leftslidingtime;
		double slidingtime;
		double lefthittime;
		double righthittime;
		double jumphitreleasetime;
		double jumphittime;
		double leftdoublejumphittime;
		double rightdoublejumphittime;
		double lefthitpigbasetime;
		double righthitpigbasetime;
		double leftpigjumphitreleasetime;
		double rightpigjumphitreleasetime;

		double beamtime;
		double chargingtime;


		double beamjumphitreleasetime;
		double beamdoublejumphittime;
		










	};
}

