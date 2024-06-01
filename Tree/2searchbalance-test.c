/* 사양 이진트리, linked list랑 똑같음
O(log2N) -> O(N)이 됨
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
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i =0; i<7; i++) {
        insert_data(a[i]);

    }
        display(root);
    return 0;
 }
