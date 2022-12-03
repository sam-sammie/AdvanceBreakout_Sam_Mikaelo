#include "Brick.h"

Brick::Brick()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();
	
	mVisible = false;
	mAnimating = false;

	
	m_pRedBreakAnimation = new AnimatedTexture("Bricks/Red Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pRedBreakAnimation->Parent(this);
	m_pRedBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pRedBreakAnimation->Position(-235.0f, -600.0f);

	m_pOrangeBreakAnimation = new AnimatedTexture("Bricks/Orange Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pOrangeBreakAnimation->Parent(this);
	m_pOrangeBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pOrangeBreakAnimation->Position(-235.0f, -535.0f);

	m_pGreenBreakAnimation = new AnimatedTexture("Bricks/Green Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pGreenBreakAnimation->Parent(this);
	m_pGreenBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pGreenBreakAnimation->Position(-235.0f, -470.0f);

	m_pYellowBreakAnimation = new AnimatedTexture("Bricks/Yellow Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pYellowBreakAnimation->Parent(this);
	m_pYellowBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pYellowBreakAnimation->Position(-235.0f, -405.0f);

}

Brick::~Brick()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pRedBreakAnimation;
	m_pRedBreakAnimation = nullptr;

	delete m_pOrangeBreakAnimation;
	m_pOrangeBreakAnimation = nullptr;

	delete m_pGreenBreakAnimation;
	m_pGreenBreakAnimation = nullptr;

	delete m_pYellowBreakAnimation;
	m_pYellowBreakAnimation = nullptr;


}

void Brick::Update(int keypress)
{
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P)) {
		m_pRedBreakAnimation->Update();

	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O))
	{
		m_pOrangeBreakAnimation->Update();
	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I)) 
	{
		m_pGreenBreakAnimation->Update();
	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_U)) 
	{
		m_pYellowBreakAnimation->Update();
	}


	


}

void Brick::Render()
{
	m_pRedBreakAnimation->Render();
	m_pOrangeBreakAnimation->Render();
	m_pGreenBreakAnimation->Render();
	m_pYellowBreakAnimation->Render();
}

void Brick::Visible(bool visible) {
	mVisible = visible;
}

bool Brick::IsAnimating() {
	return mAnimating;
}

