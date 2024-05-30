/* insert 함수 개선, 코드가 너무 지저분함. 에러 연산자를 2번 엑서스하고,
어떨때는 포인터만 넣고, 어떨때는 헤드를 넣고. 이것을 개선할 수 있는
아이디어가 있음. reverse함수할때 앞에 노드를 prev라고 했음.
이 새로운 노드를, temp라고 했다. */

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
        insert_front(temps+i, &s);
        
        display(&s);
    }
    return 0;
}   