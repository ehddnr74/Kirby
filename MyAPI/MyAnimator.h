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
			Event mStartEvent; // 처음에 애니메이션이 시작될 때 나와야하는 이벤트
			Event mCompleteEvent; // 한 애니메이션이 끝났을때 호출되는 이벤트
			Event mEndEvent;//애니메이션을 돌다가 특정 키를 눌러 전환될 때 호출되는 이벤트

			//mStartEvent();
			//mStartEvent = test;
		};

		Animator();
		~Animator();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void CreateAnimation(); // sprite 로딩 한칸씩 애니메이션을 실행시킬 수 있음
		void CreateAnimations(); // 파일로 되어있는 애니메이션 실행 시킬 수 있음

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

