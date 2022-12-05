#ifndef _BALL_H
#define _BALL_H
#include "Timer.h"
#include "InputManager.h"
#include "AnimatedTexture.h"
#include "Player.h"
#include "PhysEntity.h"

using namespace SDLFramework;
class Ball : public PhysEntity
{
private:
	Timer* m_pTimer;
	InputManager* m_pInput;

	float mMoveSpeed;
	Vector2 mMoveBounds;
	bool mVisible;

	Texture* m_pBall;

	void Movement();

public:
	Ball();
	~Ball();

	void Visible(bool visible);

	void Hit(PhysEntity* other) override;

	void Update() override;
	void Render() override;
	void Draw(SDL_Renderer* renderer);
};

#endif // !_BALL_H