#include "Stage1_3.h"
#include "MyKirby.h"
#include "MyInput.h"
#include "MySceneManager.h"
#include "MyApplication.h"
#include "MyImage.h"
#include "MyCollisionManager.h"
#include "MyCamera.h"
#include "MyObject.h"
#include "MyRectangle.h"
#include "Star.h"
#include "StarMap.h"
#include "MyRectangle.h"
#include "KirbyBeam.h"
#include "LeftKirbyBeam.h"
#include "EnergyBeam.h"
#include "LeftEnergyBeam.h"
#include "HP.h"
#include "Room3.h"
#include "MyRigidBody.h"

namespace My {
	Stage1_3::Stage1_3()
	{

	}
	Stage1_3::~Stage1_3()
	{

	}
	void Stage1_3::Initialize()
	{
		

		Scene::Initialize();
	}
	void Stage1_3::Update()
	{
		if (Input::GetKeyState(eKeyCode::Enter) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::TreeScene);
		}

		Scene::Update();
	}
	void Stage1_3::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void Stage1_3::Release()
	{
		Scene::Release();
	}
	void Stage1_3::OnEnter()
	{
		object::Instantiate<Room3>(eLayerType::Stage);

		Kirby* mKirby = object::Instantiate<Kirby>(Vector2(50.0f, 50.0f), Vector2(2.0f, 2.0f), eLayerType::Player);

		RigidBody* rb = mKirby->GetComponent<RigidBody>();

		rb->SetGravity(Vector2(0.f,10.f));

		Camera::SetTarget(mKirby);
		Camera::SetScene(this);
		
	}

	void Stage1_3::OnExit()
	{

	}
}