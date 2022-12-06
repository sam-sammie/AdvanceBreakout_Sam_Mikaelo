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
	
	m_pBrickRow_1 = new Brick();
	m_pBrickRow_1->Parent(this);
	m_pBrickRow_1->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.8f);
	
	m_pBrickRow_2 = new Brick();
	m_pBrickRow_2->Parent(this);
	m_pBrickRow_2->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_3 = new Brick();
	m_pBrickRow_3->Parent(this);
	m_pBrickRow_3->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_4 = new Brick();
	m_pBrickRow_4->Parent(this);
	m_pBrickRow_4->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_5 = new Brick();
	m_pBrickRow_5->Parent(this);
	m_pBrickRow_5->Position(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_6 = new Brick();
	m_pBrickRow_6->Parent(this);
	m_pBrickRow_6->Position(Graphics::SCREEN_WIDTH * 0.8f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_7 = new Brick();
	m_pBrickRow_7->Parent(this);
	m_pBrickRow_7->Position(Graphics::SCREEN_WIDTH * 0.9f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_8 = new Brick();
	m_pBrickRow_8->Parent(this);
	m_pBrickRow_8->Position(Graphics::SCREEN_WIDTH * 1.0f, Graphics::SCREEN_HEIGHT * 0.8f);

	m_pBrickRow_9 = new Brick();
	m_pBrickRow_9->Parent(this);
	m_pBrickRow_9->Position(Graphics::SCREEN_WIDTH * 1.1f, Graphics::SCREEN_HEIGHT * 0.8f);

	//Arrays:
	Redbrick[0] = m_pBrickRow_1;
	Redbrick[1] = m_pBrickRow_2;
	Redbrick[2] = m_pBrickRow_3;
	Redbrick[3] = m_pBrickRow_4;
	Redbrick[4] = m_pBrickRow_5;
	Redbrick[5] = m_pBrickRow_6;
	Redbrick[6] = m_pBrickRow_7;
	Redbrick[7] = m_pBrickRow_8;
	Redbrick[8] = m_pBrickRow_9;

	Orangebrick[0] = m_pBrickRow_1;
	Orangebrick[1] = m_pBrickRow_2;
	Orangebrick[2] = m_pBrickRow_3;
	Orangebrick[3] = m_pBrickRow_4;
	Orangebrick[4] = m_pBrickRow_5;
	Orangebrick[5] = m_pBrickRow_6;
	Orangebrick[6] = m_pBrickRow_7;
	Orangebrick[7] = m_pBrickRow_8;
	Orangebrick[8] = m_pBrickRow_9;

	Greenbrick[0] = m_pBrickRow_1;
	Greenbrick[1] = m_pBrickRow_2;
	Greenbrick[2] = m_pBrickRow_3;
	Greenbrick[3] = m_pBrickRow_4;
	Greenbrick[4] = m_pBrickRow_5;
	Greenbrick[5] = m_pBrickRow_6;
	Greenbrick[6] = m_pBrickRow_7;
	Greenbrick[7] = m_pBrickRow_8;
	Greenbrick[8] = m_pBrickRow_9;

	Yellowbrick[0] = m_pBrickRow_1;
	Yellowbrick[1] = m_pBrickRow_2;
	Yellowbrick[2] = m_pBrickRow_3;
	Yellowbrick[3] = m_pBrickRow_4;
	Yellowbrick[4] = m_pBrickRow_5;
	Yellowbrick[5] = m_pBrickRow_6;
	Yellowbrick[6] = m_pBrickRow_7;
	Yellowbrick[7] = m_pBrickRow_8;
	Yellowbrick[8] = m_pBrickRow_9;

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

	delete m_pBrickRow_1;
	m_pBrickRow_1 = nullptr;
	
	delete m_pBrickRow_2;
	m_pBrickRow_2 = nullptr;
	
	delete m_pBrickRow_3;
	m_pBrickRow_3 = nullptr;

	delete m_pBrickRow_4;
	m_pBrickRow_4 = nullptr;

	delete m_pBrickRow_5;
	m_pBrickRow_5 = nullptr;

	delete m_pBrickRow_6;
	m_pBrickRow_6 = nullptr;

	delete m_pBrickRow_7;
	m_pBrickRow_7 = nullptr;

	delete m_pBrickRow_8;
	m_pBrickRow_8 = nullptr;

	delete m_pBrickRow_9;
	m_pBrickRow_9 = nullptr;

	delete m_pBall;
	m_pBall = nullptr;

}

void PlayScreen::Render() {
	
	m_pSideBar->Render();
	if (mGameStarted) {
		if (mLevelStarted) {
			m_pLevel->Render();
		}
		m_pPlayer->Render();
		m_pBrickRow_1->Render();
		m_pBrickRow_2->Render();
		m_pBrickRow_3->Render();
		m_pBrickRow_4->Render();
		m_pBrickRow_5->Render();
		m_pBrickRow_6->Render();
		m_pBrickRow_7->Render();
		m_pBrickRow_8->Render();
		m_pBrickRow_9->Render();
		m_pBall->Render();
	}
	
}

void PlayScreen::Update() {
	m_pSideBar->Update();
	m_pPlayer->Update();
	m_pBall->Update();

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
	else 
	{
		mGameStarted = true;
	}
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P)) 
			{
				for (int i = 0; i < 9 - 1; i++) {
					Redbrick[0]->Update();
					Redbrick[i] = Redbrick[i + 1];
					
				}
				m_pPlayer->RedBrickDestroyed();
				m_pSideBar->SetPlayerScore(m_pPlayer->Score());
				
			}
			
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O))
			{
				for (int i = 0; i < 9 - 1; i++) {
					Orangebrick[0]->Update();
					Orangebrick[i] = Orangebrick[i + 1];

				}
				m_pPlayer->OrangeBrickDestroyed();
				m_pSideBar->SetPlayerScore(m_pPlayer->Score());
			}
			
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I))
			{
				for (int i = 0; i < 9 - 1; i++) {
					Greenbrick[0]->Update();
					Greenbrick[i] = Greenbrick[i + 1];

				}
				m_pPlayer->GreenBrickDestroyed();
				m_pSideBar->SetPlayerScore(m_pPlayer->Score());
			}
			
			if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_U))
			{
				for (int i = 0; i < 9 - 1; i++) {
					Yellowbrick[0]->Update();
					Yellowbrick[i] = Yellowbrick[i + 1];

				}
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
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * 0.55f, Graphics::SCREEN_HEIGHT * 0.8f);
	m_pPlayer->Active(false);

	m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	m_pSideBar->SetPlayerLives(m_pPlayer->Lives());

	m_pSideBar->SetLevel(0);
	mGameStarted = false;
	mLevelStarted = false;
	mCurrentStage = 0;

	delete m_pBall;
	m_pBall = new Ball();
	m_pBall->Parent(this);
	m_pBall->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.8f);
	m_pBall->Active(false);

}

void PlayScreen::StartNextLevel() {
	mCurrentStage += 1;
	mLevelStarted = true;

	delete m_pLevel;
	m_pLevel = new Level(mCurrentStage, m_pSideBar, m_pPlayer, m_pBall);
}

bool PlayScreen::GameOver() {
	return !mLevelStarted ? false : (m_pLevel->State() == Level::GameOver);
}