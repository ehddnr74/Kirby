#include "MySceneManager.h"
#include "MyTitleScene.h"
#include "Stage1_1.h"
#include "Stage1_2.h"
#include "MyCollisionManager.h"
#include "Stage1_3.h"
#include "TreeScene.h"
#include "SecretRoomScene.h"

namespace My
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::End);

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Stage1_1] = new Stage1Scene();
		mScenes[(UINT)eSceneType::Stage1_2] = new Stage2Scene();
		mScenes[(UINT)eSceneType::Stage1_3] = new Stage1_3();
		mScenes[(UINT)eSceneType::TreeScene] = new TreeScene();
		mScenes[(UINT)eSceneType::SecretRoomScene] = new SecretRoomScene();

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;
			
			scene->Initialize();
		}

		mActiveScene = mScenes[(UINT)eSceneType::Title];
	}

	void SceneManager::Update()
	{
			mActiveScene->Update();
	}
	void SceneManager::Render(HDC hdc)
	{
			mActiveScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}
	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::LoadScene(eSceneType type)
	{
		// ÇöÀç¾À
		mActiveScene->OnExit();

		CollisionManager::Clear();
		// ´ÙÀ½¾À
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}

}