#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"
#include "GFE/Core.hpp"
#include "SpaceRoguelikeGame.hpp"

int main (int argc, const char * argv[])
{
    SpaceRoguelike::SpaceRoguelikeGame game;
    
    int returnCode = game.Run();
    
    GFE::Logger::Flush();

	return returnCode;
}
