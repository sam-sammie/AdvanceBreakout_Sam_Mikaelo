#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AudioManager.h"
#include "PlaySideBar.h"
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Red Brick.h"
#include "YellowBrick.h"
#include "Ball.h"
#include "StartScreen.h"
#include "PhysEntity.h"
#include "OrangeBrick.h"
#include "GreenBrick.h"

class PlayScreen : public PhysEntity
{
private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	PlaySideBar* m_pSideBar;

	RedBrick* m_pBrickRow_1;
	RedBrick* m_pBrickRow_2;
	RedBrick* m_pBrickRow_3;
	RedBrick* m_pBrickRow_4;
	RedBrick* m_pBrickRow_5;
	RedBrick* m_pBrickRow_6;
	RedBrick* m_pBrickRow_7;
	RedBrick* m_pBrickRow_8;
	RedBrick* m_pBrickRow_9;
	RedBrick* Redbrick[9];

	YellowBrick* m_pYellow_1;
	YellowBrick* m_pYellow_2;
	YellowBrick* m_pYellow_3;
	YellowBrick* m_pYellow_4;
	YellowBrick* m_pYellow_5;
	YellowBrick* m_pYellow_6;
	YellowBrick* m_pYellow_7;
	YellowBrick* m_pYellow_8;
	YellowBrick* m_pYellow_9;
	YellowBrick* Yellowbrick[9];


	OrangeBrick* m_pOrange_1;
	OrangeBrick* m_pOrange_2;
	OrangeBrick* m_pOrange_3;
	OrangeBrick* m_pOrange_4;
	OrangeBrick* m_pOrange_5;
	OrangeBrick* m_pOrange_6;
	OrangeBrick* m_pOrange_7;
	OrangeBrick* m_pOrange_8;
	OrangeBrick* m_pOrange_9;
	OrangeBrick* Orangebrick[9];


	GreenBrick* m_pGreen_1;
	GreenBrick* m_pGreen_2;
	GreenBrick* m_pGreen_3;
	GreenBrick* m_pGreen_4;
	GreenBrick* m_pGreen_5;
	GreenBrick* m_pGreen_6;
	GreenBrick* m_pGreen_7;
	GreenBrick* m_pGreen_8;
	GreenBrick* m_pGreen_9;
	GreenBrick* Greenbrick[9];
	
	//Animation Varibles
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	bool mGameStarted;

	Player* m_pPlayer;
	Ball* m_pBall;

	Level* m_pLevel;
	bool mLevelStarted;
	int mCurrentStage;

public:
	PlayScreen();
	~PlayScreen();

	void ResetAnimation();
	void StartNewGame();
	void StartNextLevel();

	bool GameOver();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H