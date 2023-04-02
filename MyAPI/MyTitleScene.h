#pragma once
#include "MyScene.h"

namespace My
{
	class Title;
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;


		void SetTitle(class Title* title) { mtitle = title; }

	private:
		Title* mtitle;

	};
}
