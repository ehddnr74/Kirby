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
#include "R3Ground.h"
#include "Star.h"
#include "StarMap.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "BrontoBurt.h"
#include "Beam.h"
#include "LeftBeam.h"
#include "Bros.h"
#include "Box.h"
#include "BoomBros.h"
#include "KirbyRightBoom.h"
#include "KirbyLeftBoom.h"
#include "LeftZoom.h"
#include "RightZoom.h"
#include "LeftBoomb.h"
#include "RightBoomb.h"
#include "TreeGround.h"
#include "Apple.h"
#include "Breath.h"


namespace My
{
	Kirby::Kirby()
		: kirbytime(0.0f)
		, KirbyHP(110)
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
		, beamuse(true)
		, beamcharging(false)
		, leftbeamtime(0.f)
		, beamjumping(false)
		, wbeamhittime(0.f)
		, lwbeamhittime(0.f)
		, LRjumpchange(false)
		, RLjumpchange(false)
		, Ljumptime(0.f)
		, Rjumptime(0.f)
		, jumpabsorbing(false)
		, jatime(0.0f) //임시
		, boomyamyam(false)

		, deathtime(0.f) //임시

		//붐 커비
		, boombkirbytime(0.f)
		, BoombKeyCheck(false)
		, boombjumptime(0.f)
		, BoombIsJump(false)
		, BoombAirShot(false)
		, boombjumping(false)
		, BoombDoubleJump(false)
		, boomend(0.f)
		, firstpos(0.f)
		, endpos(0.f)
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


		// 와들 빔 맞았을 때
		mAnimator->CreateAnimation(L"LeftHitBeam", mKirby, Vector2(0.0f, 1640.0f), 16, 100, 10, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"RightHitBeam", mKirby, Vector2(0.0f, 1680.0f), 16, 100, 10, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"LBJHR", mKirby, Vector2(0.0f, 1640.0f), 16, 100, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"RBJHR", mKirby, Vector2(0.0f, 1680.0f), 16, 100, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"LBJH", mKirby, Vector2(160.0f, 1640.0f), 16, 100, 6, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"RBJH", mKirby, Vector2(160.0f, 1680.0f), 16, 100, 6, Vector2::Zero, 0.15);

		mAnimator->CreateAnimation(L"LPBJHR", mKirby, Vector2(0.0f, 1720.0f), 16, 100, 4, Vector2::Zero, 0.15);
		mAnimator->CreateAnimation(L"RPBJHR", mKirby, Vector2(160.0f, 1720.0f), 16, 100, 4, Vector2::Zero, 0.15);


		// 점프 방향전환
		mAnimator->CreateAnimation(L"LRJumpChange", mKirby, Vector2(160.0f, 240.0f), 16, 100, 8, Vector2::Zero, 0.03);
		mAnimator->CreateAnimation(L"RLJumpChange", mKirby, Vector2(160.0f, 360.0f), 16, 100, 8, Vector2::Zero, 0.03);
		mAnimator->CreateAnimation(L"BeamLRJumpChange", mKirby, Vector2(400.0f, 1080.0f), 16, 100, 2, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"BeamRLJumpChange", mKirby, Vector2(400.0f, 1120.0f), 16, 100, 2, Vector2::Zero, 0.1);

