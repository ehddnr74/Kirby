#pragma once
#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class Beam : public GameObject
	{
	public:
		Beam();
		~Beam();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		Animator* mAnimator;
		Collider* mCollider;

		double beamtime;
	};
}

