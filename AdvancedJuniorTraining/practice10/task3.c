#include<stdio.h>
#include<Windows.h>

//宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0
#define N 100
int temp[N];


typedef struct Node{
  int data;
  struct Node *LChild;
  struct Node *RChild;
}BiTNode,*BiTree;


void CreateBiTree(BiTree *bt, int *list, int locate){
  int num = list[locate];
  if(num==-100)
    (*bt)=NULL;
  else{
    (*bt)=(BiTree)malloc(sizeof(BiTNode));
    (*bt)->data=num;
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
  printf("%d\n", bt->data);
  PrintTree(bt->LChild, nLayer+1);
}

// BOOL ISBST(BiTree root, BiTree pre){
//   if(root!=NULL){
//     if(!ISBST(root->LChild, root->LChild))
//       return FALSE;
    
//     if(pre!=NULL && root->data < pre->data){
//       printf("pre: %d\n", pre->data);
//       printf("root: %d\n", root->data);
//       return FALSE;
//     }
      
//     if(!ISBST(root->RChild, root->RChild))
//       return FALSE;
//   }
//   return TRUE;
// }

int i=0;
void inorder(BiTree root)
{
    if(root==NULL)
        return;
    if(root->LChild!=NULL)
        inorder(root->LChild);
    temp[i++]=root->data;
    if(root->RChild!=NULL)
        inorder(root->RChild);
}
int ISBST(int temp[], int k){
  int flag=0;
  for(int i=1; i<k; i++)
      if(temp[i]<temp[i-1])
          return 0;
  return 1;
}

void PrintIsBST(BOOL b){
  if(b==TRUE)
    printf("This is a binary sort tree!\n");
  else
    printf("This is not a binary sort tree!\n");
}

void main(){
  int tree1[31] = {16, 10, 20, 5, -100, 17, 24, -100, 8, -100, -100, -100, -100, -100, -100,
    -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};
  BiTree T1;
  CreateBiTree(&T1, tree1, 0);
  printf("Give a binary tree: \n");
  PrintTree(T1, 1);
  inorder(T1);
  PrintIsBST(ISBST(temp, i));
  int tree2[31] = {16, 10, 20, 5, -100, 15, 24, -100, 8, -100, -100, -100, -100, -100, -100,
    -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};
  BiTree T2;
  i=0;
  CreateBiTree(&T2, tree2, 0);
  printf("Give a binary tree: \n");
  PrintTree(T2, 1);
  inorder(T2);
  PrintIsBST(ISBST(temp, i));
  system("pause");
}