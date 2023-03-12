#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class AbsorbEffect : public GameObject
	{
	public:
		AbsorbEffect();
		~AbsorbEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Animator* mAnimator;
		float mTime;
	};
}
