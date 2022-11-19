#include "PlaySideBar.h"

PlaySideBar::PlaySideBar()
{
	m_pTimer = Timer::Instance();
	m_pAudio = AudioManager::Instance();

	//Layout

	m_pBackground = new Texture("Black.png");
	m_pBackground->Parent(this);
	m_pBackground->Scale(Vector2(3.0f, 10.0f));
	m_pBackground->Position(50.0f, 0.0f);

	m_pRightWall = new Texture("RightWall.png");
	m_pRightWall->Parent(this);
	m_pRightWall->Scale(Vector2(3.0f, 10.0f));
	m_pRightWall->Position(-95.0f, 0.0f);

	m_pLeftWall = new Texture("LeftWall.png");
	m_pLeftWall->Parent(this);
	m_pLeftWall->Scale(Vector2(3.0f, 10.0f));
	m_pLeftWall->Position(-820.0f, 0.0f);

	m_pTopWall = new Texture("TopWall.png");
	m_pTopWall->Parent(this);
	m_pTopWall->Scale(Vector2(500.0f, 10.0f));
	m_pTopWall->Position(-850.0f, 0.0f);

	m_pScoreLabel = new Texture("SCORE:", "ARCADEPI.TTF", 32, { 150, 0, 0 });
	m_pScoreLabel->Parent(this);
	m_pScoreLabel->Position(-755.0f, 20.0f);

	m_pLivesLabel = new Texture("LIVES", "ARCADEPI.TTF", 32, { 150, 0, 0 });
	m_pLivesLabel->Parent(this);
	m_pLivesLabel->Position(-140.0f, 20.0f);

	m_pHighScoreboard = new Scoreboard();
	m_pHighScoreboard->Parent(this);
	m_pHighScoreboard->Position(-750.0f, 55.0f);

	//Bricks
	m_pRedBricks = new Texture("RedBrick.png");
	m_pRedBricks->Parent(this);
	m_pRedBricks->Scale(Vector2(2.0f, 2.0f));
	m_pRedBricks->Position(-558.0f, 90.0f);

	m_pOrangeBricks = new Texture("OrangeBrick.png");
	m_pOrangeBricks->Parent(this);
	m_pOrangeBricks->Scale(Vector2(2.0f, 2.0f));
	m_pOrangeBricks->Position(-558.0f, 155.0f);

	m_pGreenBricks = new Texture("GreenBrick.png");
	m_pGreenBricks->Parent(this);
	m_pGreenBricks->Scale(Vector2(2.0f, 2.0f));
	m_pGreenBricks->Position(-558.0f, 220.0f);

	m_pYellowBricks = new Texture("YellowBrick.png");
	m_pYellowBricks->Parent(this);
	m_pYellowBricks->Scale(Vector2(2.0f, 2.0f));
	m_pYellowBricks->Position(-558.0f, 285.0f);



}

PlaySideBar::~PlaySideBar()
{
	m_pTimer = nullptr;
	m_pAudio = nullptr;

	delete m_pRedBricks;
	m_pRedBricks = nullptr;

	delete m_pOrangeBricks;
	m_pOrangeBricks = nullptr;

	delete m_pGreenBricks;
	m_pGreenBricks = nullptr;
	
	delete m_pYellowBricks;
	m_pYellowBricks = nullptr;

	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pLeftWall;
	m_pLeftWall = nullptr;

	delete m_pRightWall;
	m_pRightWall = nullptr;

	delete m_pTopWall;
	m_pTopWall = nullptr;

	delete m_pScoreLabel;
	m_pScoreLabel = nullptr;

	delete m_pLivesLabel;
	m_pLivesLabel = nullptr;

	delete m_pHighScoreboard;
	m_pHighScoreboard = nullptr;


}

void PlaySideBar::Update()
{
	m_pBackground->Update();
	m_pTopWall->Update();
	m_pRightWall->Update();
	m_pLeftWall->Update();
	m_pHighScoreboard->Update();
	m_pScoreLabel->Update();
	m_pLivesLabel->Update();

}

void PlaySideBar::Render()
{
	m_pBackground->Render();
	m_pTopWall->Render();
	m_pRightWall->Render();
	m_pLeftWall->Render();
	m_pLivesLabel->Render();
	m_pHighScoreboard->Render();
	m_pScoreLabel->Render();
	
	m_pRedBricks->Render();
	m_pOrangeBricks->Render();
	m_pGreenBricks->Render();
	m_pYellowBricks->Render();
}

