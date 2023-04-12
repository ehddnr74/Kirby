#pragma once
#include "MyGameObject.h"
namespace My
{
	class Kirby;
	class SaveKirby : public GameObject
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release(); 

		static void OnCollisionEnter(class Collider* other);
		static void OnCollisionStay(class Collider* other);
		static void OnCollisionExit(class Collider* other);

		static void SetKirby(Kirby* mkirby) { mKirby = mkirby; }
		static Kirby* GetKirby() { return mKirby; }

	private:
		static class Kirby* mKirby;
	};
}