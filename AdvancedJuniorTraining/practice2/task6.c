#include <stdio.h>
#include<Windows.h>
 
/*
题目：天勤41页综合应用题2
将存放n个整数的顺序表循环左移P个位置，实现
(X0,X1,...,Xn-1)
(Xp,Xp+1,...,Xn-1,X0,X1...,Xp-1)
算法：
实际的操作并不是对顺序表真的进行循环左移，而是通过逆序操作，实现了循环左移的效果
将子表(X0,X1...,Xp-1)逆序为(Xp-1,...,X1,X0)
将子表(Xp,Xp+1,...,Xn-1)逆序为(Xn-1,...,Xp+1,Xp)
将整张表(Xp-1,...,X1,X0,Xn-1,...,Xp+1,Xp)逆序为(Xp,Xp+1,...,Xn-1,X0,X1...,Xp-1)
*/
 
#define maxlen 50
#define DATATYPE int
 
typedef struct{
    DATATYPE arr[maxlen];
    int length;
}Seqlist;
 
void print_SQ(Seqlist list)
{
    for(int i=0;i<list.length;i++){
        printf("%d ",list.arr[i]);
    }
    printf("\n");
}
 
void main(void)
{
    Seqlist list = {{1,2,3,4,5,6,7,8,9,10},10};
    print_SQ(list);
 
    int p = 4;
    int i = 0, j = p-1;
    int tmp;
 
    //将子表(X0,X1...,Xp-1)逆序为(Xp-1,...,X1,X0)
    while(i < j){
        tmp = list.arr[i];
        list.arr[i] = list.arr[j];
        list.arr[j] = tmp;
 
        ++i;--j;
    }
    print_SQ(list);
    //将子表(Xp,Xp+1,...,Xn-1)逆序为(Xn-1,...,Xp+1,Xp)
    i = p;
    j = list.length-1;
    while(i < j){
        tmp = list.arr[i];
        list.arr[i] = list.arr[j];
        list.arr[j] = tmp;
 
        ++i;--j;
    }
    print_SQ(list);
    //将整张表(Xp-1,...,X1,X0,Xn-1,...,Xp+1,Xp)逆序为(Xp,Xp+1,...,Xn-1,X0,X1...,Xp-1)
    i = 0;
    j = list.length-1;
    while(i < j){
        tmp = list.arr[i];
        list.arr[i] = list.arr[j];
        list.arr[j] = tmp;
 
        ++i;--j;
    }
 
    print_SQ(list);
    system("pause");
}