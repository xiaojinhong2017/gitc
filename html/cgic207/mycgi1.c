#if 1
#define SERVER_NAME cgiServerName
#endif
#if 0
#define SERVER_NAME "www.boutell.com"
#endif

#ifdef WIN32
#define SAVED_ENVIRONMENT "c:\\cgicsave.env"
#else
#define SAVED_ENVIRONMENT "/tmp/cgicsave.env"
#endif

#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int HandleSubmit();
void ShowForm();
void Name();
void show();

int do_insert(int *id,char *name,int *score);
int do_delete(int *id);
int do_update(int *id,int *score);
int call_back(void *param, int column, char **value, char **name);
sqlite3 * db;
int a,b,c,e,f;
int cgiMain() {

  cgiHeaderContentType("text/html");
  fprintf(cgiOut, "<HTML><meta charset=\"UTF-8\"><HEAD>\n");
  fprintf(cgiOut, "<style>.center{margin:auto;width:35%%;}</style>\n");//设置页面居中和div标签。
  fprintf(cgiOut, "<TITLE>学生管理系统</TITLE></HEAD>\n");
  fprintf(cgiOut, "<BODY text-align:center><h1 style=\"color:gainsboro;text-align:center;\">学生管理系统</h1>\n");//设置字体颜色居中。
  fprintf(cgiOut, "<body background=\"http://i2.buimg.com/1949/6dd97566eb0f50eb.jpg\">");//设置背景图片
  fprintf(cgiOut, "<body oncontextmenu=\"return false\" onselectstart=\"return false\">\n");//设置页面不能被复制。

  if(cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess){

    fprintf(cgiOut, "<font color=\"gainsboro\">");
    HandleSubmit();
    fprintf(cgiOut, "</font><hr>\n");
  }
  if(cgiFormSubmitClicked("showdata") == cgiFormSuccess){
    show();
  }
  if(cgiFormSubmitClicked("showdata") != cgiFormSuccess){

    ShowForm();
  }
  fprintf(cgiOut, "</BODY></HTML>\n");
  return 0;
}

int HandleSubmit(){
  int ret;
  char * errmsg;
  if(sqlite3_open("./db/my.db",&db) != SQLITE_OK){
    printf("%s\n",sqlite3_errmsg(db));
    return -1;
  }

  if((ret = sqlite3_exec(db,"create table stu(id integer,name vchar(32) not null,\
  score integer not null)",NULL,NULL,&errmsg)) != SQLITE_OK){

    if(ret != 1){
      printf("%s\n",errmsg);
      sqlite3_close(db);
      return -1;
    }
  }
  Name();
  sqlite3_close(db);
}

void Name(){
  char id[81];
  char name[81];
  char score[81];
  char delete[81];
  char updateid[81];
  char updates[81];
  int idt,scoret,deletet;
  int uid,uscore;
  char names;


  cgiFormStringNoNewlines("id", id, 81);
  cgiFormStringNoNewlines("name", name, 81);
  cgiFormStringNoNewlines("score", score, 81);
  cgiFormStringNoNewlines("delete", delete, 81);
  cgiFormStringNoNewlines("updateid", updateid, 81);
  cgiFormStringNoNewlines("updates", updates, 81);

  idt = atoi(id);
  scoret = atoi(score);
  deletet = atoi(delete);
  uid = atoi(updateid);
  uscore = atoi(updates);


  if((idt != 0) && (*name != 0)) {

    fprintf(cgiOut, "插入学号： ");
    cgiHtmlEscape(id);
    fprintf(cgiOut, "<br>\n");
    fprintf(cgiOut, "插入姓名： ");
    cgiHtmlEscape(name);
    fprintf(cgiOut, "<br>\n");
    fprintf(cgiOut, "插入成绩： ");
	  cgiHtmlEscape(score);
	  fprintf(cgiOut, "<br>\n");

    do_insert(&idt,name,&scoret);
    if(scoret == 0){
      c = 1;
    }
  }
  else{
    if(idt == 0){
      a = 1;
    }
    if(*name == 0){
      b = 1;
    }
  }
  if(deletet != 0){
	  fprintf(cgiOut, "已删除学号： ");
	  cgiHtmlEscape(delete);
	  fprintf(cgiOut, "<br>\n");
    a = 0;
    b = 0;
  }
/*  else{
    d = 1;
  }*/
  if(uid != 0){

	  fprintf(cgiOut, "学号: ");
	  cgiHtmlEscape(updateid);
	  fprintf(cgiOut, "<br>\n");
	  fprintf(cgiOut, "已修改成绩： ");
	  cgiHtmlEscape(updates);
	  fprintf(cgiOut, "<br>\n");
    a = 0;
    b = 0;
    if((uid != 0) && (uscore == 0)){
    f = 1;
    }
  }
  else if((uid == 0) && (uscore != 0)){
    a = 0;
    b = 0;
    e = 1;
  }
	  do_delete(&deletet);
	  do_update(&uid,&uscore);
}

int do_insert(int *id,char *name,int *score){
	char sql[1024];
  char * errmsg;

	sprintf(sql,"insert into stu values(%d,'%s',%d)",*id,name,*score);

	if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK){
    printf("%s\n",errmsg);

    return -1;
  }
}

int do_delete(int *id){
	char sql[1024];
	char * errmsg;

	sprintf(sql,"delete from stu where id = %d",*id);

  if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK){
    printf("%s\n",errmsg) ;
    return -1;
  }
}

