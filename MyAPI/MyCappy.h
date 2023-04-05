#pragma once
#include "MyGameObject.h"

namespace My
{
	class Animator;
	class Cappy : public GameObject
	{
	public:
		enum class CappyState
		{
			LeftMove
			,RightMove
		};

	Cappy();
	~Cappy();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

	private:
		void leftmove();
		void rightmove();


		void SetDamage(int damage) { CappyHP -= damage; }

	private:

		Animator* mAnimator;
		CappyState mState;
		double cappytime;
		int cappydir;
		int CappyHP;


	};
}
