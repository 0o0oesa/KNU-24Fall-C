#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, discriminant, x1, x2;

    // 이차방정식의 계수 입력
    printf("이차방정식의 계수를 입력하세요.(ax^2+bx+c)\n");
    printf("a 값: ");
    scanf("%f", &a);
    printf("b 값: ");
    scanf("%f", &b);
    printf("c 값: ");
    scanf("%f", &c);

    // 판별식 계산식
    discriminant = pow(b,2) - 4 * a * c;
    // a가 0이면 이차방정식이 아니므로 문제 조건 만족 x
    if (a == 0) {
        printf("이차방정식이 아닙니다.\n");
    }
     // 판별식이 음수인 경우, 허근을 가지므로 출력하지 않음
    else if (discriminant < 0) {
        printf("허근입니다.\n");
    }
    // 판별식이 0인 경우, 중근을 가지므로 하나의 근만 출력
    else if (discriminant == 0) {
        printf("중근입니다.\n");
        printf("%.2f", (-b + sqrt(discriminant)) / (2 * a));
    }
    // 판별식이 양수인 경우, 서로 다른 두 개의 실근 출력
    else {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("두 실근: %.2f, %.2f\n", x1, x2);
    }
    return 0;
}