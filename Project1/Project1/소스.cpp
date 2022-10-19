#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int Data;
    node* Next;
} node;

typedef node* nptr;
#define MAX 3
int Listmax = 0;
int Listcount = 0;


nptr create(nptr p) { //노드 두개 생성
    Listmax = MAX;
    return p;
}

bool IsEmpty() {
    if (Listcount == 0)return true;
    else return false;
}

bool IsFull() {
    if (Listcount == Listmax)return true;
    else return false;
}

void display(nptr p) {
    nptr Temp = p;

    if (IsEmpty())
        return;

    while (Temp != NULL) {
        printf("%d ", Temp->Data);
        Temp = Temp->Next;
    }

    printf("\n");
}


nptr insert(int position, int data, nptr head) { //두개 노드 사이에 아이템 삽입
    nptr Temp = NULL, p = NULL;

    if (IsFull()) {
        printf("List is full\n");
        return head;
    }

    else {
        Temp = (node*)malloc(sizeof(node));
        Temp->Data = data;
        Temp->Next = NULL;
    }

    if (IsEmpty()) { //리스트가 비어있을때
        head = Temp;
        Listcount++;
    }

    else if (position == 0) { //리스트 가장 앞에 삽입
        Temp->Next = head;
        head = Temp;
        Listcount++;
    }

    else { //리스트 중간에 삽입
        p = head;
        for (int i = 0; i < position - 1; i++) {
            p = p->Next;
        }

        Temp->Next = p->Next;
        p->Next = Temp;
        Listcount++;
    }

    return head;
}


void removal(nptr p) {
    //세 노드 중 두번 째 노드 삭제
    nptr Temp = p->Next;
    p->Next = p->Next->Next;
    free(Temp);
}


int main() {

    nptr head = NULL;
    head = create(head);
    display(head);
    head = insert(0, 11, head);
    display(head);
    head = insert(0, 12, head);
    display(head);
    head = insert(2, 13, head);
    display(head);
    head = insert(2, 14, head);
    display(head);

      //  removal(p);
      //  display(p);
    return 0;
}