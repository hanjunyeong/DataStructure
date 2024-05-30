/* 이번 tailnode에서는, insert4.c에 있는 linked list 순회에 대한
코드가 문제가 있음. void display(node *s), null에 끝나는게 문제.
유저가 짜는 이 프로그램에서 temp의 null체크를 제대로 해야한다.
그래서, tail이라는 변수를 만들고. tail를 자기자신을 가리키도록 한다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;

}node;



void insert_data(node *temp, node *s) {
    temp->next = s->next;
    s->next = temp;
}

void display(node *s, node *tail) {
    node *temp;
    for (temp = s->next; temp != tail; temp=temp->next) {
        printf("->[%d]", temp->data); // (*temp).data
    }
    printf("->[tail]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node tail = {0, &tail};
    node s = {0, &tail};
    
    node temps[7];
    for (int i = 0; i<7; i++) {
        temps[i].data = i+1;
        display(&s, &tail);
        insert_data(temps+i, &s);
    }
    return 0;
}   