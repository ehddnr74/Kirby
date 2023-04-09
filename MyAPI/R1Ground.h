#pragma once
#include "MyGameObject.h"

namespace My
{
	class Ground : public GameObject
	{
	public:
		Ground();
		virtual ~Ground();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		void SetPlayer(class Kirby* player) { mKirby = player; }
		void SetWaddle(class Waddle* waddle) { mWaddle = waddle; }
		void SetCappy(class Cappy* cappy) { mCappy = cappy; }
		void SetTwizzy(class Twizzy* twizzy) { mTwizzy = twizzy; }



	private:
		class Collider* mCollider;
		class Image* mImage;
		class Kirby* mKirby;
		class Cappy* mCappy;
		class Waddle* mWaddle;
		class Twizzy* mTwizzy;
		class Component* mcomp;

	};
}
