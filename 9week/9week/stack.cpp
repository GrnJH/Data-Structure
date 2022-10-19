//Ŭ������ ���� �������̽��� ���ø������̼Ǹ� ����
//IsEmpty = ������ -1 ���� ����Ű�� ������ 
//IsFUll = ������ ������index�� �ֻ��� ���� ����Ŵ
 
#include <stdio.h>
#define MAX 100

typedef struct {
	int Top;
	int Stack[MAX];
}stackType;


void Create(stackType* Sptr) {
	Sptr->Top = 0;
}

bool IsFull(stackType*Sptr) {
	return (Sptr->Top == MAX);
}

bool IsEmpty(stackType* Sptr) {
	return (Sptr->Top == 0);
}

void Push(stackType* Sptr, int item) {
	Sptr->Stack[Sptr->Top++] = item;
	//Top++ : ���۰��� 0 �̱⶧���� �������������ڻ��
	// if Top = -1 �� ��� ���۰��� -1 �̱⶧���� Sptr���� ++ �ؾ���
	//�����ͻ����� �ε����ø��� or �ε����ø����� �����ͻ���
}

int Pop(stackType* Sptr) {
	return Sptr->Stack[--Sptr ->Top]; //�����ְ� ����
	//��������������
}

int Getsize(stackType* Sptr) {
	return(Sptr->Top);
}

int main() {
	stackType s;
	Create(&s);
	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);

	printf("%d ", Pop(&s));
	printf("%d ", Pop(&s));
	printf("%d ", Pop(&s));

	printf("%d %d %d", s.Stack[0], s.Stack[1], s.Stack[2]);
}

class Stack {
public:
	int Top = -1;
	int stack[MAX];
};

/*
	int Top=0;
	int Stack[MAX];

void Init() { //�ʱ�ȭ 
	Top = 0;
}

bool IsEmpty() {
	return (Top == 0);
}

bool IsFull() {
	return (Top == MAX);
}

void Push(int item) {
	Stack[Top++] = item;
}

int Pop() {
	return Stack[--Top];
}

void GetSize(int item) {
	for (item = 0 ; item < Top ; item++);
}


int main() {
	Init();
	Push(10);
	Push(20);
	Push(30);

	printf("%d %d %d",Stack[0],Stack[1],Stack[2]);
}
*/