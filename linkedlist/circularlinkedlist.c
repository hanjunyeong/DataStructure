/* �״��� ������, tail�� ���� �־ null������ ���輺�� �����ڶ�� �ߴ�.
�ٵ�, ���� tail�� �ʿ��Ѱ�? ��� ������ �ִ�. display�� �� �� tail�� ���ؼ� 1000����Ʈ��
������ �� �ֱ� ������. �����ϸ� ����°� �´�. */

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

/* ����� ���� �׻� NULL*/


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