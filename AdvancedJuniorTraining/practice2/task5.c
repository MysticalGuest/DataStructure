#include <stdio.h>
#include<Windows.h>

/*宏定义*/
#define MAXSIZE 50

typedef int ElemType;  /*顺序表中存放整型元素*/
typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

void reverse(SeqList *L,int i, int j);

void printlist(SeqList L){
  printf("(");
  for(int i=0; i<L.last; i++){
    printf("%d ", L.elem[i]);
  }
  printf(")\n");
}
 
void main(){
  SeqList L = {{1,2,3,4,5,6,7,8,9,10},10};

  int n;
  int temp;
  char direction;

  printf("Give a sequence table: \n");
  printlist(L);

  printf("Please enter a positive integer n to cycle through the sequence: ");
  scanf("%d", &n);
  getchar();    // 吃掉回车
  printf("Please select the direction of movement (L for left, R for right): ");
  while(direction!='R' && direction!='L'){
    scanf("%c", &direction);
    getchar();
    if(direction=='L'){
      n = n%L.last;
    }
    else if(direction=='R'){    // 右移n格就是左移L.last-n格
      n = L.last - n%L.last;
    }
    else{
      printf("Wrong input, please re-enter: ");
    }
  }
  
  int i = 0, j = n-1;

  //将子表(X0,X1...,Xp-1)逆序为(Xp-1,...,X1,X0)
  reverse(&L, i, j);

  //将子表(Xp,Xp+1,...,Xn-1)逆序为(Xn-1,...,Xp+1,Xp)
  i = n;
  j = L.last-1;
  reverse(&L, i, j);

  //将整张表(Xp-1,...,X1,X0,Xn-1,...,Xp+1,Xp)逆序为(Xp,Xp+1,...,Xn-1,X0,X1...,Xp-1)
  i = 0;
  j = L.last-1;
  reverse(&L, i, j);

  printf("The sequence table after moving is: \n");
  printlist(L);

  system("pause");
}

void reverse(SeqList *L,int i, int j){
  int temp;
  while(i < j){
    temp = L->elem[i];
    L->elem[i] = L->elem[j];
    L->elem[j] = temp;

    ++i;
    --j;
  }
}