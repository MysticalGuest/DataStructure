#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

int num=1;

typedef struct Node{
	int num;
	char date;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

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

void NumberingTree(BiTree *bt){
	if((*bt)!=NULL){
		NumberingTree(&((*bt)->LChild));
		NumberingTree(&((*bt)->RChild));
		(*bt)->num=num;
		num++;
	}
}

void ScanfBiTree(BiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree:\n");
	CreateBiTree(bt);
	NumberingTree(bt);
}

void PrintTree(BiTree bt,int nLayer){
	int i;
	if(bt==NULL)
		return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf(" ");
	printf("%c%d\n",bt->date,bt->num);
	PrintTree(bt->LChild,nLayer+1);
}

void main(){
	BiTree BT;
	ScanfBiTree(&BT);
	PrintTree(BT,1);
	system("pause");
}