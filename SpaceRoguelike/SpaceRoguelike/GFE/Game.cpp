//
//  Game.cpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/8/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include <iostream>
#include "Core.hpp"

namespace GFE {
    
    Game::Game() {
        running = false;
        update_rate = (Uint32)(1000.0f / 100.0f);
    }
    
    int Game::Run(void) {
        running = true;
        Logger::Log() << "Running...";
        
        PreInit();
        
        // Initialize our application which might set our Running flag to false
        Init();
        
        // Loop if Running flag is still true
        Loop();
        
        // Cleanup our application
        Cleanup();
        
        // Make sure our Running flag is set to false before exiting
        running = false;
        
        return EXIT_SUCCESS;
    }
    
    bool Game::IsRunning(void) {
        return running;
    }
    
    void Game::PreInit(void) {
        Logger::Log() << "PreInit()";
        
        video_mode.Width = DEFAULT_VIDEO_WIDTH;
        video_mode.Height = DEFAULT_VIDEO_HEIGHT;
        video_mode.BitsPerPixel = DEFAULT_VIDEO_BPP;

        // Create a RenderWindow object using VideoMode object above
        window.Create(video_mode, "Space Roguelike", sf::Style::Default, context_settings);

        // Use Vertical Sync
        window.EnableVerticalSync(true);
    }

    void Game::Init(void) {
        Logger::Log() << "Init()";
        
    }

    void Game::Loop(void) {
        Logger::Log() << "Loop()";
        
        // Clock used in restricting Update loop to a fixed rate
        sf::Clock update_clock;
        update_clock.Reset();
        
        // Update immediately
        Uint32 next_update = update_clock.GetElapsedTime();
        
        // Loop while IsRunning returns true
        while(IsRunning() && window.IsOpened()) {
            
            while (update_clock.GetElapsedTime() > next_update) {
             
                sf::Event event;

                while(window.PollEvent(event)) {
                    
                }
                
                next_update += update_rate;
                
                Logger::Log() << "Time: " << update_clock.GetElapsedTime();
            }
        }
        
    }

    void Game::Cleanup(void) {
        Logger::Log() << "Cleanup()";
        
    }


}
