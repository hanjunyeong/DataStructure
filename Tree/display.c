/* Order Traverse (트리의 순회)
display: right - root - left

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

void display(node *temp) {
    static int indent = -1;
    if (temp == 0) {
        return;
    }
    ++indent;
    display(temp->right);
    for (int i = 0; i<indent; i++) {
        printf("%4c", ' ');
    }
    printf("%d\n", temp->data); 
    display(temp->left);
    --indent;
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
