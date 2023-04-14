#pragma once
#include "MyGameObject.h"
namespace My
{
	class Animator;
	class Explosion : public GameObject
	{
	public:
		Explosion();
		~Explosion();

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
		class Kirby* mkirby;
		class RightBoomb* rb;
		class LeftBoomb* lb;

		double Explosiontime;


	};
}
