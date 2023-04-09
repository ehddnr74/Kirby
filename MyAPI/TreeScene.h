#pragma once
#include "MyScene.h"
#include "MyImage.h"
namespace My {
	class TreeScene : public Scene
	{
	public:
		TreeScene();
		~TreeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	};
}

