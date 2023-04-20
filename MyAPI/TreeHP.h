#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Animator;
	class TreeHP : public GameObject
	{
	public:
		TreeHP();
		~TreeHP();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetKirby(class Kirby* mkirby) { mKirby = mkirby; }
		void SetTree(class TreeBoss* mtree) { mTree = mtree; }

	private:
		class Animator* mAnimator;
		class Kirby* mKirby;
		class TreeBoss* mTree;
		class Image* hp;
		class Image* hp2;
		class Image* hp3;
		class Image* hp4;
		class Image* hp5;
		class Image* hp6;
		class Image* hp7;
		class Image* hp8;
		class Image* hp9;
		class Image* hp10;
		class Image* hp11;

		bool firstsearch;

	};
}