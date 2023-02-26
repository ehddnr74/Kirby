#pragma once
#include "MyComponent.h"
#include "MyAnimation.h"
#include "MyImage.h"

namespace My
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator =(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
				{
					mEvent();
				}
			}

			//void(*name)(int,int);
			std::function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent; // ó���� �ִϸ��̼��� ���۵� �� ���;��ϴ� �̺�Ʈ
			Event mCompleteEvent; // �� �ִϸ��̼��� �������� ȣ��Ǵ� �̺�Ʈ
			Event mEndEvent;//�ִϸ��̼��� ���ٰ� Ư�� Ű�� ���� ��ȯ�� �� ȣ��Ǵ� �̺�Ʈ

			//mStartEvent();
			//mStartEvent = test;
		};

		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void CreateAnimation(); // sprite �ε� ��ĭ�� �ִϸ��̼��� �����ų �� ����
		void CreateAnimations(); // ���Ϸ� �Ǿ��ִ� �ִϸ��̼� ���� ��ų �� ����

		Animation* FindAnimation(const std::wstring& name);
		void Play(const std::wstring& name, bool loop);

		Events* FindEvents(const std::wstring& name);
		std::function<void>& GetStartEvent(const std::wstring& name);
		std::function<void>& GetCompleteEvent(const std::wstring& name);
		std::function<void>& GetEndEvent(const std::wstring& name);

	private:
		std::map<std::wstring, Animation*> mAnimations;
		std::map<std::wstring, Events*> mEvenets;
		Animation* mActiveAnimation;
		Image* mSpriteSheet;
	};
}

