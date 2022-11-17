#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {
private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;

	GameEntity* m_pTopBar;
	Texture* m_pPlayerOne;
	Texture* m_pPlayerTwo;
	Texture* m_pHiScore;

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
public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;

};

#endif // !_STARTSCREEN_H

