#include<stdio.h>
#include<stdlib.h>

//Ë«Ç×±íÊ¾·¨
#define MAX 100

typedef struct TNode{
	char date;
	int parent;
}TNode;

typedef struct{
	TNode tree[MAX];
	int nodenum;
}ParentTree;

void CreateTree(ParentTree *T,int order,int pa){
	char ch;
	ch=getchar();
	if(ch=='$')
		return;
	T->tree[order].date=ch;
	T->tree[order].parent=pa;
	ch=getchar();
	while(ch!='#'){
		if(ch=='.'){
			pa++;
			ch=getchar();
			continue;
		}
		order++;
		T->tree[order].date=ch;
		T->tree[order].parent=pa;
		ch=getchar();
	}
	T->nodenum=order+1;
	order++;
	pa++;
	CreateTree(T,order,pa);
}

int FirstChild(ParentTree T,int pa){
	int i;
	for(i=pa+1;i<T.nodenum;i++){
		if(T.tree[i].parent==pa)
			return i;
	}
	return -2;
}

int NumOfChild(ParentTree T,int pa){
	int i,num=0;
	for(i=pa+1;i<T.nodenum;i++){
		if(T.tree[i].parent==pa)
			num++;
	}
	return num;
}

void PrintTree(ParentTree T,int order){
	int i,kid;
	if(order==-2)
		return;
	if(order==0){
		for(i=-1;i<T.tree[order].parent;i++)
		printf(" ");
	}
	else{
		for(i=-2;i<T.tree[T.tree[order].parent].parent;i++)
			printf(" ");
	}
	printf("%c\n",T.tree[order].date);
	kid=FirstChild(T,order);
	for(i=0;i<NumOfChild(T,order);i++){
		PrintTree(T,kid);
		kid++;
	}
}

void main(){
	ParentTree T;
	printf("Please input Capital Letter to build a tree.\n!!!!!\n");
	printf("(1) Symbol '#' stands for Set Membership!\n(2) Symbol '.' stands for Next Father!\n(3) Symbol '$' stands for Ending!\n");
	CreateTree(&T,0,-1);
	PrintTree(T,0);
}