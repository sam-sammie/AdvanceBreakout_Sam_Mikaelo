#include "Star.h"

bool Star::mScroll = false;

void Star::Scroll(bool b) {
	mScroll = b;
}

Star::Star(int layer) : Texture("Stars.png",0,0,4,4) {
	m_pTimer = Timer::Instance();
	m_pRandom = Random::Instance();

	int starColor = m_pRandom->RandomInt() % 4;

	mSourceRect.x = starColor * 4;

	Position(Vector2((float)(m_pRandom->RandomInt() % Graphics::Instance()->SCREEN_WIDTH),
		(float)(m_pRandom->RandomInt() % Graphics::Instance()->SCREEN_HEIGHT)));

	mFlickerTimer = 0.0f;
	mFlickerSpeed = m_pRandom->RandomRange(0.15f, 1.0f);

	float inverseLayer = 1.0f / layer;
	Scale(Vec2_One * inverseLayer);
	mScrollSpeed = 4.0f / layer;

}

Star::~Star() {
	m_pTimer = nullptr;
	m_pRandom = nullptr;
}

void Star::ScrollStar() {
	Translate(Vec2_Up * mScrollSpeed, World);

	Vector2 pos = Position(Local);

	if (pos.y > Graphics::Instance()->SCREEN_HEIGHT) {
		pos.y == 0.0f;
		pos.x = (float)(m_pRandom->RandomInt() % Graphics::Instance()->SCREEN_HEIGHT);
		Position(pos);
	}
}

void Star::Update() {
	mFlickerTimer += m_pTimer->DeltaTime();

	if (mFlickerTimer >= mFlickerSpeed) {
		mVisible = !mVisible;
		mFlickerTimer = 0.0f;
	}

	if (mScroll) {
		ScrollStar();
	}
}

void Star::Render() {
	if (mVisible) {
		Texture::Render();
	}
}