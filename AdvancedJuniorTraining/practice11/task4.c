#include <stdlib.h>
#include <stdio.h>
#include<Windows.h>

#define ElemType char

typedef struct CSNode{
  ElemType data;
  struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

CSTree T;

int layer(CSTree t, char x){
  int cot = 0;
  if(t==NULL)
    return cot;
  else if(t->data==x){
    cot = 1;
    return cot;
  }
  else{
    if(layer(t->firstchild, x)){
      cot = layer(t->firstchild, x)+1;
      return cot;
    }
    if(layer(t->nextsibling, x)){
      cot = layer(t->nextsibling, x);
      return cot;
    }
  }
  return cot;
}

void CreatCSTree(CSTree *t){
  ElemType ch;
  scanf("%c", &ch);
  if(ch=='#') {
    (*t)=NULL;
  }
  else {
    (*t)=(CSTree)malloc(sizeof(CSNode));
    (*t)->data=ch;
    CreatCSTree(&((*t)->firstchild));
    CreatCSTree(&((*t)->nextsibling));
  }
}

void visit(CSTree t){
  int i;
  if(t){
    for(i=1; i<layer(T, t->data); i++)
      printf(" ");
    printf("%c\n", t->data);
    visit(t->firstchild);
    visit(t->nextsibling);
  }
}

void main(){
  // eg. ABE#F##CG##D###
  printf("Please enter a sequence of a tree: \n");
  CreatCSTree(&T);
  printf("Print the tree in a recessed way: \n");
  visit(T);
  system("pause");
}