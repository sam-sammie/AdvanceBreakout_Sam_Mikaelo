#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AudioManager.h"
#include "BackGroundStars.h"
#include "PlaySideBar.h"
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Brick.h"
#include "Ball.h"
#include "StartScreen.h"
#include "PhysEntity.h"
class PlayScreen : public PhysEntity
{
private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	PlaySideBar* m_pSideBar;

	Brick* m_pBrickRow_1;
	Brick* m_pBrickRow_2;
	Brick* m_pBrickRow_3;
	Brick* m_pBrickRow_4;
	Brick* m_pBrickRow_5;
	Brick* m_pBrickRow_6;
	Brick* m_pBrickRow_7;
	Brick* m_pBrickRow_8;
	Brick* m_pBrickRow_9;

	//Arrays
	Brick* Redbrick[9];
	Brick* Orangebrick[9];
	Brick* Greenbrick[9];
	Brick* Yellowbrick[9];

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