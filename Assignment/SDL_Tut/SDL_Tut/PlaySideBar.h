#ifndef _PLAYSIDEBAR_H
#define _PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"
class PlaySideBar : public GameEntity
{
private:
	static const int MAX_BRICKS_TEXTURES = 9;

private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;

	Texture* m_pBackground;
	Texture* m_pScoreLabel;
	Texture* m_pLivesLabel;
	Scoreboard* m_pHighScoreboard;

	Texture* m_pRightWall;
	Texture* m_pLeftWall;
	Texture* m_pTopWall;

	Texture* m_pRedBricks;
	Texture* m_pOrangeBricks;
	Texture* m_pGreenBricks;
	Texture* m_pYellowBricks;


	
public:
	PlaySideBar();
	~PlaySideBar();

	void Update();
	void Render();

};

#endif // !