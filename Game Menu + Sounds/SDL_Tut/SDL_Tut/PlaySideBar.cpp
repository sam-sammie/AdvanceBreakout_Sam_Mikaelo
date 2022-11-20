#include "PlaySideBar.h"

PlaySideBar::PlaySideBar() {
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();

	m_pBackground = new Texture("Black.png");
	m_pBackground->Parent(this);
	m_pBackground->Scale(Vector2(3.0f, 10.0f));
	m_pBackground->Position(45.0f, 380.0f);

	m_pHighLabel = new Texture("High", "emulogic.ttf", 32, { 150,0,0 });
	m_pHighLabel->Parent(this);
	m_pHighLabel->Position(-25.0f, 0.0f);

	m_pScoreLabel = new Texture("SCORE", "emulogic.ttf", 32, { 150,0,0 });
	m_pScoreLabel->Parent(this);
	m_pScoreLabel->Position(25.0f, 32.0f);

	m_pHighScoreboard = new Scoreboard();
	m_pHighScoreboard->Parent(this);
	m_pHighScoreboard->Position(90.0f, 64.0f);

	m_pPlayerOneLabel = new Texture("1UP", "emulogic.ttf", 32, { 150,0,0 });
	m_pPlayerOneLabel->Parent(this);
	m_pPlayerOneLabel->Position(-45.0f, 160.0f);

	mBlinkTimer = 0.0f;
	mBlinkInterval = 0.5f;
	mPlayerOneLabelVisible = true;

	m_pPlayerOneScore = new Scoreboard();
	m_pPlayerOneScore->Parent(this);
	m_pPlayerOneScore->Position(90.0f, 192.0f);
}

PlaySideBar::~PlaySideBar() {
	m_pTimer = nullptr;
	m_pAudio = nullptr;

	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pHighLabel;
	m_pHighLabel = nullptr;

	delete m_pScoreLabel;
	m_pScoreLabel = nullptr;

	delete m_pHighScoreboard;
	m_pHighScoreboard = nullptr;

	delete m_pPlayerOneLabel;
	m_pPlayerOneLabel = nullptr;

	delete m_pPlayerOneScore;
	m_pPlayerOneScore = nullptr;

}

void PlaySideBar::Update() {
	mBlinkTimer += m_pTimer->DeltaTime();

	if (mBlinkTimer >= mBlinkInterval) {
		mPlayerOneLabelVisible = !mPlayerOneLabelVisible;
		mBlinkTimer = 0.0f;
	}

}

void PlaySideBar::Render() {
	m_pBackground->Render();
	m_pHighLabel->Render();
	m_pScoreLabel->Render();
	m_pHighScoreboard->Render();

	if (mPlayerOneLabelVisible) {
		m_pPlayerOneLabel->Render();
	}

	m_pPlayerOneScore->Render();
}
