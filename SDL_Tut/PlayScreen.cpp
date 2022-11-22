#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();
	m_pStars = BackgroundStars::Instance();

	m_pSideBar = new PlaySideBar();
	m_pSideBar->Parent(this);
	m_pSideBar->Position(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.05f);

}

PlayScreen::~PlayScreen() {
	m_pTimer = nullptr;
	m_pAudio = nullptr;
	m_pStars = nullptr;

	delete m_pSideBar;
	m_pSideBar = nullptr;
}

void PlayScreen::Update() {
	m_pSideBar->Update();
}

void PlayScreen::Render() {
	m_pSideBar->Render();
}