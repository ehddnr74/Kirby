#include "MyKirby.h"
#include "MyTime.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"
#include "AbsorbEffect.h"
#include "AbsorbLeftEffect.h"
#include "MyRigidBody.h"
#include "Air.h"
#include "AirLeft.h"
#include "Stage1_1.h"
#include "MyWaddle.h"
#include "MyCappy.h"
#include "MyTwizzy.h"
#include "R1Ground.h"
#include "R2Ground.h"
#include "Star.h"
#include "StarMap.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "BrontoBurt.h"

namespace My
{
	Kirby::Kirby()
		: kirbytime(0.0f)
		, KeyCheck(false)
		, Kirbydir(0)
		, AbsorbCheck(false)
		, jumptime(0.0f)
		, IsJump(false)
		, DoubleJump(false)
		, yamyam(false)
		, PigKeyCheck(false)
		, beamkirbytime(false)
		, BeamIsJump(false)
		, BeamDoubleJump(false)
		, AirShot(false)
		, BeamAirShot(false)
		, BeamKeyCheck(false)
		, JumpCheck(false)
		, beamjumptime(0.0f)
		, pigjumptime(0.0f)
		, sliding(false)
		, Leftsliding(false)
		, Leftstar(false)
		, star(false)
		, cleartime(0.f)
		, GetMonster(false)
		, starshot(false)
		, leftslidingtime(0.f)
		, slidingtime(0.f)
		, lefthittime(0.f)
		, righthittime(0.f)
		, jumphitreleasetime(0.f)
		, jumphittime(0.f)
		, StarCol(false)
		, rightdoublejumphittime(0.f)
		, leftdoublejumphittime(0.f)
		, base(false)
		, leftbase(false)
		, righthitpigbasetime(0.f)
		, lefthitpigbasetime(0.f)
		, leftpigjumphitreleasetime(0.f)
		, rightpigjumphitreleasetime(0.f)
		, beamjumphitreleasetime(0.f)
		, beamdoublejumphittime(0.f)
		, jumpabsolb(false)
		, beamtime(0.f)
		, chargingtime(0.f)
		,  beamuse(true)
	    , beamcharging(false)

	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(30.0f, 310.0f));
		//tr->SetScale(Vector2(2.0f, 2.0f));


		Image* mKirby = Resources::Load<Image>(L"Kirby", L"..\\Resources\\Kirby.bmp");


		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimation(L"LeftIdle", mKirby, Vector2(240.0f, 0.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftWalk", mKirby, Vector2(0.0f, 80.0f), 16, 100, 10, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftAbsorbing", mKirby, Vector2(80.0f, 120.0f), 16, 100, 3, Vector2::Zero, 0.07);
		mAnimator->CreateAnimation(L"LeftDash", mKirby, Vector2(0.0f, 160.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftCrouch", mKirby, Vector2(240.0f, 200.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftSliding", mKirby, Vector2(480.0f, 200.0f), 16, 100, 1, Vector2::Zero, 0.5);
		mAnimator->CreateAnimation(L"LeftJumpFirst", mKirby, Vector2(0.0f, 360.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftJump", mKirby, Vector2(0.0f, 360.0f), 16, 100, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftJumpRelease", mKirby, Vector2(160.0f, 320.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftDoubleJump", mKirby, Vector2(0.0f, 320.0f), 16, 100, 7, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftAir", mKirby, Vector2(0.0f, 440.0f), 16, 100, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftDashRelease", mKirby, Vector2(320.0f, 280.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftAbsorbPig", mKirby, Vector2(160.0f, 480.0f), 16, 100, 4, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftPigIdle", mKirby, Vector2(0.0f, 520.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftPigWalk", mKirby, Vector2(0.0f, 600.0f), 16, 100, 10, Vector2::Zero, 0.08);
		mAnimator->CreateAnimation(L"LeftPigJump", mKirby, Vector2(280.0f, 640.0f), 16, 100, 6, Vector2::Zero, 0.08);
		mAnimator->CreateAnimation(L"LeftPigClear", mKirby, Vector2(160.0f, 680.0f), 16, 100, 4, Vector2::Zero, 0.01);
		mAnimator->CreateAnimation(L"LeftPigDashRelease", mKirby, Vector2(440.0f, 640.0f), 16, 100, 1, Vector2::Zero, 0.3);


		mAnimator->CreateAnimation(L"RightIdle", mKirby, Vector2::Zero, 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightWalk", mKirby, Vector2(0.0f, 40.0f), 16, 100, 10, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightAbsorbing", mKirby, Vector2(400.0f, 120.0f), 16, 100, 3, Vector2::Zero, 0.07);
		mAnimator->CreateAnimation(L"RightDash", mKirby, Vector2(320.0f, 160.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightCrouch", mKirby, Vector2(0.0f, 200.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightSliding", mKirby, Vector2(520.0f, 200.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightJumpFirst", mKirby, Vector2(0.0f, 240.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightJump", mKirby, Vector2(0.0f, 240.0f), 16, 100, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightJumpAbsorb", mKirby, Vector2(0.0f, 280.0f), 16, 100, 4, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightJumpRelease", mKirby, Vector2(160.0f, 280.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightDoubleJump", mKirby, Vector2(0.0f, 280.0f), 16, 100, 7, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightAir", mKirby, Vector2(0.0f, 400.0f), 16, 100, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightDashRelease", mKirby, Vector2(280.0f, 280.0f), 16, 100, 1, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightAbsorbPig", mKirby, Vector2(0.0f, 480.0f), 16, 100, 4, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightPigIdle", mKirby, Vector2(320.0f, 520.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightPigWalk", mKirby, Vector2(0.0f, 560.0f), 16, 100, 10, Vector2::Zero, 0.08);
		mAnimator->CreateAnimation(L"RightPigJump", mKirby, Vector2(0.0f, 640.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightPigClear", mKirby, Vector2(0.0f, 680.0f), 16, 100, 4, Vector2::Zero, 0.01);
		mAnimator->CreateAnimation(L"RightPigDashRelease", mKirby, Vector2(160.0f, 640.0f), 16, 100, 1, Vector2::Zero, 0.3);


		mAnimator->CreateAnimation(L"LeftBeamTransform", mKirby, Vector2(0.0f, 760.0f), 16, 100, 10, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamIdle", mKirby, Vector2(240.0f, 800.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftBeamWalk", mKirby, Vector2(0.0f, 880.0f), 16, 100, 12, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBeamCrouch", mKirby, Vector2(240.0f, 920.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftBeamSliding", mKirby, Vector2(80.0f, 960.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBeamJump", mKirby, Vector2(0.0f, 1120.0f), 16, 100, 10, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamDoubleJump", mKirby, Vector2(0.0f, 1040.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamJumpRelease", mKirby, Vector2(200.0f, 1040.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamAir", mKirby, Vector2(0.0f, 1200.0f), 16, 100, 11, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamDash", mKirby, Vector2(0.0f, 1280.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamDashRelease", mKirby, Vector2(320.0f, 1280.0f), 16, 100, 1, Vector2::Zero, 0.05);



		mAnimator->CreateAnimation(L"RightBeamTransform", mKirby, Vector2(0.0f, 720.0f), 16, 100, 10, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamIdle", mKirby, Vector2(0.0f, 800.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBeamWalk", mKirby, Vector2(0.0f, 840.0f), 16, 100, 12, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBeamCrouch", mKirby, Vector2(0.0f, 920.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBeamSliding", mKirby, Vector2(0.0f, 960.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBeamJump", mKirby, Vector2(0.0f, 1080.0f), 16, 100, 10, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamDoubleJump", mKirby, Vector2(0.0f, 1000.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamJumpRelease", mKirby, Vector2(200.0f, 1000.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamAir", mKirby, Vector2(0.0f, 1160.0f), 16, 100, 11, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamDash", mKirby, Vector2(0.0f, 1240.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamDashRelease", mKirby, Vector2(320.0f, 1240.0f), 16, 100, 1, Vector2::Zero, 0.05);

		
		// HitAnimation

		mAnimator->CreateAnimation(L"LeftHit", mKirby, Vector2(0.0f, 1360.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftJumpHitRelease", mKirby, Vector2(240.0f, 1360.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftJumpHit", mKirby, Vector2(0.0f, 1360.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftAbsorbPigHit", mKirby, Vector2(120.0f, 1400.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftPigJumpHit", mKirby, Vector2(0.0f, 1440.0f), 16, 100, 4, Vector2::Zero, 0.05);


		mAnimator->CreateAnimation(L"RightHit", mKirby, Vector2(0.0f, 1320.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightJumpHitRelease", mKirby, Vector2(240.0f, 1320.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightJumpHit", mKirby, Vector2(0.0f, 1320.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightAbsorbPigHit", mKirby, Vector2(0.0f, 1400.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightPigJumpHit", mKirby, Vector2(160.0f, 1440.0f), 16, 100, 4, Vector2::Zero, 0.05);



		// BeamKirby HitAnimation

		mAnimator->CreateAnimation(L"LeftBeamKirbyHit", mKirby, Vector2(0.0f, 1520.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamJumpHitRelease", mKirby, Vector2(40.0f, 1560.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamJumpHit", mKirby, Vector2(0.0f, 1520.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeamDoubleJumpHit", mKirby, Vector2(200.0f, 1560.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBeam", mKirby, Vector2(40.0f, 1600.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftEnergyBeam", mKirby, Vector2(120.0f, 1600.0f), 16, 100, 1, Vector2::Zero, 0.05);

		mAnimator->CreateAnimation(L"RightBeamKirbyHit", mKirby, Vector2(0.0f, 1480.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamJumpHitRelease", mKirby, Vector2(0.0f, 1560.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamJumpHit", mKirby, Vector2(0.0f, 1480.0f), 16, 100, 6, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeamDoubleJumpHit", mKirby, Vector2(80.0f, 1560.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBeam", mKirby, Vector2(0.0f, 1600.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightEnergyBeam", mKirby, Vector2(80.0f, 1600.0f), 16, 100, 1, Vector2::Zero, 0.05);




		//mAnimator->CreateAnimation(L"RightAirRelease", mKirby, Vector2(160.0f, 400.0f), 16, 16, 8, Vector2::Zero, 0.05);
		


		mAnimator->Play(L"RightIdle", true);

		//mAnimator->GetCompleteEvent(L"RightJumpAbsorb") = std::bind(&Kirby::JumpCompleteEvent,this);


		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-23.0f, -64.0f));
		collider->SetSize(Vector2(50.0f, 46.0f));

		mRigidBody = AddComponent<RigidBody>();
		mRigidBody->SetMass(1.0f);
		//mRigidBody->SetGravity(Vector2(0.0f, 70.0f));

		mState = eKirbyState::RightIdle;

		GameObject::Initialize();
	}
	void Kirby::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case My::Kirby::eKirbyState::LeftMove:
			leftmove();
			break;
		case My::Kirby::eKirbyState::RightMove:
			rightmove();
			break;
		case My::Kirby::eKirbyState::LeftIdle:
			leftidle();
			break;
		case My::Kirby::eKirbyState::RightIdle:
			rightidle();
		case My::Kirby::eKirbyState::Death:
			death();
			break;
		case My::Kirby::eKirbyState::LeftAbsorb:
			leftabsorb();
			break;
		case My::Kirby::eKirbyState::RightAbsorb:
			rightabsorb();
			break;
		case My::Kirby::eKirbyState::LeftColAbsorb:
			leftcolabsorb();
			break;
		case My::Kirby::eKirbyState::RightColAbsorb:
			rightcolabsorb();
			break;
		case My::Kirby::eKirbyState::LeftAbsorbPig:
			leftabsorbpig();
			break;
		case My::Kirby::eKirbyState::RightAbsorbPig:
			rightabsorbpig();
			break;
		case My::Kirby::eKirbyState::LeftPigIdle:
			leftpigidle();
			break;
		case My::Kirby::eKirbyState::RightPigIdle:
			rightpigidle();
			break;
		case My::Kirby::eKirbyState::LeftPigWalk:
			leftpigwalk();
			break;
		case My::Kirby::eKirbyState::RightPigWalk:
			rightpigwalk();
			break;
		case My::Kirby::eKirbyState::LeftPigJump:
			leftpigjump();
			break;
		case My::Kirby::eKirbyState::RightPigJump:
			rightpigjump();
			break;
		case My::Kirby::eKirbyState::LeftPigDash:
			leftpigdash();
			break;
		case My::Kirby::eKirbyState::RightPigDash:
			rightpigdash();
			break;
		case My::Kirby::eKirbyState::LeftPigClear:
			leftpigclear();
			break;
		case My::Kirby::eKirbyState::RightPigClear:
			rightpigclear();
			break;
		case My::Kirby::eKirbyState::LeftPigDashRelease:
			leftpigdashrelease();
			break;
		case My::Kirby::eKirbyState::RightPigDashRelease:
			rightpigdashrelease();
			break;
		case My::Kirby::eKirbyState::LeftDash:
			leftdash();
			break;
		case My::Kirby::eKirbyState::RightDash:
			rightdash();
			break;
		case My::Kirby::eKirbyState::LeftDashRelease:
			leftdashrelease();
			break;
		case My::Kirby::eKirbyState::RightDashRelease:
			rightdashrelease();
			break;
		case My::Kirby::eKirbyState::LeftCrouch:
			leftcrouch();
			break;
		case My::Kirby::eKirbyState::RightCrouch:
			rightcrouch();
			break;
		case My::Kirby::eKirbyState::LeftSliding:
			leftsliding();
			break;
		case My::Kirby::eKirbyState::RightSliding:
			rightsliding();
			break;
		case My::Kirby::eKirbyState::LeftJump:
			leftjump();
			break;
		case My::Kirby::eKirbyState::RightJump:
			rightjump();
			break;
		case My::Kirby::eKirbyState::LeftDoubleJump:
			leftdoublejump();
			break;
		case My::Kirby::eKirbyState::RightDoubleJump:
			rightdoublejump();
			break;
		case My::Kirby::eKirbyState::LeftBeamTransform:
			leftbeamtransform();
			break;
		case My::Kirby::eKirbyState::BeamTransform:
			beamtransform();
			break;
		case My::Kirby::eKirbyState::LeftBeamIdle:
			leftbeamidle();
			break;
		case My::Kirby::eKirbyState::RightBeamIdle:
			rightbeamidle();
			break;
		case My::Kirby::eKirbyState::LeftBeamWalk:
			leftbeamwalk();
			break;
		case My::Kirby::eKirbyState::RightBeamWalk:
			rightbeamwalk();
			break;
		case My::Kirby::eKirbyState::LeftBeamCrouch:
			leftbeamcrouch();
			break;
		case My::Kirby::eKirbyState::RightBeamCrouch:
			rightbeamcrouch();
			break;
		case My::Kirby::eKirbyState::LeftBeamSliding:
			leftbeamsliding();
			break;
		case My::Kirby::eKirbyState::RightBeamSliding:
			rightbeamsliding();
			break;
		case My::Kirby::eKirbyState::LeftBeamJump:
			leftbeamjump();
			break;
		case My::Kirby::eKirbyState::RightBeamJump:
			rightbeamjump();
			break;
		case My::Kirby::eKirbyState::LeftBeamDoubleJump:
			leftbeamdoublejump();
			break;
		case My::Kirby::eKirbyState::RightBeamDoubleJump:
			rightbeamdoublejump();
			break;
		case My::Kirby::eKirbyState::LeftBeamDash:
			leftbeamdash();
			break;
		case My::Kirby::eKirbyState::RightBeamDash:
			rightbeamdash();
			break;
		case My::Kirby::eKirbyState::LeftBeamDashRelease:
			leftbeamdashrelease();
			break;
		case My::Kirby::eKirbyState::RightBeamDashRelease:
			rightbeamdashrelease();
			break;
		case My::Kirby::eKirbyState::LeftBeam:
			leftbeam();
			break;
		case My::Kirby::eKirbyState::RightBeam:
			rightbeam();
			break;


		case My::Kirby::eKirbyState::LeftHit:
			lefthit();
			break;
		case My::Kirby::eKirbyState::RightHit:
			righthit();
			break;
		case My::Kirby::eKirbyState::LeftJumpHitRelease:
			leftjumphitrelease();
			break;
		case My::Kirby::eKirbyState::LeftJumpHit:
			leftjumphit();
			break;
		case My::Kirby::eKirbyState::RightJumpHitRelease:
			rightjumphitrelease();
			break;
		case My::Kirby::eKirbyState::RightJumpHit:
			rightjumphit();
			break;
		case My::Kirby::eKirbyState::LeftSlidingHit:
			leftslidinghit();
			break;
		case My::Kirby::eKirbyState::RightSlidingHit:
			rightslidinghit();
			break;
		case My::Kirby::eKirbyState::LeftAbsorbPigHit:
			leftabsorbpighit();
			break;
		case My::Kirby::eKirbyState::RightAbsorbPigHit:
			rightabsorbpighit();
			break;
		case My::Kirby::eKirbyState::LeftPigBaseHit:
			leftpigbasehit();
			break;
		case My::Kirby::eKirbyState::RightPigBaseHit:
			rightpigbasehit();
			break;
		case My::Kirby::eKirbyState::LeftPigJumpHit:
			leftpigjumphit();
			break;
		case My::Kirby::eKirbyState::RightPigJumpHit:
			rightpigjumphit();
			break;
		case My::Kirby::eKirbyState::LeftPigJumpHitRelease:
			leftpigjumphitrelease();
			break;
		case My::Kirby::eKirbyState::RightPigJumpHitRelease:
			rightpigjumphitrelease();
			break;
		case My::Kirby::eKirbyState::LeftBeamBaseHit:
			leftbeambasehit();
			break;
		case My::Kirby::eKirbyState::RightBeamBaseHit:
			rightbeambasehit();
			break;
		case My::Kirby::eKirbyState::LeftBeamJumpHitRelease:
			leftbeamjumphitrelease();
			break;
		case My::Kirby::eKirbyState::RightBeamJumpHitRelease:
			rightbeamjumphitrelease();
			break;
		case My::Kirby::eKirbyState::LeftBeamJumpHit:
			leftbeamjumphit();
			break;
		case My::Kirby::eKirbyState::RightBeamJumpHit:
			rightbeamjumphit();
			break;
		case My::Kirby::eKirbyState::LeftBeamPigHit:
			leftbeampighit();
			break;
		case My::Kirby::eKirbyState::RightBeamPigHit:
			rightbeampighit();
			break;
		default:
			break;
		}
	}
	void Kirby::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Kirby::Release()
	{
		GameObject::Release();
	}

	void Kirby::OnCollisionEnter(Collider* other)
	{

		if (mBrontoBurt = dynamic_cast<BrontoBurt*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftBeamIdle || GetState() == eKirbyState::LeftBeamWalk || GetState() == eKirbyState::LeftBeamDash)
			{
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftJumpHitRelease;
				mAnimator->Play(L"LeftJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftSliding)
			{
				mState = eKirbyState::LeftSlidingHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightSliding)
			{
				mState = eKirbyState::RightSlidingHit;
				mAnimator->Play(L"RightHit", false);
			}
		}
		
		if (mTwizzy = dynamic_cast<Twizzy*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftBeamIdle || GetState() == eKirbyState::LeftBeamWalk || GetState() == eKirbyState::LeftBeamDash)
			{
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftJumpHitRelease;
				mAnimator->Play(L"LeftJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftSliding)
			{
				mState = eKirbyState::LeftSlidingHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightSliding)
			{
				mState = eKirbyState::RightSlidingHit;
				mAnimator->Play(L"RightHit", false);
			}
		}
		if (mCappy = dynamic_cast<Cappy*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftBeamIdle || GetState() == eKirbyState::LeftBeamWalk || GetState() == eKirbyState::LeftBeamDash)
			{
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftJumpHitRelease;
				mAnimator->Play(L"LeftJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftSliding)
			{
				mState = eKirbyState::LeftSlidingHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightSliding)
			{
				mState = eKirbyState::RightSlidingHit;
				mAnimator->Play(L"RightHit", false);
			}
				
		}

		if (mWaddle = dynamic_cast<Waddle*>(other->GetOwner()))
		{

			if (GetState() == eKirbyState::RightPigJump)
			{
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit",false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				//mWaddle->SetDamage(40);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				//mWaddle->SetDamage(50);
				mState = eKirbyState::LeftJumpHitRelease;
				mAnimator->Play(L"LeftJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftSliding)
			{
				mState = eKirbyState::LeftSlidingHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightSliding)
			{
				mState = eKirbyState::RightSlidingHit;
				mAnimator->Play(L"RightHit", false);
			}
		}

		if (StarMap* mStarMap = dynamic_cast<StarMap*>(other->GetOwner()))
		{
			StarCol = true;
		}
	}

	void Kirby::OnCollisionStay(Collider* other)
	{
		
	}

	void Kirby::OnCollisionExit(Collider* other)
	{
		//int a = 0;
	}


	void Kirby::leftmove()
	{
		KeyCheck = true;
		kirbytime += Time::DeltaTime();

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftJump;

			mAnimator->Play(L"LeftJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
			kirbytime = 0.0f;
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			LeftAbsorb = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 70, pos.y - 10), Vector2(2.5f, 1.3f), eLayerType::Effect);
			mState = eKirbyState::LeftAbsorb;
			mAnimator->Play(L"LeftAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			//mRigidBody->AddForce(Vector2(-200.0f, 0.0f));
			pos.x -= 120.0f * Time::DeltaTime();
			if (Input::GetKey(eKeyCode::Right))
			{
				mState = eKirbyState::RightMove;
				mAnimator->Play(L"RightWalk", true);
			}
			if (Input::GetKey(eKeyCode::Down))
			{
				mState = eKirbyState::LeftCrouch;
				mAnimator->Play(L"LeftCrouch", true);
			}

			//if (Input::GetKey(eKeyCode::Left))
			//{
			//	mState = eKirbyState::LeftDash;
			//	mAnimator->Play(L"LeftDash", true);
			//}
		}

		tr->SetPos(pos);
	}
	void Kirby::rightmove()
	{
		KeyCheck = true;
		kirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightJump;

			mAnimator->Play(L"RightJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;

			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}



			if (Input::GetKeyUp(eKeyCode::Right))
			{
				mState = eKirbyState::RightIdle;
				mAnimator->Play(L"RightIdle", true);
				kirbytime = 0.0f;
			}

			//if (KeyCheck)
			//{
			//	if(GetKeyState(VK_RIGHT))
			//	{
			//		mState = eKirbyState::RightDash;
			//		mAnimator->Play(L"RightDash", true);
			//	}
			if (Input::GetKeyDown(eKeyCode::Z))
			{
				Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 70, pos.y - 15), Vector2(2.5f, 1.3f), eLayerType::Effect);
				mState = eKirbyState::RightAbsorb;
				mAnimator->Play(L"RightAbsorbing", true);
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				//mRigidBody->AddForce(Vector2(200.0f, 0.0f));
				pos.x += 120.0f * Time::DeltaTime();
				if (Input::GetKey(eKeyCode::Left))
				{
					mState = eKirbyState::LeftMove;
					mAnimator->Play(L"LeftWalk", true);
				}
				if (Input::GetKey(eKeyCode::Down))
				{
					mState = eKirbyState::RightCrouch;
					mAnimator->Play(L"RightCrouch", true);
				}
			}
			tr->SetPos(pos);
	}

	void Kirby::leftidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		
		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftJump;

			mAnimator->Play(L"LeftJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		kirbytime += Time::DeltaTime();
		if (Input::GetKey(eKeyCode::Left))
		{	
			mState = eKirbyState::LeftMove;
			mAnimator->Play(L"LeftWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightMove;
			mAnimator->Play(L"RightWalk", true);
		}


		if (Input::GetKeyDown(eKeyCode::Z))
		{
			LeftAbsorb = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 70, pos.y - 10), Vector2(2.5f, 1.3f), eLayerType::Effect);
			mState = eKirbyState::LeftAbsorb;
			mAnimator->Play(L"LeftAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::LeftCrouch;
			mAnimator->Play(L"LeftCrouch", true);
		}

		if (kirbytime <= 0.15f && KeyCheck && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mState = eKirbyState::LeftDash;
			mAnimator->Play(L"LeftDash", true);
		}
	}
	void Kirby::rightidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


		if (/*mRigidBody->GetGround() &&*/Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightJump;
		
			mAnimator->Play(L"RightJump", false);



			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;
			

			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		kirbytime += Time::DeltaTime();
		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftMove;
			mAnimator->Play(L"LeftWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightMove;
			mAnimator->Play(L"RightWalk", true);
		}
		if (Input::GetKeyDown(eKeyCode::Z))
		{
			Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 70, pos.y - 15), Vector2(2.5f, 1.3f), eLayerType::Effect);

			mState = eKirbyState::RightAbsorb;
			mAnimator->Play(L"RightAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::RightCrouch;
			mAnimator->Play(L"RightCrouch", true);
		}

		if (kirbytime <= 0.15f && KeyCheck && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mState = eKirbyState::RightDash;
			mAnimator->Play(L"RightDash", true);
		}
	}
		//tr->SetPos(pos);

	void Kirby::death()
	{

	}
	void Kirby::leftabsorb()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(LeftAbsorb);
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		
		if (LeftAbsorb->GetCollision() == 1)
		{
			starshot = true;
			GetMonster = true;
			mState = eKirbyState::LeftColAbsorb;
		}

		if (LeftAbsorb->GetCollision() == 2)
		{
			starshot = true;
			GetMonster = true;
			yamyam = true;
			mState = eKirbyState::LeftColAbsorb;
		}

		if (IsJump)
		{
			if (Input::GetKeyUp(eKeyCode::Z))
			{
				object::Destroy(LeftAbsorb);
				mState = eKirbyState::LeftIdle;
				mAnimator->Play(L"LeftIdle", true);
			}
			if (LeftAbsorb->GetCollision() == 1) //일반 몬스터 먹었을 때
			{
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				mState = eKirbyState::LeftColAbsorb;
			}
			if (LeftAbsorb->GetCollision() == 2) // 와들을 먹었을 때
			{
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				// 아무 몬스터를 머금었을때 true
				yamyam = true; // 와들을 먹었을 때 true
				mState = eKirbyState::LeftColAbsorb;
			}
		}


	}
	void Kirby::rightabsorb()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(Absorb);
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (Absorb->GetCollision() == 1) //일반 몬스터 먹었을 때
		{
			starshot = true;
			GetMonster = true;
			mState = eKirbyState::RightColAbsorb;
		}
		if (Absorb->GetCollision() == 2) // 와들을 먹었을 때
		{
			starshot = true;
			GetMonster = true;
			// 아무 몬스터를 머금었을때 true
			yamyam = true; // 와들을 먹었을 때 true
			mState = eKirbyState::RightColAbsorb;
		}

		if (IsJump)
		{
			if (Input::GetKeyUp(eKeyCode::Z))
			{
				object::Destroy(Absorb);
				mState = eKirbyState::RightIdle;
				mAnimator->Play(L"RightIdle", true);
			}
			if (Absorb->GetCollision() == 1) //일반 몬스터 먹었을 때
			{
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				mState = eKirbyState::RightColAbsorb;
			}
			if (Absorb->GetCollision() == 2) // 와들을 먹었을 때
			{
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				// 아무 몬스터를 머금었을때 true
				yamyam = true; // 와들을 먹었을 때 true
				mState = eKirbyState::RightColAbsorb;
			}
		}

		

	}
	void Kirby::leftcolabsorb()
	{
		kirbytime += Time::DeltaTime();

		if (0.2f <= kirbytime && kirbytime <= 0.3f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftAbsorbPig;
			mAnimator->Play(L"LeftAbsorbPig", false);
		}

		if (kirbytime >= 0.3f)
		{
			kirbytime = 0.0f;
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftAbsorbPig;
			mAnimator->Play(L"LeftAbsorbPig", false);
		}

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			yamyam = false;
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBeamTransform;
			mAnimator->Play(L"LeftBeamTransform", false);
		}
	}
	void Kirby::rightcolabsorb()
	{
		kirbytime += Time::DeltaTime();

		if (0.2f<=kirbytime && kirbytime <= 0.3f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightAbsorbPig;
			mAnimator->Play(L"RightAbsorbPig", false);
		}

		if (kirbytime >= 0.3f)
		{
			kirbytime = 0.0f;
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightAbsorbPig;
			mAnimator->Play(L"RightAbsorbPig", false);
		}

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			yamyam = false;
			kirbytime = 0.0f;
			mState = eKirbyState::BeamTransform;
			mAnimator->Play(L"RightBeamTransform", false);
		}

	}
	void Kirby::leftabsorbpig()
	{
		kirbytime += Time::DeltaTime();

		if (0.4f <= kirbytime && kirbytime <= 0.5f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
		}

		if (kirbytime >= 0.5f)
		{
			kirbytime = 0.0f;
		}
		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			yamyam = false;
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBeamTransform;
			mAnimator->Play(L"LeftBeamTransform", false);
		}

	}
	void Kirby::rightabsorbpig()
	{
		kirbytime += Time::DeltaTime();
		if (0.4f <= kirbytime && kirbytime <= 0.5f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightPigIdle; 
			mAnimator->Play(L"RightPigIdle", true); 
		}
		if (kirbytime >= 0.5f)
		{
			kirbytime = 0.0f;
		}

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			yamyam = false;
			kirbytime = 0.0f;
			mState = eKirbyState::BeamTransform;
			mAnimator->Play(L"RightBeamTransform", false);
		}
	}
	void Kirby::leftpigidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			Leftstar = true;
			Star* mLeftstar = object::Instantiate<Star>(Vector2(pos.x - 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mLeftstar->SetPlayer(this);
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBeamTransform;
			mAnimator->Play(L"LeftBeamTransform", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftPigJump;

			mAnimator->Play(L"LeftPigJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftPigWalk;
			mAnimator->Play(L"LeftPigWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightPigWalk;
			mAnimator->Play(L"RightPigWalk", true);
		}

		if (yamyam == false && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}
		if (kirbytime <= 0.15f && PigKeyCheck && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftPigDash;
			mAnimator->Play(L"LeftPigWalk", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::rightpigidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


		if (Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			star = true;
			Star* mstar = object::Instantiate<Star>(Vector2(pos.x+50, pos.y-20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mstar->SetPlayer(this);
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::BeamTransform;
			mAnimator->Play(L"RightBeamTransform", false);
		}
	
		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightPigJump;

			mAnimator->Play(L"RightPigJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (yamyam == false && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}
		if (kirbytime <= 0.15f && PigKeyCheck && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightPigDash;
			mAnimator->Play(L"RightPigWalk", true);
		}

		//if (yamyam = true && Input::GetKeyDown(eKeyCode::Down))
		//{
		//	
		//}

		

		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightPigWalk;
			mAnimator->Play(L"RightPigWalk", true);
		}

			if (Input::GetKey(eKeyCode::Left))
			{
				mState = eKirbyState::LeftPigWalk;
				mAnimator->Play(L"LeftPigWalk", true);
			}

		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = eKirbyState::LeftPigWalk;
			mAnimator->Play(L"LeftPigWalk", true);
		}


		tr->SetPos(pos);
	}
	void Kirby::leftpigclear()
	{
		cleartime += Time::DeltaTime();

		if (cleartime >= 0.3f)
		{
			cleartime = 0.0f;
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
	}
	void Kirby::rightpigclear()
	{
		cleartime += Time::DeltaTime();

		if (cleartime >= 0.3f)
		{
			cleartime = 0.0f;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}
	}
	void Kirby::leftpigwalk()
	{
		PigKeyCheck = true;
		kirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			Leftstar = true;
			Star* mLeftstar = object::Instantiate<Star>(Vector2(pos.x - 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mLeftstar->SetPlayer(this);
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 120.0f * Time::DeltaTime();

			if (Input::GetKeyDown(eKeyCode::Right))
			{
				kirbytime = 0.0f;
				mState = eKirbyState::RightPigWalk;
				mAnimator->Play(L"RightPigWalk", true);
			}

			if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
			{
				kirbytime = 0.0f;
				mState = eKirbyState::LeftBeamTransform;
				mAnimator->Play(L"LeftBeamTransform", false);
			}

		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftPigJump;

			mAnimator->Play(L"LeftPigJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
			kirbytime = 0.0f;
		}
		tr->SetPos(pos);
	}
	void Kirby::rightpigwalk()
	{
		PigKeyCheck = true;
		kirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			star = true;
			Star* mstar = object::Instantiate<Star>(Vector2(pos.x + 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mstar->SetPlayer(this);
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 120.0f * Time::DeltaTime();

			if (Input::GetKeyDown(eKeyCode::Left))
			{
				mState = eKirbyState::LeftPigWalk;
				mAnimator->Play(L"LeftPigWalk", true);
			}
		}

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::BeamTransform;
			mAnimator->Play(L"RightBeamTransform", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightPigJump;

			mAnimator->Play(L"RightPigJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);
			kirbytime = 0.0f;
		}
		tr->SetPos(pos);
	}
	void Kirby::leftpigjump()
	{
		pigjumptime += Time::DeltaTime();

		if (GetMonster == true && mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);

			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}
		if (GetMonster == false && mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);

			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		if (starshot == true && Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			starshot = false;
			GetMonster = false;
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			Leftstar = true;
			Star* mLeftstar = object::Instantiate<Star>(Vector2(pos.x - 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mLeftstar->SetPlayer(this);
			mAnimator->Play(L"LeftAir", false);
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
		}

		if (pigjumptime >= 0.2f)
		{
			JumpCheck = false;
			pigjumptime = 0.0f;
		}

	}
	void Kirby::rightpigjump()
	{
		pigjumptime += Time::DeltaTime();

		if (GetMonster == true && mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);

			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}
		if (GetMonster == false && mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);

			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}


		if (starshot == true &&Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			starshot = false;
			GetMonster = false;
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			star = true;
			Star* mstar = object::Instantiate<Star>(Vector2(pos.x + 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mstar->SetPlayer(this);
			mAnimator->Play(L"RightAir", false);
		
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
		}


		if (pigjumptime >= 0.2f)
		{
			JumpCheck = false;
			pigjumptime = 0.0f;
		}
	}
	void Kirby::leftpigdash()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			Leftstar = true;
			Star* mLeftstar = object::Instantiate<Star>(Vector2(pos.x - 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mLeftstar->SetPlayer(this);
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftPigDashRelease;
			mAnimator->Play(L"LeftPigDashRelease", false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 200.0f * Time::DeltaTime();
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftPigJump;

			mAnimator->Play(L"LeftPigJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		tr->SetPos(pos);
	}
	void Kirby::rightpigdash()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (yamyam == true && Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			star = true;
			Star* mstar = object::Instantiate<Star>(Vector2(pos.x + 50, pos.y - 20), Vector2(0.3f, 0.3f), (eLayerType::Star));
			mstar->SetPlayer(this);
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightPigDashRelease;
			mAnimator->Play(L"RightPigDashRelease", false);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 200.0f * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightPigJump;

			mAnimator->Play(L"RightPigJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}
		tr->SetPos(pos);
	}
	void Kirby::leftpigdashrelease()
	{
		kirbytime += Time::DeltaTime();

		if (kirbytime >= 0.3f)
		{
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
			PigKeyCheck = false;
			kirbytime = 0.0f;
		}

		if (kirbytime >= 0.2f && Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);
			PigKeyCheck = false;
			kirbytime = 0.0f;
		}

		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
		}
	}
	void Kirby::rightpigdashrelease()
	{
		kirbytime += Time::DeltaTime();

		if (kirbytime >= 0.3f)
		{
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);
			PigKeyCheck = false;
			kirbytime = 0.0f;
		}

		if (kirbytime >= 0.2f && Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
			PigKeyCheck = false;
			kirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);
		}
	}
	void Kirby::leftdash()
	{
		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftDashRelease;
			mAnimator->Play(L"LeftDashRelease", false);
		}


			if (Input::GetKeyDown(eKeyCode::A))
			{
				JumpCheck = true;
				mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
				mState = eKirbyState::LeftJump;

				mAnimator->Play(L"LeftJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x -= 100.0f;
				velocity.y -= 400.0f;


				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);
			}

			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			if (Input::GetKey(eKeyCode::Left))
			{
				pos.x -= 200.0f * Time::DeltaTime();
			}
			tr->SetPos(pos);
		}
	
	void Kirby::rightdash()
	{
		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightDashRelease;
			mAnimator->Play(L"RightDashRelease", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightJump;

			mAnimator->Play(L"RightJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 200.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
		
	}

	void Kirby::leftdashrelease()
	{

		kirbytime += Time::DeltaTime();

			if (kirbytime >= 0.3f)
			{
				mState = eKirbyState::LeftIdle;
				mAnimator->Play(L"LeftIdle", true);
				KeyCheck = false;
				kirbytime = 0.0f;
			}

		if (kirbytime >= 0.2f && Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}

		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
	}

	void Kirby::rightdashrelease()
	{
		kirbytime += Time::DeltaTime();

		if (kirbytime >= 0.3f)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}

		if (kirbytime>=0.2f &&Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle",true);
			KeyCheck = false;
			kirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}


	}

	void Kirby::leftcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		if (DoubleJump)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
			DoubleJump = false;
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mAnimator->Play(L"LeftCrouch", true);

			if (Input::GetKeyDown(eKeyCode::Left))
			{
				mState = eKirbyState::LeftMove;
				mAnimator->Play(L"LeftMove", true);
			}
		}
		
			if (Input::GetKeyDown(eKeyCode::X))
			{
				mState = eKirbyState::LeftSliding;
				mAnimator->Play(L"LeftSliding", true);
			}

	}

	void Kirby::rightcrouch()
	{

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (DoubleJump)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
			DoubleJump = false;
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mAnimator->Play(L"RightCrouch", true);
			{
				if (Input::GetKeyDown(eKeyCode::Right))
				{
					mState = eKirbyState::RightMove;
					mAnimator->Play(L"RightMove", true);
				}
			}
		}
		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = eKirbyState::RightSliding;
			mAnimator->Play(L"RightSliding", true);
		}
	}
	void Kirby::leftsliding()
	{
		leftslidingtime += Time::DeltaTime();
		Leftsliding = true;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (leftslidingtime < 0.5f)
		{
			mAnimator->Play(L"LeftSliding", true);
			pos.x -= 200.f * Time::DeltaTime();
		}
		if (0.5f < leftslidingtime
			&& leftslidingtime < 0.8f)
		{
			mAnimator->Play(L"LeftSliding", true);
			pos.x -= 10.f * Time::DeltaTime();
		}
		if (leftslidingtime > 0.8f)
		{
			leftslidingtime = 0.0f;
			Leftsliding = false;
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		tr->SetPos(pos);

	}

	void Kirby::rightsliding()
	{
		sliding = true;

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		slidingtime += Time::DeltaTime();

		if (slidingtime < 0.5f)
		{
			//mAnimator->Play(L"RightSliding", true);
			pos.x += 200.f * Time::DeltaTime();
		}
		if (0.5f < slidingtime
			&& slidingtime < 0.8f)
		{
			//mAnimator->Play(L"RightSliding", true);
			pos.x += 30.f * Time::DeltaTime();
		}
		if (slidingtime > 0.8f)
		{
			slidingtime = 0.0f;
			sliding = false;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		tr->SetPos(pos);

	}

	void Kirby::leftjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		jumptime += Time::DeltaTime();

		IsJump = true;
		AirShot = true;

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}

		if (jumptime >= 0.2f)
		{
			JumpCheck = false;
			jumptime = 0.0f;
		}

		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		//if (Input::GetKeyDown(eKeyCode::Z))
		//{
		//	LeftAbsorb = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 70, pos.y - 10), Vector2(2.5f, 1.3f), eLayerType::Effect);
		//	mState = eKirbyState::LeftAbsorb;
		//	mAnimator->Play(L"LeftAbsorbing", true);
		//}

		tr->SetPos(pos);


		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);

			jumptime = 0.0f;
			IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

	}

	void Kirby::rightjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		jumptime += Time::DeltaTime();

		if (jumptime >= 0.2f)
		{
			JumpCheck = false;
			jumptime = 0.0f;
		}
		IsJump = true;
		AirShot = true;


		//if (Input::GetKeyDown(eKeyCode::Z))
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	Vector2 pos = tr->GetPos();

		//	Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 70, pos.y - 15), Vector2(2.5f, 1.3f), eLayerType::Effect);

		//	mState = eKirbyState::RightAbsorb;
		//	mAnimator->Play(L"RightAbsorbing", true);
		//}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 50.0f * Time::DeltaTime();
		}


		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{	
			JumpCheck = true;
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		tr->SetPos(pos);


		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);

			jumptime = 0.0f;
			IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

	}

	void Kirby::leftdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		jumptime += Time::DeltaTime();

		IsJump = false;
		DoubleJump = true;

		if (DoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			AirShot = true;
			mAnimator->Play(L"LeftJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;



			mRigidBody->SetVelocity(velocity);
		}

		if (jumptime > 0.2f)
		{
			JumpCheck = false;
			jumptime = 0.0f;
		}

		if (AirShot && Input::GetKeyDown(eKeyCode::Z))
		{

			AirShot = false;
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"LeftAir", false);
			object::Instantiate<AirLeft>(Vector2(pos.x - 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Air);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			JumpCheck = false;
			//mState = eKirbyState::LeftIdle;
			//mAnimator->Play(L"LeftIdle", true);

			mAnimator->Play(L"LeftCrouch", true);
			mState = eKirbyState::LeftCrouch;

			jumptime = 0.0f;
			DoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}

	void Kirby::rightdoublejump()
	{
		jumptime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		IsJump = false;
		DoubleJump = true;

		if (AirShot && Input::GetKeyDown(eKeyCode::Z))
		{
			AirShot = false;
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"RightAir", false);
			object::Instantiate<Air>(Vector2(pos.x + 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Air);
		}
		if (jumptime > 0.2f)
		{
			JumpCheck = false;
			jumptime = 0.0f;
		}

		if (DoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			AirShot = true;
			mAnimator->Play(L"RightJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			//mState = eKirbyState::RightIdle;
			
			mAnimator->Play(L"RightCrouch", true);
			mState = eKirbyState::RightCrouch;
			//mAnimator->Play(L"RightIdle", true);

			jumptime = 0.0f;
			DoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}




	void Kirby::leftbeamtransform()
	{
		kirbytime += Time::DeltaTime();

		if (kirbytime > 0.8f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}

	}
	void Kirby::beamtransform()
	{
		kirbytime += Time::DeltaTime();
		
		if (kirbytime > 0.8f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}

		
	}
	void Kirby::leftbeamidle()
	{

		beamkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (Input::GetKey(eKeyCode::Z))
		{
			chargingtime += Time::DeltaTime();
			mAnimator->Play(L"LeftEnergyBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime <= 0.5f)
		{
			chargingtime = 0.0f;
			mLeftKirbyBeam = object::Instantiate<LeftKirbyBeam>(Vector2(pos.x - 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::LeftBeam;
			mAnimator->Play(L"LeftBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime >= 0.5f)
		{
			chargingtime = 0.0f;
			mLeftEnergyBeam = object::Instantiate<LeftEnergyBeam>(Vector2(pos.x - 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::LeftBeam;
			mAnimator->Play(L"LeftBeam", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftBeamJump;

			mAnimator->Play(L"LeftBeamJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBeamWalk;
			mAnimator->Play(L"LeftBeamWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBeamWalk;
			mAnimator->Play(L"RightBeamWalk", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::LeftBeamCrouch;
			mAnimator->Play(L"LeftBeamCrouch", true);
		}

		if (beamkirbytime <= 0.15f && BeamKeyCheck && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mState = eKirbyState::LeftBeamDash;
			mAnimator->Play(L"LeftBeamDash", true);
		}
	}
	void Kirby::rightbeamidle()
	{
		beamuse = false;
		beamkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (Input::GetKey(eKeyCode::Z))
		{
			chargingtime += Time::DeltaTime();
			mAnimator->Play(L"RightEnergyBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime <=0.5f)
		{
			chargingtime = 0.0f;
			mKirbyBeam = object::Instantiate<KirbyBeam>(Vector2(pos.x + 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::RightBeam;
			mAnimator->Play(L"RightBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime >= 0.5f)
		{
			chargingtime = 0.0f;
			mEnergyBeam = object::Instantiate<EnergyBeam>(Vector2(pos.x + 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::RightBeam;
			mAnimator->Play(L"RightBeam", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightBeamJump;

			mAnimator->Play(L"RightBeamJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBeamWalk;
			mAnimator->Play(L"LeftBeamWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBeamWalk;
			mAnimator->Play(L"RightBeamWalk", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::RightBeamCrouch;
			mAnimator->Play(L"RightBeamCrouch", true);
		}

		if (beamkirbytime <= 0.15f && BeamKeyCheck && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mState = eKirbyState::RightBeamDash;
			mAnimator->Play(L"RightBeamDash", true);
		}


	}
	void Kirby::leftbeamwalk()
	{
		beamuse = true;
		
		BeamKeyCheck = true;

		beamkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


		if (beamuse == true && Input::GetKey(eKeyCode::Z))
		{
			beamcharging = true;
			chargingtime += Time::DeltaTime();
			mAnimator->Play(L"LeftEnergyBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime <= 0.5f)
		{
			beamcharging = false;
			chargingtime = 0.0f;
			mLeftKirbyBeam = object::Instantiate<LeftKirbyBeam>(Vector2(pos.x - 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::LeftBeam;
			mAnimator->Play(L"LeftBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime >= 0.5f)
		{
			beamcharging = false;
			chargingtime = 0.0f;
			mLeftEnergyBeam = object::Instantiate<LeftEnergyBeam>(Vector2(pos.x - 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::LeftBeam;
			mAnimator->Play(L"LeftBeam", false);
		}

		if (beamcharging == false)
		{
			if (Input::GetKeyDown(eKeyCode::S))
			{
				yamyam = false;
				mState = eKirbyState::LeftPigClear;
				mAnimator->Play(L"LeftPigClear", false);
			}
			if (Input::GetKeyDown(eKeyCode::A))
			{
				JumpCheck = true;
				mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
				mState = eKirbyState::LeftBeamJump;

				mAnimator->Play(L"LeftBeamJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x -= 100.0f;
				velocity.y -= 400.0f;


				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				mState = eKirbyState::RightBeamWalk;
				mAnimator->Play(L"RightBeamWalk", true);
			}

			if (Input::GetKey(eKeyCode::Left))
			{
				pos.x -= 120.0f * Time::DeltaTime();

				if (Input::GetKey(eKeyCode::Right))
				{
					mState = eKirbyState::RightBeamWalk;
					mAnimator->Play(L"RightBeamWalk", true);
				}

				if (Input::GetKey(eKeyCode::Down))
				{
					mState = eKirbyState::LeftBeamCrouch;
					mAnimator->Play(L"LeftBeamCrouch", true);
				}

			}

			if (Input::GetKeyUp(eKeyCode::Left))
			{
				mState = eKirbyState::LeftBeamIdle;
				mAnimator->Play(L"LeftBeamIdle", true);
				beamkirbytime = 0.0f;
			}
		}

		tr->SetPos(pos);

	}
	void Kirby::rightbeamwalk()
	{
		beamuse = true;
		BeamKeyCheck = true;
		beamkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (beamuse = true && Input::GetKey(eKeyCode::Z))
		{
			beamcharging = true;
			chargingtime += Time::DeltaTime();
			mAnimator->Play(L"RightEnergyBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime <= 0.5f)
		{
			beamcharging = false;
			chargingtime = 0.0f;
			mKirbyBeam = object::Instantiate<KirbyBeam>(Vector2(pos.x + 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::RightBeam;
			mAnimator->Play(L"RightBeam", false);
		}

		if (Input::GetKeyUp(eKeyCode::Z) && chargingtime >= 0.5f)
		{
			beamcharging = false;
			chargingtime = 0.0f;
			mEnergyBeam = object::Instantiate<EnergyBeam>(Vector2(pos.x + 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

			mState = eKirbyState::RightBeam;
			mAnimator->Play(L"RightBeam", false);
		}



		if (beamcharging == false)
		{
			if (Input::GetKeyDown(eKeyCode::S))
			{
				yamyam = false;
				mState = eKirbyState::RightPigClear;
				mAnimator->Play(L"RightPigClear", false);
			}
			if (Input::GetKeyDown(eKeyCode::A))
			{
				JumpCheck = true;
				mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
				mState = eKirbyState::RightBeamJump;

				mAnimator->Play(L"RightBeamJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x += 100.0f;
				velocity.y -= 400.0f;


				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);
			}

			if (Input::GetKey(eKeyCode::Left))
			{
				mState = eKirbyState::LeftBeamWalk;
				mAnimator->Play(L"LeftBeamWalk", true);
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				pos.x += 120.0f * Time::DeltaTime();

				if (Input::GetKey(eKeyCode::Left))
				{
					mState = eKirbyState::LeftBeamWalk;
					mAnimator->Play(L"LeftBeamWalk", true);
				}

				if (Input::GetKey(eKeyCode::Down))
				{
					mState = eKirbyState::RightBeamCrouch;
					mAnimator->Play(L"RightBeamCrouch", true);
				}

			}

			if (Input::GetKeyUp(eKeyCode::Right))
			{
				mState = eKirbyState::RightBeamIdle;
				mAnimator->Play(L"RightBeamIdle", true);
				beamkirbytime = 0.0f;
			}
		}

		tr->SetPos(pos);
	}
	void Kirby::leftbeamcrouch()
	{

		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}

		if (BeamDoubleJump)
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
			BeamDoubleJump = false;
		}
		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = eKirbyState::LeftBeamSliding;
			mAnimator->Play(L"LeftBeamSliding", false);
		}
	}
	void Kirby::rightbeamcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (BeamDoubleJump)
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
			BeamDoubleJump = false;
		}
		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = eKirbyState::RightBeamSliding;
			mAnimator->Play(L"RightBeamSliding", false);
		}
	}

	void Kirby::leftbeamsliding()
	{
		Leftsliding = true;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		beamkirbytime += Time::DeltaTime();

		if (beamkirbytime < 0.5f)
		{
			pos.x -= 250.f * Time::DeltaTime();
		}
		if (0.5f < beamkirbytime
			&& beamkirbytime < 0.8f)
		{
			pos.x -= 10.f * Time::DeltaTime();
		}
		if (beamkirbytime > 0.8f)
		{
			beamkirbytime = 0.0f;
			Leftsliding = false;
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}

		tr->SetPos(pos);
	}

	void Kirby::rightbeamsliding()
	{
		sliding = true;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		beamkirbytime += Time::DeltaTime();

		if (beamkirbytime < 0.5f)
		{
			pos.x += 250.f * Time::DeltaTime();
		}
		if (0.5f < beamkirbytime
			&& beamkirbytime < 0.8f)
		{
			pos.x += 10.f * Time::DeltaTime();
		}
		if (beamkirbytime > 0.8f)
		{
			beamkirbytime = 0.0f;
			sliding = false;
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}

		tr->SetPos(pos);
	}

	void Kirby::leftbeamjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		beamjumptime += Time::DeltaTime();

		BeamIsJump = true;
		BeamAirShot = true;

		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);

			//jumptime = 0.0f;
			//IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}

		if (beamjumptime >= 0.2f)
		{
			JumpCheck = false;
			beamjumptime = 0.0f;
		}

		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::LeftBeamDoubleJump;
			mAnimator->Play(L"LeftBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		tr->SetPos(pos);
	}

	void Kirby::rightbeamjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		beamjumptime += Time::DeltaTime();

		BeamIsJump = true;
		BeamAirShot = true;

		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);

			//jumptime = 0.0f;
			//IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		//if (Input::GetKeyDown(eKeyCode::Z))
		//{
		//    mRigidBody->SetVelocity(Vector2::Zero);
		//	
		//	mKirbyBeam = object::Instantiate<KirbyBeam>(Vector2(pos.x + 100, pos.y + 35), Vector2(1.5f, 1.5f), eLayerType::Skill);

		//	mState = eKirbyState::RightBeam;
		//	mAnimator->Play(L"RightBeam", false);
		//}


		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 50.0f * Time::DeltaTime();
		}

		if (beamjumptime >= 0.2f)
		{
			JumpCheck = false;
			beamjumptime = 0.0f;
		}

		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::RightBeamDoubleJump;
			mAnimator->Play(L"RightBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		tr->SetPos(pos);
	}

	void Kirby::leftbeamdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		
		beamjumptime += Time::DeltaTime();
		BeamIsJump = false;
		BeamDoubleJump = true;

		//if (Input::GetKeyDown(eKeyCode::Z))
		//{
		//	mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
		//	mAnimator->Play(L"RightAir", false);
		//	object::Instantiate<Air>(Vector2(pos.x + 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		//}
		if (beamjumptime > 0.2f)
		{
			JumpCheck = false;
			beamjumptime = 0.0f;
		}


		if (BeamDoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			BeamAirShot = true;
			mAnimator->Play(L"LeftBeamJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
		if (BeamAirShot && Input::GetKeyDown(eKeyCode::Z))
		{
			BeamAirShot = false;
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"LeftBeamAir", false);
			object::Instantiate<AirLeft>(Vector2(pos.x - 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBeamDoubleJump;
			mAnimator->Play(L"RightBeamJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			mAnimator->Play(L"LeftBeamCrouch", true);
			mState = eKirbyState::LeftBeamCrouch;

			BeamDoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}

	void Kirby::rightbeamdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		beamjumptime += Time::DeltaTime();

		BeamIsJump = false;
		BeamDoubleJump = true;

		if (BeamAirShot && Input::GetKeyDown(eKeyCode::Z))
		{
			BeamAirShot = false;
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"RightBeamAir", false);
			object::Instantiate<Air>(Vector2(pos.x + 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		}

		if (beamjumptime > 0.2f)
		{
			JumpCheck = false;
			beamjumptime = 0.0f;
		}
		if (BeamDoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			BeamAirShot = true;
			mAnimator->Play(L"RightBeamJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBeamDoubleJump;
			mAnimator->Play(L"LeftBeamJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			mAnimator->Play(L"RightBeamCrouch", true);
			mState = eKirbyState::RightBeamCrouch;

			BeamDoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftbeamdash()
	{
		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBeamDashRelease;
			mAnimator->Play(L"LeftBeamDashRelease", false);
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftBeamJump;

			mAnimator->Play(L"LeftBeamJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 200.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::rightbeamdash()
	{
		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightBeamDashRelease;
			mAnimator->Play(L"RightBeamDashRelease", false);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightBeamJump;

			mAnimator->Play(L"RightBeamJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 200.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::leftbeamdashrelease()
	{
		beamkirbytime += Time::DeltaTime();

		if (beamkirbytime >= 0.3f)
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
			BeamKeyCheck = false;
			beamkirbytime = 0.0f;
		}

		if (beamkirbytime >= 0.2f && Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
			BeamKeyCheck = false;
			beamkirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}
	}
	void Kirby::rightbeamdashrelease()
	{
		beamkirbytime += Time::DeltaTime();

		if (beamkirbytime >= 0.3f)
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
			BeamKeyCheck = false;
			beamkirbytime = 0.0f;
		}

		if (beamkirbytime >= 0.2f && Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
			BeamKeyCheck = false;
			beamkirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}
	}

	void Kirby::leftbeam()
	{
		beamtime += Time::DeltaTime();

		if (beamtime >= 0.35f)
		{
			beamtime = 0.0f;
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}
	}

	void Kirby::rightbeam()
	{
		beamtime += Time::DeltaTime();

		if (beamtime >= 0.35f)
		{
			beamtime = 0.0f;
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}
	}

	void Kirby::lefthit()
	{
		lefthittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x += 150.0f * Time::DeltaTime();

		if (lefthittime >= 0.3f)
		{
			lefthittime = 0.0f;
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		tr->SetPos(pos);
	}

	void Kirby::righthit()
	{
		righthittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x -= 150.0f * Time::DeltaTime();

		if (righthittime >= 0.3f)
		{
			righthittime = 0.0f;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftjumphitrelease()
	{
		jumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 200.0f * Time::DeltaTime();
		pos.x += 250.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (jumphitreleasetime >= 0.3f)
		{
			jumphitreleasetime = 0.0f;
			mState = eKirbyState::LeftJumpHit;
			mAnimator->Play(L"LeftJumpHit", false);
		}

		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::leftjumphit()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::rightjumphitrelease()
	{
		jumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();
	
		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 200.0f * Time::DeltaTime();
		pos.x -= 250.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (jumphitreleasetime >= 0.3f)
		{
			jumphitreleasetime = 0.0f;
			mState = eKirbyState::RightJumpHit;
			mAnimator->Play(L"RightJumpHit",false);
		}

		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}


	}
	void Kirby::rightjumphit()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::leftslidinghit()
	{
		lefthittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x += 150.0f * Time::DeltaTime();

		if (lefthittime >= 0.3f)
		{
			lefthittime = 0.0f;
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		tr->SetPos(pos);
	}
	void Kirby::rightslidinghit()
	{
		righthittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x -= 150.0f * Time::DeltaTime();

		if (righthittime >= 0.3f)
		{
			righthittime = 0.0f;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftpigbasehit()
	{
		lefthitpigbasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x += 150.0f * Time::DeltaTime();

		if (lefthitpigbasetime >= 0.3f)
		{
			lefthitpigbasetime = 0.0f;
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::rightpigbasehit()
	{
		righthitpigbasetime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x -= 150.0f * Time::DeltaTime();

		if (righthitpigbasetime >= 0.3f)
		{
			righthitpigbasetime = 0.0f;
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftpigjumphit()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftPigIdle;
			mAnimator->Play(L"LeftPigIdle", true);
		}
	}

	void Kirby::rightpigjumphit()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightPigIdle;
			mAnimator->Play(L"RightPigIdle", true);
		}
	}

	void Kirby::leftpigjumphitrelease()
	{
		leftpigjumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 200.0f * Time::DeltaTime();
		pos.x += 250.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (leftpigjumphitreleasetime >= 0.3f)
		{
			leftpigjumphitreleasetime = 0.0f;
			mState = eKirbyState::LeftPigJumpHit;
			mAnimator->Play(L"LeftPigJumpHit", false);
		}


	}

	void Kirby::rightpigjumphitrelease()
	{
		rightpigjumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 200.0f * Time::DeltaTime();
		pos.x -= 250.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (rightpigjumphitreleasetime >= 0.3f)
		{
			rightpigjumphitreleasetime = 0.0f;
			mState = eKirbyState::RightPigJumpHit;
			mAnimator->Play(L"RightPigJumpHit", false);
		}

	}

	void Kirby::leftabsorbpighit()
	{
		leftdoublejumphittime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 50.0f * Time::DeltaTime();
		pos.x += 100.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (leftdoublejumphittime >= 0.4f)
		{
			JumpCheck = true;
			leftdoublejumphittime = 0.0f;
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::rightabsorbpighit()
	{
		rightdoublejumphittime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 50.0f * Time::DeltaTime();
		pos.x -= 100.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (rightdoublejumphittime >= 0.4f)
		{
			JumpCheck = true;
			rightdoublejumphittime = 0.0f;
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightDoubleJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
				velocity.x = 0.0f;
				velocity.y = -120.0f;

				mRigidBody->SetVelocity(velocity);
			}
		}
	void Kirby::leftbeambasehit()
	{
		lefthittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x += 150.0f * Time::DeltaTime();

		if (lefthittime >= 0.3f)
		{
			lefthittime = 0.0f;
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}
		tr->SetPos(pos);
	}
	void Kirby::rightbeambasehit()
	{
		righthittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x -= 150.0f * Time::DeltaTime();

		if (righthittime >= 0.3f)
		{
			righthittime = 0.0f;
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftbeamjumphitrelease()
	{
		beamjumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 200.0f * Time::DeltaTime();
		pos.x += 250.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (beamjumphitreleasetime >= 0.3f)
		{
			beamjumphitreleasetime = 0.0f;
			mState = eKirbyState::LeftBeamJumpHit;
			mAnimator->Play(L"LeftBeamJumpHit", false);
		}

		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mState = eKirbyState::LeftBeamDoubleJump;
			mAnimator->Play(L"LeftBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::rightbeamjumphitrelease()
	{
		beamjumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 200.0f * Time::DeltaTime();
		pos.x -= 250.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (beamjumphitreleasetime >= 0.3f)
		{
			beamjumphitreleasetime = 0.0f;
			mState = eKirbyState::RightBeamJumpHit;
			mAnimator->Play(L"RightBeamJumpHit", false);
		}

		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::RightBeamDoubleJump;
			mAnimator->Play(L"RightBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

	}
	void Kirby::leftbeamjumphit()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);
		}
		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mState = eKirbyState::LeftBeamDoubleJump;
			mAnimator->Play(L"LeftBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

	}
	void Kirby::rightbeamjumphit()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);
		}

		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			JumpCheck = true;
			mState = eKirbyState::RightBeamDoubleJump;
			mAnimator->Play(L"RightBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::leftbeampighit()
	{
		beamdoublejumphittime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 50.0f * Time::DeltaTime();
		pos.x += 100.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (beamdoublejumphittime >= 0.4f)
		{
			JumpCheck = true;
			beamdoublejumphittime = 0.0f;
			mState = eKirbyState::LeftBeamDoubleJump;
			mAnimator->Play(L"LeftBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}


	}
	void Kirby::rightbeampighit()
	{
		beamdoublejumphittime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 50.0f * Time::DeltaTime();
		pos.x -= 100.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (beamdoublejumphittime >= 0.4f)
		{
			JumpCheck = true;
			beamdoublejumphittime = 0.0f;
			mState = eKirbyState::RightBeamDoubleJump;
			mAnimator->Play(L"RightBeamDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	}