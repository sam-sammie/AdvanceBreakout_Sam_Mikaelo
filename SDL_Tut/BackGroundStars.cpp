#include "BackGroundStars.h"

BackgroundStars* BackgroundStars::sInstance = nullptr;

BackgroundStars* BackgroundStars::Instance() {
	if (sInstance == nullptr) {
		sInstance = new BackgroundStars();
	}

	return sInstance;
}

void BackgroundStars::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void BackgroundStars::Scroll(bool b) {
	Star::Scroll(b);
}

void BackgroundStars::Update() {
	for (auto layer : m_pLayers) {
		layer->Update();
	}
}

void BackgroundStars::Render() {
	for (auto layer : m_pLayers) {
		layer->Render();
	}
}

BackgroundStars::BackgroundStars() {
	for (int i = 0; i < LAYER_COUNT; i++) {
		m_pLayers[i] = new StarLayer(i + 1);
	}
}

BackgroundStars::~BackgroundStars() {
	for (int i = 0; i < LAYER_COUNT; i++) {
		delete m_pLayers[i];
		m_pLayers[i] = nullptr;
	}
}