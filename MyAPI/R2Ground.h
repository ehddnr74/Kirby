#pragma once
#include "MyGameObject.h"

namespace My
{
	class R2Ground : public GameObject
	{
	public:
		R2Ground();
		virtual ~R2Ground();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		void SetPlayer(class Kirby* player) { mKirby = player; }
		void SetBros(class Bros* bros) { mBros = bros; }
		void SetBoomBros(class BoomBros* boombros) { mBoomBros = boombros; }
		void SetBox(class Box* box) { mBox = box; }
		void SetBoomb(class RightBoomb* rb) { rboomb = rb; }
		void SetGrizzo(class Grizzo* grizzo) { mGrizzo = grizzo; }
		class RightBoomb* GetBoomb() { return rboomb; }

		void SetLeftBoomb(class LeftBoomb* lb) { lboomb = lb; }
		class LeftBoomb* GetLeftBoomb() { return lboomb; }

		

		void SetKirBoomb(class kirbyRightBoom* krb) { mkrb = krb; }
		void SetKirLeftBoomb(class kirbyLeftBoom* klb) { mklb = klb; }



	



	private:
		class Collider* mCollider;
		class Image* mImage;
		class Kirby* mKirby;
		class Bros* mBros;
		class BoomBros* mBoomBros;
		class Grizzo* mGrizzo;
		class Box* mBox;
		class RightBoomb* rboomb;
		class LeftBoomb* lboomb;
		class kirbyRightBoom* mkrb;
		class kirbyLeftBoom* mklb;


		

	};
}
