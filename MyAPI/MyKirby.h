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
			RightBeamIdle
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

		void SetState(eKirbyState mstate) { mState = mstate; }
		eKirbyState GetState() { return mState; }
		

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
		

		//void JumpCompleteEvent();

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
		bool DoubleJump;
		class AbsorbEffect* Absorb;
		class Waddle* mWaddle;
		class AbsorbLeftEffect* LeftAbsorb;
		bool yamyam;
	};
}

