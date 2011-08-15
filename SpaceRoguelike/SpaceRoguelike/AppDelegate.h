//
//  AppDelegate.h
//  SpaceRoguelike
//
//  Created by Jay Roberts on 8/12/11.
//  Copyright GloryFish.org 2011. All rights reserved.
//

#import "cocos2d.h"

@interface SpaceRoguelikeAppDelegate : NSObject <NSApplicationDelegate>
{
	NSWindow	*window_;
	MacGLView	*glView_;
}

@property (assign) IBOutlet NSWindow	*window;
@property (assign) IBOutlet MacGLView	*glView;

- (IBAction)toggleFullScreen:(id)sender;

@end
