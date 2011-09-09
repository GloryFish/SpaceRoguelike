//
//  Game.hpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/8/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_Game_hpp
#define SpaceRoguelike_Game_hpp

namespace GFE {
    
    class Game {

    public:
        bool running;
        
        Game();
        int Run(void);
    
    private:
        void PreInit(void);
        void Init(void);
        void Loop(void);
        void Cleanup(void);
    };
    
}


#endif
