#pragma once
#include "MyScene.h"

namespace My
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();

		static void LoadScene(eSceneType type);
		static Scene* GetActiveScene() { return mActiveScene; }
		static void SetActiveScene(Scene* scene) { mActiveScene = scene; }
		static void GetScene(eSceneType type);

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
		static Scene* get;
	};
}

