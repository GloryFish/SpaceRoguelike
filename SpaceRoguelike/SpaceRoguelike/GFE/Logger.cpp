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
    
    std::ostringstream& Logger::Log() {
        if(logstream.str() != "") {
            Flush();   
        }
        return logstream;
    }
    
    void Logger::Flush() {
        if (logstream.str() != "") {
            std::cout << logstream.str() << std::endl;
            logstream.str("");
        }
    }
    
}