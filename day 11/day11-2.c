#include <stdio.h>
#include <math.h>

// 함수 f(x) 정의
// 이 함수는 주어진 x 값에 대해 -log10(1 / x) + sin(x) 값을 반환
double f(double x) {
	return (-log10(1 / x) + sin(x));
}

int main(){
    double start, end;
	int n;

	printf("적분할 시작 값을 입력하세요: ");
	scanf("%lf", &start);
	printf("적분할 끝 값을 입력하세요: ");
	scanf("%lf", &end);
	printf("시작할 최대 구간을 입력하세요(2^n): ");
	scanf("%d", &n);

    // 구간을 점점 더 세분화하여 적분 계산
	for (int i = 0; i <= n; i++) {
		int inte = pow(2, i); // 구간 수 2^i
        double width = (end - start) / inte; // 구간 너비
        double result = 0.0;
        double x = start;
		
        // 직사각형의 넓이 계산하고 합산하여 적분값을 근사
        for (int j = 0; j <= inte; j++) {
			result += f(x) * width;
			x += width;
		}

		printf("구간 %10d 적분 결과: %10.6f\n", inte, result);
    }
    return 0;
}