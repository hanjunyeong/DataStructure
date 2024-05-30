/* 링크드리스트는 insert는 헤드로 인자로 처리했는데, 
3번의 코드의 문제는 무조건 노드를 힙에다가 잡으라고  강요하는 것. 
메모리풀링을 이번에 강의하는 것? ㅇㅇ.. 메모리 의존성 제거
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

void display(node *s) {
    node *temp;
    for (temp = s->next; temp; temp=temp->next) {
        printf("->[%d]", temp->data);
    }
    printf("\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node s= {0,};
    node *temp;
    node temps[7];
    for (int i = 0; i<7; i++) {
        temp= (node*)malloc(sizeof(node));
        temps[i].data = i+1;
        display(&s);
        insert_data(temps+i, &s);
    }
    display(&s);
    return 0;
}   