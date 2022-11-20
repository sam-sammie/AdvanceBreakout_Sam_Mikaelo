#ifndef _PLAYSIDEBAR_H
#define _PLAYSIDEBAR_H
#include "Timer.h"
#include "Scoreboard.h"
#include "AudioManager.h"


#include "GameEntity.h"
class PlaySideBar : public GameEntity
{
private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	Texture* m_pBackground;

	Texture* m_pHighLabel;
	Texture* m_pScoreLabel;
	Scoreboard* m_pHighScoreboard;

	Texture* m_pPlayerOneLabel;
	float mBlinkTimer;
	float mBlinkInterval;
	bool mPlayerOneLabelVisible;
	Scoreboard* m_pPlayerOneScore;

public:
	PlaySideBar();
	~PlaySideBar();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSIDEBAR_H