#include "Myfadein.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyCamera.h"

namespace My
{
	FadeIn::FadeIn()
		:fadeAmount(255.0f)
	{

	}
	FadeIn::~FadeIn()
	{

	}

	void My::FadeIn::Initialize()
	{

		Fadein = Resources::Load<Image>(L"FadeIn", L"..\\Resources\\Fading.bmp");                       


		GameObject::Initialize();
	}

	void My::FadeIn::Update()
	{
		GameObject::Update();

		fadeAmount -= 80 * Time::DeltaTime();

		if (fadeAmount <= 0)
		{
			object::Destroy(this);
		}
	}

	void My::FadeIn::Render(HDC hdc)
	{

		GameObject::Render(hdc);

		//TransparentBlt(hdc, 0, 0
		//	, Fadein->GetWidth()
		//	, Fadein->GetHeight()
		//	, Fadein->GetHdc()
		//	, 0, 0
		//	, Fadein->GetWidth()
		//	, Fadein->GetHeight()
		//	, RGB(72, 104, 112));


		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		func.SourceConstantAlpha = fadeAmount;

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		pos = Camera::CalculatePos(pos);

		AlphaBlend(hdc, pos.x, pos.y
			, Fadein->GetWidth()
			, 403.0f
			, Fadein->GetHdc()
			, 0, 0
			, Fadein->GetWidth()
			, Fadein->GetHeight()
			, func);
		
	}

	void My::FadeIn::Release()
	{
		GameObject::Release();
	}

}
