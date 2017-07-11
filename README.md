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
