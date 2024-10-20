#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// 배열을 임의의 수로 채우는 함수
void fillRandom(int array[SIZE][SIZE]) {
	for (int i = 0; i < 10; i++) { // 배열의 행 반복
		for (int j = 0; j < 10; j++) { // 배열의 열 반복
			array[i][j] = rand() % 20 + 1; // 1~20 범위의 랜덤 수
		}
	}
}

// 배열 출력 함수
void printArray(int array[SIZE][SIZE]) {
	printf("배열 출력 : \n");
	for (int i = 0; i < SIZE; i++) { // 배열의 행 반복
		for (int j = 0; j < SIZE; j++) { // 배열의 열 반복
			printf("%d ", array[i][j]); // 배열의 요소 출력
		}
		printf("\n");
	}
}

// 포인터를 이용해 이동하는 함수
void movePointer(void* array) {
	int move = *((int*)array); // 현재 위치에서 이동할 거리
	int x = 0; // 현재 위치

	while(1) {
		move = *((int*)array + x); 
		printf("현재 위치 : (%d, %d) , 배열의 값 : %d\n", x / 10, x % 10, move); // x / 10은 행 인덱스, x % 10은 열 인덱스
		x += move; // 현재 위치 x에 move값을 더하여 새로운 위치로 이동

		if (x > SIZE * SIZE) {
			x -= move; // 마지막 이동으로 인해 x의 값이 배열의 크기(100)을 넘어갈 경우 더 이동하지 않고 프로그램 종료되므로 이전 위치로 되돌리기
		
			printf("더 이상 이동할 수 없습니다.\n");
			printf("종료 위치 : (%d, %d), 배열의 값 : %d\n", x/10, x % 10, move);
			break;
		}

	}
}

int main() {
	 int array[SIZE][SIZE];  // 10x10 배열

    fillRandom(array); // 배열 랜덤 초기화
    printArray(array); // 배열 출력
    movePointer(array); // 포인터를 이용한 이동

	return 0;
}
