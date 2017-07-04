//
//  DocObjB.h
//  ObjCCommentsStyleDemo
//
//  Created by suxinde on 2017/6/28.
//  Copyright © 2017年 com.skyprayer.comments.style. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MyDocDelegate.h"

#pragma mark - 仅Doxygen支持的注释类型 -

#define BUFSIZE	100	//!< 缓冲区大小 （简单宏, 仅Doxygen）.

/**
 *	@brief	最小值 （参数宏, 仅Doxygen）.
 *
 *	@param 	a 	值a.
 *	@param 	b 	值b.
 *
 *	@return	返回两者中的最小值.
 */
#define min(a,b)	( ((a)<(b)) ? (a) : (b) )

/// Objective-C 文档工具枚举 （枚举, 仅Doxygen）.
typedef enum _ObjCDocEnum {
    ObjCDocEnumAppleDoc = 1,	//!< AppleDoc. http://appledoc.gentlebytes.com/ .
    ObjCDocEnumDoxygen,	//!< Doxygen. http://www.stack.nl/~dimitri/doxygen/ .
} ObjCDocEnum;


/** 整数矩形 （结构体, 仅Doxygen）.
 *
 * 结构体的详细描述.
 */
typedef struct _RectInt {
    int x;	//!< 横坐标.
    int y;	//!< 纵坐标.
    int width;	//!< 宽度.
    int height;	//!< 高度.
}RectInt, *PRectInt;	//!< 整数矩形的指针.
typedef const RectInt* PCRectInt;	//!< 整数矩形的常量指针.

/// 浮点数的字节（联合体, 仅Doxygen）.
typedef union _FloatByte {
    float f;	//!< 单精度浮点数.
    unsigned char bytes[4];	//!< 4个字节.
} FloatByte;


/**
 *	@brief	动作回调函数.
 *
 *	@param 	sender 	发送者.
 *	@param 	userdata 	自定义数据.
 */
typedef void (*ActionCallback)(void* sender, void* userdata);


/**
 *	@brief	动作块函数.
 *
 *	@param 	sender 	发送者.
 *	@param 	userdata 	自定义数据.
 */
typedef void (^ActionHandler)(id sender, id userdata);

#pragma mark -

/**
 该类用于说明仅Doxygen支持的注释类型
 
 - 说明：目前Appledoc 不支持 `宏定义`,`struct`, `union`, `enum`, `funciton`等类型的文档注释
 */
@interface DocObjDoxygen : NSObject  {
@private
    int _privateInt;	//!< 私有成员变量 (仅Doxygen具有`EXTRACT_PRIVATE`标识时, 会被归类为“Private 属性”).
    
@protected
    int _protectedInt;	//!< protected成员变量 (仅Doxygen, 会被归类为“Protected 属性”).
    id<MyDocDelegate> _delegate;	//!< 委托变量.
    
@package
    int _packageInt;	//!< 包内成员变量 (仅Doxygen, 会被归类为“Protected 属性”).
    
@public
    int _publicInt;	//!< 公开成员变量 (仅Doxygen, 会被归类为“Public 属性”).
}

#pragma mark - 测试行尾注释.
// 测试行尾注释.
@property (nonatomic,strong) NSString* strend1;	/**< 行尾注释1. appledoc不支持会变为下一项的注释, doxygen 支持, 根据英文句号自动切分详细描述与详细描述. */
@property (nonatomic,strong) NSString* strend2;	/*!< 行尾注释2. appledoc不支持会变为下一项的注释, doxygen 支持, 会全部当作详细描述, 而缺少详细描述. */
@property (nonatomic,strong) NSString* strend3;	///< 行尾注释3. appledoc不支持会变为下一项的注释, doxygen 支持.
@property (nonatomic,strong) NSString* strend4;	//!< 行尾注释4. appledoc不支持会会忽略, doxygen 支持.

@end
