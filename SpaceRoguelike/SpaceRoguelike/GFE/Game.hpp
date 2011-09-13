//
//  Game.hpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/8/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_Game_hpp
#define SpaceRoguelike_Game_hpp

#include "StateManager.hpp"
#include "StateManager.hpp"
#include "CoreTypes.hpp"

#include <SFML/Graphics.hpp>



namespace GFE {
    
    class Game {

    public:
        // Constants
        static const unsigned int DEFAULT_VIDEO_WIDTH = 800;
        static const unsigned int DEFAULT_VIDEO_HEIGHT = 600;
        static const unsigned int DEFAULT_VIDEO_BPP = 32;
        
        // Fields
        sf::RenderWindow window;
        sf::VideoMode video_mode;
        sf::ContextSettings context_settings;
        int exit_code;
        std::string title;
        
        StateManager stateManager;
        
        Game(const std::string theTitle = "GFE Game");

        // Methods
        int Run(void);
        bool IsRunning(void);
        void Quit(int status_code = EXIT_SUCCESS);
    protected:
        virtual void PreInit(void);
        virtual void Init(void);
        virtual void Loop(void);
        virtual void Cleanup(void);
        
    private:
        // Fields
        bool running;
        Uint32 update_rate;
    };
    
}


#endif
