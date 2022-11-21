#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AudioManager.h"
#include "BackGroundStars.h"
#include "PlaySideBar.h"
#include "AnimatedTexture.h"
#include "InputManager.h"


class PlayScreen : public GameEntity
{
private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	PlaySideBar* m_pSideBar;
	
	//Bricks
	Texture* m_pRedBricks;
	Texture* m_pOrangeBricks;
	Texture* m_pGreenBricks;
	Texture* m_pYellowBricks;

	//Paddle Animation + Movement
	Texture* m_pPaddle;
	Texture* m_pAnimatedPaddle;

	//Animation Varibles
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

public:
	PlayScreen();
	~PlayScreen();

	void ResetAnimation();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H