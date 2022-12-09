#include "Credits.h"

Credits::Credits() {

	m_pMadeBy = new Texture("Made By:", "emulogic.ttf", 32, { 200,0,0 });
	m_pSam = new Texture("SAMANTHA SAMAROO", "emulogic.ttf", 32, { 200,0,0 });
	m_pAnd = new Texture("AND", "emulogic.ttf", 32, { 200,0,0 });
	m_pMikaelo = new Texture("MIKAELO SAN JOSE", "emulogic.ttf", 32, { 200,0,0 });


	m_pBackground = new Texture("Backdrop.png");
	m_pBackground->Position(Graphics::SCREEN_WIDTH * 0.50f, Graphics::SCREEN_HEIGHT * 0.50f);
	m_pBackground->Parent(this);

	m_pMadeBy->Position(Graphics::SCREEN_WIDTH * 0.50f, 350.0f);
	m_pSam->Position(Graphics::SCREEN_WIDTH * 0.50f, 400.0f);
	m_pAnd->Position(Graphics::SCREEN_WIDTH * 0.50f, 450.0f);
	m_pMikaelo->Position(Graphics::SCREEN_WIDTH * 0.50f, 500.0f);
}

Credits::~Credits() {
	delete m_pSam;
	m_pSam = nullptr;

	delete m_pAnd;
	m_pAnd = nullptr;

	delete m_pMikaelo;
	m_pMikaelo = nullptr;

	delete m_pBackground;
	m_pBackground = nullptr;

	delete m_pMadeBy;
	m_pMadeBy = nullptr;
}

void Credits::Update() {
	m_pBackground->Update();
	m_pSam->Update();
	m_pAnd->Update();
	m_pMikaelo->Update();
	m_pMadeBy->Update();
}

void Credits::Render() {
	m_pBackground->Render();
	m_pSam->Render();
	m_pAnd->Render();
	m_pMikaelo->Render();
	m_pMadeBy->Render();

}

void Credits::ShowCredits() {
	
	
	
}