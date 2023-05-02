#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Animator;
	class Ending : public GameObject
	{
	public:
		Ending();
		~Ending();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;



	private:
		Image* mEnding;
		class Animator* mAnimator;
	};
}