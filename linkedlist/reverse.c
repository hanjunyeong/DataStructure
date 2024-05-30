/* �״��� ��������. single linkedlist�� �Ѱ����ε�, ���������θ� �����ϰ�
���ð�������δ� �� �ȴ�. �׷��� �达�� �ݹ� ã������, ȫ���� �ʰ� 
ã�� �� �ִ�. �̰��� �Լ��� �ذ��� �� �ִ�.  */

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

/* ����� ���� �׻� NULL*/


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