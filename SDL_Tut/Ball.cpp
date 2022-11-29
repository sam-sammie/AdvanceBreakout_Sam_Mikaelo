#include "Ball.h"

Ball::Ball() {
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();

	m_pBall = new Texture("Ball.png", 0, 0, 20, 20);
	m_pBall->Parent(this);
	m_pBall->Position(Vec2_Zero);

	mVisible = false;

	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);
};

Ball::~Ball() {
	m_pTimer = nullptr;
	m_pInput = nullptr;

	delete m_pBall;
	m_pBall = nullptr;
};

void Ball::Movement() {
	if (m_pInput->KeyDown(SDL_SCANCODE_D)) {
		Translate(Vec2_Right * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}
	else if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
		Translate(-Vec2_Right * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}
	else if (m_pInput->KeyDown(SDL_SCANCODE_W)) {
		Translate(-Vec2_Up * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}
	else if (m_pInput->KeyDown(SDL_SCANCODE_S)) {
		Translate(Vec2_Up * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}


	Vector2 pos = Position(Local);
	if (pos.x < mMoveBounds.x + m_pBall->ScaledDimensions().x * 0.5f) {
		pos.x = mMoveBounds.x + m_pBall->ScaledDimensions().x * 0.5f;
	}
	else if (pos.x > mMoveBounds.y - m_pBall->ScaledDimensions().x * 0.5f) {
		pos.x = mMoveBounds.y - m_pBall->ScaledDimensions().x * 0.5f;
	}

	Position(pos);
}

void Ball::Update() {
	m_pBall->Update();
	if (Active()) {
	
		Movement();
	}
	


}

void Ball::Render() {
	m_pBall->Render();
	if (mVisible) {
		
	}
}

void Ball::Visible(bool visible) {
	mVisible = visible;
}