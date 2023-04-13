#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{	
	class Beam;
	class LeftBeam;
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
			// �⺻ Ŀ��
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
			//�⺻ Ŀ��


			// ��Ŀ��
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
			//��Ŀ��

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

			LeftBeamHit, //�͵��
			RightBeamHit, //�¾��� ��
			LBJHR,
			RBJHR,
			LBJH,
			RBJH,
			LPBJHR,
			LPBJH,
			RPBJHR,
			RPBJH,

			//��ź Ŀ��
			LeftBoombIdle,
			RightBoombIdle,
			LeftBoombWalk,
			RightBoombWalk,
			LeftBoombTransform,
			BoombTransform,
			LeftBoombDash,
			RightBoombDash,
			LeftBoombDashRelease,
			RightBoombDashRelease,
			LeftBoombCrouch,
			RightBoombCrouch,
			LeftBoombSliding,
			RightBoombSliding,
			LeftBoombJump,
			RightBoombJump,
			LeftBoombDoubleJump,
			RightBoombDoubleJump,

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




		void SetDamage(int damage) { KirbyHP -= damage; }
		void SetHill(int hp) { KirbyHP += hp; }

		void SetHP(int hp) { KirbyHP = hp; }
		int GetHP() { return KirbyHP; }

		bool GetLeftJumpAbsorbing() { return leftjumpabsorbing; }
		bool GetJumpAbsorbing() { return jumpabsorbing; }

		bool GetJumpingBeam() { return beamjumping; }

		void SetGround(class Ground* ground) { mGround = ground; }

		void SetState(eKirbyState mstate) { mState = mstate; }
		eKirbyState GetState() { return mState; }

		void SetJump(bool isjump) { IsJump = isjump; }
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

		void SetStage2(class Stage2Scene* scene) { mstage2 = scene; }

		Kirby* GetKirby() { return this; }
		


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

		void leftbeamhit(); // �͵��
		void rightbeamhit(); // �¾��� ��
		void lbjhr();
		void lbjh();
		void rbjhr();
		void rbjh();
		void lpbjhr();
		void lpbjh();
		void rpbjhr();
		void rpbjh();


		//�� Ŀ��
		void leftboombidle();
		void rightboombidle();
		void leftboombwalk();
		void rightboombwalk();
		void boombtransform();
		void leftboombtransform();
		void leftboombdash();
		void rightboombdash();
		void leftboombdashrelease();
		void rightboombdashrelease();
		void leftboombcrouch();
		void rightboombcrouch();
		void leftboombsliding();
		void rightboombsliding();
		void leftboombjump();
		void rightboombjump();
		void leftboombdoublejump();
		void rightboombdoublejump();

		

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
		bool leftbase; // Idle, Move, Dash �˻� 
		bool base;
		bool Leftsliding;
		bool sliding;
		bool Leftstar;
		bool star;
		bool GetMonster;
		bool starshot;
		bool StarCol; // ���浹->����ȯ
		bool jumpabsolb; // ������ ���¿��� ���͸� �Ծ����� true�� ��
		bool beamuse;
		bool beamcharging;
		bool jumpabsorbing;
		bool leftjumpabsorbing;

		bool boomyamyam;

		int Kirbydir;

		class Stage2Scene* mstage2;
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
		class Beam* mBeam;
		class LeftBeam* mLeftBeam;
		class Bros* mBros;

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
		double Ljumptime;
		double Rjumptime;

		double beamtime;
		double leftbeamtime;
		double chargingtime;


		double beamjumphitreleasetime;
		double beamdoublejumphittime;
		

		double deathtime; //�ӽ�
		
		double wbeamhittime; //�͵��
		double lwbeamhittime; // �¾��� ��


		bool beamjumping; //�ӽ�
		bool LRjumpchange;
		bool RLjumpchange;

		int Damage;
		int KirbyHP;

		double jatime; //�ӽ�

		//��Ŀ��

		double boombkirbytime;
		bool BoombKeyCheck;
		double boombjumptime;
		bool BoombIsJump;
		bool BoombAirShot;
		bool boombjumping;
		bool BoombDoubleJump;


	};
}

