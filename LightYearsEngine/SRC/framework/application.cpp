#include "framework/application.h"
#include <iostream>

namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode(1000, 1000), "LighYears" },
		mTargetFrameRate{ 30.f },
		mTickClock{}
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

			std::cout << "Ticking at framerate: " << 1.f / frameDeltaTime << std::endl;
		}
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}

	void Application::Tick(float deltaTime)
	{
		// Game logic update here
	}

	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();

		mWindow.display();  // Keep only one display call
	}

	void Application::Render()
	{
		sf::RectangleShape rect(sf::Vector2f{ 100, 100 });
		rect.setFillColor(sf::Color::Magenta);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);

		mWindow.draw(rect);
	}
}
