#include<stdio.h>
#include<stdlib.h>

#define Carport 5

typedef struct{
	long plate[Carport];           //用来存车牌号
	int top;
}SeqStack;

void InitStack(SeqStack *S){
	S->top=-1;
}

void Push(SeqStack *S,long num){
	if(S->top==Carport-1)
		return;
	S->top++;
	S->plate[S->top]=num;
}

void Pop(SeqStack *S,long *num){
	if(S->top==-1)
		return;
	*num=S->plate[S->top];
	S->top--;
}

typedef struct Node{
	long plate;
	struct Node *next;
}LinkQueueNode;

typedef struct{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL){
		Q->rear=Q->front;
		Q->front->next=NULL;
	}
	else
		return;
}

void EnterQueue(LinkQueue *Q,long num){
	LinkQueueNode *NewNode;
	NewNode=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL){
		NewNode->plate=num;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
	}
	else
		return;
}

void DeleteQueue(LinkQueue *Q,long *num){
	LinkQueueNode *p;
	if(Q->front==Q->rear)
		return;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p){
		Q->rear=Q->front;
		Q->front->next=NULL;
	}
	*num=p->plate;
	free(p);
}

void ScanfInformation(SeqStack *S){
	char ch;
	printf("Please input the car arrives or leaves(A:arrive,L:leave):");
	scanf("%c",&ch);
	getchar();
	while(ch!='A'||ch!='L'){
		printf("Please input as required!Again:");
		scanf("%c",&ch);
		ch=getchar();
	}
	printf("the registration number of the car:");
	printf("the time of arrival or departure:");
}

void main(){
	SeqStack CarS;
	LinkQueue QueueRoad;
	InitStack(&CarS);
	InitQueue(&QueueRoad);
	ScanfInformation(&CarS);
}