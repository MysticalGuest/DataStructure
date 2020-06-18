#include<stdio.h>
#include<Windows.h>

#define size 100

typedef struct Node{
  char elem;
  struct Node *LChild;
  struct Node *RChild;
}BiTNode,*BiTree;

int width[size];
int max=0;

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

void MaxWidth(BiTree T,int k){
  if(T==NULL)
    return;
  width[k]++;
  if(max<width[k])
    max=width[k];
  MaxWidth(T->LChild, k+1);
  MaxWidth(T->RChild, k+1);
}

void main(){
  char list[31] = {'A', 'B', 'C', 'D', '#', 'E', 'F', '#', 'G', '#', '#', '#', '#', '#', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'};
  BiTree T;
  CreateBiTree(&T, list, 0);
  printf("Give a binary tree: \n");
  PrintTree(T, 1);
  MaxWidth(T, 1);
  int i;
  i=1;
  // while(width[i]!=0){
  //   printf("%d  ", width[i]);
  //   i++;
  // }
  printf("\nThe width of this binary tree is: %d\n", max);
  system("pause");
}