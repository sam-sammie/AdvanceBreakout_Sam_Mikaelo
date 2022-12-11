#include "OrangeBrick.h"

OrangeBrick::OrangeBrick(Player* inputPlayer, PlaySideBar* inputSideBar)
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	Active(true);

	m_pPlayer = inputPlayer;
	m_pSideBar = inputSideBar;

	m_pOrangeBreakAnimation = new AnimatedTexture("Bricks/Orange Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pOrangeBreakAnimation->Parent(this);
	m_pOrangeBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pOrangeBreakAnimation->Position(-235.0f, -535.0f);
	m_pOrangeBreakAnimation->SetWrapMode(AnimatedTexture::Once);


	////Orange Brick
	AddCollider(new BoxCollider(Vector2(105.5f, 56.0f)), Vector2(-260.0f, -502.5f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);


}

OrangeBrick::~OrangeBrick() 
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pOrangeBreakAnimation;
	m_pOrangeBreakAnimation = nullptr;
}

void OrangeBrick::Update()
{
	if (Active()) {
		m_pOrangeBreakAnimation->Update();
	}
	/*if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O))
	{
		m_pOrangeBreakAnimation->Update();
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

void OrangeBrick::Render()
{
	if (!Active()) {

	}

	if (Active()) {
		m_pOrangeBreakAnimation->Render();
		PhysEntity::Render();
	}
}

void OrangeBrick::Visible(bool visible) {
	mVisible = visible;
}

bool OrangeBrick::IsAnimating() {
	return mAnimating;
}

//bool Brick::InDeathAnimation()
//{
//	return m_pRedBreakAnimation->IsAnimating();
//	return m_pOrangeBreakAnimation->IsAnimating();
//	return m_pGreenBreakAnimation->IsAnimating();
//	return m_pYellowBreakAnimation->IsAnimating();
//}

void OrangeBrick::Hit(PhysEntity* other) {
	m_pOrangeBreakAnimation->Update();
	if (m_pPlayer->Score() < 0) {
		m_pPlayer->SetScore(0);
	}
	m_pPlayer->OrangeBrickDestroyed();
	m_pSideBar->SetPlayerScore(m_pPlayer->Score());
	m_pAudio->PlaySFX("SFX/Hitmarker.wav", 0, 1);
	Active(false);
}

bool OrangeBrick::IgnoreCollisions() {
	return !Active();
}