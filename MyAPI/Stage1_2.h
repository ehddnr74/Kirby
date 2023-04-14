#pragma once
#pragma once
#include "MyScene.h"

namespace My
{
	class Portion1;
	class Portion2;
	class Portion3;
	class Stage1Scene;
	class Stage2Pt;
	class Kirby;
	class Stage2Scene : public Scene
	{
	public:
		Stage2Scene();
		~Stage2Scene();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;


		void SetPlayer(class Kirby* player) { MyKirby = player; }
		void SetPt(class Stage2Pt* stage2pt) { mStage2Pt = stage2pt; }
		void SetGround(class R2Ground* Ground) { ground = Ground; }

		void SetBros(class Bros* bros) { mBros = bros; }
		void SetBoomBros(class BoomBros* boombros) { mBoomBros = boombros; }
		void SetBox(class Box* box) { box = box; }


		void SetStage1(class Stage1Scene* stage) { mstage1 = stage; }



		

	private:
		class Kirby* MyKirby;
		class Stage2Pt* mStage2Pt;
		class R2Ground* ground;
		class Bros* mBros;
		class Stage1Scene* mstage1; 
		class Box* box;
		class Portion1* mCherry;
		class Portion2* mCookie;
		class Portion3* mPizza;
		class BoomBros* mBoomBros;

		class LeftBoomb* mLeftBoomb;
		class RightBoomb* mRightBoomb;
		class Grizzo* mGrizzo;


	};
}

