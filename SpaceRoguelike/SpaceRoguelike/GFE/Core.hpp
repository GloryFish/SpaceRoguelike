//
//  Core.hpp
//  SpaceRoguelike
//
//  Created by Jay Roberts on 9/7/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#ifndef SpaceRoguelike_Core_hpp
#define SpaceRoguelike_Core_hpp

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

#include "Logger.hpp"
#include "Game.hpp"


#endif
