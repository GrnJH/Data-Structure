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


nptr create(nptr p) { //��� �ΰ� ����
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


nptr insert(int position, int data, nptr head) { //�ΰ� ��� ���̿� ������ ����
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

    if (IsEmpty()) { //����Ʈ�� ���������
        head = Temp;
        Listcount++;
    }

    else if (position == 0) { //����Ʈ ���� �տ� ����
        Temp->Next = head;
        head = Temp;
        Listcount++;
    }

    else { //����Ʈ �߰��� ����
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
    //�� ��� �� �ι� ° ��� ����
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