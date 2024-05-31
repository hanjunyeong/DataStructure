/*  pid hash개선
modulas hash -> pid hash
*/
#if 1
#define container_of(ptr, type, member) \
    (type*)((char*)ptr-(unsigned long)&((type*)0)->member)
#define GOLDEN_RATIO_PRIME_32 0x9e370001UL
#define pid_hashfn(pid) \
    hash_32(pid,3)
#include <stdio.h>
#include <stdlib.h>
#define hash_max 8



unsigned int hash_32(unsigned int val, unsigned int bits) {
    unsigned int hash = val * GOLDEN_RATIO_PRIME_32;
    return hash >> (32 - bits);
}


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
    return hash_32(sno, 3);
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