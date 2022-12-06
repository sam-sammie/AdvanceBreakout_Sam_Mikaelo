#include "Ball.h"

Ball::Ball() {
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudioManager = AudioManager::Instance();

	m_pBall = new Texture("Ball.png", 0, 0, 20, 20);
	m_pBall->Parent(this);
	m_pBall->Position(Vec2_Zero);
	
	mVisible = false;


	mMoveSpeed = 900.0f;

	DirectionY = 1;
	DirectionX = -1;

	AddCollider(new BoxCollider(Vector2(15.0f, 15.0f)), Vector2(-7.0f, -7.0f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);

	Velocity = 350;


};

Ball::~Ball() {
	m_pTimer = nullptr;
	m_pInput = nullptr;

	delete m_pBall;
	m_pBall = nullptr;

	
	m_pAudioManager = nullptr;
};




void Ball::Movement() {
	/*if (m_pInput->KeyDown(SDL_SCANCODE_D)) {
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
	}*/


	if (Position().y <=(Graphics::SCREEN_WIDTH * 0.1f) - m_pBall->ScaledDimensions().x * 0.5f) { // Position().y is grabbing the ball  y position
		DirectionY *= -1;
		m_pAudioManager->PlaySFX("SFX/SwitchSelect.wav", 0, 0);
	}


	if (Position().x >= Graphics::SCREEN_WIDTH - m_pBall->ScaledDimensions().x * 0.5f) {
		DirectionX *= -1;
		m_pAudioManager->PlaySFX("SFX/SwitchSelect.wav", 0, 0);
	}

	if (Position().x <=  m_pBall->ScaledDimensions().x * 0.5f) {
		DirectionX *= -1;
		m_pAudioManager->PlaySFX("SFX/SwitchSelect.wav", 0, 0);
	}

	if (Position().y >= (Graphics::SCREEN_WIDTH * 0.9f) - m_pBall->ScaledDimensions().x * 0.5f) { // Position().y is grabbing the ball  y position
		
	}

	

	
	/*if (pos.y < mMoveBounds.x + m_pBall->ScaledDimensions().y * 0.5f) {
		pos.y = mMoveBounds.x + m_pBall->ScaledDimensions().y * 0.5f;
	}*/
	/*else if (pos.y > mMoveBounds.y - m_pBall->ScaledDimensions().y * 0.5f) {
		pos.y = mMoveBounds.y - m_pBall->ScaledDimensions().y * 0.5f;
	}*/

	
	Translate(Vector2(Velocity * DirectionX, Velocity * DirectionY) * m_pTimer->DeltaTime(), World);

}

void Ball::Update() {
	m_pBall->Update();
	if (Active()) {
	
		Movement();

	}
	


}

void Ball::Render() {
	m_pBall->Render();
	PhysEntity::Render();
	if (mVisible) {
		
	}
}

void Ball::Visible(bool visible) {
	mVisible = visible;
}

void Ball::Hit(PhysEntity* other) { 
	if (Position().x <= other->Position().x ) {
		DirectionX *= -1;
		m_pAudioManager->PlaySFX("SFX/EnterSelect.wav", 0, 0);
	}
	else if (Position().x >= other->Position().x) {
		DirectionX *= -1;
		m_pAudioManager->PlaySFX("SFX/EnterSelect.wav", 0, 0);
	}

	if (Position().y <= other->Position().y) {
		DirectionY *= -1;
		m_pAudioManager->PlaySFX("SFX/EnterSelect.wav", 0, 0);
	}
	else if (Position().y >= other->Position().y) {
		DirectionY *= -1;
		m_pAudioManager->PlaySFX("SFX/EnterSelect.wav", 0, 0);
	}
}

bool Ball::IgnoreCollisions() {
	return !Active();
}

