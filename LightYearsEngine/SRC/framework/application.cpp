#include "framework/application.h"
#include "framework/core.h"
#include "framework/world.h"
namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode(1000, 1000), "LighYears" },
		mTargetFrameRate{ 30.f },
		mTickClock{},
		currentWorld{nullptr}
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
		sf::RectangleShape rect(sf::Vector2f{ 100, 100 });
		rect.setFillColor(sf::Color::Magenta);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);

		mWindow.draw(rect);
	}

	void Application::Tick(float deltaTime)
	{
		
	}
}
