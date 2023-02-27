#pragma once
#include "MyScene.h"

namespace My
{
	class Room1;
	class Kirby;
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
		Room1* mroom1;

	};
}

