#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();

	m_pSideBar = new PlaySideBar();
	m_pSideBar->Parent(this);
	m_pSideBar->Position(Graphics::SCREEN_WIDTH * 0.85f, Graphics::SCREEN_HEIGHT * 0.05f);

	//Bricks
	m_pRedBricks = new Texture("RedBrick.png");
	m_pRedBricks->Parent(this);
	m_pRedBricks->Scale(Vector2(2.0f, 2.0f));
	m_pRedBricks->Position(310.0f, 128.0f);

	m_pOrangeBricks = new Texture("OrangeBrick.png");
	m_pOrangeBricks->Parent(this);
	m_pOrangeBricks->Scale(Vector2(2.0f, 2.0f));
	m_pOrangeBricks->Position(310.0f, 193.0f);

	m_pGreenBricks = new Texture("GreenBrick.png");
	m_pGreenBricks->Parent(this);
	m_pGreenBricks->Scale(Vector2(2.0f, 2.0f));
	m_pGreenBricks->Position(310.0f, 258.0f);

	m_pYellowBricks = new Texture("YellowBrick.png");
	m_pYellowBricks->Parent(this);
	m_pYellowBricks->Scale(Vector2(2.0f, 2.0f));
	m_pYellowBricks->Position(310.0f, 323.0f);

	//Paddle Animation
	m_pPaddle = new Texture("Paddle.png", 0, 0, 360, 180);
	m_pPaddle->Parent(this);
	m_pPaddle->Position(495.0f, 755.f);

	m_pAnimatedPaddle = new AnimatedTexture("Paddle.png", 0, 0, 360, 180, 4, 0.5f, AnimatedTexture::Vertical);
	m_pAnimatedPaddle->Parent(this);
	m_pAnimatedPaddle->Position(495.0f, 755.f);

	// screen animation variables
	mAnimationStartPos = Vector2(1.0f, Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 0.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);

	ResetAnimation();
}

PlayScreen::~PlayScreen() {
	m_pTimer = nullptr;
	m_pAudio = nullptr;

	delete m_pSideBar;
	m_pSideBar = nullptr;

	delete m_pRedBricks;
	m_pRedBricks = nullptr;

	delete m_pOrangeBricks;
	m_pOrangeBricks = nullptr;

	delete m_pGreenBricks;
	m_pGreenBricks = nullptr;

	delete m_pYellowBricks;
	m_pYellowBricks = nullptr;

	delete m_pPaddle;
	m_pPaddle = nullptr;

	delete m_pAnimatedPaddle;
	m_pAnimatedPaddle = nullptr;
}

void PlayScreen::Render() {

	m_pSideBar->Render();
	m_pRedBricks->Render();
	m_pOrangeBricks->Render();
	m_pGreenBricks->Render();
	m_pYellowBricks->Render();

	if (!mAnimationDone) {
		m_pPaddle->Render();
	}
	else {
		m_pAnimatedPaddle->Render();
	}

}

void PlayScreen::Update() {
	
	if (!mAnimationDone) {
		mAnimationTimer += m_pTimer->DeltaTime();
		Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
		}
	}
	else {
		m_pAnimatedPaddle->Update();
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