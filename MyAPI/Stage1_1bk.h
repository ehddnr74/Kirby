#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Stage11bk : public GameObject
	{
	public:
		Stage11bk();
		~Stage11bk();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mbg1;
	};
}

