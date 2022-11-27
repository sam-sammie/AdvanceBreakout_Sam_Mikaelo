#include "Level.h"

void Level::StartStage() {
	mStageStarted = true;
}

Level::Level(int stage, PlaySideBar* sideBar, Player* player) {
	m_pTimer = Timer::Instance();
	m_pSideBar = sideBar;
	m_pSideBar->SetLevel(stage);

	m_pPlayer = player;

	mStage = stage;
	mStageStarted = false;

	mBallFell = false;
	mRespawnDelay = 3.0f;
	mRespawnTimer = 0.0f;
	mRespawnLabelOnScreen = 2.0f;

	m_pGameOverLabel = new Texture("GAME OVER", "emulogic.ttf", 32, { 150,0,0 });
	m_pGameOverLabel->Parent(this);
	m_pGameOverLabel->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);

	mGameOverDelay = 6.0f;
	mGameOverTimer = 0.0f;
	mGameOverLabelOnScreen = 1.0f;

	mCurrentState = Running;
}

Level::~Level() {
	m_pTimer = nullptr;
	m_pSideBar = nullptr;
	m_pPlayer = nullptr;

	delete m_pGameOverLabel;
	m_pGameOverLabel = nullptr;
}

void Level::Update() {

	if (!mStageStarted) {
		HandleStartLabels();
	}
	else {

		HandleCollisions();

		if (mBallFell) {
			HandlePlayerDeath();
		}
		else {
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_N)) {
				mCurrentState = Finished;
			}
		}

	}

}



void Level::Render() {
	if (mBallFell) {
		if (mRespawnTimer >= mRespawnLabelOnScreen) {

		}

		if (mGameOverTimer >= mGameOverLabelOnScreen) {
			m_pGameOverLabel->Render();
		}
	}
}

Level::LevelStates Level::State() {
	return mCurrentState;
}

void Level::HandleStartLabels() {


	if (mStage > 1) {
		StartStage();
	}
	else {

		StartStage();
		m_pPlayer->Active(true);
		m_pPlayer->Visible(true);
	}


}

void Level::HandleCollisions() {
	if (!mBallFell) {
		if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_X)) {
			m_pPlayer->WasHit();
			m_pSideBar->SetPlayerLives(m_pPlayer->Lives());

			mBallFell = true;
			mRespawnTimer = 0.0f;
			m_pPlayer->Active(false);

		}

	}

}

void Level::HandleBrickBreak()
{

}


void Level::HandlePlayerDeath() {
	if (!m_pPlayer->IsAnimating()) {
		if (m_pPlayer->Lives() > 0) {
			//Respawning Player
			if (mRespawnTimer == 0.0f) {
				m_pPlayer->Visible(false);
			}

			mRespawnTimer += m_pTimer->DeltaTime();
			if (mRespawnTimer >= mRespawnDelay) {
				m_pPlayer->Active(true);
				m_pPlayer->Visible(true);
				mBallFell = false;

			}
		}
		else {
			// GameOver
			if (mGameOverTimer == 0.0f) {
				m_pPlayer->Visible(false);
			}

			mGameOverTimer += m_pTimer->DeltaTime();

			if (mGameOverTimer >= mGameOverDelay) {
				mCurrentState = GameOver;
			}
		}
	}
}
