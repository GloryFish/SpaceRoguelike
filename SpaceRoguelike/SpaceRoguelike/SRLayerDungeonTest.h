//
//  SRLayerDungeonTest.h
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/17/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

#import "SpaceRoguelike.h"

@interface SRLayerDungeonTest : CCLayer {
    SRDungeon* dungeon;
}

+(CCScene *)scene;

@end
