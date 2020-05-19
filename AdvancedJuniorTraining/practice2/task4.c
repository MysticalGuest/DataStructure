#include<stdio.h>
#include<Windows.h>

/*宏定义*/
#define MAXSIZE 30

typedef int ElemType;  /*顺序表中存放整型元素*/
typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

/*函数声明*/
void initList(SeqList *L);
void printList(SeqList L);
void deleteList(SeqList *LA, SeqList *LB, int n);

void main(){

  SeqList La, Lb;
  Lb.last=-1;   // 初始化Lb

  int value;

	/* 初始化三个顺序表*/
	initList(&La);
  // 给出一个顺序表La
  printf("Give a sequence table: \nLa = ");
  printList(La);

  printf("Enter the value you want to delete: ");
  scanf("%d", &value);

  deleteList(&La, &Lb, value);
  printf("The sequence table after deleting the values is: \n");
  printList(Lb);

  system("pause");
}

/*函数定义*/
void initList(SeqList *L){
	L->last=-1;
  int i=0;
  for(i; i<MAXSIZE; i++){
    L->elem[i]=rand()%100 - 50;
  }
  L->last=MAXSIZE-1;
}

void printList(SeqList L){
   int i;

   printf("(");
   for(i=0; i<=L.last; i++)
     printf("%d ", L.elem[i]);

   printf(")\n");
}

void deleteList(SeqList *LA, SeqList *LB, int n){
  int count=0, i=0, j=0;
  for(i; i<LA->last+1; i++){
    if(LA->elem[i]==n){
      count++;    // 记录删除元素的个数
    }
    else{
      LB->elem[j] = LA->elem[i];
      j++;
    }
  }
  LB->last = LA->last-count;
}