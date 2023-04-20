#pragma once
#include "MyEngine.h"
namespace My
{
	class HP;
	class SaveUI
	{
	public:
		//static void Initialize();
		//static void Update();
		//static void Render(HDC hdc);
		//static void Release(); 

		static void OnCollisionEnter(class Collider* other);
		static void OnCollisionStay(class Collider* other);
		static void OnCollisionExit(class Collider* other);

		static void SetUI(HP* h) { hp = h; }
		static HP* GetUI() { return hp; }

	private:
		static class HP* hp;
	};
}