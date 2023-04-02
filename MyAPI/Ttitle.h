#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
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
	};
}
