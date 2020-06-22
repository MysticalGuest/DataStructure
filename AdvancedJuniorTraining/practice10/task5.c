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

void swap(BiTree *node1, BiTree *node2){
  BiTree temp;
  temp = *node1;
  *node1=*node2;
  *node2=temp;
}

void Mirror(BiTree *bt){
  if((*bt)==NULL)
    return;
  swap(&((*bt)->LChild), &((*bt)->RChild));
  Mirror(&((*bt)->LChild));
  
  Mirror(&((*bt)->RChild));
  
}

void main(){
  char list[31] = {'A', 'B', 'C', '#', 'D', '#', 'E', '#', '#', 'F', 'G','#', '#', 'H', '#',
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};
  BiTree T;
  CreateBiTree(&T, list, 0);
  printf("Give a binary tree: \n");
  PrintTree(T, 1);
  Mirror(&T);
  printf("The mirror image of this binary tree is: \n");
  PrintTree(T, 1);
  system("pause");
}