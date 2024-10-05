#include "GameFramework/gameApplication.h"
#include "framework/world.h"
#include "framework/Actor.h"

ly::Application* GetApplication()
{
	return  new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{600, 980,"Light Years", sf::Style::Titlebar | sf::Style::Close}
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpamActor<Actor>();
		actorToDestory = newWorld.lock()->SpamActor<Actor>();
		actorToDestory.lock()->SetTexture("C:/LY/LightYearsGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		counter = 0;
	}
	void GameApplication::Tick(float deltatime)
	{
		counter += deltatime;

		if (counter > 2.f)
		{
			if (!actorToDestory.expired())
			{
				actorToDestory.lock()->Destory();
		    }
		}
	}
}