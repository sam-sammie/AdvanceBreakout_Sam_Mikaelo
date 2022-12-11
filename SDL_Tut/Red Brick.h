#ifndef _REDBRICKS_H
#define _REDBRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Player.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "PlaySideBar.h"

namespace SDLFramework 
{
	class RedBrick : public PhysEntity
	{

	private:

		Timer* m_pTimer;
		InputManager* m_pInput;
		AudioManager* m_pAudio;
		

		AnimatedTexture* m_pRedBreakAnimation;

		PlaySideBar* m_pSideBar;
		Player* m_pPlayer;

		bool mVisible;
		bool mAnimating;

	protected:
		bool IgnoreCollisions() override;

	public:
		RedBrick(Player* inputPlayer, PlaySideBar* inputSideBar);
		~RedBrick();

		void Hit(PhysEntity* other) override;

		void Visible(bool visible);
		bool IsAnimating();


		void Update();
		void Render();

	};
}



#endif // !_BRICKS_H