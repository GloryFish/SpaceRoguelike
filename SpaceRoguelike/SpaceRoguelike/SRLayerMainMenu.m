//
//  SRLayerMainMenu.m
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/12/11.
//  Copyright GloryFish.org 2011. All rights reserved.
//

#import "SpaceRoguelike.h"
#import "SRLayerMainMenu.h"

@implementation SRLayerMainMenu

+(CCScene *)scene {
	CCScene *scene = [CCScene node];
	SRLayerMainMenu *layer = [SRLayerMainMenu node];
	[scene addChild: layer];
	return scene;
}

-(id)init {
	if ((self = [super init])) {
		
		// create and initialize a Label
		CCLabelTTF *label = [CCLabelTTF labelWithString:@"SpaceRoguelike" fontName:@"Helvetica" fontSize:14];

		// ask director the the window size
		CGSize size = [[CCDirector sharedDirector] winSize];
	
		// position the label on the center of the screen
		label.position =  ccp(60, size.height - 20);
		
		// add the label as a child to this Layer
		[self addChild: label];
        
        
        CCMenuItemFont* itemTileTest = [CCMenuItemFont itemFromString:@"Tile Test" block:^(id sender){
            CCScene* scene = [SRLayerTileTest scene];
            [[CCDirector sharedDirector] replaceScene:[CCTransitionSlideInL transitionWithDuration:0.5 scene:scene]];
        }];
        itemTileTest.fontName = @"Helvetica";
        itemTileTest.fontSize = 18;
        
        // Menu
        CCMenu* menu = [CCMenu menuWithItems:itemTileTest, nil];
        
        [self addChild:menu];
	}
	return self;
}

-(void)dealloc {
	[super dealloc];
}

@end
