#include "MyPlayScene.h"
#include "MyKirby.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "Room1.h"
#include "MyApplication.h"


namespace My
{
	PlayScene::PlayScene()
	{

	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
    	mKirby = new Kirby();
    	AddGameObject(mKirby, eLayerType::Player);

		Room1* stage1 = new Room1();
		AddGameObject(stage1, eLayerType::Stage);

		

		
		

		Scene::Initialize();
	}

	void PlayScene::Update()
	{

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

		Scene::Update();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}