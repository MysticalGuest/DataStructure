#include<stdio.h>
#include<Windows.h>

/*宏定义*/
#define MAXSIZE 30

typedef int ElemType;  /*顺序表中存放整型元素*/
typedef int Flag;      /*标记elem每个元素，0表示没有相邻相同元素，1表示有相邻相同元素*/
typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

void initList(SeqList *L, int array[], int l);
void printList(SeqList L);

void main(){
  SeqList L;
  printf("Give a array: \n");
  int array[]={1,5,6,8,8,8,0,1,1,0,6,5}, flag=1, i=0, j=1, k;
  // int array[]={1,9,6,8,8,8,0,1,1,0,6,5}, flag=1, i=0, j=1, k;
  int length = sizeof(array) / sizeof(array[0]);

  initList(&L, array, length);
  printList(L);

  while(flag==1){
    if(L.last==0)    // 代表顺序表中只有一个元素
      break;
    if(L.elem[i]==L.elem[j]){
      
      if(L.elem[i]==L.elem[j+1]){   // 判断是否3数相连
        for(k=i; k<L.last; k++){
          L.elem[k]=L.elem[k+1];    // 所有元素前移1位
        }
        L.last = L.last-1;
      }
      else{   // 不是3数相连，那就是2数相连
        for(k=i; k<L.last-1; k++){
          L.elem[k]=L.elem[k+2];    // 所有元素前移2位
        }
        L.last = L.last-2;
        if(j>L.last){
          i=0;
          j=1;
        }
      }
    }

    if(j==L.last){
      for(k=0; k<L.last; k++){
        if(L.elem[k]==L.elem[k+1]){
          flag=1;
          break;
        }
        else
          flag=0;
      }
      i=-1;
      j=0;
    }
    
    i++;
    j++;
  }
  printf("After deleting adjacent repeating elements: \n");
  printList(L);

  system("pause");
}

/*函数定义*/
void initList(SeqList *L, int array[], int l){
  // L->flag=1;

  int i = 0;
  for(i; i<l; i++){
    L->elem[i]=array[i];
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