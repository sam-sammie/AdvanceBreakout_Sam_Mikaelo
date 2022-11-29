#ifndef _GRAPHICS_H
#define _GRAPHICS_H
#include <SDL.h>
#include <iostream>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>


namespace SDLFramework {
	class Graphics
	{
	public:
		static const short SCREEN_WIDTH = 1024;
		static const short SCREEN_HEIGHT = 896;
		const char* WINDOW_TITLE = "BREAKOUT!";
	private:
		static Graphics* sInstance;
		static bool sInitialized;
		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;

	public:
		static Graphics* Instance();
		static void Release();
		static bool Initialized();

		void ClearBackBuffer();
		void Render();
		SDL_Texture* LoadTexture(std::string path);
		void DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect = nullptr,
			SDL_Rect* dstRect = nullptr, float angle = 0.0f, 
			SDL_RendererFlip flip = SDL_FLIP_NONE);

		SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

	private:
		Graphics();
		~Graphics();

		bool Init();
	};
}
#endif

