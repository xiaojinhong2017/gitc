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
void CookieSet();
void LoadEnvironment();
void ShowForm();
void RadioButtons();
void SaveEnvironment();
void Name();
void Address();
void show();

int do_insert(int *id,char *name,int *score);
int do_delete(int *id);
int do_update(int *id,int *score);
int call_back(void *param, int column, char **value, char **name);
sqlite3 * db;

int cgiMain() {

  cgiHeaderContentType("text/html");
  fprintf(cgiOut, "<HTML><meta charset=\"UTF-8\"><HEAD>\n");
	fprintf(cgiOut, "<TITLE>cgic test</TITLE></HEAD>\n");
	fprintf(cgiOut, "<BODY><H1>cgic 测试</H1>\n");
	fprintf(cgiOut, "<body background=\"http://i1.piimg.com/1949/186dab395823b0cc.jpg\">");

  if ((cgiFormSubmitClicked("testcgic") == cgiFormSuccess) ||
		cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess)
	{
		HandleSubmit();
		fprintf(cgiOut, "<hr>\n");
  }

  ShowForm();
  fprintf(cgiOut, "</BODY></HTML>\n");
	return 0;
}
int HandleSubmit(){
  RadioButtons();
  Address();

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
	show();
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

	fprintf(cgiOut, "ID: ");
	cgiHtmlEscape(id);
	fprintf(cgiOut, "<br>\n");
	fprintf(cgiOut, "Name: ");
	cgiHtmlEscape(name);
	fprintf(cgiOut, "<br>\n");
	fprintf(cgiOut, "Score: ");
	cgiHtmlEscape(score);
	fprintf(cgiOut, "<br>\n");
	fprintf(cgiOut, "Delete ID: ");
	cgiHtmlEscape(delete);
	fprintf(cgiOut, "<br>\n");
	fprintf(cgiOut, "Update ID: ");
	cgiHtmlEscape(updateid);
	fprintf(cgiOut, "&nbsp;&nbsp;&nbsp;&nbsp;");
	fprintf(cgiOut, "Update score: ");
	cgiHtmlEscape(updates);
	fprintf(cgiOut, "<br>\n");

	do_insert(&idt,name,&scoret);
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
	if (cgiFormCheckboxSingle("showdata") == cgiFormSuccess){
		char *errmsg;
		char **result,**temp;
		int nrow,ncolumn;
		int i,j;
		if(sqlite3_get_table(db,"select * from stu",&result,&nrow,&ncolumn,&errmsg) != SQLITE_OK){
			printf("%s\n",errmsg);
		}
	  else{
			temp = result;
			fprintf(cgiOut, "数据库表格数据：");
			printf("<table border=\"15\" bgcolor=\"red\">");
			for(i = 0;i < nrow + 1;i++){
				printf("<tr>");
				for(j = 0;j < ncolumn;j++){
					printf("<td>%15s</td>",*(temp++));
				}
        printf("</tr>");
			}
			printf("</table>");
		}
		sqlite3_free_table(result);
  }
}


void Address() {
	char address[241];
  char add[241];
	cgiFormString("add", add, 241);
	cgiFormString("address", address, 241);
	fprintf(cgiOut, "<PRE>标题：\n");
  cgiHtmlEscape(add);
  fprintf(cgiOut, "<br>内容：\n");
	cgiHtmlEscape(address);
	fprintf(cgiOut, "</PRE>\n");
}
char *ages[] = {
	"1",
	"2",
	"3",
	"4"
};

void RadioButtons(){
	int ageChoice;
	char ageText[10];
  char si[32];
  char sl[32];
  int i,j,k;
  float n,m;
	cgiFormRadio("age", ages, 4, &ageChoice, 0);

  k = atoi(ages[ageChoice]);

  cgiFormString("int",si,32);
  i = atoi(si);
  cgiFormString("ints",sl,32);
  j = atoi(sl);

  if(k == 1){
    fprintf(cgiOut, "a + b = %d",i + j);
  }
  else if(k == 2){
    fprintf(cgiOut, "a - b = %d",i - j);
  }
  else if(k == 3){
    fprintf(cgiOut, "a * b = %d",i * j);
  }
  else if(k == 4){
    n = i;
    m = j;
    fprintf(cgiOut, "a / b = %f",n / m);
  }
}
void ShowForm()
{
	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
	fprintf(cgiOut, "	action=\"");
	cgiValueEscape(cgiScriptName);
	fprintf(cgiOut, "\">\n");
  fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "ID<input type=\"text\" name=\"id\">\n");
  fprintf(cgiOut, "Name<input type=\"text\" name=\"name\">\n");
  fprintf(cgiOut, "Score<input type=\"text\" name=\"score\">\n");
  fprintf(cgiOut, "<br>\n");
  fprintf(cgiOut, "Delete ID<input type=\"text\" name=\"delete\">\n");
  fprintf(cgiOut, "<br>\n");
  fprintf(cgiOut, "Update ID<input type=\"text\" name=\"updateid\">\n");
  fprintf(cgiOut, "Update score<input type=\"text\" name=\"updates\">\n");
  fprintf(cgiOut, "<br><br>\n");
	fprintf(cgiOut, "<input type=\"checkbox\" name=\"showdata\" value=\"Showdata\" checked>\n");
	fprintf(cgiOut, "<br>");
  fprintf(cgiOut, "a=:<input type=\"text\" name=\"int\">\n");
  fprintf(cgiOut, "<br>\n");
  fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"1\" checked>+\n");
  fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"2\">-\n");
  fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"3\">*\n");
  fprintf(cgiOut, "<input type=\"radio\" name=\"age\" value=\"4\">/\n");
  fprintf(cgiOut, "<br>\n");
  fprintf(cgiOut, "b=:<input type=\"text\" name=\"ints\">\n");
  fprintf(cgiOut, "<br><br>\n");
  fprintf(cgiOut, "标题：<input type=\"text\" name=\"add\">\n");
  fprintf(cgiOut, "<br>");
  fprintf(cgiOut, "内容：\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "<textarea NAME=\"address\" ROWS=4 COLS=40>\n");
	fprintf(cgiOut, "</textarea>\n");
  fprintf(cgiOut, "<input type=\"submit\" name=\"saveenvironment\" value=\"Save Environment\">\n");
  fprintf(cgiOut, "<br>");
  fprintf(cgiOut, "</form>\n");
}
