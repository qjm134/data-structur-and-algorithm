//Author: qjm  Data: 2017.01.08

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int data[SIZE];
    int top;
}Stack;

Stack* InitStack(){
    Stack *s;

    s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int Empty(Stack *s){
    if(s == NULL)
	return -1;

    if(s->top < 0){
	return 1;
    }
    else{
	return 0;
    }
}

int Push(Stack *s, int e){
    if(s == NULL)
	return -1;

    if(s->top >= SIZE-1){
	printf("stack is full!");
	return 0;
    }
    else{
	s->data[++s->top] = e;
	return 1;
    }
}

int Pop(Stack *s, int *e){
    if(s == NULL)
	return -1;

    if(!Empty(s)){
	*e = s->data[s->top--];
	return 1;
    }
    else{
	printf("stack is empty!");
	return 0;
    }
}

int Top(Stack *s, int *e){
    if(s == NULL)
	return -1;

    if(!Empty(s)){
	*e = s->data[s->top];
	return 1;
    }
    else{
	printf("stack is empty!");
	return 0;
    }
}

int main(){
    Stack *s;
    int e=0;

    s = InitStack();
    Push(s,4);
    Top(s,&e);
    printf("top: %d\n", e);
    Pop(s,&e);
    printf("top: %d\n", e);
}
