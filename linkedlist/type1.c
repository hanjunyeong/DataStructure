/* typedef 의존성 제거 (void pointer ver)
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    void *data;
    struct _node *next;
    struct _node *prev;
}node;

typedef struct {
    char name[20];
} SAWON;



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
    SAWON *s;
    for (temp = head->next; temp != head; temp=temp->next) {
        s = (SAWON*) temp->data;
        printf("[%s]", s->name); // 참조를 prev으로 바꾸면 역방향가능
    }
    printf("->[head]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node head = {0, &head, &head};
    
    node temps[7];
    SAWON s[2] = { {"홍 길 동"}, {"임 꺽 정"}};
    for (int i = 0; i<2; i++) {
        temps[i].data = &s[i];
        insert_back(temps+i, &head);    
        display(&head);
    }
    return 0;
}   