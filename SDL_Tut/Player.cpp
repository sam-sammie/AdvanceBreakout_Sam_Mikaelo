#include "Player.h"

Player::Player() {
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;

	mScore = 0;
	mLives = 3;

	m_pPaddle = new AnimatedTexture("Paddle.png", 0, 0, 360, 180, 4, 0.5f, AnimatedTexture::Vertical);
	m_pPaddle->Parent(this);
	m_pPaddle->Position(Vec2_Zero);

	mMoveSpeed = 100.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);

	m_pDeathAnimation = new AnimatedTexture("PlayerExplosion.png", 0, 0, 128, 128, 4, 1.0f, AnimatedTexture::Horizontal);
	m_pDeathAnimation->Parent(this);
	m_pDeathAnimation->Position(Vec2_Zero);
	m_pDeathAnimation->SetWrapMode(AnimatedTexture::Once);
}

Player::~Player() {
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pDeathAnimation;
	m_pDeathAnimation = nullptr;

	delete m_pPaddle;
	m_pPaddle = nullptr;

}

void Player::Visible(bool visible) {
	mVisible = visible;
}

bool Player::IsAnimating() {
	return mAnimating;
}

int Player::Lives() {
	return mLives;
}

void Player::AddScore(int change) {
	mScore += change;
}

int Player::Score() {
	return mScore;
}

void Player::WasHit() {
	mLives -= 1;
	mAnimating = true;
	m_pDeathAnimation->ResetAnimation();
	m_pAudio->PlaySFX("SFX/Oof.wav", 0, -1);
}

void Player::HandleMovement() {
	if (m_pInput->KeyDown(SDL_SCANCODE_RIGHT)) {
		Translate(Vec2_Right * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}
	else if (m_pInput->KeyDown(SDL_SCANCODE_LEFT)) {
		Translate(-Vec2_Right * mMoveSpeed * m_pTimer->DeltaTime(), World);
	}

	Vector2 pos = Position(Local);
	if (pos.x < mMoveBounds.x + m_pPaddle->ScaledDimensions().x * 0.5f) {
		pos.x = mMoveBounds.x + m_pPaddle->ScaledDimensions().x * 0.5f;
	}
	else if (pos.x > mMoveBounds.y - m_pPaddle->ScaledDimensions().x * 0.5f) {
		pos.x = mMoveBounds.y - m_pPaddle->ScaledDimensions().x * 0.5f;
	}
	Position(pos);
}

void Player::Update() {
	m_pPaddle->Update();
	if (mAnimating) {
		m_pDeathAnimation->Update();
		mAnimating = m_pDeathAnimation->IsAnimating();
	}
	else {
		if (Active()) {
			HandleMovement();

		}
	}
}

void Player::Render() {
	if (mVisible) {
		if (mAnimating) {
			m_pDeathAnimation->Render();

		}
		else {
			m_pPaddle->Render();
		}
	}
}

void Player::RedBrickDestroyed() {
	mScore += 400;
	m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, -1);
}

void Player::OrangeBrickDestroyed() {
	mScore += 300;
	m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, -1);
}

void Player::GreenBrickDestroyed() {
	mScore += 200;
	m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, -1);
}

void Player::YellowBrickDestroyed() {
	mScore += 100;
	m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, -1);
}