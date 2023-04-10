#pragma once
#include "MyGameObject.h"
#include "MyImage.h"

namespace My
{
	class SecretRoom : public GameObject
	{
	public:
		SecretRoom();
		~SecretRoom();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;


	private:
		Image* mSRoom;
	};
}

