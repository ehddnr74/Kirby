#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Animator;
	class Title : public GameObject
	{
	public:
		Title();
		~Title();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		

	private:
		Image* mTitle;
		class Animator* mAnimator;

		double time;
		bool Check;
		bool Check2;
	};
}
