#include "MyTime.h"
#include "MyApplication.h"

extern My::Application application;

namespace My
{
	double Time::mDeltaTime = 0.0l;
	double Time::mSecond = 0.0f;
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	void Time::Initialize()
	{
		// CPU ���� ������ ��������
		QueryPerformanceFrequency(&mCpuFrequency);

		// ���α׷��� ó�� �����Ҷ� ������
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		double differenceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;

		mDeltaTime = differenceFrequency / mCpuFrequency.QuadPart;

		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		mSecond += mDeltaTime;

		if (mSecond > 1.0f)
		{
			HWND hWnd = application.GetHwnd();

			wchar_t szFloat[50] = {};
			float FPS = 1.0f / (float)mDeltaTime;
			swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
			//int iLen = wcsnlen_s(szFloat, 50);
			SetWindowText(hWnd, szFloat);

			mSecond = 0.0f;
		}
	}
}