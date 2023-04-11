#pragma once
#include "MyEngine.h"

namespace My
{
	class Scene;
	class GameObject;
	class Camera
	{
	public:
		enum class eCameraEffectType
		{
			None,
			FadeIn,
			FadeOut,
			//Shake,
			End,
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Clear();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
		static void SetCameraType(eCameraEffectType mtype) { mType = mtype; }

		static void SetScene(Scene* scene) { mScene = scene; }
		static void SetTreeScene(Scene* scene) { treescene = scene; }


	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static Vector2 mCenterPos;
		static class GameObject* mTarget;
		static class Scene* mScene;
		static class Scene* treescene;

		

		static eCameraEffectType mType;
		static class Image* mCutton;
		static float mCuttonAlpha;
		static float mAlphaTime;
		static float mEndTime;

	};
}

