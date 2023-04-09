#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class Room3 : public GameObject
	{
	public:
		Room3();
		~Room3();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mroom3;
	};
}