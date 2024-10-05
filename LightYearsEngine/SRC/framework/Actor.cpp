#include"framework/Actor.h"
#include"framework/core.h"


namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePack)
		: mOwningWorld(owningWorld),
		mHasBeganPlay{false},
		mSprite{},
		mTexture{}
	{
		SetTexture(texturePack);
	}

	Actor::~Actor()
	{
		LOG("Actor Destroy");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeganPlay();
		}
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!IsPendingDestroy())
		{
			Tick(deltaTime);
		}
	}

	void Actor::BeganPlay()
	{
		LOG("Actor began play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor Ticking");
	}

	void Actor::SetTexture(const std::string& texturePack)
	{
		mTexture.loadFromFile(texturePack);
		mSprite.setTexture(mTexture);
		
		int textureWidht = mTexture.getSize().x;
		int textureHeight = mTexture.getSize().y;

		mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidht, textureHeight} });
	}

	void Actor::Render(sf::RenderWindow& Window)
	{
		if (IsPendingDestroy())
		{
			return;
		}
		
		Window.draw(mSprite);
	}
}