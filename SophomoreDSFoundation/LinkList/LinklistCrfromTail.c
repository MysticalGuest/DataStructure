#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;
typedef struct node{
  ElemType data;
  struct node *next;
}Node,*LinkList;

void init_linklist(LinkList *l)
{
	*l=(LinkList)malloc(sizeof(Node)); 
	(*l)->next=NULL;                   
}

void CreateFromTail(LinkList L)
{ 
	Node *r, *s;
	char c;
	int   flag =1; /*设置一个标志，初值为1，当输入"$"时，flag为0，建表结束*/
	r=L;                /*r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点*/
	while(flag)         /*循环输入表中元素值，将建立新结点s插入表尾*/
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			s->next=NULL;
			r=s;
		}
		else
		{
			flag=0;
			   /*将最后一个结点的next链域置为空，表示链表的结束*/
		}
	}   
} 


void PrintLink(LinkList L)
{
   Node *p=L->next;

   while(p!=NULL)
   { 
	   printf("%c ",p->data); 
	   p = p->next;
   }  

}

void main()
{
    LinkList H;

    init_linklist(&H);

    printf("Please enter some chars:\n");
    CreateFromTail(H);    

    printf("\nThe Link you created is:\n");
    PrintLink(H);
}
