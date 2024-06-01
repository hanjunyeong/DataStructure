/* 개틀딱기법, insert 개번잡함
중복이 많고, 없애야할 코드 개많음
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
    node *p=root;
    node *prev;
    temp=malloc(sizeof(node));
    temp->data = data;
    temp->left = 0;
    temp->right = 0;

    if (root == 0) {
        root = temp;
        return;
    }
    while(p) {
        prev = p;
        if (p->data > data) {
            p=p->left;
        }
        else if (p->data < data) {
            p=p->right;
        }
        else {
            return;
        }
    }
    if (prev ->data > data) {
        prev->left = temp;
    }
    else {
        prev->right = temp;
    }
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
    // printf("%d\n", temp->data); 
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
