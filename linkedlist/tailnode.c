/* �̹� tailnode������, insert4.c�� �ִ� linked list ��ȸ�� ����
�ڵ尡 ������ ����. void display(node *s), null�� �����°� ����.
������ ¥�� �� ���α׷����� temp�� nullüũ�� ����� �ؾ��Ѵ�.
�׷���, tail�̶�� ������ �����. tail�� �ڱ��ڽ��� ����Ű���� �Ѵ�.
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

/* ����� ���� �׻� NULL*/


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