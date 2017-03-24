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
# fgets函数
```sh
示例代码：
char *fgets(char *s, int size, FILE *stream);
功能： 就是一次读取一行，遇到'\n'就立刻返回。返回值为NULL时表示文件读取结束
参数：
s， 用于存放读取的字符串（传递数组名即可）   
size， 指定读取一次最多读取到的字节个数
stearm，直接填写stdin即可
比如： fgets(buf, 64, stdin);从标准输入读入一行
```
具体说明

[fgets网址](http://baike.baidu.com/link?url=hjGrGQplavP7w_O37jrzgpOy4UHFpQyTRLsnOJ4Hupg8Fv95oib_X7YKrF-tzAysrwddKdH9lD-G0X1nljDyv_)
# Sqlite
1.sqlite 是什么 ？

2.如何在ubantu上安装sqlite？

[安装sqlite网址](https://zhidao.baidu.com/question/2012470397387706188.html)

[基本命令网址](http://blog.csdn.net/u011192270/article/details/48031763)

[sqlite基本教程](http://www.w3school.com.cn/sql/sql_select.asp)

 
