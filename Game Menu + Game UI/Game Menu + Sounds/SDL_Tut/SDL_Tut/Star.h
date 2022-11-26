#ifndef _STAR_H
#define _STAR_H
#include "Texture.h"
#include "Timer.h"
#include "Random.h"

using namespace SDLFramework;

class Star : public Texture {
private:
	static bool mScroll;

	Timer* m_pTimer;
	Random* m_pRandom;

	bool mVisible;
	float mFlickerTimer;
	float mFlickerSpeed;

	float mScrollSpeed;

public:
	Star(int layer);
	~Star();

	void Update() override;
	void Render() override;

	static void Scroll(bool b);

private:
	void ScrollStar();

};

#endif // 

