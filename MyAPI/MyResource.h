#pragma once
#include "MyEntity.h"

namespace My
{
	class Resource
	{
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetKey() { return mKey;}
		const std::wstring& GetPath() { return mPath; }
		void SetKey(const std::wstring& Key) { mKey = Key; }
		void SetPath(const std::wstring& Path) { mKey = Path; }

	private:
		std::wstring mKey;
		std::wstring mPath;
	};

	//class Image : public Resource
	//{

	//};

	//class sound : public Resource
	//{

	//};
}

