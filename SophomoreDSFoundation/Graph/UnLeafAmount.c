// Unit6.208.14
#include<stdio.h>
#include<stdlib.h>

int num=0;

typedef struct Node{
	char date;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *bt){
	char ch;
	ch=getchar();
	if(ch=='#')
		return;
	if(ch==' ')
		(*bt)=NULL;
	else{
		(*bt)=(BiTree)malloc(sizeof(BiTNode));
		(*bt)->date=ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}

void Amount(BiTree bt){
	if(bt->LChild!=NULL||bt->RChild!=NULL){
		num++;
		if(bt->LChild!=NULL)
			Amount(bt->LChild);
		if(bt->RChild!=NULL)
			Amount(bt->RChild);
	}
}

void ScanfBiTree(BiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree(Ending with '#'):\n");
	CreateBiTree(bt);
}

void PrintTree(BiTree bt,int nLayer){
	int i;
	if(bt==NULL)
		return;
	PrintTree(bt->RChild,nLayer+1);
	for(i=0;i<nLayer;i++)
		printf(" ");
	printf("%c\n",bt->date);
	PrintTree(bt->LChild,nLayer+1);
}

void main(){
	BiTree BT;
	ScanfBiTree(&BT);
	PrintTree(BT,1);
	Amount(BT);
	printf("%d",num);
}