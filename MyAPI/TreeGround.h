#pragma once
#include "MyGameObject.h"

namespace My
{
	class TreeGround : public GameObject
	{
	public:
		TreeGround();
		virtual ~TreeGround();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

		void SetPlayer(class Kirby* player) { mKirby = player; }


		void SetKirBoomb(class kirbyRightBoom* krb) { mkrb = krb; }
		void SetKirLeftBoomb(class kirbyLeftBoom* klb) { mklb = klb; }

		

		void SetTree(class TreeBoss* tree) { mTree = tree; }
		void SetApple(class Apple* apple) { mApple = apple; }
		void SetApple2(class Apple* apple2) { mApple2 = apple2; }


	private:
		class Collider* mCollider;
		class Image* mImage;
		class Kirby* mKirby;
		class kirbyRightBoom* mkrb;
		class kirbyLeftBoom* mklb;
		class TreeBoss* mTree;
		class Apple* mApple;
		class Apple* mApple2;

	};
}