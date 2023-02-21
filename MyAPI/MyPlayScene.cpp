#include "MyPlayScene.h"
#include "MyKirby.h"


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
		for (float i = 0; i < 2; i++)
		{
			Kirby* kirby = new Kirby();
			//kirby->SetPos(Vector2(0.0f, 0.0f);
			kirby->SetName(L"Player");
			AddGameObject(kirby, eLayerType::Player);
		}
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
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

}