# Objective-C代码注释规范

##### 工具简介
- appledoc：简单方便，适于生成apple风格的html文档，及直接集成到xcode帮助（docset）。官网 http://gentlebytes.com/appledoc/ 。
- doxygen：功能强大，适于生成html文档与pdf文档。官网 http://www.stack.nl/~dimitri/doxygen/index.html 。

### 注释写法
提示：这一章主要是参考性内容，比较枯燥。请根据需要来阅读——
对于想简单学一下注释写法的，读前4节就行了；
对于想全面学习appledoc与doxygen均兼容的注释写法的，读前6节就行了；
对于既想使用appledoc，又想使用doxygen增强效果的，请阅读所有的节。

##### 1.1 注释形式

标准C/C++的注释形式有“//”形式的单行注释 与“/* */”形式的多行注释这两种。
　　而appledoc与doxygen的文档化注释是它们的变种，有多种形式。例如appledoc与doxygen均兼容的注释形式有以下7种

	/// Single line comment.
	
	/// Single line comment spreading
	/// over multiple lines.
	
	/** Single line comment. */
	
	/** Single line comment spreading
	 * over multiple lines.
	 */
	
	/** Single line comment spreading
	 over multiple lines. No star.
	 */
	
	/*! Single line comment. */
	
	/*! Single line comment spreading
	 over multiple lines.
	 */
 
 虽然appledoc与doxygen都支持。但在平时编写代码时，为了避免风格杂乱的视觉污染，应该固定使用注释形式。
 
##### 1.1.1 单行注释

在很多时候只需写一个简要描述就够了，这时最好使用单行注释。推荐格式为——

	/// 简要描述.
	
appledoc与doxygen均会将单行的“///”注释识别为简要描述。兼容性非常高。


备注——

1) 文本最好统一以英文句号（.）结尾。这样做有助于代码阅读，明确地得知该段文本已经结束，而且有助于避免乱码时的换行符丢失问题。

2) 不要连续多行使用“///”。doxygen在默认情况下，会将多行的“///”当作详细描述，而没有简要注释. 虽然可以修改doxygen的配置以解决上述问题，但多行“///”本身是违背“简要描述”这个初衷的.

##### 1.1.2 多行注释
当需要写详细描述时，这时就需要使用多行注释了。推荐格式为——


	/** 
	 * 简要描述.
	 *
	 * 详细描述或其他.
	 */
	 
对于appledoc与使用了JAVADOC_AUTOBRIEF参数的doxygen来说，它们均会将注释中的第一段识别为简要描述，然后将后面的段识别为详细描述.

　　其实doxygen的标准多行注释为——
　　

	/**
	 * @brief 简要描述.
	 *
	 * 详细描述或其他.
	 */

`可惜appledoc对@brief指令的支持存在缺陷——@brief不能出现类、协议的注释中，会导致后续内容丢失。 @brief多行注释仅能安全的用在属性、方法的注释中。`

　　备注——
1) 多行注释存在“段”的概念，以内容为空的行作为分段依据。如果没有空行隔开的话，会将连续有内容的行连接起来组成一段.
2) 如果省略中间各行行首的星号（*），appledoc与doxygen也能识别。当考虑到注释缩进、美观性、兼容性，还是建议不要省略行首星号。
##### 1.1.3 行尾注释（仅doxygen）

　　`在对枚举、结构体等类型的成员进行注释时，为了使内容更加紧凑，我们一般喜欢在行尾写注释。
　　可惜目前仅有doxygen支持行尾注释，而appledoc不支持。`

　　doxygen支持以下4种行尾注释——

	/**< 行尾注释1. appledoc不支持会变为下一项的注释, doxygen 支持, 根据英文句号自动切分简要描述与详细描述. */
	/*!< 行尾注释2. appledoc不支持会变为下一项的注释, doxygen 支持, 会全部当作详细描述, 而缺少简要描述. */
	///< 行尾注释3. appledoc不支持会变为下一项的注释, doxygen 支持.
	//!< 行尾注释4. appledoc不支持会会忽略, doxygen 支持.

