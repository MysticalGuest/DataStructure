#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int seq,key;
	struct Node *next;
}Node,*LinkList;

void InitList(LinkList *L)
{
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=*L;
}

void CreateFromTail(LinkList L,int num)
{
	int i,k;
	Node *s,*r;
	r=L;
	for(i=0;i<num;i++)
	{
		s=(Node*)malloc(sizeof(Node));
		scanf("%d",&k);
		s->seq=i+1;
		s->key=k;
		r->next=s;
		r=s;
	}
	r->next=L;
}
void Delete(LinkList L,Node *d){
	int tempkey,tempseq;
	Node *s;
	tempkey=d->key;
	tempseq=d->seq;
	if(d->next!=L){
		s=d->next;
		d->key=s->key;
		s->key=tempkey;
		d->seq=s->seq;
		s->seq=tempseq;
		d->next=s->next;
		free(s);
	}
	else{
		s=L->next;
		d->key=s->key;
		s->key=tempkey;
		d->seq=L->next->seq;
		s->seq=tempseq;
		L->next=s->next;
		free(s);
	}
}
	
void main()
{
	int i,n,m;
	Node *l,*p;
	InitList(&l);
	printf("Please input the number n of people who play this game and the upper limit m of number off:\n");
	scanf("%d%d",&n,&m);
	printf("Please input the key of %d people by successively:\n",n);
	CreateFromTail(l,n);
	p=l->next;
	printf("The Sequence that people leave the group is:\n");
	while(n>0){
		for(i=1;i<m;i++){
			if(p->next==l)
				p=l->next;
			else
				p=p->next;
		}
		printf("%d\t",p->seq);
		Delete(l,p);
		n--;
		printf("\n");
	}
}
