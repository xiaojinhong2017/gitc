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

int hand();
int hong();
void wen();
void show();
void guang();
void kong();
int a,b,c,d,e;

int cgiMain(){
  cgiHeaderContentType("text/html");
  fprintf(cgiOut, "<HTML><meta charset=\"UTF-8\"><HEAD>\n");
  fprintf(cgiOut, "<style>.center{margin:auto;width:15%%;}</style>\n");
  fprintf(cgiOut, "<TITLE>智能家具控制系统</TITLE></HEAD>\n");
  fprintf(cgiOut, "<BODY text-align:center><h1 style=\"color:gainsboro;text-align:center;\">基于STM32的智能家居控制系统</h1>\n");
  fprintf(cgiOut, "<body background=\"http://i2.muimg.com/1949/d57fe812894590e3.jpg\">");
  if(hong()){
    show();
  }
  else{
    fprintf(cgiOut,"<br><br><br><h1 align=center>");
    fprintf(cgiOut,"室内无人");
    fprintf(cgiOut,"</h1>");
  }

  fprintf(cgiOut, "</BODY></HTML>\n");
  return 0;
}

int hand(){
  /*int ret;
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
  }*/
  wen();
  fprintf(cgiOut,"<br>");
  guang();
  //sqlite3_close(db);
}

int hong(){
  int i = 1;
  if(i){
    return 1;
  }
  else{
    return 0;
  }
}

void wen(){
  char wen[81];
  int i;

  cgiFormString("wen",wen,81);
  i = atoi(wen);

  if(i >= 25){
    fprintf(cgiOut,"温度过高");
    b = 1;
  }
  else if(i <= 18){
    fprintf(cgiOut,"温度过低");
    b = 1;
  }
  else{
    fprintf(cgiOut,"温度正常");
  }
}

void guang(){
  char guang[81];
  int i;

  cgiFormString("guang",guang,81);
  i = atoi(guang);

  if(i > 15){
    fprintf(cgiOut,"亮度正常");
  }
  else{
    fprintf(cgiOut,"亮度较暗");
    c = 1;
  }
}

void kong(){
  char si[10];
  char st[10];
  char sd[10];

  cgiFormString("kong",si,10);
  cgiFormString("kongtiao",st,10);
  cgiFormString("deng",sd,10);

  a = atoi(si);
  d = atoi(st);
  e = atoi(sd);

  if(a == 1){
    if(b == 1){
      fprintf(cgiOut,"<h4 style=\"color:red\">是否打开空调：<br>");
      fprintf(cgiOut,"YES:<input type=\"radio\" name=\"kongtiao\" value=\"1\">");
      fprintf(cgiOut,"NO:<input type=\"radio\" name=\"kongtiao\" value=\"2\">");
      fprintf(cgiOut,"</h4>");
    }
    if(c == 1){
      fprintf(cgiOut,"<h4 style=\"color:red\">是否打开照明灯：<br>");
      fprintf(cgiOut,"YES:<input type=\"radio\" name=\"deng\" value=\"1\">");
      fprintf(cgiOut,"NO:<input type=\"radio\" name=\"deng\" value=\"2\">");
      fprintf(cgiOut,"</h4>");
    }
  }
}

void show(){
  fprintf(cgiOut, "<div class=\"center\">\n");
  fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
  fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
  fprintf(cgiOut, "	action=\"");
  cgiValueEscape(cgiScriptName);
  fprintf(cgiOut, "\">\n");
  fprintf(cgiOut, "<h2><font color=\"lime\">温度 :</font><input type=\"text\" name=\"wen\" size=\"3\"></h2>\n");
  if(cgiFormSubmitClicked("save") == cgiFormSuccess){
    wen();
  }
  fprintf(cgiOut,"<br>");
  fprintf(cgiOut, "<h2><font color=\"lime\">亮度 :</font><input type=\"text\" name=\"guang\" size=\"3\"></h2>\n");
  if(cgiFormSubmitClicked("save") == cgiFormSuccess){
    guang();
  }
  fprintf(cgiOut, "<br><br>");
  fprintf(cgiOut, "<h2>自动控制:<input type=\"radio\" name=\"kong\" value=\"0\"></h2>");
  fprintf(cgiOut, "<h2>手动控制:<input type=\"radio\" name=\"kong\" value=\"1\">");
  fprintf(cgiOut, "</h2>");
  if(cgiFormSubmitClicked("save") == cgiFormSuccess){
    kong();
    if(d == 1){
      fprintf(cgiOut,"开空调");
    }
    fprintf(cgiOut,"<br>");
    if(e == 1){
      fprintf(cgiOut,"打开灯");
    }
  }
  fprintf(cgiOut,"<br>");
  fprintf(cgiOut, "<input type=\"submit\" name=\"save\" value=\"查看\" style=\"background:DarkOliveGreen;width:150px\">\n");
  fprintf(cgiOut, "</form>\n");
  fprintf(cgiOut, "</div>");
}
