//
//  Logger.h
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/7/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_Logger_h
#define SpaceRoguelike_Logger_h

#include <sstream>

namespace GFE {
    class Logger {
        public:
            static std::ostringstream& log();
            static void flush();
        
        private:
            static std::ostringstream logstream;
    };
}

#endif
