/* ��ũ�帮��Ʈ�� insert�� ���� ���ڷ� ó���ߴµ�, 
3���� �ڵ��� ������ ������ ��带 �����ٰ� �������  �����ϴ� ��. 
�޸�Ǯ���� �̹��� �����ϴ� ��? ����.. �޸� ������ ����
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

/* ����� ���� �׻� NULL*/


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