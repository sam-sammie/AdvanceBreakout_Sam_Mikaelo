#ifndef _BALL_H
#define _BALL_H
#include "Timer.h"
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "PhysEntity.h" 
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"
#include "Player.h"
#include "AudioManager.h"



using namespace SDLFramework;
class Ball : public PhysEntity
{
protected:

private:
	Timer* m_pTimer;
	InputManager* m_pInput;

	float mMoveSpeed;
	Vector2 mMoveBounds;
	bool mVisible;

	Texture* m_pBall;
	Player* m_pPlayer;
	AudioManager* m_pAudioManager;
	

	void Movement();

	int Velocity;


	int DirectionX;
	int DirectionY;

public:
	Ball();
	~Ball();

	void Visible(bool visible);

	void Update() override;
	void Render() override;

	bool IgnoreCollisions() override;
	void Hit(PhysEntity* other) override;

};

#endif // !_BALL_H