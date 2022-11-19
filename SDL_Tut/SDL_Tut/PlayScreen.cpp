#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();
	m_pStars - BackgroundStars::Instance();
}

PlayScreen::~PlayScreen() {
	m_pTimer = nullptr;
	m_pAudio = nullptr;
	m_pStars = nullptr;
}

void PlayScreen::Update() {}

void PlayScreen::Render() {}