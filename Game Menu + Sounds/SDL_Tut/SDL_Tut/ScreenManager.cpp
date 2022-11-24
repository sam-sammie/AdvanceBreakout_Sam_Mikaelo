#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

ScreenManager::ScreenManager() {
	m_pInput = InputManager::Instance();

	//m_pBackgroundStars = BackgroundStars::Instance();
	m_pStartScreen = new StartScreen();
	m_pPlayScreen = new PlayScreen();

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	m_pInput = nullptr;

	//BackgroundStars::Release();
	//m_pBackgroundStars = nullptr;

	delete m_pStartScreen;
	m_pStartScreen = nullptr;

	delete m_pPlayScreen;
	m_pPlayScreen = nullptr;
}

void ScreenManager::Update() {
	//m_pBackgroundStars->Update();

	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Update();

		if (m_pInput->KeyPressed(SDL_SCANCODE_RETURN)) {
			mCurrentScreen = Play;
			m_pStartScreen->ResetAnimation();
		}
		break;

	case Play:
		m_pPlayScreen->Update();

		if (m_pInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
		}

		break;
	}
}

void ScreenManager::Render() {
	//m_pBackgroundStars->Render();

	switch (mCurrentScreen) {
	case Start:
		m_pStartScreen->Render();
		break;

	case Play:
		m_pPlayScreen->Render();
		break;
	}
}