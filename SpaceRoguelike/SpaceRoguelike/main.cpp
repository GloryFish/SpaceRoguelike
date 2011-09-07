#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourcePath.hpp"

int main (int argc, const char * argv[])
{
    
    unsigned speed = 200;
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.LoadFromFile(ResourcePath() + "man.png")) {
    	return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display
//    sf::Font font;
//    if (!font.LoadFromFile(ResourcePath() + "sansation.ttf"))
//    	return EXIT_FAILURE;
//    sf::Text text("Hello SFML", font, 50);
//    text.SetColor(sf::Color::Black);

    // Load a music to play
//    sf::Music music;
//    if (!music.OpenFromFile(ResourcePath() + "nice_music.ogg"))
//    	return EXIT_FAILURE;

    // Play the music
//    music.Play();
        

    // Start the game loop
    while (window.IsOpened()) {
    	// Process events
    	sf::Event event;
    	while (window.PollEvent(event)) {
    		// Close window : exit
    		if (event.Type == sf::Event::Closed) {
    			window.Close();
            }
            
    		// Escape pressed : exit
    		if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::Escape) {
    			window.Close();
            }
            
            if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::A) {
                sf::Vector2f pos = sprite.GetPosition();
                pos.x -= speed;
                sprite.SetPosition(pos.x, pos.y);
            }

            if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::D) {
                sf::Vector2f pos = sprite.GetPosition();
                pos.x += speed;
                sprite.SetPosition(pos.x, pos.y);
            }

            if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::W) {
                sf::Vector2f pos = sprite.GetPosition();
                pos.y -= speed;
                sprite.SetPosition(pos.x, pos.y);
            }

            if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Keyboard::S) {
                sf::Vector2f pos = sprite.GetPosition();
                pos.y += speed;
                sprite.SetPosition(pos.x, pos.y);
            }

    	}

    	// Clear screen
    	window.Clear();
    	
    	// Draw the sprite
    	window.Draw(sprite);
    	
    	// Draw the string
//    	window.Draw(text);

    	// Update the window
    	window.Display();
    }

	return EXIT_SUCCESS;
}
