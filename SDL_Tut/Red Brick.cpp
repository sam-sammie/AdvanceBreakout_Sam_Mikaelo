#include "Red Brick.h"

RedBrick::RedBrick()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	Active(true);

	m_pRedBreakAnimation = new AnimatedTexture("Bricks/Red Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pRedBreakAnimation->Parent(this);
	m_pRedBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pRedBreakAnimation->Position(-235.0f, -600.0f);

	////Red Brick
	AddCollider(new BoxCollider(Vector2(105.0f, 56.5f)), Vector2(-260.0f, -566.5f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);


}

RedBrick::~RedBrick()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pRedBreakAnimation;
	m_pRedBreakAnimation = nullptr;
}

void RedBrick::Update()
{
	if (mAnimating) {
		m_pRedBreakAnimation->Update();

	}
	/*if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P)) 
	{
		m_pRedBreakAnimation->Update();
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

void RedBrick::Render()
{
	if (Active()) {
		m_pRedBreakAnimation->Render();
		m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, 1);
		PhysEntity::Render();
	}
}

void RedBrick::Visible(bool visible) {
	mVisible = visible;
}

bool RedBrick::IsAnimating() {
	return mAnimating;
}

//bool Brick::InDeathAnimation()
//{
//	return m_pRedBreakAnimation->IsAnimating();
//	return m_pOrangeBreakAnimation->IsAnimating();
//	return m_pGreenBreakAnimation->IsAnimating();
//	return m_pYellowBreakAnimation->IsAnimating();
//}

void RedBrick::Hit(PhysEntity* other) {
	m_pRedBreakAnimation->Update();
	m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, 1);
	Active(false);
}

bool RedBrick::IgnoreCollisions() {
	return !Active();
}


