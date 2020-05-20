#include<stdio.h>
#include<stdlib.h>

#define QueueSize 50

typedef struct Node{
	char date;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

typedef struct{
	BiTree elem[QueueSize];
	int front;
	int rear;
}SeqQueue;

void InitQueue(SeqQueue *Q){
	Q->front=Q->rear=0;
}

void EnterQueue(SeqQueue *Q,BiTree x){
	if((Q->rear+1)%QueueSize==Q->front)
		return;
	Q->elem[Q->rear]=x;
	Q->rear=(Q->rear+1)%QueueSize;
}

void DeleteQueue(SeqQueue *Q,BiTree *x){
	if(Q->front==Q->rear)
		return;
	*x=Q->elem[Q->front];
	Q->front=(Q->front+1)%QueueSize;
}

int IsEmpty(SeqQueue Q){
	if(Q.rear==Q.front)
		return 1;
	else
		return 0;
}

void CreateBiTree(BiTree *bt){
	char ch;
	ch=getchar();
	if(ch==' ')
		(*bt)=NULL;
	else{
		(*bt)=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->date=ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}

void ScanfBiTree(BiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree:\n");
	CreateBiTree(bt);
}

void LayerOrder(BiTree bt){
	SeqQueue Q;
	BiTree p;
	InitQueue(&Q);
	if(bt==NULL)
		return;
	EnterQueue(&Q,bt);
	printf("The layerorder is: ");
	while(!IsEmpty(Q)){
		DeleteQueue(&Q,&p);
		printf("%c",p->date);
		if(p->LChild)
			EnterQueue(&Q,p->LChild);
		if(p->RChild)
			EnterQueue(&Q,p->RChild);
	}
	printf("\n");
}

void main(){
	BiTree BT;
	ScanfBiTree(&BT);
	LayerOrder(BT);
}