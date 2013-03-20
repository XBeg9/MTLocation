//
//  MTLocateMeButton.h
//
//  Created by Matthias Tretter on 21.01.11.
//  Copyright (c) 2009-2012  Matthias Tretter, @myell0w. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "MTLocationDefines.h"

////////////////////////////////////////////////////////////////////////
#pragma mark - Customize Section
////////////////////////////////////////////////////////////////////////

// Background images
#define kMTLocationStatusIdleBackgroundImage						@"MTLocation.bundle/LocateMeButton"
#define kMTLocationStatusSearchingBackgroundImage					@"MTLocation.bundle/LocateMeButtonTrackingPressed"
#define kMTLocationStatusRecevingLocationUpdatesBackgroundImage     @"MTLocation.bundle/LocateMeButtonTrackingPressed"
#define kMTLocationStatusRecevingHeadingUpdatesBackgroundImage      @"MTLocation.bundle/LocateMeButtonTrackingPressed"

// foreground images
#define kMTLocationStatusIdleImage                      @"MTLocation.bundle/Location"
#define kMTLocationStatusRecevingLocationUpdatesImage	@"MTLocation.bundle/Location"
#define kMTLocationStatusRecevingHeadingUpdatesImage	@"MTLocation.bundle/LocationHeading"

// animation durations
#define kShrinkAnimationDuration            0.25
#define kExpandAnimationDuration            0.25
#define kExpandAnimationDelay               0.1

// size & insets
#define kWidthLandscape                     32.f
#define kHeightLandscape                    32.f

#define kActivityIndicatorInsetPortrait     6.f
#define kImageViewInsetPortrait             5.f

#define kActivityIndicatorInsetLandscape    8.f
#define kImageViewInsetLandscape            6.f


@protocol MTLocateMeButtonDelegate;


@interface MTLocateMeButton : UIButton

// Current Location-State of the Button
@property (nonatomic, assign) MTUserTrackingMode trackingMode;
@property (nonatomic, assign) BOOL headingEnabled;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, unsafe_unretained) id<MTLocateMeButtonDelegate> delegate;

// Images for different States
@property (nonatomic, strong) UIImage *idleBackgroundImage;
@property (nonatomic, strong) UIImage *searchingBackgroundImage;
@property (nonatomic, strong) UIImage *recevingLocationUpdatesBackgroundImage;
@property (nonatomic, strong) UIImage *recevingHeadingUpdatesBackgroundImage;

// Icons for states
@property (nonatomic, strong) UIImage *statusIdleImage;
@property (nonatomic, strong) UIImage *statusRecevingLocationUpdatesImage;
@property (nonatomic, strong) UIImage *statusRecevingHeadingUpdatesImage;

/** default to white, only works on iOS 5 and up */
@property (nonatomic, strong) UIColor *activityIndicatorColor;

- (void)setTrackingMode:(MTUserTrackingMode)trackingMode animated:(BOOL)animated;
// sets the right frame when used in a UINavigationBar for portrait/landscape
- (void)setFrameForInterfaceOrientation:(UIInterfaceOrientation)orientation;

- (void)updateUI;

@end


@protocol MTLocateMeButtonDelegate <NSObject>

- (void)locateMeButton:(MTLocateMeButton *)locateMeButton didChangeTrackingMode:(MTUserTrackingMode)trackingMode;

@end