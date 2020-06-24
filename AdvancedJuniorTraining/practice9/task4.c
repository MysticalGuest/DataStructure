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

void Brackets(BiTree T){
  if (T==NULL)
    return;
  printf("%c", T->elem);
	if(T->LChild!=NULL||T->RChild!=NULL)
		printf("( ");
	Brackets(T->LChild);
	if(T->RChild!=NULL)
		printf(", ", T->elem);
  Brackets(T->RChild);
	if(T->LChild!=NULL||T->RChild!=NULL)
  	printf(" )");
}

void main(){
  char list[31] = {'A', 'B', 'C', 'D', '#', 'E', 'F', '#', 'G', '#', '#','#','#','#','#',
    '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#', '#','#'};
  BiTree T;
  CreateBiTree(&T, list, 0);
  printf("Give a binary tree: \n");
  PrintTree(T, 1);
  printf("Using bracket notation to output the binary tree is: \n");
  Brackets(T);
  printf("\n");
  system("pause");
}