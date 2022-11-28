#include "PlaySideBar.h"

PlaySideBar::PlaySideBar()
{
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();

	//Layout

	m_pBackground = new Texture("Black.png");
	m_pBackground->Parent(this);
	m_pBackground->Scale(Vector2(3.0f, 10.0f));
	m_pBackground->Position(50.0f, 0.0f);

	m_pRightWall = new Texture("RightWall.png");
	m_pRightWall->Parent(this);
	m_pRightWall->Scale(Vector2(3.0f, 10.0f));
	m_pRightWall->Position(-250.0f, 0.0f);

	m_pLeftWall = new Texture("LeftWall.png");
	m_pLeftWall->Parent(this);
	m_pLeftWall->Scale(Vector2(3.0f, 10.0f));
	m_pLeftWall->Position(-975.0f, 0.0f);

	m_pTopWall = new Texture("TopWall.png");
	m_pTopWall->Parent(this);
	m_pTopWall->Scale(Vector2(500.0f, 10.0f));
	m_pTopWall->Position(-850.0f, 0.0f);

	m_pScoreLabel = new Texture("P1 SCORE:", "ARCADEPI.TTF", 32, { 150, 0, 0 });
	m_pScoreLabel->Parent(this);
	m_pScoreLabel->Position(-755.0f, 20.0f);

	m_pLivesLabel = new Texture("LIVES", "ARCADEPI.TTF", 32, { 150, 0, 0 });
	m_pLivesLabel->Parent(this);
	m_pLivesLabel->Position(-140.0f, 20.0f);

	m_pPlayerScoreboard = new Scoreboard();
	m_pPlayerScoreboard->Parent(this);
	m_pPlayerScoreboard->Position(-750.0f, 55.0f);

	m_pLives = new Scoreboard();
	m_pLives->Parent(this);
	m_pLives->Position(-140.0f, 55.0f);
}

PlaySideBar::~PlaySideBar()
{
	m_pTimer = nullptr;
	m_pAudio = nullptr;

	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pLeftWall;
	m_pLeftWall = nullptr;

	delete m_pRightWall;
	m_pRightWall = nullptr;

	delete m_pTopWall;
	m_pTopWall = nullptr;

	delete m_pScoreLabel;
	m_pScoreLabel = nullptr;

	delete m_pLivesLabel;
	m_pLivesLabel = nullptr;

	delete m_pLives;
	m_pLives = nullptr;

	delete m_pLives;
	m_pLives = nullptr;

	delete m_pPlayerScoreboard;
	m_pPlayerScoreboard = nullptr;

	delete m_PlayerOneScore;
	m_PlayerOneScore = nullptr;
}

void PlaySideBar::SetPlayerScore(int score) {
	m_pPlayerScoreboard->Score(score);
}

void PlaySideBar::SetPlayerLives(int score) {
	m_pLives->Score(score);
}

void PlaySideBar::SetLevel(int level) {
	mLevel = level;
}

void PlaySideBar::Update()
{
	m_pBackground->Update();
	m_pTopWall->Update();
	m_pRightWall->Update();
	m_pLeftWall->Update();
	m_pPlayerScoreboard->Update();
	m_pScoreLabel->Update();
	m_pLivesLabel->Update();
	m_pLives->Update();
}

void PlaySideBar::Render()
{
	m_pBackground->Render();
	m_pTopWall->Render();
	m_pRightWall->Render();
	m_pLeftWall->Render();
	m_pLivesLabel->Render();
	m_pPlayerScoreboard->Render();
	m_pScoreLabel->Render();
	m_pLives->Render();
}

void PlaySideBar::AddScore2(int score) {
	m_pPlayerScoreboard += score;
}