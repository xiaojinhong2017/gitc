#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

#define M 32
#define N 100

int do_update(sqlite3 *db);
int do_show(sqlite3 *db);
int do_delete(sqlite3 *db);
int do_insert(sqlite3 *db);
int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *errmsg;
    char clean[M];
    char buf[100] = {0};
    int cmd;
    if(sqlite3_open("./you.db",&db) != SQLITE_OK)
    {
        printf("%s\n", sqlite3_errmsg(db));
        return -1;
    }
    int ret;
    if((ret = sqlite3_exec(db, "create table stu(id integer,\
        name vchar(32) not null, score integer not null)", NULL, NULL, &errmsg)) != SQLITE_OK)
    {
        if(ret != 1)
        {
            printf("%s\n", errmsg);
            sqlite3_close(db);
            return -1;
        }
    }
      while(1)
      {
          printf("1 insert, 2 delete , 3 updata, 4 show \n");
         if(scanf("%d", &cmd) != 1)  
         {

             printf("%s", errmsg);
             fgets(clean, sizeof(clean), stdin);
             return -1;
             continue;
         }
         switch(cmd)
         {
         case 1: do_insert(db);
                 break;
         case 2: do_delete(db);
                 break;
         case 3: do_update(db);
                 break;
         case 4: do_show(db);
                 break;
         case 5: goto RET;
         default:
                 break;

         }
      }
RET:
      sqlite3_close(db);
      return 5;

    //do_update(db);
    //do_insert(db);
      //do_delete(db);
     // return 0;
}
int do_show(sqlite3 *db)
{
    char *errmsg;
    int a = 0;
    if(sqlite3_exec(db, "select *from stu", call_back, &a, &errmsg) != SQLITE_OK)
   {
        printf("%s\n", errmsg);
        return -1;
    }
    else{
        printf("\e[32mshow OK !\e[0m\n");
        return 0;
    }
}
    int call_back(void *para, int column, char **value, char **name)
    {

        int a;
        int i = 0;
        a = (*(int*)param)++;
        if (a == 0)
        {
            for(i = 0; i < column, cah)
        }
    }
}
int do_show(sqlite3 *db)
{
    int i, j;
    char **result, **temp;
    char *errmsg;
    int nrow;
    int nolumn;
    if(sqlite3_get_table(db, "select * from stu", &result, &nrow, &column, &errmsg)!= SQLITE_OK)
    {
       printf("%s\n",errmsg);
       return -1;
    }
    else
    {
        temp = result;
        for(i = 0; i < nrow + 1; i++)
        {
            for(j = 0; j < column; j++)
            {
            if(i == 0)
            {
                printf("\e[32m%-15s\e[0m", *(temp++));
            }
            else{
                printf("%-15s", *(temp++));
            }
            }
            putchar(10);
        }
    }
    sqlite3_free_table(result);
    printf("\e[32mshow ok !\e[0m\n");
    return 0;
}
int do_update(sqlite3 *db)
{
    int id;
    int score;
    char name[N];
    char *errmsg;
    char sql[N] = {0};
    printf("input id >");
    scanf("%d", &id);
    printf("input name >");
    scanf("%s", name);
    printf("input score >");
    scanf("%d", &score);
    sprintf(sql, "update stu set name = '%s', score = %d where id = %d" ,name , score, id);
    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
    {
        printf("%s\n", errmsg);
        return -1;
    }
    return 0;
}
int do_delete(sqlite3 *db)
{
    int id;
    char *errmsg;
    char sql[N] = {0};
    printf("input id >");
    scanf("%d", &id);
    sprintf(sql, "delete from stu where id = %d" , id);
    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
    {
        printf("%s\n", errmsg);
        return -1;
    }
    return 0;
}
int do_insert(sqlite3 *db)
{
    int id;
    char name[M] = {0};
    char sql[N] = {0};
    int score;
    char *errmsg;
    printf("input student id > ");
    scanf("%d", &id);
    printf("input student name >");
    scanf("%s", name);
    printf("input student score >");
    scanf("%d", &score);
    sprintf(sql, "insert into stu values(%d, '%s', %d)",id , name, score);
    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
    {
        printf("%s\n", errmsg);
        return -1;
    }
    return 0;
}
