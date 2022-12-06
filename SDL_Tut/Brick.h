#ifndef _BRICKS_H
#define _BRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"

using namespace SDLFramework;

class Brick : public PhysEntity
{

private:
	
	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;
	
	Texture* m_pOrangeBrickTexture;
	Texture* m_pGreenBrickTexture;
	Texture* m_pRedBrickTexture;
	Texture* m_pYellowBrickTexture;


	AnimatedTexture* m_pRedBreakAnimation;
	AnimatedTexture* m_pOrangeBreakAnimation;
	AnimatedTexture* m_pGreenBreakAnimation;
	AnimatedTexture* m_pYellowBreakAnimation;

	bool mVisible;
	bool mAnimating;

protected:
	bool IgnoreCollisions() override;

public:
	Brick();
	~Brick();
	
	void WasHit();

	void Visible(bool visible);
	bool IsAnimating();
	bool InDeathAnimation();


	void Update();
	void Render();

};

#endif // !_BRICKS_H