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
<<<<<<< HEAD
#include "MyRectangle1.h"
#include "AirLeft.h"
#include "Star.h"
#include "StarMap.h"
=======
#include "MyRectangle.h"
>>>>>>> 794934d37ca2edf575818af029f6a6424b07de41

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

		Ground* ground = object::Instantiate<Ground>(eLayerType::Ground);


		Rectangle1* rectangle = object::Instantiate<Rectangle1>(eLayerType::Rectangle);
	
		Rectangle1* rectangle = object::Instantiate<Rectangle1>(eLayerType::Rectangle);

		mWaddle = object::Instantiate<Waddle>(Vector2(320, 380), Vector2(2.2f, 2.2f), (eLayerType::Monster));
		
		ground->SetPlayer(mKirby);
		rectangle->SetPlayer(mKirby);
<<<<<<< HEAD
		mKirby->SetGround(ground);
		mWaddle->SetPlayer(mKirby);
		
=======
>>>>>>> 794934d37ca2edf575818af029f6a6424b07de41
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

		object::Instantiate<Cappy>(Vector2(580, 300), Vector2(1.8f, 2.0f), (eLayerType::Monster));

		//Twizzy* mTwizzy = new Twizzy();
		//AddGameObject(mTwizzy, eLayerType::Monster);

		object::Instantiate<Twizzy>(Vector2(900, 380),Vector2(2.0f,2.0f),(eLayerType::Monster)); //¿ø·¡ y 310 
		

		
	}

	void Stage1Scene::Update()
	{
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
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
	}

	void Stage1Scene::OnExit()
	{
		//object::Instantiate<FadeOut>(eLayerType::fade);
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}