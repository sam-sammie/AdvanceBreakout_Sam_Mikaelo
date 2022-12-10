#ifndef _REDBRICKS_H
#define _REDBRICKS_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "PhysEntity.h"
#include "PhysicsManager.h"

namespace SDLFramework 
{
	class RedBrick : public PhysEntity
	{

	private:

		Timer* m_pTimer;
		InputManager* m_pInput;
		AudioManager* m_pAudio;

		AnimatedTexture* m_pRedBreakAnimation;

		bool mVisible;
		bool mAnimating;

	protected:
		bool IgnoreCollisions() override;

	public:
		RedBrick();
		~RedBrick();

		void Hit(PhysEntity* other) override;

		int Score();

		void Visible(bool visible);
		bool IsAnimating();


		void Update();
		void Render();

	};
}



#endif // !_BRICKS_H