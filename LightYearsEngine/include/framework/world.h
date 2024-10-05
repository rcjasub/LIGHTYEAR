#pragma once
#include"framework/core.h"
#include<SFML/Graphics.hpp>

namespace ly
{
	class Actor;
	class Application; 
	class World
	{
	public:
		World(Application* owningApp);

		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow& window);

		virtual ~World();

		template<typename ActorType>
		weak<ActorType> SpamActor();
		
	private:
		void BegainPlay();
		void Tick(float deltaTime);
		Application* mOwningApp;  
		bool mBeganPlay;

		list<shared<Actor>> mActors;

		list<shared<Actor>> mPendingActors;

	};


	template<typename ActorType>
       weak<ActorType> World::SpamActor()
	{
		shared<ActorType> newActor{ new ActorType{ this } };
		mPendingActors.push_back(newActor);
		return newActor;
	}
}
