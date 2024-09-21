#include "GameFramework/gameApplication.h"

ly::Application* GetApplication()
{
	return  new ly::GameApplication{};
}

namespace ly
{

}