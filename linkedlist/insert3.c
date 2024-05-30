/* ���μ����� �Ѱ��� ������ �� �ִٴ� ������ ����.  
head�� �ϵ��ڵ� �Ǿ��ִ°� ����. ��带 ���ڷ� ó���ϸ� ��. 
������ �ʿ䰡 ���� ��带, ���ڰ� ó���ϴ� ����̶�� �����.
��Ÿ�ӻ󿡼� ���ڷ� �����ϴ� ��� -> ����Ʈ ���ε� */

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;

}node;



void insert_data(int data, node *s) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = s->next;
    s->next = temp;
}

void display(node *s) {
    node *temp;
    printf("[head]");
    for (temp = s->next; temp; temp=temp->next) {
        printf("->[%d]", temp->data);
    }
}

/* ����� ���� �׻� NULL*/


int main() {
    node s= {0,};
    for (int i = 0; i<7; i++) {
        insert_data(i+1, &s);
    }
    display(&s);
    return 0;
}   