#include "GreenBrick.h"

GreenBrick::GreenBrick()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	Active(true);

	m_pGreenBreakAnimation = new AnimatedTexture("Bricks/Green Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pGreenBreakAnimation->Parent(this);
	m_pGreenBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pGreenBreakAnimation->Position(-235.0f, -470.0f);
	m_pGreenBreakAnimation->SetWrapMode(AnimatedTexture::Once);

	////Green Brick
	AddCollider(new BoxCollider(Vector2(105.9f, 56.0f)), Vector2(-260.0f, -437.5f));
	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);


}

GreenBrick::~GreenBrick()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pGreenBreakAnimation;
	m_pGreenBreakAnimation = nullptr;
}

void GreenBrick::Update()
{
	if (Active()) {

	}
	/*if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I))
	{
		m_pGreenBreakAnimation->Update();
	}*/
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

void GreenBrick::Render()
{
	if (!Active()) {

	}

	if (Active()) {
		m_pGreenBreakAnimation->Render();
		PhysEntity::Render();
	}
}

void GreenBrick::Visible(bool visible) {
	mVisible = visible;
}

bool GreenBrick::IsAnimating() {
	return mAnimating;
}

//bool Brick::InDeathAnimation()
//{
//	return m_pRedBreakAnimation->IsAnimating();
//	return m_pOrangeBreakAnimation->IsAnimating();
//	return m_pGreenBreakAnimation->IsAnimating();
//	return m_pYellowBreakAnimation->IsAnimating();
//}

void GreenBrick::Hit(PhysEntity* other) {
	m_pGreenBreakAnimation->Update();
	Active(false);
}

bool GreenBrick::IgnoreCollisions() {
	return !Active();
}
