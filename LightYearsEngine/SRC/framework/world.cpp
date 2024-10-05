#include "framework/world.h"
#include "framework/core.h"
#include "framework/Actor.h"

namespace ly
{
	// Constructor definition with proper initialization list
	World::World(Application* owningApp)
		: mOwningApp{ owningApp },
		mBeganPlay{ false },
		mActors{},
		mPendingActors{}
	{

	}

	void World::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BegainPlay();
		}
	}

	void World::TickInternal(float deltaTime)
	{
		// Process all pending actors
		for (shared<Actor> actor : mPendingActors)
		{
			if (actor)
			{
				mActors.push_back(actor);
				actor->BeginPlayInternal(); // Initialize the actor
			}
		}
		mPendingActors.clear();

		for (auto iter = mActors.begin(); iter != mActors.end();)
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = mActors.erase(iter);
			}

			else
			{
				iter->get()->TickInternal(deltaTime);
				++iter;
			}
		}

		Tick(deltaTime);
	}

	void World::Render(sf::RenderWindow& window)
	{
		for (auto actor : mActors)
		{
			
			actor->Render(window);
		}

	}

	World::~World()
	{
	}

	void World::BegainPlay()
	{
		LOG("began play");
	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at framer rate %f", 1.f / deltaTime);
	}

}
