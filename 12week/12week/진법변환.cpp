#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#define MAX 100

typedef struct {
	int Top;
	int Stack[MAX];
}stackType;

void Create(stackType* Sptr) {
	Sptr->Top = 0;
}

bool IsFull(stackType* Sptr) {
	return (Sptr->Top == MAX);
}

bool IsEmpty(stackType* Sptr) {
	return (Sptr->Top == 0);
}

void Push(stackType* Sptr, int item) {
	Sptr->Stack[Sptr->Top++] = item;
}

int Pop(stackType* Sptr) {
	return Sptr->Stack[--Sptr->Top]; //내려주고 뺴
}

int Getsize(stackType* Sptr) {
	return(Sptr->Top);
}

void Display(stackType* Sptr) {
	for (int i = 0; i < Sptr->Top; i++) {
		printf("%d", Sptr->Stack[i]);
	}
	printf("\n");
}

int main() {
	stackType s;
	Create(&s);

	int num=0;
	int num2=0;
	int count = 0;

	printf("Enter Integer : ");
	scanf("%d", &num);

	while (num > 0) {
		num2 = num % 2;
		Push(&s,num2);
		num = num / 2;
		count = count+1;
	}
	for (int n = count; n > 0; n--) {
		printf("%d", Pop(&s));
	}
}