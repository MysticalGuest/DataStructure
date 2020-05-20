#include<stdio.h>
#include<stdlib.h>

typedef struct CSNode{
	char date;
	struct CSNode *FirstChild;
	struct CSNode *NextSibling;
}CSNode,*CSTree;

void CreateCSTree(CSTree *CST){
}

void main(){
	CSTree CST;
	CreateCSTree(&CST);
}