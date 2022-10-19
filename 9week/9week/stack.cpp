//클래스의 장점 인터페이스와 임플리멘테이션를 구분
//IsEmpty = 스택이 -1 값을 가리키고 있으면 
//IsFUll = 스택이 정해진index의 최상의 값을 가리킴
 
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
	//Top++ : 시작값이 0 이기때문에 후위증감연산자사용
	// if Top = -1 일 경우 시작값이 -1 이기때문에 Sptr값에 ++ 해야함
	//데이터삽입후 인덱스올리기 or 인덱스올리기후 데이터삽임
}

int Pop(stackType* Sptr) {
	return Sptr->Stack[--Sptr ->Top]; //내려주고 뺴줌
	//전위증감연산자
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

void Init() { //초기화 
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