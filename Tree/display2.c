/* Order Traverse (트리의 순회)
display: right - root - left
배열을 이용해 출력
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} node;

node *root;
typedef enum { LEFT, RIGHT } FLAG;

void insert_data(int data, node *s, FLAG flag) {
    node *temp;
    temp=malloc(sizeof(node));
    temp->data = data;
    temp->left = 0;
    temp->right = 0;

    if (root == 0) {
        root = temp;
        return;
    }
    if (flag == LEFT)  s->left = temp;
    else if (flag == RIGHT ) s->right = temp;
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
    insert_data (1, root, LEFT);
    insert_data (2, root, LEFT);
    insert_data (3, root, RIGHT);
    insert_data (4, root->left, LEFT);
    insert_data (5, root->left, RIGHT);
    insert_data (6, root->right, LEFT);
    insert_data (7, root->right, RIGHT);
    display(root);
    return 0;
 }
