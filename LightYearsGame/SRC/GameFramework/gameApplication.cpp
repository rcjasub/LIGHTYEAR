#include "GameFramework/gameApplication.h"
#include "framework/world.h"

ly::Application* GetApplication()
{
	return  new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}