		// 붐 커비
		mAnimator->CreateAnimation(L"LeftBoombTransform", mKirby, Vector2(80.0f, 1880.0f), 16, 100, 2, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"BoombTransform", mKirby, Vector2(0.0f, 1880.0f), 16, 100, 2, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBoombIdle", mKirby, Vector2(240.0f, 1840.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBoombIdle", mKirby, Vector2(0.0f, 1840.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftBoombWalk", mKirby, Vector2(0.0f, 1960.0f), 16, 100, 12, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBoombWalk", mKirby, Vector2(0.0f, 1920.0f), 16, 100, 12, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBoombDash", mKirby, Vector2(0.0f, 2040.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBoombDash", mKirby, Vector2(0.0f, 2000.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBoombDashRelease", mKirby, Vector2(320.0f, 2040.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBoombDashRelease", mKirby, Vector2(320.0f, 2000.0f), 16, 100, 1, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBoombCrouch", mKirby, Vector2(240.0f, 2080.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"RightBoombCrouch", mKirby, Vector2(0.0f, 2080.0f), 16, 100, 6, Vector2::Zero, 0.3);
		mAnimator->CreateAnimation(L"LeftBoombSliding", mKirby, Vector2(480.0f, 2080.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBoombSliding", mKirby, Vector2(520.0f, 2080.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBoombJump", mKirby, Vector2(0.0f, 2160.0f), 16, 100, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBoombJump", mKirby, Vector2(0.0f, 2120.0f), 16, 100, 12, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBoombDoubleJump", mKirby, Vector2(0.0f, 2240.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBoombDoubleJump", mKirby, Vector2(0.0f, 2200.0f), 16, 100, 8, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBoombJumpRelease", mKirby, Vector2(200.0f, 2240.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBoombJumpRelease", mKirby, Vector2(200.0f, 2200.0f), 16, 100, 3, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"LeftBoombAir", mKirby, Vector2(0.0f, 2320.0f), 16, 100, 11, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"RightBoombAir", mKirby, Vector2(0.0f, 2280.0f), 16, 100, 11, Vector2::Zero, 0.05);
		mAnimator->CreateAnimation(L"BoombLRJumpChange", mKirby, Vector2(160.0f, 2120.0f), 16, 100, 8, Vector2::Zero, 0.03);
		mAnimator->CreateAnimation(L"BoombRLJumpChange", mKirby, Vector2(160.0f, 2160.0f), 16, 100, 8, Vector2::Zero, 0.03);

		
		//
		//
		mAnimator->CreateAnimation(L"LeftBoomRelease", mKirby, Vector2(40.0f, 2440.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"LeftBoomShot", mKirby, Vector2(40.0f, 2480.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBoomRelease", mKirby, Vector2(0.0f, 2440.0f), 16, 100, 1, Vector2::Zero, 0.1);
		mAnimator->CreateAnimation(L"RightBoomShot", mKirby, Vector2(0.0f, 2480.0f), 16, 100, 1, Vector2::Zero, 0.1);

		


		//mAnimator->CreateAnimation(L"RightAirRelease", mKirby, Vector2(160.0f, 400.0f), 16, 16, 8, Vector2::Zero, 0.05);
		


		mAnimator->Play(L"RightIdle", false);

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
			break;
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
		case My::Kirby::eKirbyState::LeftBeamHit: // 와들빔
			leftbeamhit();
			break;
		case My::Kirby::eKirbyState::RightBeamHit: // 맞았을 때
			rightbeamhit();
			break;
		case My::Kirby::eKirbyState::LBJHR:
			lbjhr();
			break;
		case My::Kirby::eKirbyState::RBJHR:
			rbjhr();
			break;
		case My::Kirby::eKirbyState::LBJH: // 와들빔
			lbjh();
			break;
		case My::Kirby::eKirbyState::RBJH: // 맞았을 때
			rbjh();
			break;
		case My::Kirby::eKirbyState::LPBJHR:
			lpbjhr();
			break;
		case My::Kirby::eKirbyState::RPBJHR:
			rpbjhr();
			break;
		case My::Kirby::eKirbyState::LPBJH: // 와들빔
			lpbjh();
			break;
		case My::Kirby::eKirbyState::RPBJH: // 맞았을 때
			rpbjh();
			break;
		case My::Kirby::eKirbyState::LeftBoombIdle:
			leftboombidle();
			break;
		case My::Kirby::eKirbyState::RightBoombIdle:
			rightboombidle();
			break;
		case My::Kirby::eKirbyState::LeftBoombWalk:
			leftboombwalk();
			break;
		case My::Kirby::eKirbyState::RightBoombWalk:
			rightboombwalk();
			break;
		case My::Kirby::eKirbyState::LeftBoombTransform:
			leftboombtransform();
			break;
		case My::Kirby::eKirbyState::BoombTransform:
			boombtransform();
			break;
		case My::Kirby::eKirbyState::LeftBoombDash:
			leftboombdash();
			break;
		case My::Kirby::eKirbyState::RightBoombDash:
			rightboombdash();
			break;
		case My::Kirby::eKirbyState::LeftBoombDashRelease:
			leftboombdashrelease();
			break;
		case My::Kirby::eKirbyState::RightBoombDashRelease:
			rightboombdashrelease();
			break;
		case My::Kirby::eKirbyState::LeftBoombCrouch:
			leftboombcrouch();
			break;
		case My::Kirby::eKirbyState::RightBoombCrouch:
			rightboombcrouch();
			break;
		case My::Kirby::eKirbyState::LeftBoombSliding:
			leftboombsliding();
			break;
		case My::Kirby::eKirbyState::RightBoombSliding:
			rightboombsliding();
			break;
		case My::Kirby::eKirbyState::LeftBoombJump:
			leftboombjump();
			break;
		case My::Kirby::eKirbyState::RightBoombJump:
			rightboombjump();
			break;
		case My::Kirby::eKirbyState::LeftBoombDoubleJump:
			leftboombdoublejump();
			break;
		case My::Kirby::eKirbyState::RightBoombDoubleJump:
			rightboombdoublejump();
			break;
		case My::Kirby::eKirbyState::LeftBoomRelease:
			leftboomrelease();
			break;
		case My::Kirby::eKirbyState::RightBoomRelease:
			rightboomrelease();
			break;
		case My::Kirby::eKirbyState::LeftBoomShot:
			leftboomshot();
			break;
		case My::Kirby::eKirbyState::RightBoomShot:
			rightboomshot();
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
		////if (Box* mBox = dynamic_cast<Box*>(other->GetOwner()))
		//{
		//	if (mBox == nullptr)
		//		return;

		//	RigidBody* rb = this->GetComponent<RigidBody>();
		//}
		//	mState = eKirbyState::RightIdle;
		//	mAnimator->Play(L"RightIdle", true);
		//	rb->SetVelocity(Vector2::Zero);

		//	Collider* kirbycol = this->GetComponent<Collider>();
		//	Vector2 kirbypos = kirbycol->GetPos();

		//	Collider* boxcol = mBox->GetComponent<Collider>();
		//	Vector2 boxpos = boxcol->GetPos();



		//	float flen = fabs(kirbypos.y - boxpos.y);
		//	float fsize = (kirbycol->GetSize().y / 2.0f) + (boxcol->GetSize().y / 2.0f);

		//	if (flen < fsize)
		//	{
		//		Transform* kirbytr = this->GetComponent<Transform>();
		//		Transform* boxtr = mBox->GetComponent<Transform>();

		//		Vector2 kirpos = kirbytr->GetPos();
		//		Vector2 brpos = boxtr->GetPos();

		//		kirpos.y -= (fsize - flen) - 5.0f;
		//		kirbytr->SetPos(kirpos);
		//	}
		//}

		if (mBrontoBurt = dynamic_cast<BrontoBurt*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftBeamIdle || GetState() == eKirbyState::LeftBeamWalk || GetState() == eKirbyState::LeftBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				SetDamage(10);
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
				SetDamage(10);
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				SetDamage(10);
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
		if (mBros = dynamic_cast<Bros*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftBeamIdle || GetState() == eKirbyState::LeftBeamWalk || GetState() == eKirbyState::LeftBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				SetDamage(10);
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
		if (mBoomBros = dynamic_cast<BoomBros*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftBeamIdle || GetState() == eKirbyState::LeftBeamWalk || GetState() == eKirbyState::LeftBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				SetDamage(10);
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
				SetDamage(10);
				mState = eKirbyState::LeftBeamBaseHit;
				mAnimator->Play(L"LeftBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamIdle || GetState() == eKirbyState::RightBeamWalk || GetState() == eKirbyState::RightBeamDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamBaseHit;
				mAnimator->Play(L"RightBeamKirbyHit", false);
			}
			if (GetState() == eKirbyState::RightBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamJumpHitRelease;
				mAnimator->Play(L"RightBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftBeamJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamJumpHitRelease;
				mAnimator->Play(L"LeftBeamJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::RightBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamPigHit;
				mAnimator->Play(L"RightBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::LeftBeamDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftBeamPigHit;
				mAnimator->Play(L"LeftBeamDoubleJumpHit", false);
			}
			if (GetState() == eKirbyState::RightPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);;
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				SetDamage(10);
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
				SetDamage(10);
				mState = eKirbyState::RightPigJumpHitRelease;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigJumpHitRelease;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightPigIdle || GetState() == eKirbyState::RightPigWalk || GetState() == eKirbyState::RightPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightPigBaseHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftPigIdle || GetState() == eKirbyState::LeftPigWalk || GetState() == eKirbyState::LeftPigDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftPigBaseHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}

			if (GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
			if (GetState() == eKirbyState::RightMove || GetState() == eKirbyState::RightIdle || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::LeftDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);
			}
			if (GetState() == eKirbyState::LeftJump)
			{
				SetDamage(10);
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

		if (LeftBeam* mLeftBeam = dynamic_cast<LeftBeam*>(other->GetOwner()))
		{
			{
				if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::RightMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::RightIdle
					|| GetState() == eKirbyState::LeftDash || GetState() == eKirbyState::RightDash)
				{
					SetDamage(10);
					mState = eKirbyState::LeftBeamHit;
					mAnimator->Play(L"LeftHitBeam", false);
				}
				if (GetState() == eKirbyState::LeftJump || GetState() == eKirbyState::RightJump)
				{
					SetDamage(10);
					mState = eKirbyState::LBJHR;
					mAnimator->Play(L"LBJHR", false);
				}
				if (GetState() == eKirbyState::LeftDoubleJump || GetState() == eKirbyState::RightDoubleJump)
				{
					SetDamage(10);
					mState = eKirbyState::LPBJHR;
					mAnimator->Play(L"LPBJHR", false);
				}
			}
		}

		if (Beam* mBeam = dynamic_cast<Beam*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::RightMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::RightIdle
				|| GetState() == eKirbyState::LeftDash || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightBeamHit;
				mAnimator->Play(L"RightHitBeam", false);
			}

			if (GetState() == eKirbyState::LeftJump || GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RBJHR;
				mAnimator->Play(L"RBJHR", false);
			}
			if (GetState() == eKirbyState::LeftDoubleJump || GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RPBJHR;
				mAnimator->Play(L"RPBJHR", false);
			}
		}
		if (RightBoomb* mrb = dynamic_cast<RightBoomb*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::RightMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::RightIdle
				|| GetState() == eKirbyState::LeftDash || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::LeftHit;
				mAnimator->Play(L"LeftHit", false);
			}
			if (GetState() == eKirbyState::LeftJump || GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftJumpHitRelease;
				mAnimator->Play(L"LeftJumpHitRelease", false);

			}
			if (GetState() == eKirbyState::LeftDoubleJump || GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::LeftAbsorbPigHit;
				mAnimator->Play(L"LeftAbsorbPigHit", false);
			}
		}

		if (LeftBoomb* mlb = dynamic_cast<LeftBoomb*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::RightMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::RightIdle
				|| GetState() == eKirbyState::LeftDash || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftJump || GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);

			}
			if (GetState() == eKirbyState::LeftDoubleJump || GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
		}
		if (Breath* mBreath = dynamic_cast<Breath*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::RightMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::RightIdle
				|| GetState() == eKirbyState::LeftDash || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftJump || GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);

			}
			if (GetState() == eKirbyState::LeftDoubleJump || GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
		}
		if (Apple* mApple = dynamic_cast<Apple*>(other->GetOwner()))
		{
			if (GetState() == eKirbyState::LeftMove || GetState() == eKirbyState::RightMove || GetState() == eKirbyState::LeftIdle || GetState() == eKirbyState::RightIdle
				|| GetState() == eKirbyState::LeftDash || GetState() == eKirbyState::RightDash)
			{
				SetDamage(10);
				mState = eKirbyState::RightHit;
				mAnimator->Play(L"RightHit", false);
			}
			if (GetState() == eKirbyState::LeftJump || GetState() == eKirbyState::RightJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightJumpHitRelease;
				mAnimator->Play(L"RightJumpHitRelease", false);

			}
			if (GetState() == eKirbyState::LeftDoubleJump || GetState() == eKirbyState::RightDoubleJump)
			{
				SetDamage(10);
				mState = eKirbyState::RightAbsorbPigHit;
				mAnimator->Play(L"RightAbsorbPigHit", false);
			}
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
			KeyCheck = false;
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
			LeftAbsorb = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 70, pos.y - 10), Vector2(2.5f, 1.3f), eLayerType::Skill);
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
			KeyCheck = false;
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
				Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 70, pos.y - 15), Vector2(2.5f, 1.3f), eLayerType::Skill);
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
			LeftAbsorb = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 70, pos.y - 10), Vector2(2.5f, 1.3f), eLayerType::Skill);
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

		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightMove;
			mAnimator->Play(L"RightWalk", true);
		}

		if (/*mRigidBody->GetGround() &&*/Input::GetKeyDown(eKeyCode::A))
		{
			KeyCheck = false;
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

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 70, pos.y - 15), Vector2(2.5f, 1.3f), eLayerType::Skill);

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
		//deathtime += Time::DeltaTime();
		//if (deathtime >= 0.5f)
		//{
		//object::Destroy(this);
		//}

	}
	void Kirby::leftabsorb()
	{
		if (IsJump == false && Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(LeftAbsorb);
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}
		if (IsJump == false)
		{
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
			if (LeftAbsorb->GetCollision() == 3) //붐 먹었을 때 
			{
				starshot = true;
				GetMonster = true;
				boomyamyam = true;
				mState = eKirbyState::LeftColAbsorb;
			}
		}

		if (IsJump)
		{
			if (Input::GetKey(eKeyCode::Left))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				pos.x -= 100.0f * Time::DeltaTime();
				tr->SetPos(pos);
			}
			if (mRigidBody->GetGround())
			{
				jatime = 0.0f;
				Ljumptime = 0.0f;
				Rjumptime = 0.0f;
				jumptime = 0.0f;
				LRjumpchange = false;
				RLjumpchange = false;
				jumpabsorbing = false;
				leftjumpabsorbing = false;
				IsJump = false;
				object::Destroy(LeftAbsorb);
				mState = eKirbyState::LeftIdle;
				mAnimator->Play(L"LeftIdle", true);
			}
			if (LeftAbsorb->GetCollision() == 1) //일반 몬스터 먹었을 때
			{
				Rjumptime = 0.0f;
				Ljumptime = 0.0f;
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				mState = eKirbyState::LeftColAbsorb;
			}
			if (LeftAbsorb->GetCollision() == 2) // 와들을 먹었을 때
			{
				Rjumptime = 0.0f;
				Ljumptime = 0.0f;
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				// 아무 몬스터를 머금었을때 true
				yamyam = true; // 와들을 먹었을 때 true
				mState = eKirbyState::LeftColAbsorb;
			}
			if (LeftAbsorb->GetCollision() == 3) //붐 먹었을 때 
			{
				Rjumptime = 0.0f;
				Ljumptime = 0.0f;
				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				boomyamyam = true;
				mState = eKirbyState::LeftColAbsorb;
			}
		}


	}
	void Kirby::rightabsorb()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (IsJump == false && Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(Absorb);
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}

		if (IsJump == false)
		{
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
			if (Absorb->GetCollision() == 3) //붐 먹었을 때 
			{
				starshot = true;
				GetMonster = true;
				boomyamyam = true;
				mState = eKirbyState::RightColAbsorb;
			}
		}

		if (IsJump)
		{
			if (Input::GetKey(eKeyCode::Right))
			{
				Transform* tr = GetComponent<Transform>();
				Vector2 pos = tr->GetPos();
				pos.x += 100.0f * Time::DeltaTime();
				tr->SetPos(pos);
			}
			if (mRigidBody->GetGround())
			{
				jatime = 0.0f;
				Ljumptime = 0.0f;
				Rjumptime = 0.0f;
				jumptime = 0.0f;
				LRjumpchange = false;
				RLjumpchange = false;
				jumpabsorbing = false;
				leftjumpabsorbing = false;
				IsJump = false;
				
				object::Destroy(Absorb);
				mState = eKirbyState::RightIdle;
				mAnimator->Play(L"RightIdle", true);
			}
			if (Absorb->GetCollision() == 1) //일반 몬스터 먹었을 때
			{
				Rjumptime = 0.0f;
				Ljumptime = 0.0f;
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				mState = eKirbyState::RightColAbsorb;
			}
			if (Absorb->GetCollision() == 2) // 와들을 먹었을 때
			{
				Rjumptime = 0.0f;
				Ljumptime = 0.0f;
				mRigidBody->SetVelocity(Vector2::Zero);

				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				// 아무 몬스터를 머금었을때 true
				yamyam = true; // 와들을 먹었을 때 true
				mState = eKirbyState::RightColAbsorb;
			}
			if (Absorb->GetCollision() == 3) //붐 먹었을 때 
			{
				Rjumptime = 0.0f;
				Ljumptime = 0.0f;
				jumpabsolb = true;
				starshot = true;
				GetMonster = true;
				boomyamyam = true;
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
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBeamTransform;
			mAnimator->Play(L"LeftBeamTransform", false);
		}
		if (yamyam == false && boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBoombTransform;
			mAnimator->Play(L"LeftBoombTransform", false);
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
			kirbytime = 0.0f;
			mState = eKirbyState::BeamTransform;
			mAnimator->Play(L"RightBeamTransform", false);
		}

		if (yamyam == false && boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::BoombTransform;
			mAnimator->Play(L"BoombTransform", false);
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
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBeamTransform;
			mAnimator->Play(L"LeftBeamTransform", false);
		}
		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBoombTransform;
			mAnimator->Play(L"LeftBoombTransform", false);
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
			kirbytime = 0.0f;
			mState = eKirbyState::BeamTransform;
			mAnimator->Play(L"RightBeamTransform", false);
		}
		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::BoombTransform;
			mAnimator->Play(L"BoombTransform", false);
		}
	}
	void Kirby::leftpigidle()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			yamyam = false;
			boomyamyam = false;
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
		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBoombTransform;
			mAnimator->Play(L"LeftBoombTransform", false);
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

