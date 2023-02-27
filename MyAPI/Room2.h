#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Room2 : public GameObject
	{
	public:
		Room2();
		~Room2();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;



	private:
		Image* mroom2;
	};
}

