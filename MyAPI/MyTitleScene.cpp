#include "MyInput.h"
#include "MySceneManager.h"
#include "Ttitle.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyTitleScene.h"
#include "MyScene.h"
#include "MyObject.h"

#include "Stage1_1.h"
#include "Stage1_2.h"

#include "MySound.h"
#include "MyResources.h"


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
		Sound* mSound = Resources::Load<Sound>(L"1-01-Title", L"..\\Resources\\Sound\\1-01-Title.wav");
		mSound->Play(true);
		mSound->SetVolume(10.f);
		//mtitle = new Title();
		//AddGameObject(mtitle, eLayerType::Stage);

		mtitle = object::Instantiate<Title>(Vector2(267.0f,790.0f),Vector2(1.f,1.f),(eLayerType::BG));
	}
	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
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
		Sound* mSound = Resources::Load<Sound>(L"1-01-Title", L"..\\Resources\\Sound\\1-01-Title.wav");
		mSound->Stop(false);
	}
}
