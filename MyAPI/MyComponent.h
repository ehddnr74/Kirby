#pragma once
#include "MyEntity.h"

namespace My
{
	class Component : public Entity
	{
	public:
	    virtual void Initialize();
	    virtual void Update();
	    virtual void Render(HDC hdc);
	    virtual void Release();



	private:

	};
}