　　为了避免appledoc误将行尾注释当作下一项的注释，故推荐第4种注释——既以“//!<”开头的注释。

#### 1.2 类（协议、分类）的注释

　　对于类（协议、分类）来说，一般只需要写简要描述就行了，这时可以使用单行注释——

	/// 文档A.
	@interface DocA : NSObject

 

　　当需要留下详细描述时，可换成多行注释——

	/** 
	 * 文档B.
	 *
	 * 文档B的详细描述.
	 */
	@interface DocB : NSObject

 

#### 1.3 属性的注释

　　对于属性来说，本来使用行尾注释是最好的，能使内容更加紧凑。可惜目前appledoc不支持行尾注释。只好退而求其次，选择单行注释了——

	/// 数值属性.
	@property (nonatomic,assign) NSInteger num;

 

　　当需要留下详细描述时，可换成多行注释——

	/**
	 * @brief 字符串属性.
	 *
	 * 属性的详细描述.
	 */
	@property (nonatomic,strong) NSString* str;

 

#### 1.4 方法的注释

　　对于没有参数、返回值的简单方法，可以使用单行注释——

	/// 简单方法.
	- (void)someMethod;

 

　　若方法具有参数或返回值，这时就得使用多行注释了——


	/**
	 * 带整数参数的方法.
	 *
	 * @param  value 值.
	 *
	 * @return 返回value.
	 */
	- (int)someMethodByInt:(int)value;



　　指令说明——
　　
	@param <name> <description>: 参数描述.
	@return <description>: 返回值描述.

　　由于方法注释需要填写的内容较多（参数列表与返回值等），所以现在有很多插件可以帮忙生成方法的注释，而这些插件一般是使用@brief多行注释的。例如参考文献中的《Xcode4快速Doxygen文档注释 — 简明图文教程（3分钟后爽歪歪）》.

　　在某些时候，我们还需要在方法注释种填写异常、参见、警告 等信息——


	/**
	 * @brief 带字符串参数的方法.
	 *
	 * @param  value 值.
	 *
	 * @return 返回value.
	 *
	 * @exception NSException 可能抛出的异常.
	 *
	 * @see someMethod
	 * @see someMethodByInt:
	 * @warning 警告: appledoc中显示为蓝色背景, Doxygen中显示为红色竖条.
	 * @bug 缺陷: appledoc中显示为黄色背景, Doxygen中显示为绿色竖条.
	 */
	- (NSString*)someMethodByStr:(NSString*)value;


　　指令说明——


		@exception <name> <description>: 异常描述.
		@see <name>: 参见. 具体用法详见 1.5.2 @see、@sa（参见） .
		@warning <text>: 警告.
		@bug <text>: 警告.

#### 1.5 appledoc、doxygen均支持的指令

　　指令一般以“@”开头，也可以使用“\”等符号开头。 若想在文本中使用“@”、“\”等符号，可使用“\”转义符，例如“\@”、“\\”等。
##### 1.5.1 指令列表

　　指令在appledoc中被称作“Directive”，而在doxygen中被称作“Command”。appledoc没有专门指令参考文档，仅在《Comments formatting style》中给了几个简单示例。而doxygen有详细的指令参考文档，详见《Special Commands》。

　　经过测试，下列指令在appledoc与doxygen中均是有效的——
　　

	　　/**
		* @brief <title>: 简要注释. appledoc中仅对属性、方法有效，对类、协议 无效，会造成后续内容解析失败. 
		* @param <name> <description>: 参数描述.
		* @return <description>: 返回值描述.
		* @exception <name> <description>: 异常描述.
		* @see <name>: 参见.
		* @sa <name>: 参见. 同@see.
		* @warning <text>: 警告.
		* @bug <text>: 警告.
		* @name <title>: 组名. 用于给成员们分组, 既文档中Tasks区的子类别.
		*/


