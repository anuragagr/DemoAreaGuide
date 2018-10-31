/**
 * Copyright (c) 2017 TomTom N.V. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom N.V. and its subsidiaries and may be used
 * for internal evaluation purposes or commercial use strictly subject to separate licensee
 * agreement between you and TomTom. If you are the licensee, you are only permitted to use
 * this Software in accordance with the terms of your license agreement. If you are not the
 * licensee then you are not authorised to use this software in any manner and should
 * immediately return it to TomTom N.V.
 */

#import <UIKit/UIKit.h>
#import <TomTomOnlineSDKMaps/TomTomOnlineSDKMaps.h>
#import "TTZoomView.h"
#import "TTPanControlView.h"

/**
 TTControlView representes transparent UIView which added on top of TTMapView
 can display compass and center button. Given buttons are displyed on fixed positions
 which can be adjust using exposed constraints.
 */
@interface TTControlView : UIView

/**
Initialize default compass button and adds it to UI.
 */
- (void)initDefaultCompassButton;

/**
 Initialize default center button and adds it to UI.
 */
- (void)initDefaultCenterButton;

/**
 Reference to TTMapView on which TTControlView should take control
 */
@property (nonatomic, weak) TTMapView *_Nullable mapView;

/**
 Contains reference to active comapss button.
 Can be used to change this button to custom.
 Binding with map will be done automatically under the hood.
 */
@property (nonatomic, weak) UIButton *_Nullable compassButton;

/**
 Contains reference to active center button.
 Can be used to change this button to custom.
 Binding with map will be done automatically under the hood.
 */
@property (nonatomic, weak) UIButton *_Nullable centerButton;

/**
 Contains reference to active zooming buttons.
 Binding with map will be done automatically under the hood.
 */
@property (nonatomic, weak) TTZoomView* _Nullable zoomView;


/**
Contains reference to active control buttons.
Binding with map will be done automatically under the hood.
 */
@property (nonatomic, weak) TTPanControlView * _Nullable controlView;

/**
 Initialize default zoom view and adds it to UI.
 */
-(void) initDefaultTTZoomView;

/**
 Initialize default control view and adds it to UI.
 */
- (void) initDefaultTTPanControlView;

/**
 UI compass and center buttons constraints
 */
@property (nonatomic, weak) NSLayoutConstraint *_Nullable leftLayoutConstraintCompassButton;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable topLayoutConstraintCompassButton;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable leftLayoutConstraintCenterButton;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable bottomLayoutConstraintCenterButton;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable rightLayoutConstraintTTZoomView;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable bottomLayoutConstraintTTZoomView;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable rightLayoutConstraintTTPanControlView;
@property (nonatomic, weak) NSLayoutConstraint *_Nullable bottomLayoutConstraintTTPanControlView;

@end
