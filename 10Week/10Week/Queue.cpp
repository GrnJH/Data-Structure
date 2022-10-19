#include <stdio.h>
#define MAX 5

typedef struct Queue {
	int Queue[MAX];
	int front;
	int rear;
}QueueType;

void Init(QueueType *q) { //ÃÊ±âÈ­
	q->front = 0;
	q->rear = -1;
}

bool IsFull(QueueType *q) { //rear-1 == MAX
	if (q->rear + 1 == MAX)
	return true;
	else return false;
}

bool IsEmpty(QueueType*q) { // front>rear  
	if (q->front > q->rear)
		return true;
	else return false;
}

void Getsize(QueueType*q) {
	printf("%d ", q->rear+1 );
}

void Getpront(QueueType*p) {
	printf("%d ", p->Queue[p->front]);
}

void add(QueueType*q, int item) {
	if (IsFull(q)) {
		printf("Queue is full\n");
	}else 
	q->Queue[++q->rear] = item;	
}

void remove(QueueType* q) {
	if (IsEmpty(q)) {
		printf("Queue is empty");
	}else
	q->Queue[q->front++];
}

int main() {
	QueueType q;

	Init(&q);
	add(&q, 10);
	add(&q, 20);
	add(&q, 30);
	add(&q, 40);
	add(&q, 50);
	add(&q, 60);

	Getsize(&q);
	
	Getpront(&q);
	remove(&q);
	Getpront(&q);
	remove(&q);
	Getpront(&q);
	remove(&q);
	Getpront(&q);
	remove(&q);
	Getpront(&q);
	remove(&q);
	Getpront(&q);
	remove(&q);
}