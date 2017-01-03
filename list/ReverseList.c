#include <stdio.h>

typedef struct node {
    char data;
    struct ode *next;
}Node;

Node* CreatList(){
    Node *head, *p;
    char ch;

    head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    p = head;
    while((ch=getchar())!='\n'){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = ch;
    n->next = NULL;
    p->next = n;
    p = n;
    }
    return head;
} 

void ShowList(Node *head){
    Node *p = head;
    while(p)
    {
	printf("%c\n", p->data);
	p = p->next;
    }
}

Node* ReverseList(Node *head){
    Node *p, *q, *r;

    if(head == NULL)
	return NULL;
    
    p = head;
    q = head->next;
    head->next = NULL;

    while(q){
	r = q->next;
	q->next = p;
	p = q;
	q = r;
    }

    return p;
}

void DeleteList(Node *head){
    Node *p, *q;
    p = q = head;

    while(p){
	q = p->next;
	free(p);
	p = q;
    }
}

int main(){
    Node *head, *r;
    head = CreatList();
    ShowList(head);
    r = ReverseList(head);
    ShowList(r);
    DeleteList(r);
    return 0; 
}

