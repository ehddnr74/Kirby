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
			//���ҽ��ʿ��� �����͸� Ž���Ѵ�. �����Ͱ� �ִٸ� �ش絥���͸� ��ȯ�ϰ�
			//�����Ͱ� ���ٸ� end�� ��ȯ���ش�.
			std::map<std::wstring, Resource*>::iterator iter = mResources.find(Key);

			//ã���� �ϴ� �����Ͱ� �����Ѵٸ� 
			//�ش�Ÿ������ �ຯȯ�Ͽ� ��ȯ
			if (iter != mResources.end())
			{
				return dynamic_cast<T*>(iter->second);
			}

			return nullptr;
		}

		template<typename T>
		static T* Load(const std::wstring& Key, const std::wstring& path)
		{
			// Ű������ Ž��
			T* resource = Resources::Find<T>(Key);
			if (resource != nullptr)
			{
				return resource;
			}

			// �ش� ���ҽ��� ���ٸ� 
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

