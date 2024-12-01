#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TOPPING 10000

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int cs_top[MAX_TOPPING+1] = {0,};       // 철수가 먹는 토핑
    int brother_top[MAX_TOPPING+1] = {0,};      // 동생이 먹는 토핑
    int num_cs = 0;          // 철수가 먹는 토핑의 종류 수
    int num_brother = 0;       // 동생이 먹는 토핑의 종류 수
    int num_fair = 0;       // 공평하게 나누는 방법의 수
    
    // 동생이 모든 토핑을 먹을 경우
    for(int i=0; i<topping_len; i++) { 
        int top = topping[i];
        if(brother_top[top] == 0) num_brother++;   // 동생이 먹는 토핑의 종류 수 증가
        brother_top[top]++;   
    }
    
    // 철수가 왼쪽부터 토핑을 가져가며 나눔
    for(int i=0; i<topping_len; i++) { 
        int top = topping[i];
        brother_top[top]--;  // 동생이 해당 토핑을 뺏김   
        if(brother_top[top] == 0) num_brother--;  // 동생이 먹는 토핑의 종류 수 감소
        
        if(cs_top[top] == 0) num_cs++; // 철수가 먹는 토핑의 종류 수 증가
        cs_top[top]++; 
        
        if(num_cs == num_brother) num_fair++;  // 철수와 동생의 토핑 종류 수가 같으면 공평한 방법
    }
    
    return num_fair;  // 공평하게 나누는 방법의 수 반환
}