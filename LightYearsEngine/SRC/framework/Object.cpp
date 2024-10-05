#include"framework/Object.h"
#include"framework/Core.h"

namespace ly
{
	 Object::Object()
		: mIsPendingDestory{false}
	{
	}

	Object::~Object()
	{
		LOG("Objected Destory");
	}

	void Object::Destory()
	{
		mIsPendingDestory = true;
	}

}