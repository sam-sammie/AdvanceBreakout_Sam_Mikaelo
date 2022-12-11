#ifndef _GREENBRICK_H
#define _GREENBRICK_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Player.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "PlaySideBar.h"

namespace SDLFramework 
{
	class GreenBrick : public PhysEntity
	{
	private:

		Timer* m_pTimer;
		InputManager* m_pInput;
		AudioManager* m_pAudio;


		PlaySideBar* m_pSideBar;
		Player* m_pPlayer;

		AnimatedTexture* m_pGreenBreakAnimation;

		bool mVisible;
		bool mAnimating;

	protected:
		bool IgnoreCollisions() override;

	public:
		GreenBrick(Player* inputPlayer, PlaySideBar* inputSideBar);
		~GreenBrick();

		void Hit(PhysEntity* other);

		void Visible(bool visible);
		bool IsAnimating();
		bool InDeathAnimation();


		void Update();
		void Render();

	};

}


#endif // !_GREENBRICK_H
