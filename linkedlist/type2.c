/* type1.c는 너무 틀딱버전이니 쓰지마셈. 
문제점은 둘 다 스택에 할당하면 문제가 없겠지만
힙, 스택 둘다 할당하면 노드가 먼저 삭제되는 사태가 있을 수 있음. 
 먼저 사라지는 사태가 일어나면, 사라진 상태의 데이터가 남아있을 수 있기에
 데이터를 해제할 수 있는 포인터가 사라짐. dangling포인터라고 함.
뒤에있는 걸 먼저 삭제해서 접근했다가 free한 memory에 엑세스할 수 있으니
메모리가 죽어 소스가 안돌아가는 상황도 발생할 수 있음.
void *data는 루즈커플링 형식? ㅇㅇ..
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    
    struct _node *next;
    struct _node *prev;
}node;

typedef struct {
    char name[20];
    node list;
} sawon;



void __insert_data(node *temp, node *prev, node *next) { // pubilc 함수.
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;

}

void insert_back(node *temp, node *head) { // 뒤에서 데이터 넣는 함수
    __insert_data(temp, head->prev, head); // 랩핑 함수 메커니즘
}

void insert_front(node *temp, node *head) {
    __insert_data(temp, head, head->next); // 랩핑 함수 메커니즘
}

void display(node *head) {
    node *temp;
    sawon *s;
    for (temp = head->next; temp != head; temp=temp->next) {
        s = (sawon*)((char*) temp - (sizeof(sawon)-sizeof(node)));
        printf("[%s]", s); // 참조를 prev으로 바꾸면 역방향가능
    }
    printf("->[head]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node head = {&head, &head};
    sawon s[2] = { {"홍 길 동"}, {"임 꺽 정"}};
    for (int i = 0; i<2; i++) {
        insert_back(&s[i].list, &head);    
        display(&head);
    }
    return 0;
}   