/* Order Traverse (트리의 순회)
pre order : left - right - root (후위 순회)
root 방문하는 시점을 맨 마지막으로 늦추면 후위순회
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

void post_order(node *temp) {
    if (temp == 0) {
        return;
    }
    post_order(temp->left);
    post_order(temp->right);
    printf("%d\n", temp->data); 

    }

 int main() {
    insert_data (1, root, LEFT);
    insert_data (2, root, LEFT);
    insert_data (3, root, RIGHT);
    insert_data (4, root->left, LEFT);
    insert_data (5, root->left, RIGHT);
    insert_data (6, root->right, LEFT);
    insert_data (7, root->right, RIGHT);
    post_order(root);
    return 0;
 }
