#include "YellowBrick.h"

YellowBrick::YellowBrick()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	Active(true);

	m_pYellowBreakAnimation = new AnimatedTexture("Bricks/Yellow Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pYellowBreakAnimation->Parent(this);
	m_pYellowBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pYellowBreakAnimation->Position(-235.0f, -405.0f);
	m_pYellowBreakAnimation->SetWrapMode(AnimatedTexture::Once);
}


YellowBrick::~YellowBrick()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pYellowBreakAnimation;
	m_pYellowBreakAnimation = nullptr;
}

void YellowBrick::Update()
{
	if (Active()) {
		m_pYellowBreakAnimation->Update();
	}
	if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_U)) 
	{
		m_pYellowBreakAnimation->Update();
	}
	/*else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O))
	{

	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I))
	{

	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_U))
	{

	}*/
}

void YellowBrick::Render()
{
	if (!Active()) {

	}

	if (Active()) {
		m_pYellowBreakAnimation->Render();
		/*PhysEntity::Render();*/
	}
}

void YellowBrick::Visible(bool visible) {
	mVisible = visible;
}

bool YellowBrick::IsAnimating() {
	return mAnimating;
}

//bool Brick::InDeathAnimation()
//{
//	return m_pRedBreakAnimation->IsAnimating();
//	return m_pOrangeBreakAnimation->IsAnimating();
//	return m_pGreenBreakAnimation->IsAnimating();
//	return m_pYellowBreakAnimation->IsAnimating();
//}

void YellowBrick::Hit(PhysEntity* other) {
	m_pYellowBreakAnimation->Update();
	Active(false);
}

bool YellowBrick::IgnoreCollisions() {
	return !Active();
}

