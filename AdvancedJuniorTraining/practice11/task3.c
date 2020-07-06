#include <stdlib.h>
#include <stdio.h>
#include<Windows.h>

#define ElemType char

typedef struct CSNode{
  ElemType data;
  struct CSNode *firstchild, *nextsibling;
  int level;
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
    (*t)->level=layer(T, ch);
    CreatCSTree(&((*t)->firstchild));
    CreatCSTree(&((*t)->nextsibling));
  }
}

void borderNextSibling(CSTree t, CSTree nt){
  printf("%c%c, ", t->data, nt->data);
  if(nt->nextsibling)
    borderNextSibling(t, nt->nextsibling);
}

void border(CSTree t){
  if(t){
    if(t->firstchild){
      printf("%c%c, ", t->data, t->firstchild->data);
      if(t->firstchild->nextsibling)
        borderNextSibling(t, t->firstchild->nextsibling);
    }
    border(t->firstchild);
    border(t->nextsibling);
  }
}

int main(){
  // eg. ABE#F##CG##D###
  printf("Please enter a sequence of a tree: \n");
  CreatCSTree(&T);
  printf("Output each edge in the tree layer by layer starting from the root: \n");
  border(T);
  printf("\n");
  system("pause");
  return 0;
}