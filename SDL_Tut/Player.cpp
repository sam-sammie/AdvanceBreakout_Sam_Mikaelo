#include "Player.h"

//Ball* Player::m_pBall = nullptr;
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

	mMoveSpeed = 600.0f;
	mMoveBounds = Vector2(-100.0f, 1150.0f);

	m_pDeathAnimation = new AnimatedTexture("PlayerExplosion.png", 0, 0, 128, 128, 4, 1.0f, AnimatedTexture::Horizontal);
	m_pDeathAnimation->Parent(this);
	m_pDeathAnimation->Position(Vec2_Zero);
	m_pDeathAnimation->SetWrapMode(AnimatedTexture::Once);


	AddCollider(new BoxCollider(Vector2(100.0f, 10.0f)), Vector2(-30.0f, 60.0f));


	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);

	
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

//bool Player::IgnoreCollisions() {
//	return !mVisible || mAnimating;
//}

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

void Player::SetScore(int score) {
	mScore = score;
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
	PhysEntity::Render();
}

void Player::RedBrickDestroyed() {
	mScore += 400;
}

void Player::OrangeBrickDestroyed() {
	mScore += 300;
}

void Player::GreenBrickDestroyed() {
	mScore += 200;
}

void Player::YellowBrickDestroyed() {
	mScore += 100;
}

void Player::Hit(PhysEntity* other) {
	//Player::Hit(other);
}