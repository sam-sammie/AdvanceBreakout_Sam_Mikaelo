#include "StarLayer.h"

StarLayer::StarLayer(int layer) {
	for (int i = 0; i < STAR_COUNT; i++) {
		m_pStars[i] = new Star(layer);
	}
}

StarLayer::~StarLayer() { 
	for (int i = 0; i < STAR_COUNT; i++) {
		delete m_pStars[i];
		m_pStars[i] = nullptr;
	}
}

void StarLayer::Update() {
	for (auto star : m_pStars) {
		star->Update();
	}
}

void StarLayer::Render() {
	for (auto star : m_pStars) {
		star->Render();
	}
}