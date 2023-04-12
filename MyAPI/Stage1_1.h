#pragma once
#include "MyScene.h"
#include "MyImage.h"

namespace My
{
	class Stage2Pt;
	class StarMap;
	class Restrict;
	class HP;
	class Twizzy;
	class BrontoBurt;
	class Cappy;
	class Room1;
	class Kirby;
	class Waddle;
	class Stage11bk;
	class Stage1Scene : public Scene
	{
	public:
		Stage1Scene();
		~Stage1Scene();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

		void SetPlayer(class Kirby* player) { mKirby = player; }

		void SetGround(class Ground* ground) { mGround = ground; }

		void SetStage2(class Stage2Scene* stage) { stage2 = stage; }

		

		class Kirby* GetKirby() { return mKirby; }

	private:
		Kirby* mKirby;
		Waddle* mWaddle;
		Room1* mroom1;
		Stage11bk* mbg1;
		Cappy* mCappy;
		Twizzy* mTwizzy;
		BrontoBurt* mBrontoBurt;
		HP* hp;
		Restrict* mRestrict;
		StarMap* mStar;
		Ground* mGround;

		class Stage2Scene* stage2;

		double fadingtime;

	};
}

