#ifndef _SCOREBOARD_H
#define _SCOREBOARD_H
#include "Texture.h"
#include <vector>

using namespace SDLFramework;

class Scoreboard: public GameEntity
{
private:
	std::vector<Texture*> m_pScore;
	SDL_Color mColor;

public:
	Scoreboard();
	Scoreboard(SDL_Color color);
	~Scoreboard();

	void Score(int score);
	void Lives(int lives);
	void Render();

private:
	void ClearBoard();
};

#endif // !_SCOREBOARD_H