#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
#include "AudioManager.h"
#include "BackGroundStars.h"


class PlayScreen : public GameEntity
{
private:
	Timer* m_pTimer;
	AudioManager* m_pAudio;
	BackgroundStars* m_pStars;

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};

#endif // !_PLAYSCREEN_H