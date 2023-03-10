#pragma once
#include "MyEngine.h"

namespace My
{
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Update();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }


	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static class GameObject* mTarget;

	};
}

