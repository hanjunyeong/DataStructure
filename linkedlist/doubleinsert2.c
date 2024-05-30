/* 이런 구조상 이게 원형리스트기때문에 맨 뒤에 데이터를 넣는 구조로 바꾸면?
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
}node;



void __insert_data(node *temp, node *prev, node *next) { // pubilc 함수.
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;

}

void insert_back(node *temp, node *s) { // 뒤에서 데이터 넣는 함수
    __insert_data(temp, s->prev, s); // 랩핑 함수 메커니즘
}

void insert_front(node *temp, node *s) {
    __insert_data(temp, s, s->next); // 랩핑 함수 메커니즘
}

void display(node *s) {
    node *temp;
    for (temp = s->next; temp != s; temp=temp->next) {
        printf("[%d]", temp->data); // 참조를 prev으로 바꾸면 역방향가능
    }
    printf("->[head]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node s = {0, &s, &s};
    
    node temps[7];
    for (int i = 0; i<7; i++) {
        temps[i].data = i+1;
        insert_back(temps+i, &s);    
        display(&s);
    }
    return 0;
}   