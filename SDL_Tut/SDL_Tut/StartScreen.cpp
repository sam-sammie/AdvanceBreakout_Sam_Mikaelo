#include "StartScreen.h"

StartScreen::StartScreen() {
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	// Top bar entities
	m_pTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	m_pPlayerOne = new Texture("1UP", "emulogic.ttf", 32, { 200,0,0 });
	m_pPlayerTwo = new Texture("2UP", "emulogic.ttf", 32, { 200,0,0 });
	m_pHiScore = new Texture("HI SCORE", "emulogic.ttf", 32, { 200,0,0 });
	m_pPlayerOneScore = new Scoreboard;
	m_pPlayerTwoScore = new Scoreboard;
	m_pTopScore = new Scoreboard;

	// Play mode entites
	m_pPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * .55f);
	m_pOnePlayerMode = new Texture("1 Player ", "emulogic.ttf", 32, { 230,230,230 });
	m_pTwoPlayerMode = new Texture("2 Players ", "emulogic.ttf", 32, { 230,230,230 });
	m_pCursor = new Texture("Cursor.png");
	
	//Nottom Bar Entites
	m_pBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	m_pNamco = new Texture("namco", "namco__.ttf", 36, { 200,0,0 });
	m_pDates = new Texture("1982 1985 NAMCO LTD.", "emulogic.ttf", 32, { 230,230,230 });
	m_pRights = new Texture("ALL RIGHTS RESERVED", "emulogic.ttf", 32, {230, 230, 230});

	//Logo Entities
	m_pLogo = new Texture("Test3.png", 0, 0, 360, 180);
	m_pLogo->Parent(this);
	m_pLogo->Position(Graphics::SCREEN_WIDTH * 0.48f, Graphics::SCREEN_HEIGHT * 0.32f);

	m_pAnimatedLogo = new AnimatedTexture("Test3.png", 0, 0, 360, 180, 3, 0.2f, AnimatedTexture::Vertical);
	m_pAnimatedLogo->Parent(this);
	m_pAnimatedLogo->Position(Graphics::SCREEN_WIDTH * 0.48f, Graphics::SCREEN_HEIGHT * 0.32f);

	// Top bar entities
	m_pTopBar->Parent(this);
	m_pPlayerOne->Parent(m_pTopBar);
	m_pPlayerTwo->Parent(m_pTopBar);
	m_pHiScore->Parent(m_pTopBar);
	m_pPlayerOneScore->Parent(m_pTopBar);
	m_pPlayerTwoScore->Parent(m_pTopBar);
	m_pTopScore->Parent(m_pTopBar);

	// Play mode entities
	m_pPlayModes->Parent(this);
	m_pOnePlayerMode->Parent(m_pPlayModes);
	m_pTwoPlayerMode->Parent(m_pPlayModes);
	m_pCursor->Parent(m_pPlayModes);

	m_pPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	m_pPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.35F, 0.0F);
	m_pHiScore->Position(-30.0f, 0.0f);
	m_pPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * 0.35f, 40.0f);
	m_pPlayerTwoScore->Position(Graphics::SCREEN_WIDTH * 0.35f, 40.0f);
	m_pTopScore->Position(Graphics::SCREEN_WIDTH * 0.05f, 40.0f);
	m_pTopScore->Score(645987);

	//Play mode entites
	m_pOnePlayerMode->Position(0.0f, -35.0f);
	m_pTwoPlayerMode->Position(0.0f, 35.0f);
	m_pCursor->Position(-175.0f, -35.0f);

	m_pBottomBar->Parent(this);
	m_pNamco->Parent(m_pBottomBar);
	m_pDates->Parent(m_pBottomBar);
	m_pRights->Parent(m_pBottomBar);

	//Bottom bar entites
	m_pNamco->Position(Vec2_Zero);
	m_pDates->Position(0.0f, 90.0f);
	m_pRights->Position(0.0f, 170.0f);

	// screen animation variables
	mAnimationStartPos = Vector2(1.0f, Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);

	mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0; // 0 for single player and 1 for 2 players

	ResetAnimation();
	//ScreenShake();

	m_pStars = BackgroundStars::Instance();
	m_pStars->Scroll(true);
}

StartScreen::~StartScreen() {
	delete m_pTopBar;
	m_pTopBar = nullptr;

	delete m_pPlayerOne;
	m_pPlayerOne = nullptr;

	delete m_pPlayerTwo;
	m_pPlayerTwo = nullptr;

	delete m_pHiScore;

	m_pTimer = nullptr;
	m_pInputManager = nullptr;

	delete m_pPlayModes;
	m_pPlayModes = nullptr;

	delete m_pOnePlayerMode;
	m_pOnePlayerMode = nullptr;
	
	delete m_pTwoPlayerMode;
	m_pTwoPlayerMode = nullptr;
	
	delete m_pCursor;
	m_pCursor = nullptr;

	delete m_pBottomBar;
	m_pBottomBar = nullptr;

	delete m_pNamco;
	m_pNamco = nullptr;

	delete m_pDates;
	m_pDates = nullptr;

	delete m_pRights;
	m_pRights = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pAnimatedLogo;
	m_pAnimatedLogo = nullptr;

	delete m_pPlayerOneScore;
	m_pPlayerOneScore = nullptr;

	delete m_pPlayerTwoScore;
	m_pPlayerTwoScore = nullptr;

	delete m_pTopScore;
	m_pTopScore = nullptr;
}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	m_pCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

void StartScreen::Update() {
	if (!mAnimationDone) {
		mAnimationTimer += m_pTimer->DeltaTime();
		Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
			m_pStars->Scroll(false);
		}
		if (m_pInputManager->KeyPressed(SDL_SCANCODE_DOWN) || m_pInputManager->KeyPressed(SDL_SCANCODE_UP)) {
				mAnimationTimer = mAnimationTotalTime;
			 }
	}
	else {
		m_pAnimatedLogo->Update();

		if (m_pInputManager->KeyPressed(SDL_SCANCODE_DOWN)) {
			ChangeSelectedMode(1);
		}
		else if (m_pInputManager->KeyPressed(SDL_SCANCODE_UP)) {
			ChangeSelectedMode(-1);
		}
	}
}

void StartScreen::Render() {
	m_pRights->Render(); 
	m_pPlayerOne->Render();
	m_pPlayerTwo->Render();
	m_pHiScore->Render();
	m_pOnePlayerMode->Render();
	m_pTwoPlayerMode->Render();
	m_pCursor->Render();
	m_pNamco->Render();
	m_pDates->Render();
	m_pRights->Render();
	m_pLogo->Render();
	m_pPlayerOneScore->Render();
	m_pPlayerTwoScore->Render();
	m_pTopScore->Render();


	if (!mAnimationDone) {
		m_pLogo->Render();
	}
	else {
		m_pAnimatedLogo->Render();
	}
}


void StartScreen::ResetAnimation() {
	mAnimationStartPos = Vector2(0.0f, -Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
	Position(mAnimationStartPos);
	m_pCursor->Position(-175.0f, -35.0f);

	mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode - 0;
}

int StartScreen::SelectedMode() {
	return mSelectedMode;
}

