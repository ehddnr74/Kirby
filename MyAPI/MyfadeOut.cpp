#include "Myfadeout.h"
#include "MyResources.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyTime.h"
#include "MyTransform.h"
#include "MyScene.h"
#include "MyObject.h"

namespace My
{
	FadeOut::FadeOut()
		:fadeAmount(0.0f)
		, FadeClear(false)
	{

	}
	FadeOut::~FadeOut()
	{

	}

	void My::FadeOut::Initialize()
	{

		fadeOut = Resources::Load<Image>(L"FadeOut", L"..\\Resources\\Fading.bmp");


		GameObject::Initialize();
	}

	void My::FadeOut::Update()
	{
		GameObject::Update();

		fadeAmount += 80 * Time::DeltaTime();

		//if (fadeAmount >= 255)
		//{
		//	object::Destroy(this);
		//}
	}

	void My::FadeOut::Render(HDC hdc)
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

		AlphaBlend(hdc, 0, 0
			, fadeOut->GetWidth()
			, fadeOut->GetHeight()
			, fadeOut->GetHdc()
			, 0, 0
			, fadeOut->GetWidth()
			, fadeOut->GetHeight()
			, func);

	}

	void My::FadeOut::Release()
	{
		GameObject::Release();
	}

}