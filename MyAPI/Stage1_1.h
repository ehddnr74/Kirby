#pragma once
#include "MyScene.h"
#include "MyImage.h"

namespace My
{
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

	private:
		Kirby* mKirby;
		Waddle* mWaddle;
		Room1* mroom1;
		Stage11bk* mbg1;


	};
}

