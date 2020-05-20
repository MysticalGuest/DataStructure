/*包含文件*/
#include "stdio.h"

/*宏定义*/
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElemType;  /*顺序表中存放整型元素*/
typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

/*函数声明*/
void initList(SeqList *L);
void printList(SeqList L);
void inputData(SeqList *L);
void merge(SeqList *LA,SeqList *LB,SeqList *LC);

/*主函数*/
void main()
{
	SeqList La,Lb,Lc;

	/* 初始化三个顺序表*/
	initList(&La);
	initList(&Lb);
	initList(&Lc);

	/*给顺序表La和Lb赋初值*/
	printf("请给顺序表La输入元素(按非递减顺序),输入-100表示结束\n");
	inputData(&La);

	printf("请给顺序表Lb输入元素(按非递减顺序),输入-100表示结束\n");
	inputData(&Lb);

	merge(&La,&Lb,&Lc);  

	/*输出三个顺序表*/
	printf("\nLa=");	printList(La);

	printf("\nLb=");	printList(Lb);

	printf("\nLc(La+Lb)=");	printList(Lc);

	printf("\n");
}


/*函数定义*/
void initList(SeqList *L)
{
	L->last=-1;
}

void inputData(SeqList *L)
{
	int i=0,num; 
	scanf("%d",&num); 
	while(num!=-100)
	{
		L->elem[i]=num;
		i++; 
		scanf("%d",&num); 
	}

	L->last=i-1;
}

void printList(SeqList L)
{
   int i;

   printf("(");
   for(i=0;i<=L.last;i++)
     printf("%d ",L.elem[i]);

   printf(")");
}

void merge(SeqList *LA,  SeqList *LB,  SeqList *LC)
{
	int i,j,k;
	i=0;j=0;k=0;
	while(i<=LA->last&&j<=LB->last)
		if(LA->elem[i]<=LB->elem[j])
		{
			LC->elem[k]= LA->elem[i];
			i++; 
			k++;
		}
		else
		{
			LC->elem[k]=LB->elem[j];
			j++; 
			k++;
        }
	while(i<=LA->last)	/*当表LA有剩余元素时，则将表LA余下的元素赋给表LC*/
	{
		LC->elem[k]= LA->elem[i];
		i++; 
		k++;
	}
	while(j<=LB->last)  /*当表LB有剩余元素时，则将表LB余下的元素赋给表LC*/	
	{
		LC->elem[k]= LB->elem[j];
		j++; 
		k++;
	}
	LC->last=LA->last+LB->last+1;
}