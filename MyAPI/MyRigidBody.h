#pragma once
#include "MyComponent.h"


namespace My 
{
	class RigidBody : public Component
	{
	public:
		RigidBody();
		~RigidBody();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force);
		void SetGround(bool ground) { mbGround = ground; }
		bool GetGround() { return mbGround; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }
		void SetGravity(Vector2 gravity) { mGravity = gravity; }
		Vector2 GetGravity() { return mGravity; }
		void SetFriction(float mfriction) { mFriction = mfriction; }
		float GetFriction() { return mFriction; }


	private:
		float mMass;
		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
		Vector2 mLimitedVelocity;

		Vector2 mGravity;
		float mFriction;
		bool mbGround;

		//float mStaticFriction; Á¤Áö¸¶Âû·Â
		//float mKineticFriction; ¿îµ¿¸¶Âû·Â 
		//float mCoefficientFriction; ¸¶Âû·Â°è¼ö 
		//float mNormalForce; 
	};
}

