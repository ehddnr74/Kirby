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
#include "MyCollisionManager.h"
#include "MyCamera.h"
#include "MyObject.h"
#include "AbsorbEffect.h"

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
		Scene::Initialize();

		//mKirby = new Kirby();
		//AddGameObject(mKirby, eLayerType::Player);

		//Camera::SetTarget(mKirby);

	    object::Instantiate< Kirby>(Vector2(30.0f,310.0f),Vector2(2.0f,2.0f),(eLayerType::Player));

		//mbg1 = new Stage11bk();
		//AddGameObject(mbg1, eLayerType::BG);

		//mroom1 = new Room1();
		//AddGameObject(mroom1, eLayerType::Stage);

		object::Instantiate<Stage11bk>(eLayerType::BG);

		object::Instantiate<Room1>(eLayerType::Stage);

		//Waddle* mWaddle = new Waddle();
		//AddGameObject(mWaddle, eLayerType::Monster);

		object::Instantiate<Waddle>(Vector2(320, 300),Vector2(2.2f,2.2f),(eLayerType::Monster));

		//Cappy* mCappy = new Cappy();
		//AddGameObject(mCappy, eLayerType::Monster);

		object::Instantiate<Cappy>(Vector2(580, 255), Vector2(1.8f, 2.0f), (eLayerType::Monster));

		//Twizzy* mTwizzy = new Twizzy();
		//AddGameObject(mTwizzy, eLayerType::Monster);

		object::Instantiate<Twizzy>(Vector2(900, 310),Vector2(2.0f,2.0f),(eLayerType::Monster));

		

		
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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Effect, true);
	}

	void Stage1Scene::OnExit()
	{
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}