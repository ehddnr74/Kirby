#include "Stage1_3.h"
#include "MyKirby.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyCollisionManager.h"
#include "MyCamera.h"
#include "MyObject.h"
#include "MyRectangle.h"
#include "Star.h"
#include "StarMap.h"
#include "MyRectangle.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "HP.h"
#include "Room3.h"
#include "MyRigidBody.h"
#include "Stage1_3bk.h"
#include "R3Ground.h"
#include "Stage3Pt.h"
#include "MyCappy.h"
#include "MyWaddle.h"
#include "SaveKirby.h"
#include "SaveUI.h"
#include "Grizzo.h"
namespace My {
	Stage1_3::Stage1_3()
	{

	}
	Stage1_3::~Stage1_3()
	{

	}
	void Stage1_3::Initialize()
	{
		Scene::Initialize();

	}
	void Stage1_3::Update()
	{
		if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::TreeScene);
		}
		if (mStage3Pt->GetPortal())
		{
			if (Input::GetKeyDown(eKeyCode::Up))
			{
				SceneManager::LoadScene(eSceneType::TreeScene);
			}
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
	void Stage1_3::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void Stage1_3::Release()
	{
		Scene::Release();
	}
	void Stage1_3::OnEnter()
	{
		hp = SaveUI::GetUI();
		AddGameObject(hp, eLayerType::UI);
		mKirby = SaveKirby::GetKirby();
		AddGameObject(mKirby, eLayerType::Player);
		Transform* kr = mKirby->GetComponent<Transform>();
		kr->SetPos(Vector2(200.0f, 1000.0f));
		//Kirby* MyKirby = object::Instantiate<Kirby>(Vector2(129.0f, 384.0f), Vector2(2.0f, 2.0f), eLayerType::Player);
		SetPlayer(mKirby);
		Camera::SetTarget(mKirby);
		Camera::SetScene(this);

		mStage3Pt = object::Instantiate<Stage3Pt>(Vector2(275.0f, 200.f), Vector2(1.0f, 1.0f), (eLayerType::Portal));
		
		mGround = object::Instantiate<R3Ground>(eLayerType::Ground);
		mKirby->SetGround3(mGround);
		SetGround(mGround);
		Rectangle1* rectangle = object::Instantiate<Rectangle1>(eLayerType::Rectangle);

		if (mKirby != nullptr)
		{
	    rectangle->SetPlayer(mKirby);
		mGround->SetPlayer(mKirby);
		SetPt(mStage3Pt);
		}

		object::Instantiate<HP>(eLayerType::UI);

		object::Instantiate<Room3>(eLayerType::Stage);
		object::Instantiate<Stage1_3bk>(eLayerType::BG);


		Waddle* mWaddle = object::Instantiate<Waddle>(Vector2(510.f, 910.f), Vector2(2.2f, 2.2f), (eLayerType::Monster));

		mWaddle->SetGround(mGround);

		mCappy = object::Instantiate<Cappy>(Vector2(400, 350), Vector2(1.8f, 2.0f), (eLayerType::Monster));
		mCappy->SetGround3(mGround);
		mGround->SetCappy(mCappy);

		Grizzo* mGrizzo = object::Instantiate<Grizzo>(Vector2(250.f, 760.f), Vector2(2.0f, 2.0f), (eLayerType::Monster));
		mGrizzo->SetGround3(mGround);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::MonsterSkill, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		//CollisionManager::SetLayer(eLayerType::Player, eLayerType::Box, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Air, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
		
	}

	void Stage1_3::OnExit()
	{
		SaveKirby::SetKirby(mKirby);
		SaveUI::SetUI(hp);
	}
}