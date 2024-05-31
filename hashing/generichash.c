/*hash의 시간복잡도는 O(N/x), linked list는 시간복잡도 O(N) 
만약 데이터값이 1000, 1912, 2134, 4567, 5678이라면
각각의 수를 x의 모듈러스를 해서 (나머지값) index를 매달아두는 것이다.
예를들어, 1000의 8나머지 값은 0이다. 그럼 index 0에는 1234 만 할당
1234만 할당되어있는 상태에서, 1912을 나머지값 계산, 0이나왔다.
back에 넣을것인지, front에다가 넣을것인지에 따라 말이 달라지긴 한데
back이라고 하자, 그럼 hash[0]에는 1000 -> 1912가 할당이 된다.

마찬가지로 , 2134을 나머지했을때 6이 나오므로 [6]에는 2134
5678은 6이나오므로 2134, 5678이 할당된다.

[0] 에는 1000, 1092 [1] NULL [2] NULL [3] NULL [4] NULL [5] NULL
[6] 2134 -> 5678 [7] 4567 할당
*/
#if 1
#define container_of(ptr, type, member) \
    (type*)((char*)ptr-(unsigned long)&((type*)0)->member)

#include <stdio.h>
#include <stdlib.h>
#define hash_max 8

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev; // prev는 역참조같은데?
};

typedef struct {
    int sno;
    struct hlist_node hash;
} sawon;

struct hlist_head heads[hash_max];

void hlist_add_head(struct hlist_node *n, struct hlist_head *h) {
    struct hlist_node *first = h->first;
    n->next = first;
    if (first) { first->pprev = &n->next; }
    h->first =n;
    n->pprev = &h->first; /* next 1중 포인터, h->pprev는 이중포인터.
    뒤에는 노드지만, 앞에는 포인터.
    근데 노드의 포인터를 가르키는게아니라, 포인터하고 이 노드속에 있는
    넥스트하고 같은 1중 포인터니까, 이곳의 시작주소는 둘다 2중이다.
    그러니까, 노드가 오든 포인터가 오든 그 속에 있는 포인터의 주소를
    가리키면 이중으로 p->pprev가 가르킬 수 있으므로, p->pprev가
    이중이라면, 얘가 노드든 포인터든 둘 다 가리킬 수 있다. */

}

int hash_sno(int sno) {
    return sno % hash_max;
}


void display(struct hlist_head *heads) {
    struct hlist_node *temp;
    sawon *s;
    for (int i =0; i<hash_max; i++) {
        printf("[%d]", i);
        for (temp = heads[i].first; temp; temp=temp->next) {
                s = container_of(temp, sawon, hash);
                printf("[%d]", s->sno);
        }
        printf("\n");
    }
    getchar();
}
  
int main() {
    struct hlist_head heads[hash_max] = {0,};
    sawon s[30] = {0,};
    int sno;
    display(heads);
    for (int i =0; i<30; i++) {
        sno = 1000+i;
        s[i].sno = sno;  
        hlist_add_head(&s[i].hash, &heads[hash_sno(sno)]);
        display(heads);
    }
    return 0;
}

#endif