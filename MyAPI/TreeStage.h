#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class TreeStage : public GameObject
	{
	public:
		TreeStage();
		~TreeStage();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mtreeroom;
	};
}
