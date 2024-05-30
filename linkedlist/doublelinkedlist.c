/* single linked list�� �����⼭ġ�� �ȵȴٴ� ������ �־���.
������, ���� 1000, 2000�������� Ŀ������ �� ���Ӱ� ����°Ŷ�� 
��ü�� �������ϴ°� ��ȿ�����̶�� �� �� �־�, �޸𸮸� �� �����ν� 
������ ��ġ�� ���� (10���� �̻��̸� ��¿��?) */

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
    temp->next->prev = temp; // 1�� 1�� ����Ű�� �ϴ� ������ ������

}

void display(node *s) {
    node *temp;
    for (temp = s->prev; temp != s; temp=temp->prev) {
        printf("->[%d]", temp->data); // (*temp).data
    }
    printf("->[tail]\n");
}

/* ����� ���� �׻� NULL*/


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