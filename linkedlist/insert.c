#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;

}node;

node *s;  // �ʱ�ȭ ���� ������ 0�� default


void insert_data(int data) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = s->next;
    s->next = temp;
}



/* ����� ���� �׻� NULL*/


int main() {
    for (int i = 0; i<7; i++) {
        insert_data(i+1);
    }
    display();
    return 0;
}   