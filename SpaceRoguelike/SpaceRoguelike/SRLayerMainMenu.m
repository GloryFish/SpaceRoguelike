//
//  SRLayerMainMenu.m
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/12/11.
//  Copyright GloryFish.org 2011. All rights reserved.
//


// Import the interfaces
#import "SRLayerMainMenu.h"

// HelloWorldLayer implementation
@implementation SRLayerMainMenu

+(CCScene *) scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'layer' is an autorelease object.
	SRLayerMainMenu *layer = [SRLayerMainMenu node];
	
	// add layer as a child to scene
	[scene addChild: layer];
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
-(id) init
{
	// always call "super" init
	// Apple recommends to re-assign "self" with the "super" return value
	if( (self=[super init])) {
		
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

// on "dealloc" you need to release all your retained objects
- (void) dealloc
{
	// in case you have something to dealloc, do it in this method
	// in this particular example nothing needs to be released.
	// cocos2d will automatically release all the children (Label)
	
	// don't forget to call "super dealloc"
	[super dealloc];
}
@end
