#ifndef _ORANGEBRICK_H
#define _ORANGEBRICK_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"

using namespace SDLFramework;

class OrangeBrick : public PhysEntity
{
private:

	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	AnimatedTexture* m_pOrangeBreakAnimation;

	bool mVisible;
	bool mAnimating;



protected:
	bool IgnoreCollisions() override;

public:
	OrangeBrick();
	~OrangeBrick();

	void Hit(PhysEntity* other);

	void Visible(bool visible);
	bool IsAnimating();
	bool InDeathAnimation();


	void Update();
	void Render();

};

#endif // !_ORANGEBRICK_H
