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
		Kirby* mKirby = object::Instantiate<Kirby>(Vector2(150.0f, 100.0f), Vector2(2.0f, 2.0f), eLayerType::Player);

		TreeGround* treegr = object::Instantiate<TreeGround>(eLayerType::Ground);
		treegr->SetPlayer(mKirby);

		TreeBk* treebk = object::Instantiate<TreeBk>(eLayerType::BG);

		Camera::SetTarget(mKirby);
		Camera::SetTreeScene(this);
		object::Instantiate<TreeStage>(eLayerType::Stage);
		object::Instantiate<HP>(eLayerType::UI);
	}
	void TreeScene::OnExit()
	{

	}
}