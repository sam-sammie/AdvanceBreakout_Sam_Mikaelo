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
	
	Scoreboard* m_pHighScoreboard;
	Scoreboard* m_pLives;

	Texture* m_pRightWall;
	Texture* m_pLeftWall;
	Texture* m_pTopWall;


public:
	PlaySideBar();
	~PlaySideBar();

	void Update();
	void Render();

};

#endif // !