int do_update(int *id,int *score){
	char sql[1024];
	char * errmsg;

	sprintf(sql,"update stu set score = %d where id = %d",*score,*id);

	if(sqlite3_exec(db,sql,NULL,NULL,&errmsg) != SQLITE_OK){
    printf("%s\n",errmsg);
    return -1;
  }
}

void show() {
	//if (cgiFormCheckboxSingle("showdata") == cgiFormSuccess)
    char *errmsg;
		char **result,**temp;
		int nrow,ncolumn;
		int i,j;
    int ret;
  	if(sqlite3_open("./db/my.db",&db) != SQLITE_OK){
  		printf("%s\n",sqlite3_errmsg(db));

  	}                        //创建数据库

  	/*if((ret = sqlite3_exec(db,"create table stu(id integer,name vchar(32) not null,\
  	score integer not null)",NULL,NULL,&errmsg)) != SQLITE_OK){

  		if(ret != 1){
  			printf("%s\n",errmsg);
  			sqlite3_close(db);

  		}
  	} */                      //创建表
		if(sqlite3_get_table(db,"select * from stu order by id",&result,&nrow,&ncolumn,&errmsg) != SQLITE_OK){
			printf("%s\n",errmsg);
		}
	  else{
			temp = result;
      fprintf(cgiOut, "<div class=\"center\">\n");
			fprintf(cgiOut, "<h2 style=\"color:lime\">学生成绩表格</h2>");
			printf("<table border=\"1\" bgcolor=\"red\" width=\"600\"");       //设置表格大小颜色
			for(i = 0;i < nrow + 1;i++){
				printf("<tr>");
				for(j = 0;j < ncolumn;j++){
					printf("<td align=\"center\"><h3>%15s</h3></td>",*(temp++));
				}
        printf("</tr>");
			}
			printf("</table>");
		}
		sqlite3_free_table(result);
	  sqlite3_close(db);
    fprintf(cgiOut, "<br>");
    fprintf(cgiOut, "<input type=\"button\" onclick=\"window.location.href=\'http://localhost/cgi-bin/mycgi1\'\" value=\"返回\">");           //设置链接按钮
    fprintf(cgiOut, "</div>\n");
}



void ShowForm()
{
//  fprintf(cgiOut, "<div class=\"center\">\n");
	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
	fprintf(cgiOut, "	action=\"");
	cgiValueEscape(cgiScriptName);
	fprintf(cgiOut, "\">\n");
  fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "<ol>\n");
  fprintf(cgiOut, "<font color=\"orangered\"><h2><li>插入数据</li></h2></font>");
  fprintf(cgiOut, "<font color=\"lime\">学号 :</font><input type=\"text\" name=\"id\" size=\"3\">\n");
  if(a == 1){fprintf(cgiOut, "<font style=\"color:red\">学号不能为0！</font>");}
  fprintf(cgiOut, "<br><br>\n");
  fprintf(cgiOut, "<font color=\"lime\">姓名 :</font><input type=\"text\" name=\"name\" size=\"3\">\n");
  if(b == 1){fprintf(cgiOut, "<font color=\"red\">姓名不能为空！</font>");}
  fprintf(cgiOut, "<br><br>\n");
  fprintf(cgiOut, "<font color=\"lime\">成绩 :</font><input type=\"text\" name=\"score\" size=\"3\">\n");
  if(c == 1){fprintf(cgiOut, "<font color=\"yellow\">成绩为空，默认为0！</font>");}
  fprintf(cgiOut, "<br><br>\n");
  fprintf(cgiOut, "<font color=\"orangered\"><h2><li>删除数据</li></h2></font>\n");
  fprintf(cgiOut, "<font color=\"lime\">学号 :</font><input type=\"text\" name=\"delete\" size=\"3\">\n");
//  if(d == 1){fprintf(cgiOut, "<font color=\"red\">ID不能为0！</font>");}
  fprintf(cgiOut, "<br>\n");
  fprintf(cgiOut, "<font color=\"orangered\"><h2><li>修改数据</li></h2></font>");
  fprintf(cgiOut, "<font color=\"lime\">学号 :</font><input type=\"text\" name=\"updateid\" size=\"3\">\n");
  if(e == 1){fprintf(cgiOut, "<font color=\"red\">学号不能为0！</font>");}
  fprintf(cgiOut, "<br><br>\n");
  fprintf(cgiOut, "<font color=\"lime\">成绩 :</font><input type=\"text\" name=\"updates\" size=\"3\">\n");
  if(f == 1){fprintf(cgiOut, "<font color=\"yellow\">成绩为空，默认为0！</font>");}
  fprintf(cgiOut, "</ol>\n");
	//fprintf(cgiOut, "<input type=\"checkbox\" name=\"showdata\" value=\"Showdata\" checked>\n");
	fprintf(cgiOut, "<br>");
  fprintf(cgiOut, "<input type=\"submit\" name=\"saveenvironment\" value=\"提交数据\" style=\"background:DarkOliveGreen;width:150px\">\n");
  fprintf(cgiOut, "<br>");
  fprintf(cgiOut, "<input type=\"submit\" name=\"showdata\" value=\"显示数据\" style=\"background:DarkOliveGreen;width:150px\">\n");
  fprintf(cgiOut, "<br>");
  fprintf(cgiOut, "</form>\n");
//  fprintf(cgiOut, "</div>");
}
