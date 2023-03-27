#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class AbsorbLeftEffect : public GameObject
	{
	public:
		AbsorbLeftEffect();
		~AbsorbLeftEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetCollision(int collision) { Collision = collision; }
		int GetCollision() { return Collision; }

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		Animator* mAnimator;
		float mTime;
		int Collision;
		class Kirby* mKirby;
		class Waddle* mWaddle;
	};
}