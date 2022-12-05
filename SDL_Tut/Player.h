#ifndef _PLAYER_H
#define _PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
//#include "Ball.h"


using namespace SDLFramework;
class Player : public PhysEntity
{
protected:
	 //static Ball* m_pBall;
private:
	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	bool mVisible;
	bool mAnimating;

	int mScore;
	int mLives;

	AnimatedTexture* m_pPaddle;
	AnimatedTexture* m_pDeathAnimation;
	Texture* m_pTexture;

	float mMoveSpeed;
	Vector2 mMoveBounds;

	void HandleMovement();

public:
	Player();
	~Player();

	void Visible(bool visible);
	bool IsAnimating();

	int Score();
	int Lives();

	void AddScore(int change);

	void WasHit();

	void RedBrickDestroyed();
	void OrangeBrickDestroyed();
	void GreenBrickDestroyed();
	void YellowBrickDestroyed();

	void Update() override;
	void Render() override;

	//bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;
};

#endif // !_PLAYER_H

