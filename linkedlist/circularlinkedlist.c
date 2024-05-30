/* 그다음 문제는, tail을 집어 넣어서 null참조의 위험성을 지우자라고 했다.
근데, 과연 tail이 필요한가? 라는 문제가 있다. display을 할 때 tail을 위해서 1000바이트를
낭비할 수 있기 때문에. 웬만하면 지우는게 맞다. */

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
    for (temp = s->next; temp != s; temp=temp->next) {
        printf("->[%d]", temp->data); // (*temp).data
    }
    printf("->[tail]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node s = {0, &s};
    
    node temps[7];
    for (int i = 0; i<7; i++) {
        temps[i].data = i+1;
        display(&s);
        insert_data(temps+i, &s);
    }
    return 0;
}   