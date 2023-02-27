#include "MyTitleScene.h"
#include "MyInput.h"
#include "MySceneManager.h"

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
	}
	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::Z) == eKeyState::Down)
			{
			SceneManager::LoadScene(eSceneType::Stage1_1);
			}
	}
	void TitleScene::Render(HDC hdc)
	{
	}
	void TitleScene::Release()
	{
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}
