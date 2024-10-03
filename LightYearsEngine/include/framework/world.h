#pragma once

namespace ly
{
	class Application; 
	class World
	{
	public:
		World(Application* owningApp);

		void BeginPlayInternal();
		void TickInternal(float deltaTime);

		virtual ~World();

	private:
		void BegainPlay();
		void Tick(float deltaTime);
		Application* mOwningApp;  
		bool mBeganPlay;
	};
}
