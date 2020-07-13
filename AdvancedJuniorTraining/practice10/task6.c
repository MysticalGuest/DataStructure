#include<stdio.h>
#include<math.h>
#include<Windows.h>

#define StackSize 50

typedef struct Node{
	int data;
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


void CreateBiTree(BiTree *bt, int *list, int locate){
  int ch = list[locate];
	if(ch==-100)
		(*bt)=NULL;
	else{
		(*bt)=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->data=ch;
		CreateBiTree(&((*bt)->LChild), list, 2*locate+1);
		CreateBiTree(&((*bt)->RChild), list, 2*locate+2);
	}
}

void PrintTree(BiTree bt,int nLayer){
	int i;
	if(bt==NULL)
		return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0; i<nLayer; i++)
		printf("  ");
	printf("%d\n", bt->data);
	PrintTree(bt->LChild,nLayer+1);
}

SeqStack ResultStack[10];
int i=0;

void SumPath(BiTree bt, SeqStack *S, int value){
  BiTree p;
  Push(S, bt);
  if(bt){
    if(!bt->LChild && !bt->LChild){
      if(value==bt->data){
        ResultStack[i]=*S;
        i++;
      }
    }
    else{
      SumPath(bt->LChild, S, value-bt->data);
      SumPath(bt->RChild, S, value-bt->data);
    }
    if(!IsEmpty(*S))
      Pop(S, &p);
  }
}

void main(){
  int tree[11] = {10, 5, 12, 4, 7, -100, -100, -100, -100, -100, -100};
  BiTree T;
  CreateBiTree(&T, tree, 0);
  SeqStack S;
  InitStack(&S);
  printf("Give a binary tree: \n");
  PrintTree(T, 1);
	printf("Please enter an integer: ");
	int target;
	scanf("%d", &target);
  SumPath(T, &S ,target);
  int k;
  BiTree p;
  printf("All paths of the sum of the node values in the binary tree of %d: \n", target);
  for(k=0; k<i; k++){
    while(!IsEmpty(ResultStack[k])){
      Pop(&ResultStack[k], &p);
      if(p)
        printf("%d  ", p->data);
    }
    printf("\n");
  }
  system("pause");
}