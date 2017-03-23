# System函数
```sh

示例代码:
#include <stdib.h>

int system(const char *command);
功能: 就是执行一个命令
比如： system(" cp file newfile");
完成文件拷贝，简单讲就是在终端中的shell命令可以写在systen函数里
```
# Sprintf函数
```sh
函数功能：把格式化的数据写入某个字符串
函数原型： int sprintf（char *buffer,const char*format[argument]...);
返回值： 字符串长度 
```
例子：
```sh
cahar*who = "i";
char*whom = "APPLE";
sprints(s,"%s love %s", who, whom);//产生："i love APPLE"这字符串写到s中去;
sprints(s,"%10.3f",3.1415626);//产生："3.142"
```
# Sqlite
1.sqlite 是什么 ？

2.如何在ubantu上安装sqlite？

[安装sqlite网址](https://zhidao.baidu.com/question/2012470397387706188.html)

[基本命令网址](http://blog.csdn.net/u011192270/article/details/48031763)

[sqlite基本教程](http://www.w3school.com.cn/sql/sql_select.asp)

 
