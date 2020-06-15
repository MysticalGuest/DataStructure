#include<stdio.h>
#include<Windows.h>

/*宏定义*/
#define MAXSIZE 30

//宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef int ElemType;  /*顺序表中存放整型元素*/
typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

/*函数声明*/
void initList(SeqList *L);
void printList(SeqList L);
BOOL rule(int elem, int select);
void sortList(SeqList *L, SeqList *L1, int select);

void main(){

  SeqList La, Lb;
  Lb.last=-1;   // 初始化Lb

  int select;

	initList(&La);
  // 给出一个顺序表La
  printf("Give a sequence table: \nLa = ");
  printList(La);

  /* 给出下列几种排序规则:
     奇数在前，偶数在后;
     负数在前，非负数在后;
     能被3整除的数在前面，不能被3整除的数在后面.
  */
  printf("\nGive the following sorting rules: \
  \n1.Odd number first, even number behind;\
  \n2.Negative numbers first, non-negative numbers last;\
  \n3.Numbers divisible by 3 are in the front, and numbers that are not divisible by 3 are in the back.\
  \nPlease select the sorting rule you want and enter the rule number:");

  scanf("%d", &select);
  while(select != 1 && select != 2 && select != 3){
    printf("Please reselect: ");
    scanf("%d", &select);
  }
  sortList(&La, &Lb, select);
  printf("The adjusted sequence table is: \n");
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

void sortList(SeqList *L, SeqList *L1, int select){
  int i=0, end=L->last, start=0;
  for(i; i<=L->last; i++){
    if( rule(L->elem[i], select) == TRUE){    // 偶数尾插法
      L1->elem[end] = L->elem[i];
      end--;
    }
    else{   // 奇数前插法
      L1->elem[start] = L->elem[i];
      start++;
    }
  }
  L1->last=L->last;
}

BOOL rule(int elem, int select){
  switch (select)
  {
  case 1:
    if(elem%2==0)
      return TRUE;
    return FALSE;
    break;
  case 2:
    if(elem>=0)
      return TRUE;
    return FALSE;
    break;
  case 3:
    if(elem%3!=0)
      return TRUE;
    return FALSE;
    break;
  default:
    return FALSE;
    break;
  }
}

