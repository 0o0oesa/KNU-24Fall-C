#include <iostream>
using namespace std;

int solution(int n)
{
    int k = 0; // 건전지 사용량
    
    while (n>0) {
        if(n%2 == 0) { // 짝수일 경우
            n = n/2; // 순간이동으로 위치 반으로 감소
        } else { // 홀수일 경우
            n--; // 1칸 점프하여 n을 짝수로 만듦
            k++; // 점프했으니 건전지 사용량 증가
            n = n/2; // 순간이동으로 위치 반으로 감소
        }
    }

    return k; // 건전지 사용량 반환
}
