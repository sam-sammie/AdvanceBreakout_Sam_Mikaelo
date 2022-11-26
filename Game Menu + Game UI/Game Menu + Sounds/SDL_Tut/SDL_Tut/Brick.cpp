#include "Brick.h"

Brick::Brick()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	
	m_pColorBrick = new Texture("Bricks/Yellow Brick.png", 0, 0, 67, 100);
	
	m_pBreakAnimation = new AnimatedTexture("Bricks/Brick Destroy Animation.png", 0, 0, 67, 100, 8, 1.0f, AnimatedTexture::Vertical);
	m_pBreakAnimation->Parent(this);
	m_pBreakAnimation->Position(Vec2_Zero);
}

Brick::~Brick()
{
	delete m_pBreakAnimation;
	m_pBreakAnimation = nullptr;

	delete m_pColorBrick;
	m_pColorBrick = nullptr;
}

void Brick::Update()
{

}

void Brick::Render()
{

}
