#include "MyInput.h"
#include "MyTime.h"


namespace My
{
	int ASCII[(UINT)eKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SPACE,VK_RETURN
	};

	std::vector<Input::Key> Input::mKeys;

	double keytime = 0.0f;


	void Input::Initialize()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			Key keyInfo;
			keyInfo.key = (eKeyCode)i;
			keyInfo.state = eKeyState::None;
			keyInfo.bPressed = false;
			keyInfo.bDouble = false;


			mKeys.push_back(keyInfo);
		}



	}



	void Input::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{

				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;


				mKeys[i].bPressed = true;

				//if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				//{
				//	keytime += Time::DeltaTime();
				//	if (keytime <= 2.0f)
				//	mKeys[i].state = eKeyState::Double;
				//}
			}
				
			else // 현재 프레임에 키가 눌려있지 않다.
			{
				// 이전 프레임에 내키가 눌려있었다.
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;

				mKeys[i].bPressed = false;

			}
		}
	}



	void Input::Render(HDC hdc)
	{

	}
}
