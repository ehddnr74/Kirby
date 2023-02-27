#pragma once
#pragma once
#include "MyScene.h"

namespace My
{
	class Room2;
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

	private:
		Kirby* mKirby;
		Room2* mroom2;

	};
}

