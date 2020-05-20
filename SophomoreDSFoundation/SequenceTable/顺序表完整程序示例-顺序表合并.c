/*�����ļ�*/
#include "stdio.h"

/*�궨��*/
#define MAXSIZE 100
#define OK 1
#define ERROR 0

typedef int ElemType;  /*˳����д������Ԫ��*/
typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

/*��������*/
void initList(SeqList *L);
void printList(SeqList L);
void inputData(SeqList *L);
void merge(SeqList *LA,SeqList *LB,SeqList *LC);

/*������*/
void main()
{
	SeqList La,Lb,Lc;

	/* ��ʼ������˳���*/
	initList(&La);
	initList(&Lb);
	initList(&Lc);

	/*��˳���La��Lb����ֵ*/
	printf("���˳���La����Ԫ��(���ǵݼ�˳��),����-100��ʾ����\n");
	inputData(&La);

	printf("���˳���Lb����Ԫ��(���ǵݼ�˳��),����-100��ʾ����\n");
	inputData(&Lb);

	merge(&La,&Lb,&Lc);  

	/*�������˳���*/
	printf("\nLa=");	printList(La);

	printf("\nLb=");	printList(Lb);

	printf("\nLc(La+Lb)=");	printList(Lc);

	printf("\n");
}


/*��������*/
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
	while(i<=LA->last)	/*����LA��ʣ��Ԫ��ʱ���򽫱�LA���µ�Ԫ�ظ�����LC*/
	{
		LC->elem[k]= LA->elem[i];
		i++; 
		k++;
	}
	while(j<=LB->last)  /*����LB��ʣ��Ԫ��ʱ���򽫱�LB���µ�Ԫ�ظ�����LC*/	
	{
		LC->elem[k]= LB->elem[j];
		j++; 
		k++;
	}
	LC->last=LA->last+LB->last+1;
}