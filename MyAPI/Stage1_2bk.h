#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Stage12bk : public GameObject
	{
	public:
		Stage12bk();
		~Stage12bk();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mbg2;
	};
}

