//
//  CoreTypes.h
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/12/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_CoreTypes_h
#define SpaceRoguelike_CoreTypes_h

#import <string>

#include <stdint.h>

namespace GFE {
    // All "common" platforms use the same size for char, short and int
    // (basically there are 3 types for 3 sizes, so no other match is possible),
    // we can use them without doing any kind of check
    
    // 8 bits integer types
    typedef signed   char Int8;     ///< Standard 8 bit signed integer
    typedef unsigned char Uint8;    ///< Standard 8 bit unsigned integer
    
    // 16 bits integer types
    typedef signed   short Int16;   ///< Standard 16 bit signed integer
    typedef unsigned short Uint16;  ///< Standard 16 bit unsigned integer
    
    // 32 bits integer types
    typedef signed   int Int32;     ///< Standard 32 bit signed integer
    typedef unsigned int Uint32;    ///< Standard 32 bit unsigned integer
    
    // 64 bits integer types
#if defined(_MSC_VER)
    typedef signed   __int64 Int64;  ///< Standard 64 bit signed integer
    typedef unsigned __int64 Uint64; ///< Standard 64 bit unsigned integer
#else
    typedef int64_t          Int64;  ///< Standard 64 bit signed integer
    typedef uint64_t         Uint64; ///< Standard 64 bit unsigned integer
#endif
    
    // Declare State ID typedef which is used for identifying State objects
    typedef std::string stateID;
    
    /// Status Enumeration for Status Return values
    enum StatusType {
        // Values from -99 to 99 are common Error and Good status responses
        StatusAppMissingAsset = -4,  ///< Application failed due to missing asset file
        StatusAppStackEmpty   = -3,  ///< Application States stack is empty
        StatusAppInitFailed   = -2,  ///< Application initialization failed
        StatusError           = -1,  ///< General error status response
        StatusAppOK           =  0,  ///< Application quit without error
        StatusNoError         =  0,  ///< General no error status response
        StatusFalse           =  0,  ///< False status response
        StatusTrue            =  1,  ///< True status response
        StatusOK              =  1   ///< OK status response
        
        // Values from +-100 to +-199 are reserved for File status responses
    };
    
    // Forward declare interfaces provided
    class IState;
    
    // Forward declare classes provided
    class Game;
    class StateManager;
    
    // Forward declare GQE loggers provided
    class Logger;
    
    // Forward declare GQE states provided
    class GreenState;
}


#endif
