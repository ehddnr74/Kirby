#pragma once
#include "MyGameObject.h"
namespace My
{
	class Kirby;
	class Animator;
	class Box : public GameObject
	{
	public:
		Box();
		~Box();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		void SetDestroy(bool destroy) {Destroy = destroy; }
		bool GetDestroy() { return Destroy; }
		void SetBoxCol(bool boxcol) { BoxCol = boxcol; }

	private:
		Animator* mAnimator;
		Collider* boxcol;
		class Kirby* mKirby;

		bool Destroy;
		bool BoxCol;

	};
}