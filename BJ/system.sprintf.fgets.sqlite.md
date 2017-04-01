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
## 教学目的

1.让你掌握sqlite的安装
2.让你掌握sqlite的常用命令
3.让你掌握sqlite的常用sql语句
4.让你掌握sprintf的拼接功能
5.让你掌握sqlite的C语言简单接口


## sqlite知识
1.sqlite 是什么 ？
2.查询如何在ubuntu中安装sqlite数据库(sudo apt-get install sqlite3)
3.如何在ubuntu的命令行中使用sqlite的命令进行数据库操作
数据库文件：sqlite中是以一个独立的文件存在，所有的数据都存储在该文件中 (sqlite3 数据库名称)
数据库表格：属于数据库文件中的一部分，表格是用于存储具体的数据
(数据库文件 > 数据库表格 > 具体数据)
4.学习sqlite常用命令.txt
5.在ubuntu中安装 C语言的sqlite3函数库

## 如何在ubantu上安装sqlite？

[安装sqlite网址](https://zhidao.baidu.com/question/2012470397387706188.html)

[基本命令网址](http://blog.csdn.net/u011192270/article/details/48031763)

[sqlite基本教程](http://www.w3school.com.cn/sql/sql_select.asp)

## 安装sqlite的语言库
```sh
1.sudo apt-get update
2.sudo apt-get install libsqlite3-dev sqlite3
检查是否安装成功： cd /usr/include 中查看是否有sqlite3.h文件
```
## sqlite基本命令


1.建数据库：
  sqlite3 test.db /*注意sqlite的版本*/

2.查看帮助：
  sqlite> .help

3.文件存放位置：
  sqlite> .database

4.退出：
  sqlite> .quit

5.查看表：
  sqlite> .tables

6.显示表的结构：
  sqlite> .schema
## sqlite3常见语句

1.创建表：
  sqlite> create table usr(id integer primary key, name text, age integer null, gender text,
  salary real not null);

2.删除表
  sqlite> drop table usr；

3.插入数据：
  sqlite> insert into usr(id, name, age, salary) values(2, ‘liu’, 20, 6000);

4.删除数据:
  sqlite> delete from usr where id = 2 and name = ‘lisi’；//删除一条记录

  sqlite> delete from usr where id = 2 or name = ‘lisi’；// and(与）or（或）

5.修改数据：
  sqlite> update usr set gender = ‘man’，name = ‘lisi’ where id = 3;

6.查询数据：
  sqlite> select * from usr where id = 2;

7.修改表的名称
  sqlite> alter table oldname rename to newname;

