#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int book_id;
    float price;
    char name[100];
}BOOK;
typedef struct node{
    BOOK data;
    struct node *next;
    struct node *prior;
}linknode,*linklist;

linklist create();
int delete(linklist h,int i);
int head_insert(linklist h, BOOK value);
void show(linklist h);
int main(void)
{
    linklist h = NULL;
    if((h=create())==NULL)
    {
        printf("create failed\n");
    }
    BOOK book1 = {1,3,"c" };
    head_insert(h,book1);
   // delete(h, 1);
    show(h);
    return 0;
}
linklist create(){
    linklist p = NULL;
    if((p = malloc(sizeof(linknode))) == NULL)
    {
        printf("create failed\n");
    }
    p->next = p;
    p->prior = p;
    return p;
}
int head_insert(linklist h,BOOK value)
{
    linklist p = malloc(sizeof(linknode));
    if(p == NULL)
    {
        return -1;
    }
    p->data = value;
    p->next = h;
    h->next = p;
    p->prior = h;
    h->prior = p;
    return 0;
}
void show(linklist h)
{
    linklist q;
    q = h;
    h = h->next;
    while(h != q)
    {
        printf("%d\n",h->data.book_id);
        h = h->next;
    }
}
int delete(linklist h, int i)
{
    int j;
    for(j = 1;j <= i ; j++ )
    {
        h = h->next;

    }
    linklist e = h;
    h->next->prior = h->prior;
    h->prior->next = h->next;
    free(e);
}

