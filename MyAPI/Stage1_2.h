#pragma once
#pragma once
#include "MyScene.h"

namespace My
{
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

		void SetStage1(class Stage1Scene* stage) { mstage1 = stage; }



		

	private:
		class Kirby* MyKirby;
		class Stage2Pt* mStage2Pt;
		class R2Ground* ground;
		class Bros* mBros;
		class Stage1Scene* mstage1; 

	};
}

