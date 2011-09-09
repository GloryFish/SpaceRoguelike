#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include "GFE/Core.hpp"

int main (int argc, const char * argv[])
{
    GFE::Game game;
    
    int returnCode = game.Run();
    
    GFE::Logger::flush();

	return returnCode;
}
