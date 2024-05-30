/* single linked list는 역방향서치가 안된다는 단점이 있었음.
하지만, 원소 1000, 2000개까지는 커버가능 단 새롭게 만드는거라면 
전체를 리버스하는건 비효율적이라고 볼 수 있어, 메모리를 더 씀으로써 
역방향 서치를 막음 (10만개 이상이면 어쩔거?) */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
}node;



void insert_data(node *temp, node *s) {
    temp->next = s->next;
    s->next = temp;
    temp->prev = s;
    temp->next->prev = temp; // 1이 1을 가리키게 하는 유일한 포인터

}

void display(node *s) {
    node *temp;
    for (temp = s->prev; temp != s; temp=temp->prev) {
        printf("->[%d]", temp->data); // (*temp).data
    }
    printf("->[tail]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node s = {0, &s, &s};
    
    node temps[7];
    for (int i = 0; i<7; i++) {
        temps[i].data = i+1;
        insert_data(temps+i, &s);
        display(&s);
    }
    return 0;
}   