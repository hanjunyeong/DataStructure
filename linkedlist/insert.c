#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;

}node;

node *s;  // 초기화 하지 않으면 0이 default


void insert_data(int data) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = s->next;
    s->next = temp;
}



/* 노드의 끝은 항상 NULL*/


int main() {
    for (int i = 0; i<7; i++) {
        insert_data(i+1);
    }
    display();
    return 0;
}   