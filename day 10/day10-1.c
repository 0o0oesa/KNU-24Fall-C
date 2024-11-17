#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX (50)

struct NODE {
   char name[NAME_MAX]; // 학생 이름
   int score; // 학생 점수
   struct NODE* link;
};

struct NODE* head = NULL;

// 학생 이름과 점수를 받아 새 노드 생성하고 초기화
struct NODE* create_node(char* name, int score) {
   struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
   strcpy(new_node->name, name);
   new_node->score = score;
   new_node->link = NULL;
   return new_node;
}

// 연결 리스트에 정렬된 위치에 노드 삽입
void insert_node_sorted(struct NODE* new_node) {
   struct NODE* cur = head->link;
   struct NODE* prev = head;
   
   // 정렬된 위치에 노드를 삽입하기 위해 위치 찾기
   while (cur != NULL && cur->score > new_node->score) {
      prev = cur;
      cur = cur->link;
   }
   
   prev->link = new_node;
   new_node->link = cur;
}

// 현재 연결 리스트에 있는 모든 노드 출력
void print_nodes() {
   struct NODE* cur = head->link;
   printf("--------------------\n");
   while (cur != NULL) {
      printf("%s : %d\n", cur->name, cur->score);
      cur = cur->link;
   }
   printf("--------------------\n");
}

// 주어진 이름과 일치하는 노드 삭제
int delete_node(char* name) {
   struct NODE* prev = head;
   struct NODE* cur = head->link;
   while (cur != NULL) {
      if (strcmp(name, cur->name) == 0) {
         prev->link = cur->link;
         free(cur);
         return 1;
      }
      prev = cur;
      cur = cur->link;
   }
   return 0;
}

int main() {
   head = (struct NODE*)malloc(sizeof(struct NODE));
   head->link = NULL;

   int inst;
   int iteration = 1;

   char name[NAME_MAX];
   int score;

   while (iteration) {
      printf("1. 학생의 성적을 입력\n");
      printf("2. 학생 삭제\n");
      printf("3. 프로그램 종료\n");
      printf("명령 입력: ");
      scanf("%d", &inst);

      switch (inst) {
      case 1: // 학생 추가
         printf("학생 이름: ");
         scanf("%s", name);
         printf("점수: ");
         scanf("%d", &score);
         
         insert_node_sorted(create_node(name, score)); // 정렬된 위치에 삽입
         break;
      case 2: // 학생 삭제
         printf("삭제할 학생의 이름: ");
         scanf("%s", name);
         delete_node(name);
         break;
      case 3: // 종료
      default:
         iteration = 0;
         break;
      }

      print_nodes();
   }

   return 0;
}