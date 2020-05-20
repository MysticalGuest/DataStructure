// 二叉树遍历应用
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
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
		(*bt)=(BiTNode*)malloc(sizeof(BiTNode));
		(*bt)->date=ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}

//二叉树基本操作：求双亲结点
BiTNode* Parent(BiTree bt,char x){
	BiTree p;
	if(bt==NULL||bt->date==x)
		return NULL;//空树或者根节点为x，返回NULL

	if(bt->LChild!=NULL)
		if(bt->LChild->date==x)
			return bt;
	if(bt->RChild!=NULL)
		if(bt->RChild->date==x)
			return bt;//找到x的结点和其双亲

	p=Parent(bt->LChild,x);//在左子树上找
	if(p!=NULL)
		return p;//在左子树上找到，返回

	p=Parent(bt->RChild,x);//在左子树上没找到，在又子树上找
	if(p!=NULL)
		return p;//在右子树上找到，返回

	return NULL;//在左右子树上都没找到，返回空
}

void ScanfBiTree(BiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree:\n");
	CreateBiTree(bt);
}

void main(){
	BiTree BT;
	char ch;
	ScanfBiTree(&BT);
	fflush(stdin);
	printf("Which parent of node do you want to get? : ");
	ch=getchar();
	if(Parent(BT,ch)==NULL)
		printf("It has no parent!\n");
	else
		printf("Its parent is: %c\n",Parent(BT,ch)->date);
}