#pragma once
#include "MyEntity.h"

namespace My
{
	class Component : public Entity
	{
	public:
		Component(eComponentType type);
		~Component();

	    virtual void Initialize();
	    virtual void Update();
	    virtual void Render(HDC hdc);
	    virtual void Release();

		eComponentType GetType() { return mType; }

	private:
		const eComponentType mType;
	};
}

