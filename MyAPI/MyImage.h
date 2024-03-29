#pragma once
#include "MyResource.h"
namespace My
{
	class Image : public Resource
	{
	public:
		static Image* Create(const std::wstring& name, UINT widht, UINT height, COLORREF rgb = RGB(255, 255, 255));

		Image();
		virtual ~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		COLORREF GetPixel(int x, int y);
		void SetPixel(int x, int y, COLORREF color);

		HDC GetHdc() { return mHdc; }
		HBITMAP GetBitmap() { return mBitmap; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}

