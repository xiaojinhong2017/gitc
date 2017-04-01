#include <stdio.h>

int main(void)
{
  int i = 1;
  printf("content type: text/html\n\n");
  printf("<html>\n");
  printf("<head><title>An html page from a cgi</title>\n");
  printf("<style type=\"text/css\">");
  printf("h1{color: blue; text-align: right;}");
  printf("</style></head>");
  printf("<body>\n");
  for(i = 1; i < 7; i++)
  printf("<h%d>Hello world! I = %d </h%d>\n", i, i, i);
  printf("</body>\n");
  printf("</html>\n");

  fflush(stdout);
  return 0;
}
