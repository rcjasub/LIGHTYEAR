#include "framework/application.h"
#include "framework/core.h"
#include "framework/world.h"
namespace ly
{
	Application::Application(unsigned int windowWidth, unsigned int windowHeighht, const std::string& title, sf::Uint32 style)
		: mWindow{ sf::VideoMode(windowWidth, windowHeighht), title, style },
		mTargetFrameRate{ 60.f },
		mTickClock{},
		currentWorld{ nullptr }
	{
	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float TargetDeltaTime = 1.f / mTargetFrameRate;

		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::Closed)
				{
					mWindow.close();
				}
			}

			// Calculate time passed since the last frame
			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;  // Accumulate time correctly

			while (accumulatedTime >= TargetDeltaTime)
			{
				accumulatedTime -= TargetDeltaTime;
				TickInternal(TargetDeltaTime);
				RenderInternal();
			}
			
		}
	}

	void Application::TickInternal(float deltaTime)
	{

		Tick(deltaTime);

		if (currentWorld)
		{
			currentWorld->BeginPlayInternal();
			currentWorld->TickInternal(deltaTime);
		}
	}
	
	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();

		mWindow.display(); 
	}

	void Application::Render()
	{
		if (currentWorld)
		{
			currentWorld->Render(mWindow);
		}
	}

	void Application::Tick(float deltaTime)
	{
		
	}
}
