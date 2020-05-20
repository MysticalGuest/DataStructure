#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;
int judge[50];

#define StackSize 50

typedef struct Node{
	int num;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

typedef struct
{
	BiTree elem[StackSize];
	int top;
}SeqStack;

void InitStack(SeqStack *S)
{
	S->top=-1;
}

void Push(SeqStack *S,BiTree bt){
	if(S->top==StackSize-1)
		return;
	else{
		S->top++;
		S->elem[S->top]=bt;	
	}
}

void Pop(SeqStack *S,BiTree *bt){
	if(S->top==-1)
		return;
	else{
		*bt=S->elem[S->top];
		S->top--;}
}

int IsEmpty(SeqStack S){
	if(S.top==-1)
		return 1;
	else
		return 0;
}
/*
void InsertBST(BSTree *bst,int n){
	BSTree s;
	if(*bst==NULL){
		s=(BSTree)malloc(sizeof(BSTNode));
		s->num=n;
		s->LChild=NULL;
		s->RChild=NULL;
		*bst=s;
	}
	else if(n<(*bst)->num)
		InsertBST(&((*bst)->LChild),n);
	else if(n>(*bst)->num)
		InsertBST(&((*bst)->RChild),n);
}

void CreateBST(BSTree *bst){
	int num;
	*bst=NULL;
	scanf("%d",&num);
	while(num!=-1){
		InsertBST(bst,num);
		scanf("%d",&num);
	}
}
*/
void CreateBiTree(BiTree *bt){
	int num;
	scanf("%d",&num);
	if(num==0)
		(*bt)=NULL;
	else{
		(*bt)=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->num=num;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}

void InOrder(BiTree bt){
	BiTree p;
	SeqStack S;
	InitStack(&S);
	p=bt;
	while(p!=NULL||!IsEmpty(S)){
		if(p!=NULL){
			Push(&S,p);
			p=p->LChild;
		}
		else{
			Pop(&S,&p);
			judge[i]=p->num;
			printf("%d ",judge[i]);
			i++;
			p=p->RChild;
		}
	}
	printf("\n%d",i);
}

void Judge(){
	int j;
	for(j=0;j<i-1;j++)
		if(judge[j]>judge[j+1]){
			printf("No BST!\n");
			return;
		}
	printf("Yes BST!\n");
}
void main(){
	BiTree BT;
	CreateBiTree(&BT);
	InOrder(BT);
	Judge();
}