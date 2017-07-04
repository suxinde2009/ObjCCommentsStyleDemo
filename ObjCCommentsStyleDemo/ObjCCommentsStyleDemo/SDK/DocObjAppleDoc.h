//
//  DocObjA.h
//  ObjCCommentsStyleDemo
//
//  Created by suxinde on 2017/6/28.
//  Copyright © 2017年 com.skyprayer.comments.style. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DocObjDoxygen.h"

//-----------------------------------------------------
#pragma mark - 文件头注释 -
//-----------------------------------------------------
/**
 * @file	DocObjAppleDoc.h
 * @brief	主页面.
 * @author	sxd
 * @version	1.0
 * @date	2017-06-28
 *
 * # update （更新日志）
 *
 * [2017-06-28] <sxd> v1.0
 *
 * + v1.0版发布.
 *
 *
 */

//-----------------------------------------------------

//-----------------------------------------------------
#pragma mark - Overview注释 -
//-----------------------------------------------------

/** OverView注释
 *
 * OverView描述.
 *
 * 引用短代码, 如 `someMethodByStr:` .
 *
 * 示例代码:
 *
 * 	int sum=0;
 * 	for(int i=1; i<=10; ++i) {
 * 		sum += i;
 * 	}
 *
 * 无序列表:
 *
 * - abc
 * - xyz
 * - rgb
 *
 * 有序列表:
 *
 * 1. first.
 * 2. second.
 * 3. third.
 *
 * 多级列表:
 *
 * - xyz
 *	- x
 *	- y
 *	- z
 * - rgb
 *	- red
 *		1. first.
 *			1. alpha.
 *			2. beta.
 *		2. second.
 *		3. third.
 *	- green
 *	- blue
 *
 *
 * ------------------------------------------------------------
 * 以下是仅doxygen可见内容. 因为appledoc不支持`类型注释`中的\@see标签(但支持在`属性`、`方法`中使用)，会导致后续内容丢弃.
 *
 * @see str
 * @see someMethodByStr:
 * @see MyDocAppDelegate
 * @see [MyDocAppDelegate window]	// 仅 appledoc. doxygen仅能识别出左边的类名.
 * @see [MyDocAppDelegate someMethodByFloat:]	// 仅 appledoc. doxygen仅能识别出左边的类名.
 * @see MyDocAppDelegate.window	// 仅 doxygen. appledoc仅能识别出左边的类名.
 * @see MyDocAppDelegate.someMethodByFloat:	// 仅 doxygen. appledoc仅能识别出左边的类名.
 *
 * end.
 *
 */



/**
 该类用于说明仅AppleDoc支持及AppleDoc和Doxygen均支持的的注释类型
 */
@interface DocObjAppleDoc : NSObject

#pragma mark - property

/// 数值属性.
@property (nonatomic,assign) NSInteger num;

/** 字符串属性.
 *
 * 属性的详细描述.
 */
@property (nonatomic,strong) NSString* str;

/**
 数值属性.
 */
@property (nonatomic,assign) int dummy;


/// 枚举的属性.
@property (nonatomic, assign) ObjCDocEnum docType;

/// 结构体的属性.
@property (nonatomic, assign) RectInt rectInt;

/// 结构体常量指针的属性.
@property (nonatomic, assign) PCRectInt prectInt;

/// 联合体的属性.
@property (nonatomic, assign) FloatByte floatByte;

/// 委托.
@property (nonatomic, strong) id<MyDocDelegate> delegate;


/** 链接测试.
 *
 * 链接:
 *
 * - http://appledoc.gentlebytes.com/ : 直接写url链接.
 * - [Doxygen](http://www.stack.nl/~dimitri/doxygen/) : 为链接提供文本 .
 * - MyDocDelegate : 接口.
 * - DocA : 类.
 * - [文档B](DocB) : 类的链接文本.（仅appledoc）
 * - [文档B](@ref DocB) : 为\@ref链接提供文本 （仅doxygen. appledoc会把\@ref当作文本而生成错误的链接）.
 * - @ref DocB : \@ref链接 （仅doxygen. appledoc会把\@ref当作文本）.
 *
 * @see str
 * @see someMethodByStr:
 * @see MyDocAppDelegate
 * @see [MyDocAppDelegate window]	// 仅 appledoc. doxygen仅能识别出左边的类名.
 * @see [MyDocAppDelegate someMethodByFloat:]	// 仅 appledoc. doxygen仅能识别出左边的类名.
 * @see MyDocAppDelegate.window	// 仅 doxygen. appledoc仅能识别出左边的类名.
 * @see MyDocAppDelegate.someMethodByFloat:	// 仅 doxygen. appledoc仅能识别出左边的类名.
 */
@property (nonatomic,strong) NSString* alink;

/** 本地链接测试1 （仅appledoc）.
 *
 * 链接:
 *
 * - str : 自身属性.
 * - someMethodByStr: : 自身方法.
 * - DocViewController : 自身类.	// appledoc无法识别.
 * - MyDocAppDelegate : 外部类.
 */
@property (nonatomic,strong) NSString* alinklocal1;

/** 本地链接测试2 （仅appledoc）.
 *
 * 只要出现了 \[ 类 成员 \] 形式的链接, 本地链接便会生效.
 *
 * 链接:
 *
 * - str : 自身属性.
 * - someMethodByStr: : 自身方法.
 * - DocViewController : 自身类.	// appledoc无法识别.
 * - MyDocAppDelegate : 外部类.
 * - [DocViewController str] : 自身属性.
 */
@property (nonatomic,strong) NSString* alinklocal2;

/** 本地链接测试3 （仅appledoc）.
 *
 * 只要出现了 \[ 类 成员 \] 形式的链接, 本地链接便会生效.
 *
 * 链接:
 *
 * - str : 自身属性.
 * - someMethodByStr: : 自身方法.
 * - DocViewController : 自身类.	// appledoc无法识别.
 * - MyDocAppDelegate : 外部类.
 * - [MyDocAppDelegate window] : 外部类属性.
 * - [MyDocAppDelegate someMethodByFloat:] : 外部类方法.
 */
@property (nonatomic,strong) NSString* alinklocal3;


#pragma mark - method

/// 简单方法.
- (void)someMethod;

/**
 *	@brief	带整数参数的方法.
 *
 *	@param 	value	值.
 *
 *	@return	返回value.
 */
- (int)someMethodByInt:(int)value;

/**
 *	@brief	带字符串参数的方法.
 *
 *	@param 	value	值.
 *
 *	@return	返回value.
 *
 *	@exception NSException 可能抛出的异常.
 *
 *	@see someMethod
 *	@see someMethodByInt:
 *	
 *  @warning 警告: appledoc中显示为蓝色背景, Doxygen中显示为红色竖条.
 *	@bug 缺陷: appledoc中显示为黄色背景, Doxygen中显示为绿色竖条.
 */
- (NSString*)someMethodByStr:(NSString*)value;


/**
 *	@brief	取得静态变量值的类方法.
 *
 *	@return	返回_classInt静态变量的值.
 */
+ (int)classInt;


@end
