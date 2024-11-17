#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum rank {RANK_1 = 1, RANK_2, RANK_3}; // 고객의 등급

struct Customer {
    char* customerName;
    enum rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
};

struct Customer* head = NULL;

// 고객의 이름, 등급, 주문량, 포인트를 받아 새로운 struct customer 객체 생성
struct Customer* create_customer(const char* name, enum rank rank, int order_amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    new_customer->customerName = (char*)malloc(strlen(name) + 1);
    strcpy(new_customer->customerName, name);
    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->prev = NULL;
    new_customer->next = NULL;

    return new_customer;
}

// 새로운 고객을 연결 리스트에 삽입
void insert_customer(struct Customer* new_customer) {
    if (!head) {
        head = new_customer;
        return;
    }

// 고객 등급이 1에 가까울 수록 우선적으로 출력되고, 같은 등급일 경우 전체 주문량이 많을 수록 우선적으로 출력되고, 주문량이 같다면 포인트가 많을 수록 우선적으로 출력
    struct Customer* cur = head;
    while (cur) {
        if ((new_customer->rank < cur->rank) ||
            (new_customer->rank == cur->rank && new_customer->order_amount > cur->order_amount) ||
            (new_customer->rank == cur->rank && new_customer->order_amount == cur->order_amount &&
             new_customer->point > cur->point)) {
            
            new_customer->next = cur;
            new_customer->prev = cur->prev;
            if (cur->prev) {
                cur->prev->next = new_customer;
            } else {
                head = new_customer;
            }
            cur->prev = new_customer;
            return;
        }
        cur = cur->next;
    }

    
    cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new_customer;
    new_customer->prev = cur;
}

// 고객의 이름을 입력받으면 해당 고객 삭제
void delete_customer(const char* name) {
    struct Customer* cur = head;
    while (cur) {
        if (strcmp(cur->customerName, name) == 0) {
            if (cur->prev) {
                cur->prev->next = cur->next;
            } else {
                head = cur->next;
            }
            if (cur->next) {
                cur->next->prev = cur->prev;
            }
            free(cur->customerName);
            free(cur);
            printf("고객 '%s' 삭제 완료.\n", name);
            return;
        }
        cur = cur->next;
    }
    printf("고객 '%s'을(를) 찾을 수 없습니다.\n", name);
}

// 고ㄱ의 이름을 입력받아 해당 고객 수정
void update_customer(const char* name, enum rank rank, int order_amount, int point) {
    struct Customer* cur = head;
    while (cur) {
        if (strcmp(cur->customerName, name) == 0) {
            cur->rank = rank;
            cur->order_amount = order_amount;
            cur->point = point;
            printf("고객 '%s' 정보 수정 완료.\n", name);
            return;
        }
        cur = cur->next;
    }
    printf("고객 '%s'을(를) 찾을 수 없습니다.\n", name);
}

// 연결 리스트에 있는 모든 고객 출력
void print_customers() {
    struct Customer* cur = head;
    printf("고객 목록:\n");
    printf("--------------------------------------------------\n");
    while (cur) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
               cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("--------------------------------------------------\n");
}

// 연결 리스트에 있는 모든 고객의 메모리 해제
void free_customers() {
    struct Customer* cur = head;
    while (cur) {
        struct Customer* temp = cur;
        cur = cur->next;
        free(temp->customerName);
        free(temp);
    }
    head = NULL;
}

int main() {
    int choice;
    char name[100];
    enum rank rank;
    int order_amount, point;

    while (1) {
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 고객 출력\n");
        printf("5. 종료\n");
        printf("명령 입력: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("이름을 입력하세요: ");
                scanf("%s", name);
                printf("등급을 입력하세요 (1-3): ");
                scanf("%d", (int*)&rank);
                printf("주문량을 입력하세요: ");
                scanf("%d", &order_amount);
                printf("포인트를 입력하세요: ");
                scanf("%d", &point);
                insert_customer(create_customer(name, rank, order_amount, point));
                break;
            case 2:
                printf("삭제할 고객의 이름 입력: ");
                scanf("%s", name);
                delete_customer(name);
                break;
            case 3:
                printf("수정할 고객의 이름 입력: ");
                scanf("%s", name);
                printf("새로운 등급 입력 (1-3): ");
                scanf("%d", (int*)&rank);
                printf("새로운 주문량 입력: ");
                scanf("%d", &order_amount);
                printf("새로운 포인트 입력: ");
                scanf("%d", &point);
                update_customer(name, rank, order_amount, point);
                break;
            case 4:
                print_customers();
                break;
            case 5:
                free_customers();
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
}