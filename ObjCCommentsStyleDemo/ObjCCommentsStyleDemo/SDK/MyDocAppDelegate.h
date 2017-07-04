//
//  MyDocAppDelegate.h
//  ObjCCommentsStyleDemo
//
//  Created by suxinde on 2017/6/28.
//  Copyright © 2017年 com.skyprayer.comments.style. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface MyDocAppDelegate : NSObject

/// 主窗口.
@property (strong, nonatomic) UIWindow *window;


/**
 *	@brief	带浮点数参数的方法.
 *
 *	@param 	value	值.
 *
 *	@return	返回value.
 */
- (float)someMethodByFloat:(float)value;


@end
