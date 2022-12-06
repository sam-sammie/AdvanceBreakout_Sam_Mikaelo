#include "Brick.h"

bool Brick::IgnoreCollisions()
{
	return false;
}

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
	m_pRedBreakAnimation->SetWrapMode(AnimatedTexture::Once);

	m_pOrangeBreakAnimation = new AnimatedTexture("Bricks/Orange Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pOrangeBreakAnimation->Parent(this);
	m_pOrangeBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pOrangeBreakAnimation->Position(-235.0f, -535.0f);
	m_pOrangeBreakAnimation->SetWrapMode(AnimatedTexture::Once);

	m_pGreenBreakAnimation = new AnimatedTexture("Bricks/Green Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pGreenBreakAnimation->Parent(this);
	m_pGreenBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pGreenBreakAnimation->Position(-235.0f, -470.0f);
	m_pGreenBreakAnimation->SetWrapMode(AnimatedTexture::Once);

	m_pYellowBreakAnimation = new AnimatedTexture("Bricks/Yellow Destroy.png", 0, 0, 67, 100, 2, 0.01f, AnimatedTexture::Vertical);
	m_pYellowBreakAnimation->Parent(this);
	m_pYellowBreakAnimation->Scale(Vector2(2.0f, 2.0f));
	m_pYellowBreakAnimation->Position(-235.0f, -405.0f);
	m_pYellowBreakAnimation->SetWrapMode(AnimatedTexture::Once);
	
	//Red Brick
	AddCollider(new BoxCollider(Vector2(105.0f, 56.5f)), Vector2(-260.0f, -566.5f));

	////Orange Brick
	AddCollider(new BoxCollider(Vector2(105.5f, 56.0f)), Vector2(-260.0f, -502.5f));

	////Green Brick
	AddCollider(new BoxCollider(Vector2(105.9f, 56.0f)), Vector2(-260.0f, -437.5f));

	////YellowBrick
	AddCollider(new BoxCollider(Vector2(105.9f, 56.0f)), Vector2(-260.0f, -373.0f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Hostile);




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

void Brick::Update()
{
	m_pRedBreakAnimation->Update();
	m_pOrangeBreakAnimation->Update();
	m_pGreenBreakAnimation->Update();
	m_pYellowBreakAnimation->Update();
	/*if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_P)) {
	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_O))
	{
		
	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_I)) 
	{
		
	}
	else if (InputManager::Instance()->KeyPressed(SDL_SCANCODE_U)) 
	{
		
	}*/
}

void Brick::Render()
{
	m_pRedBreakAnimation->Render();
	m_pOrangeBreakAnimation->Render();
	m_pGreenBreakAnimation->Render();
	m_pYellowBreakAnimation->Render();

	PhysEntity::Render();
}

void Brick::Visible(bool visible) {
	mVisible = visible;
}

bool Brick::IsAnimating() {
	return mAnimating;
}

//bool Brick::InDeathAnimation()
//{
//	return m_pRedBreakAnimation->IsAnimating();
//	return m_pOrangeBreakAnimation->IsAnimating();
//	return m_pGreenBreakAnimation->IsAnimating();
//	return m_pYellowBreakAnimation->IsAnimating();
//}


