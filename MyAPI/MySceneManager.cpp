#include "MySceneManager.h"
#include "MyPlayScene.h"
#include "MyTitleScene.h"

namespace My
{


	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::End);

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		

		mActiveScene = mScenes[(UINT)eSceneType::Title];

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;
			
			scene->Initialize();
		}
	}

	void SceneManager::Update()
	{
			mActiveScene->Update();
	}
	void SceneManager::Render(HDC hdc)
	{
			mActiveScene->Render(hdc);

	}
	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Release();
		}
	}

	void SceneManager::LoadScene(eSceneType type)
	{
		// ÇöÀç¾À
		mActiveScene->OnExit();

		// ´ÙÀ½¾À
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}

}