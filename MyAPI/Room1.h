#pragma once

#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Room1 : public GameObject
	{
	public:
		Room1();
		~Room1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;



	private:
		Image* room1;
	};
}

