#pragma once
#include "MyGameObject.h"
#include "MyImage.h"
namespace My
{
	class Animator;
	class TreeBranch : public GameObject
	{
	public:
		TreeBranch();
		~TreeBranch();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


	private:
		Animator* mAnimator;
		class Image* mbranch;
	};
}
