#include "StartScreen.h"

StartScreen::StartScreen() {
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();

	m_pBackdrop = new Texture("Backdrop.png");
	m_pBackdrop->Position(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.50f);

	// Top bar entities
	m_pTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	m_pPlayerOne = new Texture("1UP", "ARCADEPI.ttf", 32, { 200,0,0 });
	m_pPlayerTwo = new Texture("2UP", "ARCADEPI.ttf", 32, { 200,0,0 });
	m_pHiScore = new Texture("HI SCORE", "ARCADEPI.ttf", 32, { 200,0,0 });
	m_pPlayerOneScore = new Scoreboard;
	m_pPlayerTwoScore = new Scoreboard;
	m_pTopScore = new Scoreboard;

	// Play mode entites
	m_pPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * .55f);
	m_pOnePlayerMode = new Texture("1 PLAYER ", "ARCADEPI.ttf", 32, { 230,230,230 });
	m_pTwoPlayerMode = new Texture("2 PLAYERS ", "ARCADEPI.ttf", 32, { 230,230,230 });
	m_pCursor = new Texture("Cursor.png");
	
	//Bottom Bar Entites
	m_pBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);
	m_pNamco = new Texture("atari", "namco__.ttf", 36, { 200,0,0 });
	m_pDates = new Texture("1976 ATARI LTD.", "ARCADEPI.ttf", 32, { 230,230,230 });
	m_pRights = new Texture("ALL RIGHTS RESERVED", "ARCADEPI.ttf", 32, {230, 230, 230});

	//Logo Entities
	m_pLogo = new Texture("Test12.png", 0, 0, 360, 180);
	//m_pLogo->Parent(this);
	m_pLogo->Position(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.32f);

	m_pAnimatedLogo = new AnimatedTexture("Test11.png", 0, 0, 360, 180, 3, 1.5f, AnimatedTexture::Vertical);
	//m_pAnimatedLogo->Parent(this);
	m_pAnimatedLogo->Position(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.32f);

	// Top bar entities
	//m_pTopBar->Parent(this);
	m_pPlayerOne->Parent(m_pTopBar);
	m_pPlayerTwo->Parent(m_pTopBar);
	m_pHiScore->Parent(m_pTopBar);
	m_pPlayerOneScore->Parent(m_pTopBar);
	m_pPlayerTwoScore->Parent(m_pTopBar);
	m_pTopScore->Parent(m_pTopBar);

	// Play mode entities
	//m_pPlayModes->Parent(this);
	m_pOnePlayerMode->Parent(m_pPlayModes);
	m_pTwoPlayerMode->Parent(m_pPlayModes);
	m_pCursor->Parent(m_pOnePlayerMode);

	m_pPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);
	m_pPlayerTwo->Position(Graphics::SCREEN_WIDTH * 0.35F, 0.0F);
	m_pHiScore->Position(-30.0f, 0.0f);
	m_pPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * 0.35f, 40.0f);
	m_pPlayerTwoScore->Position(Graphics::SCREEN_WIDTH * 0.35f, 40.0f);
	m_pTopScore->Position(Graphics::SCREEN_WIDTH * 0.05f, 40.0f);
	m_pTopScore->Score(645987);

	//Play mode entites
	m_pOnePlayerMode->Position(-200.0f, 35.0f);
	m_pTwoPlayerMode->Position(200.0f, 35.0f);
	m_pCursor->Position(175.0f, -35.0f);

	m_pLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, -100.0f);
	mTitleAnimationStartPos[5] = m_pLogo->Position(Local);
	mTitleAnimationEndPos[5] = Vector2(m_pLogo->Position().x, Graphics::SCREEN_HEIGHT * 0.32f);

	m_pTopBar->Position(Graphics::SCREEN_WIDTH * 0.5f, -100.0f);
	mTitleAnimationStartPos[4] = m_pTopBar->Position(Local);
	mTitleAnimationEndPos[4] = Vector2(m_pTopBar->Position().x, 70.0f);

	m_pPlayModes->Position(Graphics::SCREEN_WIDTH * 0.5f, -50.0f);
	mTitleAnimationStartPos[3] = m_pPlayModes->Position(Local);
	mTitleAnimationEndPos[3] = Vector2(m_pPlayModes->Position().x, 550.0f);

	m_pNamco->Position(Graphics::SCREEN_WIDTH * 0.5f, -50.0f);
	mTitleAnimationStartPos[2] = m_pNamco->Position(Local);
	mTitleAnimationEndPos[2] = Vector2(m_pNamco->Position().x, 700.0f);

	m_pDates->Position(Graphics::SCREEN_WIDTH * 0.5f, -50.0f);
	mTitleAnimationStartPos[1] = m_pDates->Position(Local);
	mTitleAnimationEndPos[1] = Vector2(m_pDates->Position().x, 750.0f);

	m_pRights->Position(Graphics::SCREEN_WIDTH * 0.5f, -50.0f);
	mTitleAnimationStartPos[0] = m_pRights->Position(Local);
	mTitleAnimationEndPos[0] = Vector2(m_pRights->Position().x, 800.0f);
	mTitleText[0] = m_pRights;
	mTitleText[1] = m_pDates;
	mTitleText[2] = m_pNamco;
	mTitleText[3] = m_pPlayModes;
	mTitleText[4] = m_pTopBar;
	mTitleText[5] = m_pLogo;

	// screen animation variables
	mAnimationStartPos = Vector2(1.0f, Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 1.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);

	mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 600.0f);
	mSelectedMode = 0; // 0 for single player and 1 for 2 players

	ResetAnimation();
	//ScreenShake();

	m_pAudioManager = AudioManager::Instance();
	for (int i = 0; i < 6; i++) {
		mTitleAnimation[i] = false;

	}
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

	delete m_pBackdrop;
	m_pBackdrop = nullptr;


	AudioManager::Release();
	m_pAudioManager = nullptr;
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
		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				if (!mTitleAnimation[i]) {
					mAnimationTimer += m_pTimer->DeltaTime();
					mTitleText[i]->Position(Lerp(mTitleAnimationStartPos[i], mTitleAnimationEndPos[i], mAnimationTimer / mAnimationTotalTime));

					if (mAnimationTimer >= mAnimationTotalTime) {
						mTitleAnimation[i] = true;
						mAnimationTimer = 0.0f;

					}
				}

			}
			else {
				if (mTitleAnimation[i - 1]) {
					if (!mTitleAnimation[i]) {
						mAnimationTimer += m_pTimer->DeltaTime();
						mTitleText[i]->Position(Lerp(mTitleAnimationStartPos[i], mTitleAnimationEndPos[i], mAnimationTimer / mAnimationTotalTime));

						if (mAnimationTimer >= mAnimationTotalTime) {
							mTitleAnimation[i] = true;
							mAnimationTimer = 0.0f;

						}
					}
				}
			}

		}
		if (mTitleAnimation[5]) {
			
		mAnimationDone = true;
			
		}
		if (m_pInputManager->KeyPressed(SDL_SCANCODE_DOWN) || m_pInputManager->KeyPressed(SDL_SCANCODE_UP)) {
			mAnimationTimer = mAnimationTotalTime;
			
		}
	}

	else {
		
		m_pAnimatedLogo->Update();
		if (m_pInputManager->KeyPressed(SDL_SCANCODE_RIGHT)) {
			ChangeSelectedMode(1);
			m_pAudioManager->PlaySFX("SFX/SwitchSelect.wav", 0, 0);
		}
		else if (m_pInputManager->KeyPressed(SDL_SCANCODE_LEFT)) {
			ChangeSelectedMode(-1);
			m_pAudioManager->PlaySFX("SFX/SwitchSelect.wav", 0, 0);
		}
		else if (m_pInputManager->KeyPressed(SDL_SCANCODE_RETURN)) {
			m_pAudioManager->PlaySFX("SFX/EnterSelect.wav", 0, 0);
		}
	}
	
	//if (!mAnimationDone) {
	//	mAnimationTimer += m_pTimer->DeltaTime();
	//	Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

	//	//if (mAnimationTimer >= mAnimationTotalTime) {
	//	//	mAnimationDone = true;
	//	//	m_pStars->Scroll(false);
	//	//}
	//	
	//}

	
}

void StartScreen::Render() {

	m_pBackdrop->Render();
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
	m_pLogo->Render();



	if (!mAnimationDone) {
		
		//m_pLogo->Render();
	}
	else {
		m_pAnimatedLogo->Render();

	}
}


void StartScreen::ResetAnimation() {
	mAnimationStartPos = Vector2(0.0f, -Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = .5f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
	Position(mAnimationStartPos);
	m_pCursor->Position(-175.0f, 0.0f);

	mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(400.0f, 0.0f);
	mSelectedMode - 0;
}

int StartScreen::SelectedMode() {
	return mSelectedMode;
}

