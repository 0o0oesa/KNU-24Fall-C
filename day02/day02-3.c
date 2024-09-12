#include <stdio.h>

int main()
{
    for(int i = 0; i <= 99; i++){

        if(i %7 == 0 || i %(3*4) == 0){
            printf("%d", i);
        }
            
    }
    return 0;
}