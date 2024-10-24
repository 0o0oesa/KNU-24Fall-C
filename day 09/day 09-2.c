#include <stdio.h>

// 상품 정보를 담을 구조체 정의
struct Product {
    int id;             // 상품 ID
    char name[100];      // 상품명
    int price;          // 가격
};

// 상품 정보를 출력하는 함수
void printProduct(struct Product p) {
    printf("상품 ID : %d\n", p.id);
    printf("상품명 : %s\n", p.name);
    printf("가격 : %d원\n", p.price);
}

int main() {
    struct Product products[5]; // 최대 5개의 상품을 저장할 수 있는 배열
    int count = 0;              // 입력된 상품의 개수 카운트

    while (count < 5) {
        printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");

        printf("상품 ID : ");
        scanf("%d", &products[count].id);

        // ID에 0이 입력되면 중단
        if (products[count].id == 0) {
            break;
        }

        
        printf("상품명 : ");
        scanf("%s", products[count].name);

        
        printf("가격 : ");
        scanf("%d", &products[count].price);

        count++;
    }

    // 입력된 상품 목록 모두 출력
    if (count > 0) {
        printf("\n<<입력된 상품 목록>>\n");
        for (int i = 0; i < count; i++) {
            printProduct(products[i]);
            printf("\n");
        }
    } else {
        printf("\n입력된 상품이 없습니다.\n");
    }

    return 0;
}
