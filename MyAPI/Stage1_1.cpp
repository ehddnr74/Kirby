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
#include "MyfadeIn.h"
#include "Myfadeout.h"
#include "R1Ground.h"
#include "AbsorbEffect.h"
#include "MyRectangle.h"
#include "AirLeft.h"
#include "Star.h"
#include "StarMap.h"
#include "MyRectangle.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "BrontoBurt.h"
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
		Scene::Initialize();

		
		//mKirby = new Kirby();
		//AddGameObject(mKirby, eLayerType::Player);
		// 
		//object::Instantiate<FadeIn>(eLayerType::fade);

		Kirby* mKirby = object::Instantiate<Kirby>(Vector2(129.0f, 394.0f), Vector2(2.0f, 2.0f), (eLayerType::Player));

		SetPlayer(mKirby);

		Ground* ground1 = object::Instantiate<Ground>(eLayerType::Ground);


		Rectangle1* rectangle = object::Instantiate<Rectangle1>(eLayerType::Rectangle);
	
		BrontoBurt* mBrontoBurt = object::Instantiate<BrontoBurt>(Vector2(900.0f, 80.0f), Vector2(2.0f, 2.0f), (eLayerType::Monster));

		mWaddle = object::Instantiate<Waddle>(Vector2(370, 342), Vector2(2.2f, 2.2f), (eLayerType::Monster)); //370 , 342 // 250 , 390 = 야매
		mCappy =object::Instantiate<Cappy>(Vector2(610, 338), Vector2(1.8f, 2.0f), (eLayerType::Monster)); //610 , 338 // 370, 342 = 야매
		mTwizzy = object::Instantiate<Twizzy>(Vector2(900, 310), Vector2(2.0f, 2.0f), (eLayerType::Monster)); //900,310 // 700,335 = 야매

		//object::Instantiate<LeftEnergyBeam>(Vector2(700, 700), Vector2(1.5f, 1.5f), (eLayerType::Skill)); 

		ground1->SetWaddle(mWaddle);
		ground1->SetPlayer(mKirby);
		ground1->SetCappy(mCappy);
		rectangle->SetPlayer(mKirby);
		mKirby->SetGround(ground1);
		mWaddle->SetPlayer(mKirby);
		ground1->SetTwizzy(mTwizzy);
		
		
		//Camera::SetTarget(mKirby);

		//mbg1 = new Stage11bk();
		//AddGameObject(mbg1, eLayerType::BG);

		//mroom1 = new Room1();
		//AddGameObject(mroom1, eLayerType::Stage);

		object::Instantiate<Stage11bk>(eLayerType::BG);

		object::Instantiate<Room1>(eLayerType::Stage);

		object::Instantiate<StarMap>(Vector2(1320, 240), Vector2(0.3f, 0.3f), (eLayerType::MapStar));

		//Waddle* mWaddle = new Waddle();
		//AddGameObject(mWaddle, eLayerType::Monster);

		


		//Cappy* mCappy = new Cappy();
		//AddGameObject(mCappy, eLayerType::Monster);

		

		//Twizzy* mTwizzy = new Twizzy();
		//AddGameObject(mTwizzy, eLayerType::Monster);

	
		

		
	}

	void Stage1Scene::Update()
	{
		if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Stage1_2);
		}
		if (mKirby->GetStarCol() == true)
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
		object::Instantiate<FadeIn>(eLayerType::fade);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Effect, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Air, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::MapStar, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}

	void Stage1Scene::OnExit()
	{
		//object::Instantiate<FadeOut>(eLayerType::fade);
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}