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
#include "BoomBros.h"
#include "Box.h"
#include "Stage1_1.h"
#include "MyTransform.h"
#include "SaveKirby.h"
#include "Portion1.h"
#include "portion2.h"
#include "portion3.h"
#include "LeftBoomb.h"
#include "RightBoomb.h"
#include "Explosion.h"
#include "MyRigidBody.h"
#include "boomrect.h"
#include "Grizzo.h"
#include "SaveUI.h"
#include "MySound.h"
#include "MyResources.h"

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

		R2Ground* ground = object::Instantiate<R2Ground>(eLayerType::Ground);

		SetGround(ground);



		//mroom2 = new Room2();
		//AddGameObject(mroom2, eLayerType::Stage);

		//Camera::SetTarget(mKirby);

		//object::Instantiate<Stage12bk>(eLayerType::BG);




		//object::Instantiate<Room2>(eLayerType::Stage);
		

		
	}

	void Stage2Scene::Update()
	{
		//if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
		//{
		//	SceneManager::LoadScene(eSceneType::Stage1_3);
		//}

		if (mStage2Pt->GetPortal())
		{
			if (Input::GetKeyDown(eKeyCode::Up))
			{
				Sound* mSound = Resources::Load<Sound>(L"enter-door", L"..\\Resources\\Sound\\enter-door.wav");
				mSound->Play(false);
				SceneManager::LoadScene(eSceneType::Stage1_3);
			}
		}

		//if (mBoomBros != nullptr)
		//{
		//	if (mBoomBros->GetBoomb() != nullptr)
		//	{
		//		ground->SetBoomb(mBoomBros->GetBoomb());
		//	}

		//	if (mBoomBros->GetLeftBoomb() != nullptr)
		//	{
		//		ground->SetLeftBoomb(mBoomBros->GetLeftBoomb());
		//	}
		//}

		if (mBros->GetHP() <= 0)
		{
			//SetBros(nullptr);
			ground->SetBros(nullptr);
		}


		if (mBoomBros->GetHP() <= 0)
		{
			//SetBoomBros(nullptr);
			ground->SetBoomBros(nullptr);
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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::MonsterSkill, true);
		CollisionManager::SetLayer(eLayerType::Portal, eLayerType::Player, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Air, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);

		hp = SaveUI::GetUI();
		AddGameObject(hp, eLayerType::UI);
		MyKirby = SaveKirby::GetKirby();
		AddGameObject(MyKirby, eLayerType::Player);
		Transform* kr = MyKirby->GetComponent<Transform>();
		kr->SetPos(Vector2(129.0f, 384.0f));
		//Kirby* MyKirby = object::Instantiate<Kirby>(Vector2(129.0f, 384.0f), Vector2(2.0f, 2.0f), eLayerType::Player);
		SetPlayer(MyKirby);
		Camera::SetTarget(MyKirby);
		//mKirby->SetStage2(this);
		//Stage1Scene* mstage1 = new Stage1Scene;
		//SetStage1(mstage1);
		//MyKirby = mstage1->GetKirby();

		Camera::Camera::SetCameraType(Camera::eCameraEffectType::FadeIn);

		R2Ground* ground = object::Instantiate<R2Ground>(eLayerType::Ground);
		MyKirby->SetGround2(ground);
		SetGround(ground);
		ground->SetPlayer(MyKirby);

		//Box* box1 = object::Instantiate<Box>(Vector2(895, 325), Vector2(1.0f, 1.0f), eLayerType::Box);
		//Box* box2 = object::Instantiate<Box>(Vector2(980, 326), Vector2(0.9f, 1.0f), eLayerType::Box);
		//Box* box3 = object::Instantiate<Box>(Vector2(1025, 326), Vector2(0.9f, 1.0f), eLayerType::Box);
		//Box* box4 = object::Instantiate<Box>(Vector2(1070, 326), Vector2(0.9f, 1.0f), eLayerType::Box);
		//Box* box5 = object::Instantiate<Box>(Vector2(1155, 380), Vector2(1.0f, 1.0f), eLayerType::Box);
		
		Portion1* mCherry = object::Instantiate<Portion1>(Vector2(980, 430), Vector2(1.0f, 1.0f), eLayerType::Item);
		Portion2* mCookie = object::Instantiate<Portion2>(Vector2(1025, 430), Vector2(1.0f, 1.0f), eLayerType::Item);
		Portion3* mPizza = object::Instantiate<Portion3>(Vector2(1070, 430), Vector2(1.0f, 1.0f), eLayerType::Item);





		/*SetBox(box);*/


		//if(box1 != nullptr)
		//{
		//ground->SetBox(box1);
		//}
		//if (box2 != nullptr)
		//{
		//	ground->SetBox(box2);
		//}
		//if (box3 != nullptr)
		//{
		//	ground->SetBox(box3);
		//}
		//if (box4 != nullptr)
		//{
		//	ground->SetBox(box4);
		//}
		//if (box5 != nullptr)
		//{
		//	ground->SetBox(box5);
		//}


		object::Instantiate<Stage12bk>(eLayerType::BG);

		object::Instantiate<Room2>(eLayerType::Stage);







		//RightBoomb* rb = object::Instantiate<RightBoomb>(Vector2(200.f, 400.0f), Vector2(2.0f, 2.0f), eLayerType::MonsterSkill);
		
		
		//boomrect* rect = object::Instantiate<boomrect>(eLayerType::Rectangle);
		//rect->SetBoom(rb);

		mGrizzo = object::Instantiate<Grizzo>(Vector2(1500.f, 345.0f), Vector2(2.0f, 2.0f), eLayerType::Monster);
		mGrizzo->SetGround(ground);
		ground->SetGrizzo(mGrizzo);






		//Kirby* mKirby = object::Instantiate<Kirby>(Vector2(129.0f, 384.0f), Vector2(2.0f, 2.0f), eLayerType::Player);


		Bros* mBros = object::Instantiate<Bros>(Vector2(400.0f, 430.0f), Vector2(2.0f, 2.0f), eLayerType::Monster); // 400, 440
		BoomBros* mBoomBros = object::Instantiate<BoomBros>(Vector2(1250.0f, 430.0f), Vector2(2.0f, 2.0f), eLayerType::Monster);
		
		SetBros(mBros);
		ground->SetBros(mBros);

		if (mBoomBros != nullptr)
		{
			SetBoomBros(mBoomBros);
			mBoomBros->SetKirby(MyKirby);
			ground->SetBoomBros(mBoomBros);
			mBoomBros->SetGround(ground);
		}

		//class Explosion* mExplosion = object::Instantiate<Explosion>(Vector2(400.f,400.f),Vector2(1.f,1.f),eLayerType::Effect);

	}

	void Stage2Scene::OnExit()
	{
		SaveKirby::SetKirby(MyKirby);
		SaveUI::SetUI(hp);
		//mKirby->SetPos(Vector2(0.0f, 0.0f));
	}

}