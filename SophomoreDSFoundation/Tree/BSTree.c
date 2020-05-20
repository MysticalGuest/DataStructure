#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMELEN 40
/*
typedef struct Node{
	char name[NAMELEN];
	char author[NAMELEN];
	double price;
	struct Node *LChild;
	struct Node *RChild;
}BSTNode,*BSTree;

void InsertBST(BSTree *bst,char n[]){
	BSTree s;
	if(*bst==NULL){
		s=(BSTree)malloc(sizeof(BSTNode));
		strcpy(s->name,n);
		//strcpy(s->author,a);
		//s->price=p;
		s->LChild=NULL;
		s->RChild=NULL;
		*bst=s;
	}
	else if(strcmp(n,(*bst)->name)<0)
		InsertBST(&((*bst)->LChild),n);
	else if(strcmp(n,(*bst)->name)>0)
		InsertBST(&((*bst)->RChild),n);
}

void CreateBST(BSTree *bst){
	char name[NAMELEN],author[NAMELEN];
	double price;
	*bst=NULL;
	gets(name);
	//gets(author);
	//scanf("%lf",&price);
	getchar();
	while(1){
		InsertBST(&((*bst)->LChild),name);
		gets(name);
		getchar();
		if(name[0]=='#')
			break;
		//gets(author);	
		//scanf("%lf",&price);
	}
}
*/
void main(){
/*	BSTree BST;
	printf("Please input that which book do you want to search?\nThe name of book is: ");
	CreateBST(&BST);*/
	char name[30];
	gets(name);
	printf("%c",name[4]);
}