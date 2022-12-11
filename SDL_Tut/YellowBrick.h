#ifndef _YELLOWBRICKS_H
#define _YELLOWBRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Player.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "PlaySideBar.h"

using namespace SDLFramework;

class YellowBrick : public PhysEntity
{

private:

	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	PlaySideBar* m_pSideBar;
	Player* m_pPlayer;

	AnimatedTexture* m_pYellowBreakAnimation;

	bool mVisible;
	bool mAnimating;



protected:
	bool IgnoreCollisions() override;

public:
	YellowBrick(Player* inputPlayer, PlaySideBar* inputSideBar);
	~YellowBrick();

	void Hit(PhysEntity* other);

	void Visible(bool visible);
	bool IsAnimating();
	bool InDeathAnimation();


	void Update();
	void Render();


};

#endif // !_BRICKS_H
