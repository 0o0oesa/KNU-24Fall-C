#include <stdio.h>

int main()
{
    int num;
    scanf_s("%d, &num");

    int res = fact(num);
    printf(res = "%d", res);
    return 0;
}

int fact(int num)
{
    int res;
    if (num == 0 || num == 1){
    res= 1;
    return res;
    }
res = num * fact(num - 1);
return res;
}