#include<stdio.h>
#include<Windows.h>

/*宏定义*/
#define MAXSIZE 30

typedef int ElemType;  /*顺序表中存放整型元素*/
typedef int Flag;      /*标记elem每个元素，0表示相邻没有相同元素，1表示相邻有相同元素*/
typedef struct{
  ElemType elem[MAXSIZE];
  Flag mark[MAXSIZE];
  int last;
}SeqList;

void initList(SeqList *L, int array[], int l);
void printList(SeqList L);

void main(){
  SeqList L;
  int array[]={1,5,6,8,8,8,0,1,1,0,6,5};
  int length = sizeof(array) / sizeof(array[0]);

  initList(&L, array, length);
  printList(L);

  // for()

  system("pause");
}

/*函数定义*/
void initList(SeqList *L, int array[], int l){

  int i = 0;
  for(i; i<l; i++){
    L->elem[i]=array[i];
    L->mark[i] = 0;   // 初始化为0
  }
  L->last=l-1;
}

void printList(SeqList L){
   int i;

   printf("(");
   for(i=0; i<=L.last; i++)
     printf("%d ", L.elem[i]);

   printf(")\n");
}