##### 1.5.2 @see、@sa（参见）

　　参见指令的格式为——
	
	@see <name>
	@sa <name>

　　在保证appledoc与doxygen均兼容的情况下，<name>可为——

1) 当前类（或协议）中的属性或方法。（注意Objective-C方法签名的写法，一般为“方法名:参数1:参数2:⋯⋯”的格式）
	
2) 类（或协议）名。（注意appledoc不支持当前类）

　　虽然appledoc与doxygen都支持参见“其他类或协议中的成员”，可惜它们的写法不同，而且相互不兼容——
appledoc：使用Objective-C消息语法，既`“[类 成员]”`格式。
doxygen：使用传统的对象成员访问语法，既`“类.成员”`格式。

　　注意本指令与@brief指令存在同样的问题——appledoc中仅对属性、方法有效，对类、协议 无效，会造成后续内容解析失败。 这时有两种处理策略——
1) 将参见指令放在注释的最后面，避免内容丢失，且能保证在doxygen中的效果.
2) 使用链接来代替参见。详见 1.6.4 链接。

#### 1.6 appledoc、doxygen均支持的排版格式

　　无格式的纯文本看起来比较费劲，得进行格式排版，以提高文档的组织性与表现力。appledoc与doxygen均有自己的一套约定——
appledoc可参考《Comments formatting style》。
doxygen可参考《Markdown support》。

　　本节将会介绍appledoc与doxygen均支持的排版格式。
　　
##### 1.6.1 代码文本

