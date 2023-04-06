#include "KirbyBeam.h"
#include "MyImage.h"
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

namespace My
{
	KirbyBeam::KirbyBeam()
		:beamtime(0.f)
	{

	}
	KirbyBeam::~KirbyBeam()
	{

	}
	void KirbyBeam::Initialize()
	{


		Image* KirbyBeam = Resources::Load<Image>(L"KirbyBeam", L"..\\Resources\\Beam.bmp");

		mAnimator = AddComponent<Animator>();
		
		
		mAnimator->CreateAnimation(L"RightKirbyBeam", KirbyBeam, Vector2::Zero, 22, 1, 17, Vector2::Zero, 0.02);

		//mAnimator->CreateAnimation(L"RightKirbyBeam", KirbyBeam, Vector2(300.0f,0.0f), 20, 1, 1, Vector2::Zero, 0.05);

		mAnimator->Play(L"RightKirbyBeam", false);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-65.0f, -130.0f));
		collider->SetSize(Vector2(140.0f, 100.0f));

		

		GameObject::Initialize();
	}
	void KirbyBeam::Update()
	{
		beamtime += Time::DeltaTime();

		if (beamtime >= 0.34f)
		{
			object::Destroy(this);
		}

				if (mkirby->GetJumpingBeam())
				{
					Transform* tr = GetComponent<Transform>();
					Vector2 BeamPos = tr->GetPos();
					Transform* kr = mkirby->GetComponent<Transform>();
					Vector2 KirbyPos = kr->GetPos();

					BeamPos.x = KirbyPos.x + 100;
					BeamPos.y = KirbyPos.y + 80;

					tr->SetPos(BeamPos);
				}


		GameObject::Update();
	}
	void KirbyBeam::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void KirbyBeam::Release()
	{
		GameObject::Release();
	}
	void KirbyBeam::OnCollisionEnter(Collider* other)
	{
	}
	void KirbyBeam::OnCollisionStay(Collider* other)
	{
	}
	void KirbyBeam::OnCollisionExit(Collider* other)
	{
	}
};