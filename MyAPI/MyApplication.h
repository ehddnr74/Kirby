#pragma once
#include "MyEngine.h"


namespace My
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc;}

	private:
		HWND mHwnd;
		HDC mHdc;

		//¹é¹öÆÛ
		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;

		Vector2 mPos;

		//Scene mScene[256];
	};
}

