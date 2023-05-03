#include "EndingScene.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyTitleScene.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MySound.h"
#include "MyResources.h"
#include "Ending.h"
#include "MyfadeOut.h"


namespace My
{
	EndingScene::EndingScene()
	{
	}
	EndingScene::~EndingScene()
	{
	}
	void EndingScene::Initialize()
	{
		Scene::Initialize();

		//Sound* mSound = Resources::Load<Sound>(L"1-01-Title", L"..\\Resources\\Sound\\1-01-Title.wav");
		//mSound->Play(true);
		//mSound->SetVolume(10.f);
		//mtitle = new Title();
		//AddGameObject(mtitle, eLayerType::Stage);

		mEnding = object::Instantiate<Ending>(Vector2(0.0f, 1155.0f), Vector2(1.f, 1.f), (eLayerType::BG));
	}
	void EndingScene::Update()
	{
		Scene::Update();
	}
	void EndingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void EndingScene::Release()
	{
		Scene::Release();
	}
	void EndingScene::OnEnter()
	{
		Sound* mSound = Resources::Load<Sound>(L"6-26-Green-Greens", L"..\\Resources\\Sound\\6-26-Green-Greens.wav");
		mSound->Stop(false);
		Sound* mSound2 = Resources::Load<Sound>(L"Ending", L"..\\Resources\\Sound\\Ending.wav");
		mSound2->Play(false);
		mSound2->SetVolume(10.f);

	}
	void EndingScene::OnExit()
	{
		//Sound* mSound = Resources::Load<Sound>(L"1-01-Title", L"..\\Resources\\Sound\\1-01-Title.wav");
		//mSound->Stop(false);
	}
}
