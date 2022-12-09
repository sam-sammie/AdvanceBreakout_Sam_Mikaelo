#ifndef _BRICKS_H
#define _BRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "YellowBrick.h"

using namespace SDLFramework;

class RedBrick : public PhysEntity
{

private:
	
	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	AnimatedTexture* m_pRedBreakAnimation;
	//AnimatedTexture* m_pOrangeBreakAnimation;
	//AnimatedTexture* m_pGreenBreakAnimation;

	bool mVisible;
	bool mAnimating;

protected:
	bool IgnoreCollisions() override;

public:
	RedBrick();
	~RedBrick();
	
	void Hit(PhysEntity* other);

	void Visible(bool visible);
	bool IsAnimating();
	bool InDeathAnimation();


	void Update();
	void Render();

};

#endif // !_BRICKS_H