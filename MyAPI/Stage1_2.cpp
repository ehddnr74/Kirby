#include "Stage1_2.h"
#include "MyKirby.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "Room2.h"
#include "MyApplication.h"
#include "MyImage.h"


namespace My
{
	Stage2Scene::Stage2Scene()
	{

	}

	Stage2Scene::~Stage2Scene()
	{
	}

	void Stage2Scene::Initialize()
	{
		mKirby = new Kirby();
		AddGameObject(mKirby, eLayerType::Player);

		mroom2 = new Room2();
		AddGameObject(mroom2, eLayerType::Stage);


		Scene::Initialize();
	}

	void Stage2Scene::Update()
	{
		/*if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Stage1_1);
		}*/

		Scene::Update();
	}

	void Stage2Scene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void Stage2Scene::Release()
	{
		Scene::Release();
	}

	void Stage2Scene::OnEnter()
	{
	}

	void Stage2Scene::OnExit()
	{
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}