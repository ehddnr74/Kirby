#pragma once
#include "MyGameObject.h"
#include "MyScene.h"
#include "MySceneManager.h"
#include "MyTransform.h"

namespace My::object
{
	template <typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	template <typename T>
	static inline T* Instantiate(Vector2 pos ,Vector2 scale, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);
		gameObj->GameObject::GetComponent<Transform>()->SetScale(scale);
		gameObj->Initialize();

		return gameObj;
	}


	static void Destroy(GameObject* obj)
	{
		obj->SetState(GameObject::eState::Death);
	}
}