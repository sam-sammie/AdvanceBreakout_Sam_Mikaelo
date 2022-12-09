#ifndef _CREDITS_H
#define _CREDITS_H
#include "Texture.h"

using namespace SDLFramework;

class Credits :    public GameEntity
{
private:
	Texture* m_pSam;
	Texture* m_pAnd;
	Texture* m_pMikaelo;
	Texture* m_pBackground;
	Texture* m_pMadeBy;

	
public:
	Credits();
	~Credits();

	void Update() override;
	void Render() override;

	void ShowCredits();
};

#endif // !_CREDITS_H