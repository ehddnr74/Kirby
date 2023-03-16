#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class mWaddle;
	class AbsorbEffect : public GameObject
	{
	public:
		AbsorbEffect();
		~AbsorbEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		Animator* mAnimator;
		double mTime;
		bool Check;
	};
}
