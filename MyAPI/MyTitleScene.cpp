#include "MyInput.h"
#include "MySceneManager.h"
#include "Ttitle.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyTitleScene.h"
#include "MyScene.h"


namespace My
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		mtitle = new Title();
		AddGameObject(mtitle, eLayerType::Stage);

		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::Q) == eKeyState::Down)
			{
			SceneManager::LoadScene(eSceneType::Stage1_1);
			}

		Scene::Update();
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TitleScene::Release()
	{
		Scene::Release();
	}
	void TitleScene::OnEnter()
	{

	}
	void TitleScene::OnExit()
	{
		
	}
}
