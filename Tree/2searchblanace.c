/* in order-travese (전위순회) sort 완료
현재 시점에서도 많이 쓰는 거긴 한데, 그래도 이 코드엔 문제가 있어서 다른걸 주로 쓴다.
얘는 실시간 밸런스가 아니라서 문제
밸런스는 항상 logn승을 보장해야하는데 아님.
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
} node;

node *root;

void _fill(node *temp, int *a, int *n) {
    if (temp == 0) {
        return;
    }
    _fill(temp->left, a, n);
    a[(*n)++] = temp ->data;
    _fill(temp->right, a, n);
}

node* _bal (int *a, int n) {
    int mid;
    node *temp;
    if (n <= 0) {
        return 0;
    }
    mid = n/2;
    temp=malloc(sizeof(node));
    temp->data=a[mid];
    temp->left=_bal(a,mid);
    temp->right=_bal(a+mid+1,n-mid-1);
    return temp;
}

void bal(node *temp) {
    int a[100];
    int n=0;
    _fill(temp, a, &n);
    root=_bal(a, n);
}

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
    int a[] = {7,6,5,4,3,2,1};
    for (int i =0; i<7; i++) {
        insert_data(a[i]);

    }
        bal(root);
        display(root);

    return 0;
 }
