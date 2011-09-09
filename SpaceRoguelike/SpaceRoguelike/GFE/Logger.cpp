//
//  Logger.cpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/7/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#include <iostream>
#include "Logger.hpp"

namespace GFE {
    
    std::ostringstream Logger::logstream;
    
    std::ostringstream& Logger::log() {
        if(logstream.str() != "") {
            flush();   
        }
        return logstream;
    }
    
    void Logger::flush() {
        if (logstream.str() != "") {
            std::cout << logstream.str() << std::endl;
            logstream.str("");
        }
    }
    
}