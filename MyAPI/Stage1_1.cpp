#include "Stage1_1.h"
#include "MyKirby.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "Room1.h"
#include "MyApplication.h"
#include "Stage1_1bk.h"
#include "MyImage.h"
#include "MyWaddle.h"
#include "MyCappy.h"
#include "MyTwizzy.h"


namespace My
{
	Stage1Scene::Stage1Scene()
	{

	}

	Stage1Scene::~Stage1Scene()
	{
	}

	void Stage1Scene::Initialize()
	{
		mKirby = new Kirby();
		AddGameObject(mKirby, eLayerType::Player);

		mbg1 = new Stage11bk();
		AddGameObject(mbg1, eLayerType::BG);

		mroom1 = new Room1();
		AddGameObject(mroom1, eLayerType::Stage);

		Waddle* mWaddle = new Waddle();
		AddGameObject(mWaddle, eLayerType::Monster);
		
		Cappy* mCappy = new Cappy();
		AddGameObject(mCappy, eLayerType::Monster);

		Twizzy* mTwizzy = new Twizzy();
		AddGameObject(mTwizzy, eLayerType::Monster);

		Scene::Initialize();
	}

	void Stage1Scene::Update()
	{
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Stage1_2);
		}

		Scene::Update();
	}

	void Stage1Scene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void Stage1Scene::Release()
	{
		Scene::Release();
	}

	void Stage1Scene::OnEnter()
	{
	}

	void Stage1Scene::OnExit()
	{
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}