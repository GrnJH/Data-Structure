#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int vl;
    char ch;
    int Data;
    node* Next;
} node;

typedef struct List {
    struct node N[100];
    int count;
};

typedef node* nptr;

void GetMax(node* p) {
    node* Temp = p;
    int max_value = Temp->Data;
    for (Temp; Temp != NULL; Temp = Temp->Next)
        if (max_value < Temp->Data)
            max_value = Temp->Data;
    printf("Max = %d\n", max_value);
}

void GetMin(node* p) {
    node* Temp = p;
    int min_value = Temp->Data;
    for (Temp; Temp != NULL; Temp = Temp->Next)
        if (min_value > Temp->Data)
            min_value = Temp->Data;
    printf("Min = %d\n", min_value);   
}

void GetMaxItem(node* p) {
    node* Temp = p;
    int max_value = Temp->Data;
    for (Temp; Temp != NULL; Temp = Temp->Next)
        if (max_value < Temp->Data)
            max_value = Temp->Data;
    printf("max = %d", max_value);
    free(Temp);
    printf("max = %d\n", max_value);
}

void display(node* p) {
    node* Temp = p;
    while (Temp != NULL) {
        printf("%d ", Temp->Data);
        Temp = Temp->Next;
    }
    printf("\n");
}

nptr create(node* p) { //노드 두개 생성
    p = (node*)malloc(sizeof(node));
    p->Data = 33;
    p->Next = (node*)malloc(sizeof(node));
    p->Next->Data = 22;
    p->Next->Next = (node*)malloc(sizeof(node));
    p->Next->Next->Data = 12;
    p->Next->Next->Next = NULL;
    return p;
}

int main() {
    nptr p = NULL;
    p=create(p);
    display(p);
    GetMax(p);
    GetMin(p);
    GetMaxItem(p);
    display(p);
}