		//if (yamyam == false && Input::GetKeyDown(eKeyCode::Down))
		//{
		//	kirbytime = 0.0f;
		//	mState = eKirbyState::LeftPigClear;
		//	mAnimator->Play(L"LeftPigClear", false);
		//}
		if (yamyam == false && boomyamyam == false && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
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
			boomyamyam = false;
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

		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::BoombTransform;
			mAnimator->Play(L"BoombTransform", false);
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

		//if (yamyam == false && Input::GetKeyDown(eKeyCode::Down))
		//{
		//	kirbytime = 0.0f;
		//	mState = eKirbyState::RightPigClear;
		//	mAnimator->Play(L"RightPigClear", false);
		//}
		if (yamyam == false && boomyamyam == false && Input::GetKeyDown(eKeyCode::Down))
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
			boomyamyam = false;
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

			if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
			{
				kirbytime = 0.0f;
				mState = eKirbyState::LeftBoombTransform;
				mAnimator->Play(L"LeftBoombTransform", false);
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
			boomyamyam = false;
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
		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Down))
		{
			kirbytime = 0.0f;
			mState = eKirbyState::BoombTransform;
			mAnimator->Play(L"BoombTransform", false);
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
			boomyamyam = false;
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
			boomyamyam = false;
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
		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Z))
		{
			boomyamyam = false;
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
		if (boomyamyam == true && Input::GetKeyDown(eKeyCode::Z))
		{
			boomyamyam = false;
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


		IsJump = true;
		AirShot = true;

		jatime += Time::DeltaTime();
		jumptime += Time::DeltaTime();
		Ljumptime += Time::DeltaTime();

		if (RLjumpchange)
		{
			jatime = 0.0f;
			jumptime = 0.0f;
			mRigidBody->SetVelocity(Vector2(-100.f,180.0f));
		}
		if (Ljumptime >=0.5f && Input::GetKey(eKeyCode::Right))
		{
			Ljumptime = 0.0f;
			LRjumpchange = true;
			mState = eKirbyState::RightJump;
			mAnimator->Play(L"LRJumpChange", false);
		}

		if (jumptime >= 0.2f)
		{
			JumpCheck = false;
			jumptime = 0.0f;
		}


		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}



		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			kirbytime = 0.0f;
			jumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jatime = 0.0f;
			JumpCheck = true;
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		if (jatime > 0.4f && Input::GetKeyDown(eKeyCode::Z))
		{
			jatime = 0.0f;
			leftjumpabsorbing = true;

			mRigidBody->SetVelocity(Vector2::Zero);
			LeftAbsorb = object::Instantiate<AbsorbLeftEffect>(Vector2(pos.x - 70, pos.y - 10), Vector2(2.5f, 1.3f), eLayerType::Skill);
			LeftAbsorb->SetKirby(this);
			mState = eKirbyState::LeftAbsorb;
			mAnimator->Play(L"LeftAbsorbing", true);
		}

		tr->SetPos(pos);


		if (mRigidBody->GetGround() == true)
		{
			jatime = 0.0f;
			leftjumpabsorbing = false;
			jumpabsorbing = false;
			LRjumpchange = false;
			RLjumpchange = false;
			jumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			IsJump = false;
			JumpCheck = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
		}

	}

	void Kirby::rightjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		jatime += Time::DeltaTime();
		jumptime += Time::DeltaTime();
		Rjumptime += Time::DeltaTime();

		if (LRjumpchange)
		{
			jatime = 0.0f;
			jumptime = 0.0f;
			mRigidBody->SetVelocity(Vector2(+100.f, 180.0f));
		}

		if (Rjumptime >=0.5f && Input::GetKey(eKeyCode::Left))
		{
			Rjumptime = 0.0f;
			RLjumpchange = true;
			mState = eKirbyState::LeftJump;
			mAnimator->Play(L"RLJumpChange", false);
		}

		if (jumptime >= 0.2f)
		{
			JumpCheck = false;
			jumptime = 0.0f;
		}
		IsJump = true;
		AirShot = true;


		if (jatime > 0.4f && Input::GetKeyDown(eKeyCode::Z))
		{
			jatime = 0.0f;
			jumpabsorbing = true;

			mRigidBody->SetVelocity(Vector2::Zero);
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			Absorb = object::Instantiate<AbsorbEffect>(Vector2(pos.x + 70, pos.y - 15), Vector2(2.5f, 1.3f), eLayerType::Skill);
			Absorb->SetKirby(this);

			mState = eKirbyState::RightAbsorb;
			mAnimator->Play(L"RightAbsorbing", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 50.0f * Time::DeltaTime();
		}


		if (IsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{	
			kirbytime = 0.0f;
			jumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jatime = 0.0f;
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
			jatime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jumptime = 0.0f;
			LRjumpchange = false;
			RLjumpchange = false;
			jumpabsorbing = false;
			leftjumpabsorbing = false;
			IsJump = false;
			JumpCheck = false;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);

			mRigidBody->SetVelocity(Vector2::Zero);
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

		if (beamjumping == false && Input::GetKeyUp(eKeyCode::Z) && chargingtime <= 0.5f)
		{
			chargingtime = 0.0f;
			mLeftKirbyBeam = object::Instantiate<LeftKirbyBeam>(Vector2(pos.x - 100, pos.y + 80), Vector2(1.2f, 1.2f), eLayerType::Skill);

			mLeftKirbyBeam->SetKirby(this);

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

		if (beamjumping == false && Input::GetKeyUp(eKeyCode::Z) && chargingtime <=0.5f)
		{
			chargingtime = 0.0f;
			mKirbyBeam = object::Instantiate<KirbyBeam>(Vector2(pos.x + 100, pos.y +80), Vector2(1.2f, 1.2f), eLayerType::Skill);
			mKirbyBeam->SetKirby(this);
			
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

		if (beamjumping == false && Input::GetKeyUp(eKeyCode::Z) && chargingtime <= 0.5f)
		{
			beamcharging = false;
			chargingtime = 0.0f;

			mLeftKirbyBeam = object::Instantiate<LeftKirbyBeam>(Vector2(pos.x - 100, pos.y + 80), Vector2(1.2f, 1.2f), eLayerType::Skill);

			mLeftKirbyBeam->SetKirby(this);

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
				BeamKeyCheck = false;
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

		if (beamjumping == false && Input::GetKeyUp(eKeyCode::Z) && chargingtime <= 0.5f)
		{
			beamcharging = false;
			chargingtime = 0.0f;
			mKirbyBeam = object::Instantiate<KirbyBeam>(Vector2(pos.x + 100, pos.y + 80), Vector2(1.2f, 1.2f), eLayerType::Skill);
			mKirbyBeam->SetKirby(this);

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
				BeamKeyCheck = false;
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

		leftslidingtime += Time::DeltaTime();

		if (leftslidingtime < 0.5f)
		{
			pos.x -= 250.f * Time::DeltaTime();
		}
		if (0.5f < leftslidingtime
			&& leftslidingtime < 0.8f)
		{
			pos.x -= 10.f * Time::DeltaTime();
		}
		if (leftslidingtime > 0.8f)
		{
			leftslidingtime = 0.0f;
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

		slidingtime += Time::DeltaTime();

		if (slidingtime < 0.5f)
		{
			pos.x += 250.f * Time::DeltaTime();
		}
		if (0.5f < slidingtime
			&& slidingtime < 0.8f)
		{
			pos.x += 10.f * Time::DeltaTime();
		}
		if (slidingtime > 0.8f)
		{
			slidingtime = 0.0f;
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

		jatime += Time::DeltaTime();
		beamjumptime += Time::DeltaTime();
		Ljumptime += Time::DeltaTime();

		BeamIsJump = true;
		BeamAirShot = true;



		if (mRigidBody->GetGround() == true)
		{
			JumpCheck = false;
			LRjumpchange = false;
			RLjumpchange = false;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			beamjumptime = 0.0f;
			beamjumping = false;
			jatime = 0.0f;
			mState = eKirbyState::LeftBeamIdle;
			mAnimator->Play(L"LeftBeamIdle", true);

			//jumptime = 0.0f;
			//IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		if (jatime > 0.4f && Input::GetKeyDown(eKeyCode::Z))
		{
			jatime = 0.0f;
			LRjumpchange = false;
			RLjumpchange = false;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			beamjumptime = 0.0f;
			beamjumping = true;
			mLeftKirbyBeam = object::Instantiate<LeftKirbyBeam>(Vector2(pos.x - 100, pos.y + 80), Vector2(1.2f, 1.2f), eLayerType::Skill);
			mLeftKirbyBeam->SetKirby(this);

			mState = eKirbyState::LeftBeam;
			mAnimator->Play(L"LeftBeam", false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}

		if (RLjumpchange)
		{
			jumptime = 0.0f;
			mRigidBody->SetVelocity(Vector2(-100.f, 180.0f));
		}
		if (Ljumptime >= 0.5f && Input::GetKey(eKeyCode::Right))
		{
			Ljumptime = 0.0f;
			LRjumpchange = true;
			mState = eKirbyState::RightBeamJump;
			mAnimator->Play(L"BeamLRJumpChange", false);
		}

		if (beamjumptime >= 0.2f)
		{
			JumpCheck = false;
			beamjumptime = 0.0f;
		}

		if (BeamIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			beamkirbytime = 0.0f;
			beamjumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jatime = 0.0f;
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
		Rjumptime += Time::DeltaTime();
		jatime += Time::DeltaTime();

		BeamIsJump = true;
		BeamAirShot = true;

		if (mRigidBody->GetGround() == true)
		{
			JumpCheck = false;
			LRjumpchange = false;
			RLjumpchange = false;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			beamjumptime = 0.0f;
			beamjumping = false;
			jatime = 0.0f;
			mState = eKirbyState::RightBeamIdle;
			mAnimator->Play(L"RightBeamIdle", true);

			//IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		if (jatime > 0.4f &&Input::GetKeyDown(eKeyCode::Z))
		{
			jatime = 0.0f;
			LRjumpchange = false;
			RLjumpchange = false;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			beamjumptime = 0.0f;
			beamjumping = true;
			//mRigidBody->SetVelocity(Vector2::Zero);
			

			mKirbyBeam = object::Instantiate<KirbyBeam>(Vector2(pos.x + 100, pos.y + 80), Vector2(1.2f, 1.2f), eLayerType::Skill);
			mKirbyBeam->SetKirby(this);

			
			mState = eKirbyState::RightBeam;
			mAnimator->Play(L"RightBeam", false);
		}


		if (LRjumpchange)
		{
			mRigidBody->SetVelocity(Vector2(+100.f, 180.0f));
		}

		if (Rjumptime >= 0.5f && Input::GetKey(eKeyCode::Left))
		{
			Rjumptime = 0.0f;
			RLjumpchange = true;
			mState = eKirbyState::LeftBeamJump;
			mAnimator->Play(L"BeamRLJumpChange", false);
		}


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
			beamkirbytime = 0.0f;
			beamjumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jatime = 0.0f;
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
		leftbeamtime += Time::DeltaTime();


		if (mRigidBody->GetGround() == true)
		{
			mRigidBody->SetVelocity(Vector2(0.0f, 0.0f));
			if (leftbeamtime >= 0.35f)
			{
				beamjumping = false;
				//mRigidBody->SetVelocity(Vector2(0.0f, 0.0f));
				leftbeamtime = 0.0f;
				mState = eKirbyState::LeftBeamIdle;
				mAnimator->Play(L"LeftBeamIdle", true);
			}
		}
	}

	void Kirby::rightbeam()
	{
		beamtime += Time::DeltaTime();


		if (mRigidBody->GetGround() == true)
		{
			mRigidBody->SetVelocity(Vector2(0.0f, 0.0f));
			if (beamtime >= 0.35f)
			{
				beamjumping = false;
				//mRigidBody->SetVelocity(Vector2(0.0f, 0.0f));
				beamtime = 0.0f;
				mState = eKirbyState::RightBeamIdle;
				mAnimator->Play(L"RightBeamIdle", true);
			}
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
	void Kirby::leftbeamhit()
	{
		lwbeamhittime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.x -= 150.0f * Time::DeltaTime();

		if (lwbeamhittime >= 1.0f)
		{
			lwbeamhittime = 0.0f;
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
		}
		tr->SetPos(pos);
	}
	void Kirby::rightbeamhit()
	{
			wbeamhittime += Time::DeltaTime();

			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();

			pos.x += 150.0f * Time::DeltaTime();

			if (wbeamhittime >= 1.0f)
			{
				wbeamhittime = 0.0f;
				mState = eKirbyState::LeftIdle;
				mAnimator->Play(L"LeftIdle", true);
			}
			tr->SetPos(pos);
		}
	void Kirby::lbjhr()
	{
		jumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 150.0f * Time::DeltaTime();
		pos.x -= 150.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (jumphitreleasetime >= 0.5f)
		{
			jumphitreleasetime = 0.0f;
			mState = eKirbyState::LBJH;
			mAnimator->Play(L"LBJH", false);
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
	void Kirby::lbjh()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::RightIdle;
			mAnimator->Play(L"RightIdle", true);
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
	void Kirby::rbjhr()
	{
		jumphitreleasetime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 150.0f * Time::DeltaTime();
		pos.x += 150.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (jumphitreleasetime >= 0.5f)
		{
			jumphitreleasetime = 0.0f;
			mState = eKirbyState::RBJH;
			mAnimator->Play(L"RBJH", false);
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
	void Kirby::rbjh()
	{
		if (mRigidBody->GetGround() == true)
		{
			mState = eKirbyState::LeftIdle;
			mAnimator->Play(L"LeftIdle", true);
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
	void Kirby::lpbjhr()
	{
		leftdoublejumphittime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 50.0f * Time::DeltaTime();
		pos.x -= 100.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (leftdoublejumphittime >= 0.6f)
		{
			JumpCheck = true;
			leftdoublejumphittime = 0.0f;
			mState = eKirbyState::RightDoubleJump;
			mAnimator->Play(L"RightDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::lpbjh()
	{
	}
	void Kirby::rpbjhr()
	{
		rightdoublejumphittime += Time::DeltaTime();

		Vector2 velocity = mRigidBody->GetVelocity();

		mRigidBody->SetVelocity(Vector2::Zero);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		pos.y -= 50.0f * Time::DeltaTime();
		pos.x += 100.0f * Time::DeltaTime();

		tr->SetPos(pos);

		if (rightdoublejumphittime >= 0.6f)
		{
			JumpCheck = true;
			rightdoublejumphittime = 0.0f;
			mState = eKirbyState::LeftDoubleJump;
			mAnimator->Play(L"LeftDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::rpbjh()
	{
	}
	void Kirby::leftboombidle()
	{
		boombkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::S))
		{
			boomyamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
			kirbyLeftBoom* mLeftBoom = object::Instantiate<kirbyLeftBoom>(Vector2(pos.x + 10, pos.y - 65), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Skill));
			SetLeftBoom(mLeftBoom);
			if (gr2 != nullptr)
			{
				gr2->SetKirLeftBoomb(mLeftBoom);
			}
			if (gr3 != nullptr)
			{
				gr3->SetKirLeftBoomb(mLeftBoom);
			}
			if (gr4 != nullptr)
			{
				gr4->SetKirLeftBoomb(mLeftBoom);
			}
			LeftZoom* mLeftZoom = object::Instantiate<LeftZoom>(Vector2(pos.x - 35, pos.y - 10), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			SetLeftZoom(mLeftZoom);

			Transform* rr = mLeftZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			firstpos = zPos.y;

			endpos = firstpos - 35;

			mState = eKirbyState::LeftBoomRelease;
			mAnimator->Play(L"LeftBoomRelease", false);


		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftBoombJump;

			mAnimator->Play(L"LeftBoombJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombWalk;
			mAnimator->Play(L"LeftBoombWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombWalk;
			mAnimator->Play(L"RightBoombWalk", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::LeftBoombCrouch;
			mAnimator->Play(L"LeftBoombCrouch", true);
		}

		if (boombkirbytime <= 0.15f && BoombKeyCheck && GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mState = eKirbyState::LeftBoombDash;
			mAnimator->Play(L"LeftBoombDash", true);
		}
	}
	void Kirby::rightboombidle()
	{
		boombkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyDown(eKeyCode::S))
		{
			boomyamyam = false;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
			kirbyRightBoom* mRightBoom = object::Instantiate<kirbyRightBoom>(Vector2(pos.x - 10, pos.y - 65), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Skill));
			SetRightBoom(mRightBoom);
			if (gr2 != nullptr)
			{
				gr2->SetKirBoomb(mRightBoom);
			}
			if (gr3 != nullptr)
			{
				gr3->SetKirBoomb(mRightBoom);
			}
			if (gr4 != nullptr)
			{
				gr4->SetKirBoomb(mRightBoom);
			}
			RightZoom* mRightZoom = object::Instantiate<RightZoom>(Vector2(pos.x + 35, pos.y - 10), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			SetRightZoom(mRightZoom);

			Transform* rr = mRightZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			firstpos = zPos.y;

			endpos = firstpos - 35;

			mState = eKirbyState::RightBoomRelease;
			mAnimator->Play(L"RightBoomRelease", false);
		}


		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightBoombJump;

			mAnimator->Play(L"RightBoombJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombWalk;
			mAnimator->Play(L"LeftBoombWalk", true);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombWalk;
			mAnimator->Play(L"RightBoombWalk", true);
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = eKirbyState::RightBoombCrouch;
			mAnimator->Play(L"RightBoombCrouch", true);
		}

		if (boombkirbytime <= 0.15f && BoombKeyCheck && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mState = eKirbyState::RightBoombDash;
			mAnimator->Play(L"RightBoombDash", true);
		}
	}
	void Kirby::leftboombwalk()
	{
		BoombKeyCheck = true;
        boombkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


		if (Input::GetKeyDown(eKeyCode::S))
		{
			boomyamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}
		if (Input::GetKeyDown(eKeyCode::Z))
		{
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
			kirbyLeftBoom* mLeftBoom = object::Instantiate<kirbyLeftBoom>(Vector2(pos.x + 10, pos.y - 65), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Skill));
			SetLeftBoom(mLeftBoom);
			if (gr2 != nullptr)
			{
				gr2->SetKirLeftBoomb(mLeftBoom);
			}
			if (gr3 != nullptr)
			{
				gr3->SetKirLeftBoomb(mLeftBoom);
			}
			if (gr4 != nullptr)
			{
				gr4->SetKirLeftBoomb(mLeftBoom);
			}
			LeftZoom* mLeftZoom = object::Instantiate<LeftZoom>(Vector2(pos.x - 35, pos.y - 10), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			SetLeftZoom(mLeftZoom);

			Transform* rr = mLeftZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			firstpos = zPos.y;

			endpos = firstpos - 35;
			mState = eKirbyState::LeftBoomRelease;
			mAnimator->Play(L"LeftBoomRelease", false);
		}
		if (Input::GetKeyDown(eKeyCode::A))
		{
			BoombKeyCheck = false;
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftBoombJump;

			mAnimator->Play(L"LeftBoombJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombWalk;
			mAnimator->Play(L"RightBoombWalk", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 120.0f * Time::DeltaTime();

			if (Input::GetKey(eKeyCode::Right))
			{
				mState = eKirbyState::RightBoombWalk;
				mAnimator->Play(L"RightBoombWalk", true);
			}

			if (Input::GetKey(eKeyCode::Down))
			{
				mState = eKirbyState::LeftBoombCrouch;
				mAnimator->Play(L"LeftBoombCrouch", true);
			}

		}

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
			boombkirbytime = 0.0f;
		}

		tr->SetPos(pos);
	}
	void Kirby::rightboombwalk()
	{
		
		BoombKeyCheck = true;
		boombkirbytime += Time::DeltaTime();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


			if (Input::GetKeyDown(eKeyCode::S))
			{
				boomyamyam = false;
				mState = eKirbyState::RightPigClear;
				mAnimator->Play(L"RightPigClear", false);
			}

			if (Input::GetKeyDown(eKeyCode::Z))
			{
				BoombKeyCheck = false;
				boombkirbytime = 0.0f;
				kirbyRightBoom* mRightBoom = object::Instantiate<kirbyRightBoom>(Vector2(pos.x - 10, pos.y - 65), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Skill));
				SetRightBoom(mRightBoom);
				if (gr2 != nullptr)
				{
					gr2->SetKirBoomb(mRightBoom);
				}
				if (gr3 != nullptr)
				{
					gr3->SetKirBoomb(mRightBoom);
				}
				if (gr4 != nullptr)
				{
					gr4->SetKirBoomb(mRightBoom);
				}
				RightZoom* mRightZoom = object::Instantiate<RightZoom>(Vector2(pos.x + 35, pos.y - 10), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
				SetRightZoom(mRightZoom);

				Transform* rr = mRightZoom->GetComponent<Transform>();
				Vector2 zPos = rr->GetPos();

				firstpos = zPos.y;

				endpos = firstpos - 35;

				mState = eKirbyState::RightBoomRelease;
				mAnimator->Play(L"RightBoomRelease", false);
			}

			if (Input::GetKeyDown(eKeyCode::A))
			{
				BoombKeyCheck = false;
				JumpCheck = true;
				mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
				mState = eKirbyState::RightBoombJump;

				mAnimator->Play(L"RightBoombJump", false);

				Vector2 velocity = mRigidBody->GetVelocity();
				velocity.x += 100.0f;
				velocity.y -= 400.0f;


				mRigidBody->SetVelocity(velocity);
				mRigidBody->SetGround(false);
			}

			if (Input::GetKey(eKeyCode::Left))
			{
				mState = eKirbyState::LeftBoombWalk;
				mAnimator->Play(L"LeftBoombWalk", true);
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				pos.x += 120.0f * Time::DeltaTime();

				if (Input::GetKey(eKeyCode::Left))
				{
					mState = eKirbyState::LeftBoombWalk;
					mAnimator->Play(L"LeftBoombWalk", true);
				}

				if (Input::GetKey(eKeyCode::Down))
				{
					mState = eKirbyState::RightBoombCrouch;
					mAnimator->Play(L"RightBoombCrouch", true);
				}

			}

			if (Input::GetKeyUp(eKeyCode::Right))
			{
				mState = eKirbyState::RightBoombIdle;
				mAnimator->Play(L"RightBoombIdle", true);
				boombkirbytime = 0.0f;
			}

		tr->SetPos(pos);
	}
	void Kirby::boombtransform()
	{
		kirbytime += Time::DeltaTime();
		if (kirbytime > 0.4f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
		}
	}
	void Kirby::leftboombtransform()
	{
		kirbytime += Time::DeltaTime();

		if (kirbytime > 0.4f)
		{
			kirbytime = 0.0f;
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
		}
	}
	void Kirby::leftboombdash()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombDashRelease;
			mAnimator->Play(L"LeftBoombDashRelease", false);
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}
		if (Input::GetKeyDown(eKeyCode::Z))
		{
			boombkirbytime = 0.0f;
			kirbyLeftBoom* mLeftBoom = object::Instantiate<kirbyLeftBoom>(Vector2(pos.x + 10, pos.y - 65), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Skill));
			SetLeftBoom(mLeftBoom);
			if (gr2 != nullptr)
			{
				gr2->SetKirLeftBoomb(mLeftBoom);
			}
			if (gr3 != nullptr)
			{
				gr3->SetKirLeftBoomb(mLeftBoom);
			}
			if (gr4 != nullptr)
			{
				gr4->SetKirLeftBoomb(mLeftBoom);
			}
			LeftZoom* mLeftZoom = object::Instantiate<LeftZoom>(Vector2(pos.x - 35, pos.y - 10), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			SetLeftZoom(mLeftZoom);

			Transform* rr = mLeftZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			firstpos = zPos.y;

			endpos = firstpos - 35;
			mState = eKirbyState::LeftBoomRelease;
			mAnimator->Play(L"LeftBoomRelease", false);
		}
		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::LeftBoombJump;

			mAnimator->Play(L"LeftBoombJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x -= 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}


		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 200.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::rightboombdash()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();


		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombDashRelease;
			mAnimator->Play(L"RightBoombDashRelease", false);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			yamyam = false;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			boombkirbytime = 0.0f;
			kirbyRightBoom* mRightBoom = object::Instantiate<kirbyRightBoom>(Vector2(pos.x - 10, pos.y - 65), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Skill));
			SetRightBoom(mRightBoom);
			if (gr2 != nullptr)
			{
				gr2->SetKirBoomb(mRightBoom);
			}
			if (gr3 != nullptr)
			{
				gr3->SetKirBoomb(mRightBoom);
			}
			if (gr4 != nullptr)
			{
				gr4->SetKirBoomb(mRightBoom);
			}
			RightZoom* mRightZoom = object::Instantiate<RightZoom>(Vector2(pos.x + 35, pos.y - 10), Vector2(2.0f, 2.0f), eLayerType(eLayerType::Effect));
			SetRightZoom(mRightZoom);

			Transform* rr = mRightZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			firstpos = zPos.y;

			endpos = firstpos - 35;
			mState = eKirbyState::RightBoomRelease;
			mAnimator->Play(L"RightBoomRelease", false);
		}

		if (Input::GetKeyDown(eKeyCode::A))
		{
			JumpCheck = true;
			mRigidBody->SetGravity(Vector2(0.0f, 800.0f));
			mState = eKirbyState::RightBoombJump;

			mAnimator->Play(L"RightBoombJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			velocity.x += 100.0f;
			velocity.y -= 400.0f;


			mRigidBody->SetVelocity(velocity);
			mRigidBody->SetGround(false);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 200.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::leftboombdashrelease()
	{
		boombkirbytime += Time::DeltaTime();

		if (boombkirbytime >= 0.3f)
		{
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
		}

		if (boombkirbytime >= 0.2f && Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
		}
	}
	void Kirby::rightboombdashrelease()
	{
		boombkirbytime += Time::DeltaTime();

		if (boombkirbytime >= 0.3f)
		{
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
		}

		if (boombkirbytime >= 0.2f && Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
			BoombKeyCheck = false;
			boombkirbytime = 0.0f;
		}
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
		}
	}
	void Kirby::leftboombcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			boomyamyam = false;
			mState = eKirbyState::LeftPigClear;
			mAnimator->Play(L"LeftPigClear", false);
		}

		if (BoombDoubleJump)
		{
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
			BoombDoubleJump = false;
		}
		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = eKirbyState::LeftBoombSliding;
			mAnimator->Play(L"LeftBoombSliding", false);
		}
	}
	void Kirby::rightboombcrouch()
	{
		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
		}
		if (Input::GetKeyDown(eKeyCode::S))
		{
			boomyamyam = false;
			mState = eKirbyState::RightPigClear;
			mAnimator->Play(L"RightPigClear", false);
		}

		if (BoombDoubleJump)
		{
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
			BoombDoubleJump = false;
		}
		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = eKirbyState::RightBoombSliding;
			mAnimator->Play(L"RightBoombSliding", false);
		}
	}
	void Kirby::leftboombsliding()
	{
		Leftsliding = true;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		leftslidingtime += Time::DeltaTime();

		if (leftslidingtime < 0.5f)
		{
			pos.x -= 250.f * Time::DeltaTime();
		}
		if (0.5f < leftslidingtime
			&& leftslidingtime < 0.8f)
		{
			pos.x -= 10.f * Time::DeltaTime();
		}
		if (leftslidingtime > 0.8f)
		{
			leftslidingtime = 0.0f;
			Leftsliding = false;
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::rightboombsliding()
	{
		sliding = true;
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		slidingtime += Time::DeltaTime();

		if (slidingtime < 0.5f)
		{
			pos.x += 250.f * Time::DeltaTime();
		}
		if (0.5f < slidingtime
			&& slidingtime < 0.8f)
		{
			pos.x += 10.f * Time::DeltaTime();
		}
		if (slidingtime > 0.8f)
		{
			slidingtime = 0.0f;
			sliding = false;
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftboombjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		boombjumptime += Time::DeltaTime();
		Ljumptime += Time::DeltaTime();
		jatime += Time::DeltaTime();

		BoombIsJump = true;
		BoombAirShot = true;

		if (mRigidBody->GetGround() == true)
		{
			JumpCheck = false;
			LRjumpchange = false;
			RLjumpchange = false;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			boombjumptime = 0.0f;
			boombjumping = false;
			jatime = 0.0f;
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);

			IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		if (RLjumpchange)
		{
			mRigidBody->SetVelocity(Vector2(-100.f, 180.0f));
		}

		if (Ljumptime >= 0.5f && Input::GetKey(eKeyCode::Right))
		{
			Ljumptime = 0.0f;
			LRjumpchange = true;
			mState = eKirbyState::RightBoombJump;
			mAnimator->Play(L"BoombLRJumpChange", false);
		}


		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 50.0f * Time::DeltaTime();
		}

		if (boombjumptime >= 0.2f)
		{
			JumpCheck = false;
			boombjumptime = 0.0f;
		}

		if (BoombIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			boombkirbytime = 0.0f;
			boombjumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jatime = 0.0f;
			JumpCheck = true;
			mState = eKirbyState::LeftBoombDoubleJump;
			mAnimator->Play(L"LeftBoombDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
	}
	void Kirby::rightboombjump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		boombjumptime += Time::DeltaTime();
		Rjumptime += Time::DeltaTime();
		jatime += Time::DeltaTime();

		BoombIsJump = true;
		BoombAirShot = true;

		if (mRigidBody->GetGround() == true)
		{
			JumpCheck = false;
			LRjumpchange = false;
			RLjumpchange = false;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			boombjumptime = 0.0f;
			boombjumping = false;
			jatime = 0.0f;
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);

			IsJump = false;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		if (LRjumpchange)
		{
			mRigidBody->SetVelocity(Vector2(+100.f, 180.0f));
		}

		if (Rjumptime >= 0.5f && Input::GetKey(eKeyCode::Left))
		{
			Rjumptime = 0.0f;
			RLjumpchange = true;
			mState = eKirbyState::LeftBoombJump;
			mAnimator->Play(L"BoombRLJumpChange", false);
		}


		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 50.0f * Time::DeltaTime();
		}

		if (boombjumptime >= 0.2f)
		{
			JumpCheck = false;
			boombjumptime = 0.0f;
		}

		if (BoombIsJump && Input::GetKeyDown(eKeyCode::A))//GetAsyncKeyState(0x41) & 0x8000)
		{
			boombkirbytime = 0.0f;
			boombjumptime = 0.0f;
			Ljumptime = 0.0f;
			Rjumptime = 0.0f;
			jatime = 0.0f;
			JumpCheck = true;
			mState = eKirbyState::RightBoombDoubleJump;
			mAnimator->Play(L"RightBoombDoubleJump", false);

			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftboombdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		boombjumptime += Time::DeltaTime();
		BoombIsJump = false;
		BoombDoubleJump = true;

	
		if (boombjumptime > 0.2f)
		{
			JumpCheck = false;
			boombjumptime = 0.0f;
		}


		if (BoombDoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			BoombAirShot = true;
			mAnimator->Play(L"LeftBoombJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}
		if (BoombAirShot && Input::GetKeyDown(eKeyCode::Z))
		{
			BoombAirShot = false;
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"LeftBoombAir", false);
			object::Instantiate<AirLeft>(Vector2(pos.x - 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = eKirbyState::RightBoombDoubleJump;
			mAnimator->Play(L"RightBoombJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			mAnimator->Play(L"LeftBoombCrouch", true);
			mState = eKirbyState::LeftBoombCrouch;

			BoombDoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}
	void Kirby::rightboombdoublejump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		boombjumptime += Time::DeltaTime();

		BoombIsJump = false;
		BoombDoubleJump = true;

		if (BoombAirShot && Input::GetKeyDown(eKeyCode::Z))
		{
			BoombAirShot = false;
			mRigidBody->SetGravity(Vector2(0.0f, 1000.0f));
			mAnimator->Play(L"RightBoombAir", false);
			object::Instantiate<Air>(Vector2(pos.x + 10, pos.y), Vector2(2.0f, 2.0f), eLayerType::Effect);
		}

		if (boombjumptime > 0.2f)
		{
			JumpCheck = false;
			boombjumptime = 0.0f;
		}
		if (BoombDoubleJump && Input::GetKeyDown(eKeyCode::A))
		{
			BoombAirShot = true;
			mAnimator->Play(L"RightBoombJumpRelease", true);
			Vector2 velocity = mRigidBody->GetVelocity();
			mRigidBody->SetGravity(Vector2(0.0f, 200.0f));
			velocity.x = 0.0f;
			velocity.y = -120.0f;

			mRigidBody->SetVelocity(velocity);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = eKirbyState::LeftBoombDoubleJump;
			mAnimator->Play(L"LeftBoombJumpRelease", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (mRigidBody->GetGround() == true)
		{
			mAnimator->Play(L"RightBoombCrouch", true);
			mState = eKirbyState::RightBoombCrouch;

			BoombDoubleJump = true;
			mRigidBody->SetVelocity(Vector2::Zero);
			mRigidBody->SetGround(true);
		}

		tr->SetPos(pos);
	}
	void Kirby::leftboomrelease()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Z))
		{
			Transform* rr = mLeftZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			if (zPos.y <= endpos)
			{
				object::Destroy(mLeftZoom);
				RigidBody* mr = mLeftBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 550.0f));
				mr->SetVelocity(Vector2(-100.f, -300.0f));
				mState = eKirbyState::LeftBoomShot;
				mAnimator->Play(L"LeftBoomShot", false);
			}


			zPos.y -= 0.8;

			rr->SetPos(zPos);

		}

		Transform* rr = mLeftZoom->GetComponent<Transform>();
		Vector2 zPos = rr->GetPos();

		if (Input::GetKeyUp(eKeyCode::Z))
		{
			if (zPos.y >= firstpos - 13 && zPos.y <= firstpos)
			{
				object::Destroy(mLeftZoom);
				RigidBody* mr = mLeftBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 600.0f));
				mr->SetVelocity(Vector2(-300.f, -150.0f));
				mState = eKirbyState::LeftBoomShot;
				mAnimator->Play(L"LeftBoomShot", false);
			}
			if (zPos.y >= firstpos - 23 && zPos.y <= firstpos - 13)
			{
				object::Destroy(mLeftZoom);
				RigidBody* mr = mLeftBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 600.0f));
				mr->SetVelocity(Vector2(-200.f, -250.0f));
				mState = eKirbyState::LeftBoomShot;
				mAnimator->Play(L"LeftBoomShot", false);
			}

			if (zPos.y >= endpos && zPos.y <= firstpos - 23)
			{
				object::Destroy(mLeftZoom);
				RigidBody* mr = mLeftBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 600.0f));
				mr->SetVelocity(Vector2(-150.f, -350.0f));
				mState = eKirbyState::LeftBoomShot;
				mAnimator->Play(L"LeftBoomShot", false);
			}

		}

	}
	void Kirby::rightboomrelease()
	{
		//Transform* kr = this->GetComponent<Transform>();
		//Vector2 krpos = kr->GetPos();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKey(eKeyCode::Z))
		{
			Transform* rr = mRightZoom->GetComponent<Transform>();
			Vector2 zPos = rr->GetPos();

			if (zPos.y <= endpos)
			{
				object::Destroy(mRightZoom);
				RigidBody* mr = mRightBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 550.0f));
				mr->SetVelocity(Vector2(+100.f, -300.0f));
				mState = eKirbyState::RightBoomShot;
				mAnimator->Play(L"RightBoomShot", false);
			}


			zPos.y -= 0.8;

			rr->SetPos(zPos);
		
		}

		Transform* rr = mRightZoom->GetComponent<Transform>();
		Vector2 zPos = rr->GetPos();

		if (Input::GetKeyUp(eKeyCode::Z))
		{
           	if (zPos.y >= firstpos - 13 && zPos.y <= firstpos)
            {
                object::Destroy(mRightZoom);
                RigidBody* mr = mRightBoom->GetComponent<RigidBody>();
                mr->SetGravity(Vector2(0.0f, 600.0f));
                mr->SetVelocity(Vector2(+300.f, -150.0f));
                mState = eKirbyState::RightBoomShot;
                mAnimator->Play(L"RightBoomShot", false);
            }
			if (zPos.y >= firstpos - 23 && zPos.y <= firstpos - 13)
			{
				object::Destroy(mRightZoom);
				RigidBody* mr = mRightBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 600.0f));
				mr->SetVelocity(Vector2(+200.f, -250.0f));
				mState = eKirbyState::RightBoomShot;
				mAnimator->Play(L"RightBoomShot", false);
			}

			if (zPos.y >= endpos && zPos.y <= firstpos - 23)
			{
				object::Destroy(mRightZoom);
				RigidBody* mr = mRightBoom->GetComponent<RigidBody>();
				mr->SetGravity(Vector2(0.0f, 600.0f));
				mr->SetVelocity(Vector2(+150.f, -350.0f));
				mState = eKirbyState::RightBoomShot;
				mAnimator->Play(L"RightBoomShot", false);
			}

		}

	}
	void Kirby::leftboomshot()
	{
		boomend += Time::DeltaTime();
		if (boomend >= 0.5f)
		{
			boomend = 0.0f;
			mState = eKirbyState::LeftBoombIdle;
			mAnimator->Play(L"LeftBoombIdle", true);
		}
	}
	void Kirby::rightboomshot()
	{
		boomend += Time::DeltaTime();
		if (boomend >= 0.5f)
		{
			boomend = 0.0f;
			mState = eKirbyState::RightBoombIdle;
			mAnimator->Play(L"RightBoombIdle", true);
		}
	}
	}
	
	