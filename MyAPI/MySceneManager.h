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
		static void Release();


	private:
		static std::vector<Scene*> mScenes;
	};
}

