#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
   double x = 0;
   double y = 0;
   int r = 0; // 정사각형 변의 길이
   int p = pow(10, 7); // pow(10,7) = 10^7을 의미하므로 p는 진행 상황을 출력하는 주기인 1천만

   int count = 0, circle = 0; // count: 몇 번 수행되었는지를 세는 변수, circle: 원 안에 포함된 점의 개수를 세는 변수
   double pi = 0;

   printf("몬테 카를로 알고리즘\n");
   printf("정사각형 변의 길이 입력 : ");
   scanf("%d", &r);

   srand(time(NULL)); // 각 실행마다 다른 난수 생성

   if (r > 0) {
      while (count < pow(10,9)) {
         x = (double)rand() / (double)RAND_MAX*r; // x의 값이 [0,1]범위의 실수로 지정된 후 r을 곱해 [0,r]범위의 좌표가 됨
         y = (double)rand() / (double)RAND_MAX*r; // y의 값이 [0,1]범위의 실수로 지정된 후 r을 곱해 [0,r]범위의 좌표가 됨
         count++; 
         int c = count / p; // 몇% 진행되었는지 알 수 있는 변수
         
         //점이 원의 내부에 있는지 확인
         if (x*x + y*y < r*r) {
            circle++; // 점이 원의 내부에 있을 경우 circle의 값 증가시키기
         }

         // 1천만회마다 계산된 원주율과 진행 상황 출력
         if (count % p == 0) {
            pi = 4 * ((double)circle / (double)count);
            printf("%d%%진행.. 원주율 : %lf ", c, pi);
            // 진행 상황 시각적으로 보여주기 위한 막대 출력
            // 5%마다 막대 한 칸이 채워져 막대 전체는 총 20칸
            for (int i = 0; i < 20; i++) {
                if (c / 5 > i) { // 진행률을 5% 단위로 나누므로 c / 5로 계산된 값만큼 ■가 출력되고 나머지는 □로 출력됨 
                  printf("■");
               }
               else {
                  printf("□");
               }
            }
            printf("\n");
         }
      }
      printf("원주율 : %lf", pi); // 최종 원주율 값 출력
   }
   // r이 0보다 작거나 같으면, 잘못된 입력값임을 알리고 프로그램 종료
   else {
      printf("잘못된 입력값 입니다.\n");
      printf("프로그램을 종료합니다.\n");
   }
   return 0;
}