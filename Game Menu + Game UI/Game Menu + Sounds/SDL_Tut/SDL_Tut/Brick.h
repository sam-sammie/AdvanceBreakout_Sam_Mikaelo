#ifndef _BRICKS_H
#define _BRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"

using namespace SDLFramework;

class Brick : public GameEntity
{
private:
	Timer* m_pTimer;
	InputManager* m_pInput;

	Texture* m_pColorBrick;
	AnimatedTexture* m_pBreakAnimation;

public:
	Brick();
	~Brick();

	void Update() override;
	void Render() override;
};

#endif // !_BRICKS_H