#include <stdio.h>

int main(void)
{
  printf("Content type : text/html\n\n");
printf("<html long=en>\n");
    printf("<head><meta charset=\"UTF-8\">\n");
        printf("<title>An html page</title>\n");
        printf("<style type=\"text/css\">\n");
printf("</style></head>\n");
printf("<body>\n");
    printf("<h1>4.H5技术框架</h1>\n");
    printf("<h2>需要基本功</h2>\n");
    printf("<ul>\n");
        printf("<li>linux基本操作</li>\n");
        printf("<li>简单的shell编程能力</li>\n");
        printf("<li>精通javascript</li>\n");
        printf("<li>精通python</li>\n");
    printf("</ul>\n");
    printf("<h2>计算机体系理论基础课</h2>\n");
    printf("<ul>\n");
        printf("<li>操作系统原理</li>\n");
        printf("<li>数据结构与算法</li>\n");
        printf("<li>网络协议与通信</li>\n");
        printf("<li>数据库理论，将会学习到关系型和非关系型数据库。将以Mysql和MongdoDB为代表</li>\n");
    printf("</ul>\n");
    printf("<h2>业界流行的技术与前沿框架</h2>\n");
    printf("<ul>\n");
        printf("<li>Node.js</li>\n");
        printf("<li>Diango</li>\n");
        printf("<li>Docker虚拟化技术</li>\n");
        printf("<li>Meteor</li>\n");
        printf("<li>Bootstrap</li>\n");
        printf("<li>MongDB与H5 API接口应用</li>\n");
    printf("</ul>\n");
    printf("<p>\n");
    printf("<img src=\"../images/1.jpeg\" alt=\"samile face\" align=\"left\" height=\"800\" width=\"1000\">\n");
    printf("</p>\n");
    printf("</body>\n");
    printf("</html>\n");
    fflush(stdout);
    return 0;
}
