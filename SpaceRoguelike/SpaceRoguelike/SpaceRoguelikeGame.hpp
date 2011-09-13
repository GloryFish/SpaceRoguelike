//
//  SpaceRoguelikeGame.hpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/12/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_SpaceRoguelikeGame_hpp
#define SpaceRoguelike_SpaceRoguelikeGame_hpp

#import "GFE/Game.hpp"

namespace SpaceRoguelike {
    class SpaceRoguelikeGame : public GFE::Game {
        
    public:
        SpaceRoguelikeGame(const std::string theTitle = "SpaceRoguelike");
        virtual ~SpaceRoguelikeGame();
    
    protected:
        virtual void Init(void);
    private:
    };
}



#endif
