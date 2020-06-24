#include<stdio.h>
#include<Windows.h>

#define QueueSize 50

//宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0

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

BOOL IsCBT(BiTree bt){
  if(bt==NULL)    // 空树
    return TRUE;
  BOOL leaf = FALSE;
  SeqQueue Q;
  BiTree p;
  InitQueue(&Q);
  EnterQueue(&Q, bt);

  while(!IsEmpty(Q)){
    DeleteQueue(&Q, &p);
    if(p->LChild==NULL && p->RChild!=NULL)   // 情况3: 当前节点有右孩子，没有左孩子
      return FALSE;
    if(leaf && (p->LChild!=NULL||p->RChild!=NULL))    //上述的状态已经发生，但是当前访问到的节点不是叶节点（有左孩子或者右孩子）
      return FALSE;
    if(p->LChild!=NULL)    //左孩子不为空，加入到队列中去
      EnterQueue(&Q, p->LChild);
    if(p->RChild!=NULL)   //右孩子不为空，加入到队列中去
      EnterQueue(&Q, p->RChild);
    if((p->LChild!=NULL && p->RChild==NULL)||(p->LChild==NULL && p->RChild==NULL))   //这个if语句就是判断状态是否要发生
      leaf=TRUE;
  }
  return TRUE;
}

void PrintIsCBT(BOOL b){
  if(b==TRUE)
    printf("This is a complete binary tree!\n");
  else
    printf("This is not a complete binary tree!\n");
}

void main(){
  char tree1[31] = {'A', 'B', 'C', 'D', '#', 'E', 'F', '#', 'G', '#', '#', '#', '#', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'};
  BiTree T1;
  CreateBiTree(&T1, tree1, 0);
  printf("Give a binary tree: \n");
  PrintTree(T1, 1);
  // printf("The layerorder is: %d", IsCBT(T));
  PrintIsCBT(IsCBT(T1));
  char tree2[31] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '#','#','#','#','#',
    '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#'};
  BiTree T2;
  CreateBiTree(&T2, tree2, 0);
  printf("Give an another binary tree: \n");
  PrintTree(T2, 1);
  // printf("The layerorder is: %d", IsCBT(T2));
  PrintIsCBT(IsCBT(T2));
  system("pause");
}