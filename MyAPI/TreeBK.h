#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class TreeBk : public GameObject
	{
	public:
		TreeBk();
		~TreeBk();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* treebk;
	};
}