#include<stdio.h>
#include<stdlib.h>

#define StackSize 50

typedef struct Node{
	char date;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

typedef struct{
	BiTree elem[StackSize];
	int top;
}SeqStack;

void InitStack(SeqStack *S){
	S->top=-1;
}

void Push(SeqStack *S,BiTree x){
	if(S->top==StackSize-1)
		return;
	S->top++;
	S->elem[S->top]=x;
}

void Pop(SeqStack *S,BiTree *x){
	if(S->top!=-1){
		(*x)=S->elem[S->top];
		S->top--;
	}
}

int IsEmpty(SeqStack S){
	if(S.top==-1)
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

void PreOrder(BiTree root){
	SeqStack S;
	BiTree p;
	InitStack(&S);
	p=root;
	printf("The preorder is:");
	while(p!=NULL||!IsEmpty(S)){
		if(p!=NULL){
			printf("%c",p->date);
			Push(&S,p);
			p=p->LChild;
		}
		else{
			Pop(&S,&p);
			p=p->RChild;
		}
	}
	printf("\n");
}
void ScanfBiTree(BiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree:\n");
	CreateBiTree(bt);
}

void main(){
	BiTree BT;
	ScanfBiTree(&BT);
	PreOrder(BT);
}