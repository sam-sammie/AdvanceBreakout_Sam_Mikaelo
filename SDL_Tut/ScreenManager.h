#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
#include "StartScreen.h"
#include "BackGroundStars.h"
#include "PlayScreen.h"
#include "Credits.h"


class ScreenManager
{
private: 
	static ScreenManager* sInstance;

public:
	static ScreenManager* Instance();
	static void Release();

private:
	ScreenManager();
	~ScreenManager();

private:
	enum Screens {Start, Play, Credit};
	Screens mCurrentScreen; // used to determine which screens needs to be rendered adn updating
	InputManager* m_pInput;
	BackgroundStars* m_pBackgroundStars;
	StartScreen* m_pStartScreen;
	PlayScreen* m_pPlayScreen;
	Credits* m_pCredits;

public:
	void Update();
	void Render();
};

#endif // !"StartScreen.h"