//
//  SRLayerTileTest.m
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/15/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#import "SRLayerTileTest.h"


@implementation SRLayerTileTest

+(CCScene *)scene {
	CCScene *scene = [CCScene node];
	SRLayerTileTest *layer = [SRLayerTileTest node];
	[scene addChild: layer];
	return scene;
}

-(id)init {
	if ((self = [super init])) {
        
        CGSize size = [[CCDirector sharedDirector] winSize];

        CCLabelTTF* label = [CCLabelTTF labelWithString:@"Tile test" fontName:@"Helvetica" fontSize:12];
        label.position = ccp(size.width / 2, size.height / 2);
        [self addChild:label];
        
        CCTMXTiledMap* tiledMap = [CCTMXTiledMap tiledMapWithTMXFile:@"DefaultTileset.tmx"];
        [self addChild:tiledMap];
        
    }
    return self;
}

-(void)dealloc {
	[super dealloc];
}

@end
