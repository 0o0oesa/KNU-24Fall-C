#include <stdio.h>

int main()
{
    int Num;
    printf("만들 피라미드 층수 : ");
    scanf("%d", &Num); // 피라미드 층수 입력
    
    // i가 증가할수록 위층에서 아래층으로 내려가며 피라미드가 입력한 층수만큼 쌓임
    for (int i = 0; i < Num; i++) {
    // 공백 출력하는 코드
    // Num - i - 1은 각 층에서 출력되는 공백의 개수
        for (int j = 0; j < Num - i - 1; j++) {
            printf(" ");
        }
    // 별(*) 출력하는 코드
    // i * 2 + 1은 각 층에서 출력되는 별(*)의 개수
        for (int k = 0; k < i * 2 + 1; k++) {
            printf("*");
        }
        printf("\n"); // 줄 바꿈
    }
    return 0;
}