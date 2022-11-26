#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "BackGroundStars.h"
#include "AudioManager.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {
private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;
	AudioManager* m_pAudioManager;
	// Top Bar Entities
	GameEntity* m_pTopBar;
	Texture* m_pPlayerOne;
	Texture* m_pPlayerTwo;
	Texture* m_pHiScore;
	Scoreboard* m_pPlayerOneScore;
	Scoreboard* m_pPlayerTwoScore;
	Scoreboard* m_pTopScore;

	// Play Mode Entites
	GameEntity* m_pPlayModes;
	Texture* m_pOnePlayerMode;
	Texture* m_pTwoPlayerMode;
	Texture* m_pCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	//Bottom Baar Entities
	GameEntity* m_pBottomBar;
	Texture* m_pNamco;
	Texture* m_pDates;
	Texture* m_pRights;

	// Logo Entities
	Texture* m_pLogo;
	Texture* m_pAnimatedLogo;

	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	BackgroundStars* m_pStars;

	bool mTitleAnimation[7];

	Vector2 mTitleAnimationStartPos[7];
	Vector2 mTitleAnimationEndPos[7];
	GameEntity* mTitleText[7];

public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	void ResetAnimation();
	int SelectedMode();
	//void ScreenShake();

	void Update() override;
	void Render() override;

};

#endif // !_STARTSCREEN_H

