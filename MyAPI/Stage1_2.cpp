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
#include "MyfadeOut.h"
#include "R2Ground.h"
#include "MyCamera.h"
#include "HP.h"
#include "Stage2Pt.h"
#include "MyCollisionManager.h"
#include "Bros.h"
#include "Box.h"


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

		//Transform* tr = mKirby->GetComponent<Transform>();
		//Vector2 pos = tr->GetPos();
		//tr->SetPos(Vector2(129.0f, 384.0f));

		
		mStage2Pt = object::Instantiate<Stage2Pt>(Vector2(1380.0f, 250.f), Vector2(1.0f, 1.0f), (eLayerType::Portal));
		SetPt(mStage2Pt);

		object::Instantiate<HP>(eLayerType::UI);

		//Box* box1 = object::Instantiate<Box>(Vector2(895,325),Vector2(1.0f,1.0f),eLayerType::Box);
		//Box* box2 = object::Instantiate<Box>(Vector2(980, 326), Vector2(0.9f, 1.0f), eLayerType::Box);
		//Box* box3 = object::Instantiate<Box>(Vector2(1025, 326), Vector2(0.9f, 1.0f), eLayerType::Box);
		//Box* box4 = object::Instantiate<Box>(Vector2(1070, 326), Vector2(0.9f, 1.0f), eLayerType::Box);
		//Box* box5 = object::Instantiate<Box>(Vector2(1155, 380), Vector2(1.0f, 1.0f), eLayerType::Box);
	

		//mroom2 = new Room2();
		//AddGameObject(mroom2, eLayerType::Stage);

		//Camera::SetTarget(mKirby);

		//object::Instantiate<Stage12bk>(eLayerType::BG);




		//object::Instantiate<Room2>(eLayerType::Stage);
		

		
	}

	void Stage2Scene::Update()
	{
		if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Stage1_3);
		}

		if (mStage2Pt->GetPortal())
		{
			if (Input::GetKeyDown(eKeyCode::Up))
			{
				SceneManager::LoadScene(eSceneType::Stage1_3);
			}
		}

		if (mBros->GetHP() <= 0)
		{
			ground->SetBros(nullptr);
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
		//mKirby->SetStage2(this);

		Camera::Camera::SetCameraType(Camera::eCameraEffectType::FadeIn);

		R2Ground* ground = object::Instantiate<R2Ground>(eLayerType::Ground);

		SetGround(ground);

		object::Instantiate<Stage12bk>(eLayerType::BG);

		object::Instantiate<Room2>(eLayerType::Stage);

		Kirby* mKirby = object::Instantiate<Kirby>(Vector2(129.0f, 384.0f), Vector2(2.0f, 2.0f), eLayerType::Player);


		Bros* mBros = object::Instantiate<Bros>(Vector2(400.0f, 430.0f), Vector2(2.0f, 2.0f), eLayerType::Monster); // 400, 440

		SetBros(mBros);

		ground->SetBros(mBros);

		Camera::SetTarget(mKirby);

		ground->SetPlayer(mKirby);



		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::MonsterSkill, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Box, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Air, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);
	}

	void Stage2Scene::OnExit()
	{
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}