#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  long i, j , k;
  char *data = NULL;
  data = getenv("QUERY_STRING");
  if(data == NULL)
  {
  printf("error!!!\n");
}
/*  int  m = 0;
  char ch;
  for(; *data != '\0'; )
  {
       ch = *data;
      if(ch == '=')
      {
        data ++;
        ch = *data;
        if(ch < '9' && ch > '0')
        {
          break;
        }
        else{
          m ++;

        }
      }
      data++;
  }
  int n;
  n = (m/2)+1;*/
  printf("Content type: text/html\n\n");
  printf("<html lang=\"en\">\n");
  printf("<meta charset= \"UTF-8\">\n");
  printf("<head><title>An html page from a cgi</title>\n");
  printf("<style type = \"text/css\">");
  printf("</style></head>");
  printf("<body>\n");
  //data = data - 3;
      printf("%s\n",data);
      sscanf(data, "a1=%ld&k=%ld&b1=%ld",&i,&k, &j);
/*  if(n == 1)
  {
      sscanf(data, "a1=%ld&b1=%ld",&i, &j);
      printf("<Hr />\n");*/
      switch(k){
      case 1:
      printf("<Hr />\n");
      printf("%ld + %ld = %ld\n", i, j, i + j);
      break;
    //}
  /*else if(n == 2)
    {
      sscanf(data, "a2=%ld&b2=%ld",&i, &j);
      printf("<Hr />\n");*/
      case 2:
      printf("<Hr />\n");
      printf("%ld - %ld = %ld\n", i, j, i - j);
      break;
    //}
  /*else if(n == 3)
  {
    sscanf(data, "a3=%ld&b3=%ld",&i, &j);
    printf("<Hr />\n");*/
    case 3:
    printf("<Hr />\n");
    printf("%ld * %ld = %ld\n", i, j, i * j);
    break;
  /*}
  else if(n == 4 )
  {
    sscanf(data, "a4=%ld&b4=%ld",&i, &j);
    printf("<Hr />\n");*/
    case 4:
    printf("<Hr />\n");
    printf("%ld / %ld = %ld\n", i, j, i / j);
    break;
    case 5:
    printf("<Hr />\n");
    sscanf(data, "a1=%ld", &i);
    printf("%ld 开方 = %f\n", i, sqrt(i));
    printf("%ld\n", i );
    printf("%f\n", sqrt(i));
    break;
  }
  //}
  printf("</body>\n");
  printf("</html>\n");
  fflush(stdout);
  return 0;
}
