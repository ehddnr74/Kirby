#pragma once
#include "MyScene.h"
#include "MyImage.h"
namespace My {
	class SecretRoomScene : public Scene
	{
	public:
		SecretRoomScene();
		~SecretRoomScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	};
}
