/* 문제점 1. root = null일때, 아닐때 코드 구현 o 
이코드 없이도 이거 구현 가능?
2. p = left, right 백업할 코드가 왜 필요함?ㅋㅋ
3. prev메모리 낭비
4. if - else가 있는데, else또 왜필요한데?
이걸 일반화할걸 지금 만들거

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} node;

node *root;


void insert_data(int data) {
    node *temp;
    node **p=&root;
    temp=malloc(sizeof(node));
    temp->data = data;
    temp->left = 0;
    temp->right = 0;
    while(*p) {
        
        if ((*p)->data > data) {
            p=&(*p)->left;
        }
        else if ((*p)->data < data) {
            p=&(*p)->right;
        }
        else {
            return;
        }
    }
    *p = temp;
}


int (*__display(node *temp)) [10] {
    static int row= -1;
    static int col = 0;
    static int a[10][10]={0,};
    if (temp == 0) {
        return a;
    }
    ++row;
    __display(temp->left);
    a[row][col++]=temp->data;
    __display(temp->right);
    --row;
    return a;
}

void display(node *temp) {
    int (*a)[10];
    a = __display(temp);

    for (int i =0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            if (a[i][j]) {
                printf("%4d", a[i][j]);
            }
            else {
                printf("%4c", ' ');
            }
        }
        printf("\n");
    }
}

 int main() {
    int a[] = {4, 2, 1, 3, 6, 5, 7};
    for (int i =0; i<7; i++) {
        insert_data(a[i]);

    }
        display(root);
    return 0;
 }
