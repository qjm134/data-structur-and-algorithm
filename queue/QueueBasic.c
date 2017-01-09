//front is empty
//Author: qjm  Data: 2017.1.9

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int data[SIZE];
    int front;
    int rear;
}Queue;

Queue* InitQueue(){
    Queue *q;
    q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = 0;
    return q;
}

int Empty(Queue *q){
    if(q == NULL)
	return -1;

    if(q->front == q->rear){
	return 1;
    }
    else{
	return 0;
    }
}

int Full(Queue *q){
    if(q == NULL)
	return -1;

    if((q->rear+1)%SIZE == q->front){
	return 1;
    }
    else{
	return 0;
    }
}

int Enqueue(Queue *q, int e){
    if(q == NULL)
	return -1;

    if(Full(q)){
	printf("queue if full!\n");
	return 1;
    }
    else{
	q->rear = (q->rear+1)%SIZE;
	q->data[q->rear] = e;
	return 0;
    }
}

int Dequeue(Queue *q, int *e){
    if(q == NULL)
	return -1;

    if(Empty(q)){
	printf("queue is empty!\n");
	return 1;
    }
    else{
	q->front = (q->front+1)%SIZE;
	*e = q->data[q->front];
	return 0;
    }
}

int Length(Queue *q){
    if(q == NULL)
	return -1;

    return (q->rear - q->front + SIZE)%SIZE;
}

int main(){
    Queue *q;
    int e=0;

    q = InitQueue();
    Enqueue(q,4);
    Dequeue(q,&e);
    printf("The first element in queue is: %d\n", e);
    printf("The length of the queue is: %d\n", Length(q));
    return 0;
}
