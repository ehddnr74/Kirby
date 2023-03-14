#include "Stage1_2.h"
#include "MyKirby.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "Room2.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyObject.h"
#include "Stage1_2bk.h"
#include "Myfadein.h"


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
		Scene::Initialize();
		//mroom2 = new Room2();
		//AddGameObject(mroom2, eLayerType::Stage);

		object::Instantiate<Stage12bk>(eLayerType::BG);

		object::Instantiate<Kirby>(Vector2(30.0f, 310.0f),Vector2(2.0f,2.0f),eLayerType::Player);

		object::Instantiate<Room2>(eLayerType::Stage);
		

		
	}

	void Stage2Scene::Update()
	{
		if (Input::GetKeyState(eKeyCode::E) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

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
		object::Instantiate<FadeIn>(eLayerType::fade);
	}

	void Stage2Scene::OnExit()
	{
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}