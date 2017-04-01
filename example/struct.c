struct A{
    int a;
    char b;
    float c;
    int ab[];
};
struct A  a;
struct A  b;


struct A{
    int a;
    char b;
    float c;
    int ab[];
}a;
struct A b;//变量可以放在分号里面也可以在下面定义



struct {
    int a;
    char b;
    float c;
    int ab[];
}a;//临时定义一个变量



typedef struct {
    int a;
    char b;
    float c;
    int ab[];
}A;
A    a , b;


//变量初始化
struct A{
    int a;
    char b;
    float c;
    int ab[];
};
struct A  a = {,,,,};
struct A  b = {,,,,};//或者写在一行


struct A{
    int a;
    char b;
    float c;
    int ab[];
}a = {,,,,};
struct A  b = {,,,,};

//必须在定义变量是进行初始化，若没有按以下格式写
b.a =  ;
b.b =  ;
b.c =  ;
b. ab = ;
//当想调用结构体内容时也可以按上面方式写

typedef int INT//意思是以后再定义int时就用INT

typedef struct s{//s一般省略下面也是
    int b;
}a,*q;//struct s 的类型名为a， struct s 指针的类型名为 q
struct s * ====> q
q p //定义结构体类型的指针变量 p


int *p = *a;
*p;//定义int类型的指针 *p是a的内容

struct s *p
struct s abc;
p = &abc;//定义一个结构体指针类型的变量 p *p是结构体变量abc里的内容
(*p).b ===p->b//因为abc的内容是一个结构体，取其中元素就可以用(*p).b来表示等价于p->b

