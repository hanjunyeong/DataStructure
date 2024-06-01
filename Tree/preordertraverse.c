/* Order Traverse (트리의 순회)
pre order : root - left - right
재귀함수 호출로 주로 짠다. 전위순회하는듯?
근데, 종료조건이 없으면 memory overflow로 죽기때문에
temp가 단말노드가 없을때에는 temp==null일때 종료인듯 ?
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

void pre_order(node *temp) {
    if (temp == 0) {
        return;
    }
    printf("%d\n", temp->data);
    pre_order(temp->left);
    pre_order(temp->right);
    }

 int main() {
    insert_data (1, root, LEFT);
    insert_data (2, root, LEFT);
    insert_data (3, root, RIGHT);
    insert_data (4, root->left, LEFT);
    insert_data (5, root->left, RIGHT);
    insert_data (6, root->right, LEFT);
    insert_data (7, root->right, RIGHT);
    pre_order(root);
    return 0;
 }
