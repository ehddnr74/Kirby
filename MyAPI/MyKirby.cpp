#include "MyKirby.h"
#include "MyTime.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTransform.h"


namespace My
{
	Kirby::Kirby()
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		mKirby = Resources::Load<Image>(L"Kirby", L"..\\Resources\\Kirby.bmp");
		

		GameObject::Initialize();
	}
	void Kirby::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyState(eKeyCode::Left) == eKeyState::Pressed)
		{
			

			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Right) == eKeyState::Pressed)
		{
			
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Up) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Down) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);
	}
	void Kirby::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		TransparentBlt(hdc, pos.x+50, pos.y+195, mKirby->GetWidth(), mKirby->GetHeight()
			, mKirby->GetHdc(), 0, 0, mKirby->GetWidth(), mKirby->GetHeight(), RGB(255, 255, 255));

		//BitBlt(hdc, pos.x, pos.y, mKirby->GetWidth(), mKirby->GetHeight(), mKirby->GetHdc(), 0, 0, SRCCOPY);
	}
	void Kirby::Release()
	{
		GameObject::Release();
	}
}

