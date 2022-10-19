#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int Data;
    node* Next;
} node;

typedef node* nptr;
//����Ʈ ���÷���
void display(nptr p) {
    nptr Temp = p;
    while (Temp != NULL) {
        printf("%d ", Temp->Data);
        Temp = Temp->Next;
    }
    printf("\n");
}

nptr create(nptr p) { //��� �ΰ� ����
    //���Ḯ��Ʈ ����
    p = (node*)malloc(sizeof(node));
    p->Next = (node*)malloc(sizeof(node));

    p->Data = 33;
    p->Next->Data = 22;

    p->Next->Next = NULL;

    return p;
}

void insert(nptr p) { //�ΰ� ��� ���̿� ������ ����
    nptr Temp;
    //��� ����
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

