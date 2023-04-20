#include "TreeScene.h"
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
#include "TreeStage.h"
#include "MyRigidBody.h"
#include "TreeGround.h"
#include "TreeBK.h"
#include "SaveKirby.h"
#include "SaveUI.h"
#include "TreeBoss.h"
#include "TreeBranch.h"
#include "TreeHP.h"

namespace My {
	TreeScene::TreeScene()
	{

	}
	TreeScene::~TreeScene()
	{

	}
	void TreeScene::Initialize()
	{
		Scene::Initialize();
	}
	void TreeScene::Update()
	{
		Scene::Update();
	}
	void TreeScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TreeScene::Release()
	{
		Scene::Release();
	}
	void TreeScene::OnEnter()
	{
		hp = SaveUI::GetUI();
		AddGameObject(hp, eLayerType::UI);
		mKirby = SaveKirby::GetKirby();
		AddGameObject(mKirby, eLayerType::Player);
		Transform* kr = mKirby->GetComponent<Transform>();
		kr->SetPos(Vector2(100.f, 50.0f));

		TreeGround* treegr = object::Instantiate<TreeGround>(eLayerType::Ground);
		mKirby->SetGround4(treegr);
		treegr->SetPlayer(mKirby);


		TreeBk* treebk = object::Instantiate<TreeBk>(eLayerType::BG);



		Camera::SetTarget(mKirby);
		Camera::SetTreeScene(this);
		object::Instantiate<TreeStage>(eLayerType::Stage);
		object::Instantiate<HP>(eLayerType::UI);

		mTree = object::Instantiate<TreeBoss>(Vector2(375.f, 1430.f), Vector2(2.0f, 2.0f), (eLayerType::Boss));
		treegr->SetTree(mTree);
		mTree->SetGround(treegr);
		mTree->SetKirby(mKirby);

		TreeBranch* mBranch = object::Instantiate<TreeBranch>(Vector2(410.f, 1320.f), Vector2(6.0f, 6.0f), (eLayerType::Branch));
		TreeHP* treehp = object::Instantiate<TreeHP>/*(Vector2(315, 865), Vector2(1.f, 1.f), */ (eLayerType::UI);
		
		treehp->SetKirby(mKirby);
		treehp->SetTree(mTree);

		



		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::MonsterSkill, true);
		//CollisionManager::SetLayer(eLayerType::Player, eLayerType::Box, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Air, true);
		CollisionManager::SetLayer(eLayerType::Monster, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Monster, true);


		CollisionManager::SetLayer(eLayerType::Boss, eLayerType::Star, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Boss, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Boss, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::BossSkill, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Apple, true);
		CollisionManager::SetLayer(eLayerType::Skill, eLayerType::Apple, true);
	}
	void TreeScene::OnExit()
	{

	}
}