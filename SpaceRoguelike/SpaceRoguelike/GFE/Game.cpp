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
    }
    
    int Game::Run(void) {
        running = true;
        Logger::log() << "Running...";
        
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
    
    void Game::PreInit(void) {
        Logger::log() << "PreInit()";
        
    }

    void Game::Init(void) {
        Logger::log() << "Init()";
        
    }

    void Game::Loop(void) {
        Logger::log() << "Loop()";
        
    }

    void Game::Cleanup(void) {
        Logger::log() << "Cleanup()";
        
    }


}
