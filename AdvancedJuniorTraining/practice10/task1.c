#include<stdio.h>
#include<Windows.h>

typedef struct Node{
	char elem;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

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

void PrintTree(BiTree bt,int nLayer){
	int i;
	if(bt==NULL)
		return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf(" ");
	printf("%c\n", bt->elem);
	PrintTree(bt->LChild,nLayer+1);
}

// 1代表是正则二叉树，0代表不是
int IsRegular(BiTree T){
  if(T==NULL)
    return 1;
  else if(T->LChild==NULL ^ T->RChild==NULL)
    return 0;
  else{
    IsRegular(T->LChild);
    IsRegular(T->RChild);
  }
}

void PrintIsRegular(BiTree T){
  if(IsRegular(T)==0)
    printf("This binary tree is not a regular binary tree!\n");
  else
    printf("This is a regular binary tree!\n");
}

void main(){
  char list1[31] = {'A', 'B', 'C', '#', 'D', '#', 'E', '#', '#', 'F', 'G','#', '#', 'H', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
  BiTree T1;
  CreateBiTree(&T1, list1, 0);
  printf("Give a binary tree: \n");
  PrintTree(T1, 1);
  PrintIsRegular(T1);
  char list2[31] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '#', '#','#','#','#','#',
    '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#'};
  BiTree T2;
  CreateBiTree(&T2, list2, 0);
  printf("\nGive an another binary tree: \n");
  PrintTree(T2, 1);
  PrintIsRegular(T2);
  system("pause");
}