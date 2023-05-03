#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class FadeOut : public GameObject
	{
	public:
		FadeOut();
		~FadeOut();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		double GetAmount() { return fadeAmount; }

		bool GetFadeClear() { return FadeClear; }


	private:
		Image* fadeOut;
		double fadeAmount;
		bool FadeClear;
	};
}
