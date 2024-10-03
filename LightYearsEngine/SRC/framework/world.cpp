#include "framework/world.h"
#include "framework/core.h"

namespace ly
{
	// Constructor definition with proper initialization list
	World::World(Application* owningApp)
		: mOwningApp{ owningApp },
		mBeganPlay{ false }
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
		Tick(deltaTime);
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
