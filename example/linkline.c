#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int book_id;
    float price;
    char name[100];
    //char *p;
}BOOK;
typedef struct node{
    BOOK data;
    struct node  *next;
}linknode,*linklist;

linklist create();
int head_insert(linklist,BOOK);
void show(linklist);
int head_delete(linklist);

int main(void)
{
    linklist h = NULL;
    if((h = create()) == NULL)
    {
        printf("create failed\n");
    }

    BOOK book1 = {1,1.1,"C"};
    head_insert(h,book1);
   // head_delete(h);
    show(h);

}

linklist create()
{
    linklist p = NULL;

    if((p = malloc(sizeof(linknode))) == NULL)
    {
        printf("malloc failed\n");
    }
    p->next = NULL; 

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
    p->next = NULL;

    p->next = h->next;
    h->next = p;

    return 0;
}

int head_delete(linklist h)
{
    linklist s;
    s = h->next;
    h->next = h->next->next;
    free(s);
    return 0;
}
void show(linklist h)
{
    while(h != NULL)
    {
        printf("%d\n",h->data.book_id);
        h = h->next;
    }
}
