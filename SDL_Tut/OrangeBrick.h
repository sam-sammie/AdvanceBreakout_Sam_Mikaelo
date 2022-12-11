#ifndef _ORANGEBRICK_H
#define _ORANGEBRICK_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "Player.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"
#include "PlaySideBar.h"

namespace SDLFramework {
	
	class OrangeBrick : public PhysEntity
	{
	private:

		Timer* m_pTimer;
		InputManager* m_pInput;
		AudioManager* m_pAudio;

		PlaySideBar* m_pSideBar;
		Player* m_pPlayer;

		AnimatedTexture* m_pOrangeBreakAnimation;

		bool mVisible;
		bool mAnimating;



	protected:
		bool IgnoreCollisions() override;

	public:
		OrangeBrick(Player* inputPlayer, PlaySideBar* inputSideBar);
		~OrangeBrick();

		void Hit(PhysEntity* other);

		void Visible(bool visible);
		bool IsAnimating();
		bool InDeathAnimation();


		void Update();
		void Render();

	};
}



#endif // !_ORANGEBRICK_H
