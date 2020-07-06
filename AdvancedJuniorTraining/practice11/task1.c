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

void visit(CSTree t){
  if(t){
    printf("Tree->data: %c\n", t->data);
    visit(t->firstchild);
    visit(t->nextsibling);
  }
}

int main(){
  CSTree T;
  // eg. ABE#F##C#DGH#I#J#####
  printf("Please enter a sequence of a tree: \n");
  CreatCSTree(&T);
  printf("The result of the first traversal is: \n");
  visit(T);
  system("pause");
  return 0;
}

//找寻树的叶子节点数
int Leaves(CSTree T){
  if(T==NULL){
    return 0;
  }
  if(T->firstchild==NULL){
    return 1+Leaves(T->nextsibling);
  }
  else{
    return Leaves(T->firstchild)+Leaves(T->nextsibling);
  }
}

//树的高度
int TreeHeight(CSTree T){
  int ch, nh;
  if(T==NULL){
    return 0;
  }
  ch=TreeHeight(T->firstchild);   //获得第一个子树的高度
  nh=TreeHeight(T->nextsibling);  //获得兄弟树的高度
  if(ch+1>nh){
    return ch+1;
  }       //判断子树和兄弟树的高度
  else {return nh;}
}