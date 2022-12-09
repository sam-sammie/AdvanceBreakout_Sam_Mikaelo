#ifndef _YELLOWBRICKS_H
#define _YELLOWBRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"

using namespace SDLFramework;

class YellowBrick : public PhysEntity
{

private:

	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	AnimatedTexture* m_pYellowBreakAnimation;

	bool mVisible;
	bool mAnimating;



protected:
	bool IgnoreCollisions() override;

public:
	YellowBrick();
	~YellowBrick();

	void Hit(PhysEntity* other);

	void Visible(bool visible);
	bool IsAnimating();
	bool InDeathAnimation();


	void Update();
	void Render();


};

#endif // !_BRICKS_H
