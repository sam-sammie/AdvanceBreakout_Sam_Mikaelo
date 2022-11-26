#ifndef _PLAYSIDEBAR_H
#define _PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"

class PlaySideBar : public GameEntity
{

private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;

	Texture* m_pBackground;
	Texture* m_pScoreLabel;
	Texture* m_pLivesLabel;

	Scoreboard* m_pPlayerScoreboard;
	Scoreboard* m_pLives;

	Texture* m_pRightWall;
	Texture* m_pLeftWall;
	Texture* m_pTopWall;

	int mLevel;

	Scoreboard* m_PlayerOneScore;

public:
	PlaySideBar();
	~PlaySideBar();

	void SetPlayerScore(int score);
	void SetPlayerLives(int lives);
	void SetLevel(int level);

	void Update() override;
	void Render() override;

	void AddScore2(int score);
};

#endif // !_PLAYSIDEBAR_H
