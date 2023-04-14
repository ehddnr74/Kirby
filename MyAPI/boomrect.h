#pragma once
#include "MyGameObject.h"


namespace My
{
	class boomrect : public GameObject
	{
	public:
		boomrect();
		~boomrect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetBoom(class RightBoomb* rb) { RightBoomb = rb; }
		void SetLeftBoom(class LeftBoomb* lb) { LeftBoomb = lb; }


	private:
		class RightBoomb* RightBoomb;
		class LeftBoomb* LeftBoomb;
	};
}