/* insert �Լ� ����, �ڵ尡 �ʹ� ��������. ���� �����ڸ� 2�� �������ϰ�,
����� �����͸� �ְ�, ����� ��带 �ְ�. �̰��� ������ �� �ִ�
���̵� ����. reverse�Լ��Ҷ� �տ� ��带 prev��� ����.
�� ���ο� ��带, temp��� �ߴ�. */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
    struct _node *prev;
}node;



void __insert_data(node *temp, node *prev, node *next) { // pubilc �Լ�.
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;

}

void insert_front(node *temp, node *s) {
    __insert_data(temp, s, s->next); // ���� �Լ� ��Ŀ����
}

void display(node *s) {
    node *temp;
    for (temp = s->next; temp != s; temp=temp->next) {
        printf("[%d]", temp->data); // ������ prev���� �ٲٸ� �����Ⱑ��
    }
    printf("->[head]\n");
}

/* ����� ���� �׻� NULL*/


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