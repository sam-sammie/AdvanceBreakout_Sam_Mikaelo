#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();

	m_pSideBar = new PlaySideBar();
	m_pSideBar->Parent(this);
	m_pSideBar->Position(Graphics::SCREEN_WIDTH * 1.0f, Graphics::SCREEN_HEIGHT * 0.0f);


	// screen animation variables
	mAnimationStartPos = Vector2(1.0f, Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 0.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);

	ResetAnimation();

	m_pPlayer = new Player();
	m_pPlayer->Parent(this);
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pTesting = new Brick();
	m_pTesting->Parent(this);
	m_pTesting->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	m_pLevel = nullptr;
	mLevelStarted = false;
}

PlayScreen::~PlayScreen() {
	m_pTimer = nullptr;
	m_pAudio = nullptr;

	delete m_pSideBar;
	m_pSideBar = nullptr;

	delete m_pLevel;
	m_pLevel = nullptr;

	delete m_pPlayer;
	m_pPlayer = nullptr;

	delete m_pTesting;
	m_pTesting = nullptr;

}

void PlayScreen::Render() {
	
	m_pSideBar->Render();
	m_pTesting->Render();
	if (mGameStarted) {
		if (mLevelStarted) {
			m_pLevel->Render();
		}
		m_pPlayer->Render();
	}
	
}

void PlayScreen::Update() {
	m_pSideBar->Update();
	m_pPlayer->Update();
	m_pTesting->Update();
	if (!mAnimationDone) {
		mAnimationTimer += m_pTimer->DeltaTime();
		Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
		}
	}

	if (mGameStarted) {

		if (!mLevelStarted) {
			StartNextLevel();
		}

		else {
			m_pLevel->Update();
			if (m_pLevel->State() == Level::Finished) {
				mLevelStarted = false;
			}
		}
		if (mCurrentStage > 0) {
			m_pSideBar->Update();
		}
	}
	else {
		mGameStarted = true;
	}
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P)) {
		m_pPlayer->RedBrickDestroyed();
		m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	}
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O)) {
		m_pPlayer->OrangeBrickDestroyed();
		m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	}
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I)) {
		m_pPlayer->GreenBrickDestroyed();
		m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	}
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_U)) {
		m_pPlayer->YellowBrickDestroyed();
		m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	}
}

void PlayScreen::ResetAnimation() {
	mAnimationStartPos = Vector2(0.0f, -Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 0.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
	
	Position(mAnimationStartPos);
}

void PlayScreen::StartNewGame() {

	delete m_pPlayer;
	m_pPlayer = new Player();
	m_pPlayer->Parent(this);
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	m_pPlayer->Active(false);

	m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	m_pSideBar->SetPlayerLives(m_pPlayer->Lives());

	m_pSideBar->SetLevel(0);
	mGameStarted = false;
	mLevelStarted = false;
	mCurrentStage = 0;

}

void PlayScreen::StartNextLevel() {
	mCurrentStage += 1;
	mLevelStarted = true;

	delete m_pLevel;
	m_pLevel = new Level(mCurrentStage, m_pSideBar, m_pPlayer);
}

bool PlayScreen::GameOver() {
	return !mLevelStarted ? false : (m_pLevel->State() == Level::GameOver);
}