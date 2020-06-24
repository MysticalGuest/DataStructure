#include<stdio.h>
#include<Windows.h>

#define QueueSize 50

typedef struct Node{
  char elem;
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
  if((Q->rear+1)%QueueSize == Q->front)
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

void CreateBiTree(BiTree *bt, char *list, int locate){
  char ch = list[locate];
  if(ch=='#')
    (*bt)=NULL;
  else{
    (*bt)=(BiTree)malloc(sizeof(BiTNode));
    (*bt)->elem=ch;
    CreateBiTree(&((*bt)->LChild), list, 2*locate+1);
    CreateBiTree(&((*bt)->RChild), list, 2*locate+2);
  }
}

void PrintTree(BiTree bt, int nLayer){
  int i;
  if(bt==NULL)
    return;
  PrintTree(bt->RChild, nLayer+1);
  for(i=0; i<nLayer; i++)
    printf(" ");
  printf("%c\n", bt->elem);
  PrintTree(bt->LChild, nLayer+1);
}

void LayerOrder(BiTree bt){
  SeqQueue Q;
  BiTree p;
  InitQueue(&Q);
  if(bt==NULL)
    return;
  EnterQueue(&Q, bt);

  while(!IsEmpty(Q)){
    DeleteQueue(&Q, &p);
    printf("%c", p->elem);
    if(p->LChild)
      EnterQueue(&Q, p->LChild);
    if(p->RChild)
      EnterQueue(&Q, p->RChild);
  }
}

void main(){
  char list[31] = {'A', 'B', 'C', 'D', '#', 'E', 'F', '#', 'G', '#', '#', '#', '#', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'};
  BiTree T;
  CreateBiTree(&T, list, 0);
  printf("Give a binary tree: \n");
  PrintTree(T, 1);
  printf("The layerorder is: ");
  LayerOrder(T);
  printf("\n");
  system("pause");
}