#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // 사용자의 입력 저장할 배열

    printf("문자열을 입력하세요 : ");
    scanf("%s", input);

    int len = strlen(input); // 문자열의 길이 계산
    char *start = input;        // 문자열의 첫 번째 문자 주소
    char *end = input + len - 1; // 문자열의 마지막 문자 주소, 공백 제외 위해 -1

    // 문자열 뒤집기
    while (start < end) {
        char temp = *start;   
        *start = *end;
        *end = temp;        
        start++;              
        end--;               
    } // 첫 번째 문자와 마지막 문자를 서로 교환, 주소를 각각 앞과 뒤로 이동시켜 중간으로 접근

    printf("뒤집어진 문자열 : %s\n", input);

    return 0;
}