#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class Cappy : public GameObject
	{
	public:
	Cappy();
	~Cappy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	private:
	Animator* mAnimator;

	};
}
