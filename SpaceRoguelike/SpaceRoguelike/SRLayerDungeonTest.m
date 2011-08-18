//
//  SRLayerDungeonTest.m
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/17/11.
//  Copyright 2011 GloryFish.org. All rights reserved.
//

#import "SRLayerDungeonTest.h"


@implementation SRLayerDungeonTest

+(CCScene *)scene {
	CCScene *scene = [CCScene node];
	SRLayerDungeonTest *layer = [SRLayerDungeonTest node];
	[scene addChild: layer];
	return scene;
}

-(id)init {
	if ((self = [super init])) {
        
        CGSize size = [[CCDirector sharedDirector] winSize];
        
        CCLabelTTF* label = [CCLabelTTF labelWithString:@"Dungeon test" fontName:@"Helvetica" fontSize:12];
        label.position = ccp(60, size.height - 20);
        [self addChild:label];
        
        dungeon = [[SRDungeon alloc] init];
        [self addChild:dungeon];
        
    }
    return self;
}

-(void)dealloc {
    [dungeon release];
	[super dealloc];
}


@end
