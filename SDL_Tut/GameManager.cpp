#include "GameManager.h"

namespace SDLFramework {
	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() {
		while (!mQuit) {
			m_pTimer->Update();
			while (SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}

			if (m_pTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				m_pTimer->Reset();
				Update();
			LateUpdate();
			Render();
			}

			
		}
	}

	void GameManager::Update() // runs every frame
	{
		m_pInputManager->Update();
		m_pScreenManager->Update();

	}

	void GameManager::LateUpdate() {
		m_pInputManager->UpdatePrevInput();
		m_pPhysicsManager->Update();
	}

	void GameManager::Render() {
		m_pGraphics->ClearBackBuffer(); // call this oen first
		// The order we render matters
		//We render on top of each one.
		m_pScreenManager->Render();
		
		m_pGraphics->Render(); // call this one last
	}

	GameManager::GameManager() : mQuit(false) {
		m_pGraphics = Graphics::Instance();
		m_pPhysicsManager = PhysicsManager::Instance();
		m_pTimer = Timer::Instance();
		if (!Graphics::Initialized()) {
			mQuit = true;
		}
		m_pAssetManager = AssetManager::Instance();
		m_pInputManager = InputManager::Instance();
		m_pAudioManager = AudioManager::Instance();

		m_pScreenManager = ScreenManager::Instance();

		m_pPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::Friendly,
			PhysicsManager::CollisionFlags::Hostile |
			PhysicsManager::CollisionFlags::HostileProjectiles);
		m_pPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::FriendlyProjectiles,
			PhysicsManager::CollisionFlags::Hostile);
		m_pPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::Hostile,
			PhysicsManager::CollisionFlags::Friendly |
			PhysicsManager::CollisionFlags::FriendlyProjectiles);
		m_pPhysicsManager->SetLayerCollisionMask(
			PhysicsManager::CollisionLayers::HostileProjectiles,
			PhysicsManager::CollisionFlags::Friendly);
	}

	GameManager::~GameManager() {
		Graphics::Release();
		Timer::Release();
		PhysicsManager::Release();
		m_pPhysicsManager = nullptr;
		m_pGraphics = nullptr;
		m_pTimer = nullptr;
		AssetManager::Release();
		m_pAssetManager = nullptr;
		InputManager::Release();
		m_pInputManager = nullptr;
		AudioManager::Release();
		m_pAudioManager = nullptr;
		ScreenManager::Release();
		m_pScreenManager = nullptr;

		SDL_Quit();
	}
}