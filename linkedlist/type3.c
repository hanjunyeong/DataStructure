/* container_of 버전
사이즈업으로 재는 건 좋지만, 첫번째 멤버면 가능한데. 멤버들이
마지막 멤버들이면 또 가능. 근데 또 다른 멤버가 들어올 수 있지 않는가?
중간것들은 적용이 안 된다. 구조체들의 오프셋들을 이용하여 푼다.
// 포인터는 unsigned long으로 밖에 호환이 안 된다. (음수가 나올 수 있음)
  */
#if 1
#define container_of(ptr, type, member) \
    (type*)((char*)ptr-(unsigned long)&((type*)0)->member)


#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    
    struct _node *next;
    struct _node *prev;
}node;

typedef struct {
    char name[20];
    node list1;
    node list2;
} sawon;



void __insert_data(node *temp, node *prev, node *next) { // pubilc 함수.
    temp->next = next;
    prev->next = temp;
    temp->prev = prev;
    next->prev = temp;

}

void insert_back(node *temp, node *head) { // 뒤에서 데이터 넣는 함수
    __insert_data(temp, head->prev, head); // 랩핑 함수 메커니즘
}

void insert_front(node *temp, node *head) {
    __insert_data(temp, head, head->next); // 랩핑 함수 메커니즘
}

void display(node *head) {
    node *temp;
    sawon *s;
    for (temp = head->next; temp != head; temp=temp->next) {
        s = container_of(temp, sawon, list2);
        printf("[%s]", s->name); // 참조를 prev으로 바꾸면 역방향가능
    }
    printf("->[head]\n");
}

/* 노드의 끝은 항상 NULL*/


int main() {
    node head = {&head, &head};
    sawon s[2] = { {"홍 길 동"}, {"임 꺽 정"}};
    for (int i = 0; i<2; i++) {
        insert_back(&s[i].list2, &head);    
        display(&head);
    }
    return 0;
}   

#endif