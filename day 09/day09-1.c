#include <stdio.h>

// 3차원 벡터 구조체 정의
struct Vector {
	int x;
    int y;
    int z;
};

// 벡터의 합 계산하는 함수
void add(struct Vector v1, struct Vector v2) {
	struct Vector result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;

	printf("벡터의 합은   x : %d, y : %d, z : %d\n", result.x, result.y, result.z);
}

// 벡터의 차 계산하는 함수
void sub(struct Vector v1, struct Vector v2) {
	struct Vector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;

	printf("벡터의 차는   x : %d, y : %d, z : %d\n", result.x, result.y, result.z);
}

// 벡터의 내적 계산하는 함수
void in(struct Vector v1, struct Vector v2) {
	int result;

	result = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);

	printf("벡터의 내적은   v1 · v2 = %d\n", result);
}

// 벡터의 외적 계산하는 함수
void out(struct Vector v1, struct Vector v2) {
	struct Vector result;

	result.x = (v1.y * v2.z) - (v1.z * v2.y);
	result.y = (v1.z * v2.x) - (v1.x * v2.z);
	result.z = (v1.x * v2.y) - (v1.y * v2.x);

	printf("벡터의 외적은   x : %d, y : %d, z : %d\n", result.x, result.y, result.z);
}


int main() {
	struct Vector v1;
	struct Vector v2;
    int num = 0;

	// 벡터 입력
	printf("첫번째 벡터(x,y,z) : ");
	scanf("%d, %d, %d", &v1.x, &v1.y, &v1.z);

	printf("두번째 벡터(x,y,z) : ");
	scanf("%d, %d, %d", &v2.x, &v2.y, &v2.z);

	// 입력된 벡터 출력
	printf("입력된 첫번째 벡터       %d,      %d,      %d\n", v1.x, v1.y, v1.z);
	printf("입력된 두번째 벡터       %d,      %d,      %d\n", v2.x, v2.y, v2.z);

	printf("\n\n-----------------------------------------\n");
	
    printf("1. 벡터의 합\n");
	printf("2. 벡터의 차\n");
	printf("3. 벡터의 외적\n");
	printf("4. 벡터의 내적\n");
	printf("5. 종료\n");

	while (1) {
		printf("-------------------------\n");

		printf("명령 입력 : ");
		scanf("%d", &num);

		switch (num) {
		// 벡터의 합
        case 1:	
			add(v1, v2);
			break;
        // 벡터의 차
		case 2:	
			sub(v1, v2);
			break;
        // 벡터의 외적
		case 3:	
			out(v1, v2);
			break;
        // 벡터의 내적
		case 4:	
			in(v1, v2);
			break;
        // 종료
		case 5:	
			printf("프로그램을 종료합니다.\n");
			printf("-------------------------\n");
			return 0;
        // 1~5까지의 숫자가 아닌 다른 값을 입력했을 때
		default:
        printf("잘못된 숫자입니다. 다시 입력하세요.");
        break;

		}
	}
	return 0;
}