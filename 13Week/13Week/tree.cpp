#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXNODE 100

typedef struct node{
	char Name[MAXNODE];
	node* LChild;
	node* RChild;
}node;

typedef node* nptr;

class Stack {  //����Ŭ����
public:
	int Top = -1;
	nptr Item[MAXNODE];
	void create() {
		Top = -1; 
	}
	bool IsEmpty() {
		return (Top == -1); 
	}
	bool IsFull() {
		return (Top == MAXNODE - 1); 
	}
	void Push(nptr item) {
		Item[++Top] = item; 
	}
	nptr Pop() {
		return Item[Top--]; 
	}
};

class Queue {  //ťŬ
public:
	int front = 0;
	int rear = -1;
	int count = 0;
	nptr Item[MAXNODE];

	bool IsEmpty() {
		return (count == 0); 
	}
	bool IsFULL() {
		return (count == MAXNODE); 
	}
	void Add(nptr item) {
		Item[(++rear) % MAXNODE] = item; count++; 
	}
	nptr Removal() {
		return Item[(front++) % MAXNODE]; count--; 
	}
};


void PreOrder(nptr T) { // ����
	if (T != NULL) {
		printf("%s ", T->Name);
		PreOrder(T->LChild);
		PreOrder(T->RChild);
	}
}

void InOrder(nptr T) { // ����
	if (T != NULL) {
		InOrder(T->LChild);
		printf("%s ", T->Name); 
		InOrder(T->RChild);
	}
}

void PostOrder(nptr T) { // ����
		if (T != NULL) {
		PostOrder(T->LChild);
		PostOrder(T->RChild);
		printf("%s ", T->Name);
	}
}

void IterativePreOrder(nptr t) {

}

int main() {

	nptr p, t;

	p = (node*)malloc(sizeof(node));
	strcpy_s(p->Name, 100,"Park");
	p->LChild = NULL;
	p->RChild = NULL;
	
	t = p; //���� �޸𸮿� t,p�� ����Ǿ�����
	
	p = (node*)malloc(sizeof(node));
	strcpy_s(p->Name, 100, "Kim");
	p->LChild = NULL;
	p->RChild = NULL;
	t->LChild = p;

	p = (node*)malloc(sizeof(node));
	strcpy_s(p->Name, 100, "Seo");
	p->LChild = NULL;
	p->RChild = NULL;
	t->RChild = p;

	p = (node*)malloc(sizeof(node));
	strcpy_s(p->Name, 100, "Lee");
	p->LChild = NULL;
	p->RChild = NULL;
	t->LChild->RChild = p;

	p = (node*)malloc(sizeof(node));
	strcpy_s(p->Name, 100, "Cho");
	p->LChild = NULL;
	p->RChild = NULL;
	t->RChild->RChild = p;

	PreOrder(t); 
	printf("\n");
	InOrder(t);
	printf("\n");
	PostOrder(t);

}

/* n������ n log n
int main() {

	Nptr t = NULL;
	int S[6] = { 5,2,3,9,6,8 };
	for (int i = 0; i < 6; i++)
		t = Insert(t, S[i]);

	Delete(t, 8);
	return 0;
}
��� logn x n������
*/