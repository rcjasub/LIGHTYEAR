#pragma once
#include <SFML/Graphics.hpp>  
#include "framework/Object.h"
#include "framework/core.h"

namespace ly
{
    class World;
    class Actor : public Object
    {
    public:
        Actor(World* owningWorld, const std::string& textturePack = "");
        virtual ~Actor();
        void BeginPlayInternal();
        void TickInternal(float deltaTime);
        virtual void BeganPlay();
        virtual void Tick(float deltaTime);
        void SetTexture(const std::string& texturePack);
        void Render(sf::RenderWindow& Window);

    private:
        World* mOwningWorld;
        bool mHasBeganPlay;

        sf::Sprite mSprite;  
        sf::Texture mTexture;
    };
}
