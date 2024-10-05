#pragma once

namespace ly
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Destory();
		bool IsPendingDestroy() const { return mIsPendingDestory; };

	private:
		bool mIsPendingDestory;

	};
}