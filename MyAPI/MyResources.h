#pragma once
#include "Myresource.h"

namespace My
{

	class Resources
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& Key)
		{
			//리소스맵에서 데이터를 탐색한다. 데이터가 있다면 해당데이터를 반환하고
			//데이터가 없다면 end를 반환해준다.
			std::map<std::wstring, Resource*>::iterator iter = mResources.find(Key);

			//찾고자 하는 데이터가 존재한다면 
			//해당타입으로 행변환하여 반환
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}

			return nullptr;
		}

		template<typename T>
		static T* Load(const std::wstring& Key, const std::wstring& path)
		{
			// 키값으로 탐색
			T* resource = Resources::Find<T>(Key);
			if (resource != nullptr)
			{
				return resource;
			}

			// 해당 리소스가 없다면 
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				assert(false);
				return nullptr;
			}

			resource->SetKey(Key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(Key, resource));

			return dynamic_cast<T*>(resource);
		}

		template <typename T>
		static void Insert(const std::wstring& key, T* resource)
		{
			mResources.insert(std::make_pair(key, resource));
		}


		static void Release()
		{
			for (auto pair : mResources)
			{
				delete pair.second;
				pair.second = nullptr;
			}
		}

	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}

