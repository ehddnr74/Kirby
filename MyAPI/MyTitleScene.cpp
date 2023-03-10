#include "MyInput.h"
#include "MySceneManager.h"
#include "Ttitle.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyTitleScene.h"
#include "MyScene.h"
#include "MyObject.h"


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
		Scene::Initialize();

		//mtitle = new Title();
		//AddGameObject(mtitle, eLayerType::Stage);

		object::Instantiate<Title>(eLayerType::BG);

		
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
