//
//  SRLayerMainMenu.m
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/12/11.
//  Copyright GloryFish.org 2011. All rights reserved.
//

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
        
        
        CCMenuItemFont* testItem = [CCMenuItemFont itemFromString:@"Test Item" block:^(id sender){
            NSLog(@"Testing...");
        }];
        testItem.fontName = @"Helvetica";
        testItem.fontSize = 18;
        
        // Menu
        CCMenu* menu = [CCMenu menuWithItems:testItem, nil];
        
        [self addChild:menu];
	}
	return self;
}

-(void)dealloc {
	[super dealloc];
}

@end