　　有时需要在一段话中引入一小段代码，这时可以用重音符（`）将那一段代码给包起来。例如——

	/**
	 * 引用短代码, 如 `someMethodByStr:` .
	 */

 

##### 1.6.2 代码块

　　代码块适用于需要在注释中放置多行代码的情况。具体办法是在每行内容的前面加一个tab字符，例如——


	/**
	 * 示例代码:
	 *
	 *     int sum=0;
	 *     for(int i=1; i<=10; ++i) {
	 *         sum += i;
	 *     }
	 */





　　因为空格与Tab字符均显示为空白，不易区分。于是用<space>、<tab>表达空格与tab字符，上述注释实际为——


	/**
	<space>*<space>示例代码:
	<space>*
	<space>*<space><tab>int sum=0;
	<space>*<space><tab>for(int i=1; i<=10; ++i) {
	<space>*<space><tab><tab>sum += i;
	<space>*<space><tab>}
	<space>*/

 

　　因每行注释开始的星号（*）与内容之间必须用空白型字符隔开，所以平时用空格或tab字符都行。但在使用代码块时，为了避免对Tab字符的误判，内容最好严格以“<space><tab>”开头（既每行以“<space>*<space><tab>”开头）。

　　备注——

1) 注意段的概念，代码块与前后文本之间应该空开一行。

2) appledoc与doxygen还支持将4个空格当作一个tab字符。但4个字符的录入、维护起来会更费力一些，不推荐使用。

##### 1.6.2.1 xcode中输入代码块

　　在xcode中，按下Tab键时，会自动整合前面的空格字符，导致代码块排版失效。所以建议先在多行注释中粘贴代码，然后在行前输入“*<space><tab>”。范例如下——

　　首先，最初的注释是这样的——

	/**
	 * @brief    简要描述.
	 *
	 * 详细描述或其他.
	 */

 

　　第一步，在多行注释中粘贴代码，注意xcode会自动对新粘贴内容进行排版，在每一行的前面加一个空格——

	/**
	 * @brief    简要描述.
	 *
	 * 详细描述或其他.
	 int sum=0;
	 for(int i=1; i<=10; ++i) {
	     sum += i;
	 }
	 */

　　第二步，补齐行首。复制“*<space><tab>”，对于先前所粘贴的那段代码，在每一行的第二个字符处粘贴，以形成“<space>*<space><tab>”开头的代码块格式——


	/**
	 * @brief    简要描述.
	 *
	 * 详细描述或其他.
	 *     int sum=0;
	 *     for(int i=1; i<=10; ++i) {
	 *         sum += i;
	 *     }
	 */


　　第三步，修尾。增加空行，增加“代码:”行，提示下面是代码——


	/**
	 * @brief    简要描述.
	 *
	 * 详细描述或其他.
	 *
	 * 代码:
	 *
	 *     int sum=0;
	 *     for(int i=1; i<=10; ++i) {
	 *         sum += i;
	 *     }
	 */



 

1.6.3 列表
1.6.3.1 无序列表

　　在内容的每一行开头使用“-”、“+”或“*”字符，可创建无序列表。例如——
复制代码

/**
 * 无序列表:
 *
 * - abc
 * - xyz
 * - rgb
 */

复制代码

 
1.6.3.2 有序列表

　　使用数字与小数点，可创建有序列表。例如——
复制代码

/**
 * 有序列表:
 *
 * 1. first.
 * 2. second.
 * 3. third.
 */

复制代码

 
1.6.3.3 多级列表

　　使用tab字符配合使用无序列表或多级列表，可创建多级列表。例如——
复制代码

/**
 * 多级列表:
 *
 * - xyz
 *    - x
 *    - y
 *    - z
 * - rgb
 *    - red
 *        1. first.
 *            1. alpha.
 *            2. beta.
 *        2. second.
 *        3. third.
 *    - green
 *    - blue
 */

复制代码

 

1.6.4 链接

　　链接有三种形式——
1) 直接链接。格式为 <link>。会将链接地址直接作为文本来显示。
2) 文本链接。格式为 [text](<link>)。使用自定义的文本作为链接名。
3) 交叉引用链接。比较复杂，且难以兼容appledoc与doxygen，故本文不讨论。
1.6.4.1 Url

　　在注释中直接写上url便会自动创建链接，例如——

/**
 * http://appledoc.gentlebytes.com/ : 直接写url链接.
 */

 

　　还可以使用文本链接形式——

/**
 * [Doxygen](http://www.stack.nl/~dimitri/doxygen/) : 为链接提供文本 .
 */

 
1.6.4.2 类与协议

　　在注释中直接写上类（或协议）名，并注意左右两侧留空格，appledoc与doxygen便会自动生成指向该类（或协议）的链接。例如——

/**
 * DocA : 类.
 */

 

　　但对于文本链接来说，appledoc与doxygen的写法不同——

/**
 * - [文档B](DocB) : 类的链接文本.（仅appledoc）
 * - [文档B](@ref DocB) : 为\@ref链接提供文本 （仅doxygen. appledoc会把\@ref当作文本而生成错误的链接）.
 */

 

　　建议还是使用直接链接吧。
1.6.4.3 属性与方法（仅appledoc）

　　如果注释中出现了 [类 成员]，appledoc会自动的为其创建链接，但doxygen不支持此功能。

　　如果注释中出现当前类的属性或方法名，appledoc会自动的为其创建链接，但doxygen不支持此功能。而且appledoc还存在Bug——如果在同一片注释中出现了[类 成员]，那么当前类的的属性或方法的链接会失效。

　　这么不稳定的功能还是暂时别用吧。

1.7 常用的doxygen注释示例

　　doxygen的注释功能多的令人眼花缭乱，这里还是介绍几种常用写法吧。
1.7.1 文件头

　　一般格式为——


	/**
	 * @file    MyDocViewController.h
	 * @brief    主页面.
	 * @author    [zyl910](http://www.cnblogs.com/zyl910/)
	 * @version    1.0
	 * @date    2013-06-07
	 *
	 * # update （更新日志）
	 *
	 * [2013-06-07] <zyl910> v1.0
	 *
	 * + v1.0版发布.
	 *
	 */

　　指令说明——
　　
　　~~~
　　
	/**
	* @file [<name>]：文件名.
	* @author <list of authors>：作者. 这里我使用了链接，详见 1.6.4 链接 .
	* @version <version number>：版本号.
	* @date <date description>：日期.
	*/
    ~~~
    
　　以井号（#）开头的行表示是标题。如果有1个井号（#），表示是一级标题。如果有2个井号（##），表示是二级标题，以此类推。
1.7.2 枚举、结构体、联合体与typedef

　　对于枚举、结构体、联合体等类型，一般可选用单行注释或多行注释。对于其中的成员，推荐使用行尾注释。例如——


	/// Objective-C 文档工具枚举 （枚举, 仅Doxygen）.
	typedef enum _ObjCDocToolEnum{
	    ObjCDocToolEnumAppleDoc = 1,    //!< AppleDoc. http://appledoc.gentlebytes.com/ .
	    ObjCDocToolEnumDoxygen,    //!< Doxygen. http://www.stack.nl/~dimitri/doxygen/ .
	}ObjCDocToolEnum;
	
	
	/** 整数矩形 （结构体, 仅Doxygen）.
	 *
	 * 结构体的详细描述.
	 */
	typedef struct _RectInt {
	    int x;    //!< 横坐标.
	    int y;    //!< 纵坐标.
	    int width;    //!< 宽度.
	    int height;    //!< 高度.
	}RectInt, *PRectInt;    //!< 整数矩形的指针.
	typedef const RectInt* PCRectInt;    //!< 整数矩形的常量指针.
	
	
	/// 浮点数的字节（联合体, 仅Doxygen）.
	typedef union _FloatByte {
	    float f;    //!< 单精度浮点数.
	    unsigned char bytes[4];    //!< 4个字节.
	} FloatByte;



 　　注意行尾注释是对前一项的注释，所以一定要使用分号（;）或逗号（,）标明本项成员定义好后，再写行尾注释。包括最后一个成员。

　　在定义结构体时，一般还需要定义其相关的指针类型与常量指针类型——
定义指针类型时，可以跟结构体的定义写在一起，利用行尾注释的特点来注释。
定义常量指针类型时，需要单独写一行typedef，并使用行尾注释。

1.7.3 宏

　　对于常量形式的简单宏，推荐使用行尾注释。例如——

	#define BUFSIZE    100    //!< 缓冲区大小 （简单宏, 仅Doxygen）.

 

　　对于带参数的宏，可参考“方法的注释”写多行注释。例如——


	/**
	 *    @brief    最小值 （参数宏, 仅Doxygen）.
	 *
	 *    @param     a     值a.
	 *    @param     b     值b.
	 *
	 *    @return    返回两者中的最小值.
	 */
	#define min(a,b)    ( ((a)<(b)) ? (a) : (b) )



 

1.7.4 函数指针与块函数（Block Objects）

　　对于函数指针与块函数，也可参考“方法的注释”写多行注释。例如——

	/**
	 *    @brief    动作回调函数.
	 *
	 *    @param     sender     发送者.
	 *    @param     userdata     自定义数据.
	 */
	typedef void (*ActionCallback)(void* sender, void* userdata);
	
	
	/**
	 *    @brief    动作块函数.
	 *
	 *    @param     sender     发送者.
	 *    @param     userdata     自定义数据.
	 */
	typedef void (^ActionHandler)(id sender, id userdata);



 
1.7.5 成员变量

　　对于成员变量，推荐使用行尾注释。例如——


	@interface MyDocViewController : UIViewController {
	    @private
	    int _privateInt;    //!< 私有成员变量 (仅Doxygen具有EXTRACT_PRIVATE标识时, 会被归类为“Private 属性”).
	    
	    @protected
	    int _protectedInt;    //!< protected成员变量 (仅Doxygen, 会被归类为“Protected 属性”).
	    id<MyDocDelegate> _delegate;    //!< 委托变量.
	    
	    @package
	    int _packageInt;    //!< 包内成员变量 (仅Doxygen, 会被归类为“Protected 属性”).
	    
	    @public
	    int _publicInt;    //!< 公开成员变量 (仅Doxygen, 会被归类为“Public 属性”).
	}



 





