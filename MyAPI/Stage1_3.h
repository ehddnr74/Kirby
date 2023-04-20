#pragma once
#include "MyScene.h"
#include "MyImage.h"
namespace My {
	class Cappy;
	class RigidBody;
	class Stage3Pt;
	class R3Ground;
	class Stage1_3 : public Scene
	{
	public:
		Stage1_3();
		~Stage1_3();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void SetPlayer(class Kirby* player) { mKirby = player; }
		void SetPt(class Stage3Pt* stage3pt) { mStage3Pt = stage3pt; }
		void SetGround(class R3Ground* ground) { mGround = ground; }



	private:
		class Kirby* mKirby;
		RigidBody* mRigidBody;
		class Stage3Pt* mStage3Pt;
		class Cappy* mCappy;
		class R3Ground* mGround;
		class HP* hp;
		class Grizzo* mGrizzo;
	};
}

