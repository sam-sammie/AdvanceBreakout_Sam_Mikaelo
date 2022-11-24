#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include<SDL.h>
#include "MathHelper.h"
#include <string>

namespace SDLFramework {
	class InputManager
	{
	public:
		enum MouseButton{Left = 0, Right, Middle, Back, Forward};
	private:
		static InputManager* sInstance;

	public:
		static InputManager* Instance();
		static void Release();
	private:
		const Uint8* m_pKeyboardState;
		Uint8* m_pPrevKeyboardState;
		int mKeyLength;
		Uint32 mPrevMouseState;
		Uint32 mMouseState;
		int mMouseXPosition;
		int mMouseYPosition;

	public:
		bool KeyDown(SDL_Scancode scancode);	// holding down
		bool KeyPressed(SDL_Scancode scancode);	// single press
		bool KeyReleased(SDL_Scancode scancode);// releasing

		bool MouseButtonDown(MouseButton button);
		bool MouseButtonPressed(MouseButton button);
		bool MouseButtonReleased(MouseButton button);

		Vector2 MousePosition();

		void Update();
		void UpdatePrevInput();

	private:
		InputManager();
		~InputManager();

	};



}
#endif //
