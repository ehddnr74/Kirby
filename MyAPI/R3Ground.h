#pragma once
#include "MyGameObject.h"

namespace My
{
	class R3Ground : public GameObject
	{
	public:
		R3Ground();
		virtual ~R3Ground();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		void SetPlayer(class Kirby* player) { mKirby = player; }
		void SetCappy(class Cappy* cappy) { mCappy = cappy; }

		void SetKirBoomb(class kirbyRightBoom* krb) { mkrb = krb; }
		void SetKirLeftBoomb(class kirbyLeftBoom* klb) { mklb = klb; }

	private:
		class Collider* mCollider;
		class Image* mImage;
		class Kirby* mKirby;
		class Cappy* mCappy;
		class kirbyRightBoom* mkrb;
		class kirbyLeftBoom* mklb;
	};
}