//
//  SpageRoguelikeGame.cpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/12/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#import "SpaceRoguelikeGame.hpp"

#import "GFE/GreenState.hpp"
#import "GFE/Logger.hpp"

namespace SpaceRoguelike {
    SpaceRoguelikeGame::SpaceRoguelikeGame(const std::string theTitle) : GFE::Game(theTitle) {
        
        GFE::Logger::Log() << "SRG ctor";
        
    }
    
    SpaceRoguelikeGame::~SpaceRoguelikeGame() {
        
    }
    
     void SpaceRoguelikeGame::Init(void) {
        GFE::Logger::Log() << "SRG Init";
        stateManager.AddActiveState(new(std::nothrow) GFE::GreenState(this));
        stateManager.GetActiveState();
    }
}