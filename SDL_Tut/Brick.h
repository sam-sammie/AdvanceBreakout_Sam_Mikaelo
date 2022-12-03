#ifndef _BRICKS_H
#define _BRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"

using namespace SDLFramework;

class Brick : public GameEntity
{

private:
	
	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	AnimatedTexture* m_pRedBreakAnimation;
	AnimatedTexture* m_pOrangeBreakAnimation;
	AnimatedTexture* m_pGreenBreakAnimation;
	AnimatedTexture* m_pYellowBreakAnimation;

	bool mVisible;
	bool mAnimating;

public:
	Brick();
	~Brick();
	
	void Visible(bool visible);
	bool IsAnimating();

	void RedBrickDestroyed();
	void OrangeBrickDestroyed();
	void GreenBrickDestroyed();
	void YellowBrickDestroyed();

	void Update(int keypress);
	void Render();

};

#endif // !_BRICKS_H