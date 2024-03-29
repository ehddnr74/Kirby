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
#include "HP.h"
#include "Stage1_2.h"
#include "SaveKirby.h"
#include "SaveUI.h"
#include "MySound.h"
#include "MyResources.h"

namespace My
{
	Stage1Scene::Stage1Scene()
		:fadingtime(0.f)
	{

	}

	Stage1Scene::~Stage1Scene()
	{
	}

	void Stage1Scene::Initialize()
	{
		Scene::Initialize();


		Kirby* mKirby = object::Instantiate<Kirby>(Vector2(129.0f, 100.0f), Vector2(2.0f, 2.0f), (eLayerType::Player));
		SetPlayer(mKirby);
		
		mStar = object::Instantiate<StarMap>(Vector2(1370, 260), Vector2(0.3f, 0.3f), (eLayerType::Portal));



		
	}

	void Stage1Scene::Update()
	{
		if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Stage1_2);
		}
		if (mKirby->GetStarCol() == true)
		{
			Sound* mSound = Resources::Load<Sound>(L"enter-door", L"..\\Resources\\Sound\\enter-door.wav");
			mSound->Play(false);
			SceneManager::LoadScene(eSceneType::Stage1_2);
		}		
		if (mCappy->GetHP() <= 0)
		{
			mGround->SetCappy(nullptr);
		}


		
		if (mKirby->GetHP() <= 0)
		{
			Camera::SetTarget(nullptr);
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
		Sound* mSound = Resources::Load<Sound>(L"6-26-Green-Greens", L"..\\Resources\\Sound\\6-26-Green-Greens.wav");
		mSound->Play(true);
		mSound->SetVolume(10.f);

		//Camera::SetCameraType(Camera::eCameraEffectType::FadeIn);

		object::Instantiate<FadeIn>(eLayerType::Rectangle);

		//Rectangle1* rectangle = object::Instantiate<Rectangle1>(eLayerType::Rectangle);

		Ground* mGround = object::Instantiate<Ground>(eLayerType::Ground);

		object::Instantiate<Room1>(eLayerType::Stage);
		object::Instantiate<Stage11bk>(eLayerType::BG);
		HP* hp = object::Instantiate<HP>/*(Vector2(315,865),Vector2(1.f,1.f),*/(eLayerType::UI);
		SetUI(hp);
		

		//hp->SetState(HP::UIState::UI5);
		mWaddle = object::Instantiate<Waddle>(Vector2(420, 390), Vector2(2.2f, 2.2f), (eLayerType::Monster));
		mCappy = object::Instantiate<Cappy>(Vector2(800, 390), Vector2(1.8f, 2.0f), (eLayerType::Monster));
		mTwizzy = object::Instantiate<Twizzy>(Vector2(1150, 330), Vector2(2.0f, 2.0f), (eLayerType::Monster));
		BrontoBurt* mBrontoBurt = object::Instantiate<BrontoBurt>(Vector2(900.0f, 150.0f), Vector2(2.0f, 2.0f), (eLayerType::Monster));

		SetGround(mGround);
		mGround->SetCappy(mCappy);

		if (mKirby != nullptr)
		{
			mGround->SetPlayer(mKirby);
			//rectangle->SetPlayer(mKirby);
			mWaddle->SetPlayer(mKirby);
			mBrontoBurt->SetPlayer(mKirby);
			mKirby->SetGround(mGround);
			Camera::SetTarget(mKirby);
			hp->SetKirby(mKirby); //hp�� kirby�� �� 
		}



		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::MonsterSkill, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Air, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}

	void Stage1Scene::OnExit()
	{
		SaveKirby::SetKirby(mKirby);
		SaveUI::SetUI(hp);


		//Camera::SetCameraType(Camera::eCameraEffectType::FadeOut);
		//object::Instantiate<FadeOut>(eLayerType::fade);
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}