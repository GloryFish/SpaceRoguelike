//
//  SRDungeon.m
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/17/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#import "SRDungeon.h"


@implementation SRDungeon

-(id)init {
    if ((self = [super init])) {
        tiledMap = [[CCTMXTiledMap tiledMapWithTMXFile:@"DefaultTileset.tmx"] retain];
        [self addChild:tiledMap];
    }
    return self;
}


-(void)dealloc {
    [tiledMap release];
    [super dealloc];
}

@end
