#include <stdlib.h>
#include <stdio.h>
#include<Windows.h>

#define ElemType char

typedef struct CSNode{
  ElemType data;
  struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

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

int depth(CSTree t){
  if(t){
    int fd = depth(t->firstchild)+1;
    int nd = depth(t->nextsibling);
    return fd>nd? fd:nd;
  }
}

int main(){
  CSTree T;
  // eg. ABE#F##C#DGH#I#J#####
  printf("Please enter a sequence of a tree: \n");
  CreatCSTree(&T);
  printf("The depth of this tree is: %d\n", depth(T));
  system("pause");
  return 0;
}