#include <stdio.h>
int get_temperature();
int get_yushe();
int get_red();

int main(void)
{
  int t1, t2, t3 ;
   while(1){
   t1 = get_red();
  if(get_red() == 1)
  {
    t2 = get_temper();
    t3 = get_yushe();
    if(t2 != t3)
      {
          turn on;
         if(t2 > t3)
          {
            turn down;
          }
        else if(t2 < t3)
         {
            turn up;
         }
     }
     else{
       turn off;
     }
   }
 }
  return 0;
}
int get_temper(int t)
{
  return t;
}
int get_yushe(int T)
{
  return T;
}
int get_red(int r)
{
  if(r > shuzhi)
  {
    return 1;
  }
  else{
    return 0;
  }
}
