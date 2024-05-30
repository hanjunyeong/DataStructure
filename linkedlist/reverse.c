/* 그다음 문제점은. single linkedlist의 한계점인데, 정방향으로만 가능하고
역시계방향으로는 안 된다. 그러면 김씨는 금방 찾겠지만, 홍씨는 늦게 
찾을 수 있다. 이것을 함수로 해결할 수 있다.  */

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

void display(node *s) {
    node *temp;
    printf("[head]");
    for (temp = s->next; temp != s; temp=temp->next) {
        printf("->[%d]", temp->data); // (*temp).data
    }
    printf("->[head]\n");
}

void reverse(node *s) {
    node *prev = s;
    node *curr = prev->next;
    node *next;
    while (curr != s) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node s = {0, &s};
    node temps[7];
    for (int i = 0; i<7; i++) {
        temps[i].data = i+1;
        insert_data(temps+i, &s);
        display(&s);
    }
    reverse(&s);
    display(&s);
    reverse(&s);
    display(&s);
    return 0;
}   