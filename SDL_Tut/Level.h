#ifndef _LEVEL_H
#define _LEVEL_H
#include "PlaySideBar.h"
#include "Player.h"
#include "Ball.h"
#include "Red Brick.h"
#include "Texture.h"

class Level : public GameEntity
{
public:
	enum LevelStates { Running, Finished, GameOver };
private:
	Timer* m_pTimer;
	PlaySideBar* m_pSideBar;

	int mStage;
	bool mStageStarted;

	Player* m_pPlayer;
	Ball* m_pBall;
	

	void StartStage();

	/*bool RedBrickDestroyed();
	bool OrangeBrickDestroyed();
	bool GreenBrickDestroyed();
	bool YellowBrickDestroyed();*/

	
	float mRespawnDelay;
	float mRespawnTimer;
	float mRespawnLabelOnScreen;

	Texture* m_pGameOverLabel;
	float mGameOverDelay;
	float mGameOverTimer;
	float mGameOverLabelOnScreen;

	LevelStates mCurrentState;

	void HandleBrickBreak();
	void HandleStartLabels();
	void HandleCollisions();
	void HandlePlayerDeath();

public:
	Level(int stage, PlaySideBar* sidebar, Player* player, Ball* ball);
	~Level();

	LevelStates State();
	bool mBallFell;

	void Update() override;
	void Render() override;

protected:
	
};

#endif // !_Level_h

