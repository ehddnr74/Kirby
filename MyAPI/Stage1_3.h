#pragma once
#include "MyScene.h"
#include "MyImage.h"
namespace My {
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
	};
}

