#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int Data;
    node* Next;
} node;

typedef node* nptr;
//리스트 디스플레이
void display(nptr p) {
    nptr Temp = p;
    while (Temp != NULL) {
        printf("%d ", Temp->Data);
        Temp = Temp->Next;
    }
    printf("\n");
}

nptr create(nptr p) { //노드 두개 생성
    //연결리스트 기초
    p = (node*)malloc(sizeof(node));
    p->Next = (node*)malloc(sizeof(node));

    p->Data = 33;
    p->Next->Data = 22;

    p->Next->Next = NULL;

    return p;
}

void insert(nptr p) { //두개 노드 사이에 아이템 삽입
    nptr Temp;
    //노드 삽입
    Temp = (node*)malloc(sizeof(node));
    Temp->Data = 11;

    p->Next = Temp;
    Temp->Next = p->Next;
    p->Next = Temp;
}

int main() {
    nptr p = NULL;
    p = create(p);
    display(p);
    insert(p);
    display(p);
    return 0;
}

