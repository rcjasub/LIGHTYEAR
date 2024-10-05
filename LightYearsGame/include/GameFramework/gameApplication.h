#pragma once
#include"framework/application.h"
#include"framework/core.h"

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		virtual void Tick(float deltatime) override;

	private:
		float counter;
		weak<Actor> actorToDestory;
	};

}
