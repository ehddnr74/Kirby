#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Stage1_3bk : public GameObject
	{
	public:
		Stage1_3bk();
		~Stage1_3bk();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mbg3;
	};
}

