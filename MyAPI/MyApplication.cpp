#include "MyApplication.h"
#include "MySceneManager.h"
#include "MyTime.h"
#include "MyInput.h"

namespace My
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	Application::~Application()
	{
		SceneManager::Release();

	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Render(mHdc);
		SceneManager::Update();
	}

	void Application::Render()
	{
		Time::Render(mHdc);
		Input::Render(mHdc);
		SceneManager::Render(mHdc);
	}
}