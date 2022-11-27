#ifndef _LEVEL_H
#define _LEVEL_H
#include "PlaySideBar.h"
#include "Player.h"
#include "Brick.h"

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

	void StartStage();

	/*bool RedBrickDestroyed();
	bool OrangeBrickDestroyed();
	bool GreenBrickDestroyed();
	bool YellowBrickDestroyed();*/

	bool mBallFell;
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
	Level(int stage, PlaySideBar* sidebar, Player* player);
	~Level();

	LevelStates State();

	void Update() override;
	void Render() override;
};

#endif // !_Level_h
