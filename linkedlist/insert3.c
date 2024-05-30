/* 프로세스에 한개만 존재할 수 있다는 문제가 있음.  
head가 하드코딩 되어있는게 문제. 헤드를 인자로 처리하면 됨. 
변형이 필요가 없는 헤드를, 인자가 처리하는 방식이라고 얘기함.
런타임상에서 인자로 전달하는 방법 -> 레이트 바인딩 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;

}node;



void insert_data(int data, node *s) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = s->next;
    s->next = temp;
}

void display(node *s) {
    node *temp;
    printf("[head]");
    for (temp = s->next; temp; temp=temp->next) {
        printf("->[%d]", temp->data);
    }
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node s= {0,};
    for (int i = 0; i<7; i++) {
        insert_data(i+1, &s);
    }
    display(&s);
    return 0;
}   