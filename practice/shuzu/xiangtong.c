#include <stdio.h>


int main(void){
    int i, j;
    int a[10] = {3, 54, 43, 656, 54, 43, 453, 54, 43, 656};
    int b[10] = {0};
    int flag = 1;

    for(i = 0; i < 10; i++){
        for(j = i + 1; j < 10; j++){
            if(a[i] == a[j]){
                if(!b[i]){
                    b[i] = flag;
                }
                if(!b[j]){
                        b[j] = b[i];
                }
                flag++;
            }
        }
    }
    
      printf("b[%d] = %d\n", i, b[i]);
    }
    return 0;
}
