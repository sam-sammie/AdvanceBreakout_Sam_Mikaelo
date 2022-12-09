#ifndef _GREENBRICK_H
#define _GREENBRICK_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"

using namespace SDLFramework;

class GreenBrick : public PhysEntity
{
private:

	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	AnimatedTexture* m_pGreenBreakAnimation;

	bool mVisible;
	bool mAnimating;

protected:
	bool IgnoreCollisions() override;

public:
	GreenBrick();
	~GreenBrick();

	void Hit(PhysEntity* other);

	void Visible(bool visible);
	bool IsAnimating();
	bool InDeathAnimation();


	void Update();
	void Render();

};

#endif // !_GREENBRICK_H
