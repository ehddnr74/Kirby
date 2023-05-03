#include "Endingstar.h"
#include "myTime.h"
#include "MySceneManager.h"
#include "MyInput.h"
#include "MyResources.h"
#include "MyTransform.h"
#include "MyAnimator.h"
#include "MyCollider.h"
#include "MyScene.h"
#include "MyObject.h"
#include "MyKirby.h"
#include "MyCollider.h"
#include "MySound.h"
#include "MyResources.h"
#include "MyCamera.h"
#include "MyfadeOut.h"

namespace My
{
	EndingStar::EndingStar()
		:GetEnd(false)
		,time(0.f)
	{

	}
	EndingStar ::~EndingStar()
	{

	}
	void EndingStar::Initialize()
	{
		Image* endingstar = Resources::Load<Image>(L"EndingStar", L"..\\Resources\\endingstar.bmp");

		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"EndingStar", endingstar, Vector2(0.f,0.f), 7, 1, 7, Vector2::Zero, 0.05);

		mAnimator->Play(L"EndingStar", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-50.0f, -150.0f));
		collider->SetSize(Vector2(100.0f, 100.0f));

		GameObject::Initialize();
	}
	void EndingStar::Update()
	{
		if (GetEnd == true)
		{
			GetEnd = false;
			Sound* mSound2 = Resources::Load<Sound>(L"00b8 - SE_WARPSTAR2", L"..\\Resources\\Sound\\00b8 - SE_WARPSTAR2.wav");
			mSound2->Stop(false);
			Sound* mSound = Resources::Load<Sound>(L"enter-door", L"..\\Resources\\Sound\\enter-door.wav");
			mSound->Play(false);
			FadeOut* mFadeOut = object::Instantiate<FadeOut>(eLayerType::Rectangle);
			SetFade(mFadeOut);
		}

		if (mFadeOut != nullptr)
		{
			if (mFadeOut->GetAmount() >= 250.f)
			{
				SceneManager::LoadScene(eSceneType::Ending);
			}
		}


		GameObject::Update();
	}
	void EndingStar::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void EndingStar::Release()
	{
		GameObject::Release();
	}
	void EndingStar::OnCollisionEnter(Collider* other)
	{
		if (mKirby = dynamic_cast<Kirby*>(other->GetOwner()))
		{
			GetEnd = true;
		}
	}
	void EndingStar::OnCollisionStay(Collider* other)
	{
	}
	void EndingStar::OnCollisionExit(Collider* other)
	{
	}
}
