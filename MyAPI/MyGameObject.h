#pragma once
#include "MyEntity.h"
#include "MyComponent.h"

namespace My
{

	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();


	protected:
		Vector2 mPos;

	private:
		std::vector<Component*> mComponents;

	};
}

