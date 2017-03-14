## git
1.什么是git?
* GIT 是一个分布式版本控制软件，最初由林纳斯·托瓦兹（Linus Torvalds）创作，于2005年以GPL发布。
最初目的是为更好地管理Linux内核开发而设计。是目前世界上最先进的分布式版本控制系统.
## git 安裝
ubuntu linux 安装方法
```sh
$ sudo apt-get install git
```
mac ox 安装方法
```sh
$ brew install git
```
## 创建git本地仓库
```sh
$ mkdir git 
$ cd git 
$ mkdir c
$ cd c
$ git init
```
## 增加一个新文件
1.复制已有文件到当前目录
```sh
cp ../../c/*.c .
```
2.创建一个新文件
```sh
$ touch hello.c
$ vim hello.c
```
查看当前目录下文件状态
```sh
$ git status
```
## 跟踪文件
```sh
$ git add hello.c
```
## 配置个人用户信息
为提交个人用户信息
```sh
$ git config --global user.name "XIAOJINHONG"
$ git config --global user.email "1870232639@qq.com"
$ git config --global core.editor vim
```
## 提交
想本地git仓库提交，跟踪文件
```sh
$ git commit
```
对文件进行描述
```sh
First commit
Init commit
```
## 查看提交信息
```sh
$ git log
```
```sh
第一行: commit ID
第二行：提交作者的名字和email 
第三行： 提交时间 
第四行： 提交信息标题
第五行： 提交信息具体内容
```
## 查看修改源码
1.修改原来建的文件hello.c
2.再查看一下文件的状态 
```sh
$ git status
```
3.查看修改源码
```sh
$ git diff
```
4. 两个提交版本之间作比较
```sh
$ git diff  commitID-1 commitID-2
```
6. 理解patch标记格式的含义
## 删除文件
1.删除文件后，恢复文件
```sh
$ rm -rf hello.c
$ git status
$ git checkout hello.c
2.从版本库里删除文件（真正删除文件）
```sh
$ git rm hello.c(or)rm hello.c
$ git status
$ git add
$ git add.
$ git commit
```
## 版本间切换
根据commitId可以进行版本切换
```sh
$ git reset --hard commitID
```
## 忽略文件
忽略不需要跟踪到git仓库里的文件
```sh
$ touch gitignore
$ vim .gitignore
-----
a.out
-----
$ git add
$ git commit
## github
1.注册github帐号
   注册邮箱注意不要使用qq邮箱
2.创建仓库
3.从github将创建的git仓库克隆到本地
```sh
$ git clone https://github.com/user.name/gitc.git
```
4.将本地仓库与github进行同步，将本地提交到服务器上
```.sh
$ git push origin master
input username:
input password:
```
5.更新本地仓库，与github仓库进行同步，将服务器提交拉取到本地
```sh
$ gitpull
```
## MarkDown
Markdown 是一种轻量级标记语言.
## Github MarkDown
Markdown 标记转成HTML的样式每个网站有自己的风格, 但整体的标记格式是统一的. 我们以github来保存相关的文档,
所以我们以github的为样式为标准.
## 标题使用#，
