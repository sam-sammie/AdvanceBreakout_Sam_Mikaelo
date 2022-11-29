#include "Random.h"

namespace SDLFramework {
	Random* Random::sInstance = nullptr;

	Random* Random::Instance() {
		if (sInstance == nullptr) {
			sInstance = new Random();
		}

		return sInstance;
	}

	void Random::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	Random::Random() {
		unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
		mGenerator.seed(seed);
	}

	Random::~Random() {

	}

	unsigned Random::RandomInt() {
		return mGenerator();
	}

	float Random::RandomFloat() {
		std::uniform_real_distribution<float> dist(0.0f, 1.0f);
		return dist(mGenerator);
	}

	int SDLFramework::Random::RandomRange(int low, int high) {
		std::uniform_int_distribution<int> dist(low, high);
		return dist(mGenerator);
	}

	float SDLFramework::Random::RandomRange(float low, float high) {
		std::uniform_real_distribution<float> dist(low, high);
		return dist(mGenerator);
	}
}
