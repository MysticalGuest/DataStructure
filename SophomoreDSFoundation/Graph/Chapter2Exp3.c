#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char date;
	struct Node *next;
}Node,*LinkList;

void InitLinkList(LinkList *L){
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}

void CreateFromTail(LinkList L){
	int count=0;
	Node *s,*r;
	r=L;
	printf("Please input even letters to build a linklist (End by inputing '$'):\n");
	s=(Node*)malloc(sizeof(Node));
	scanf("%c",&s->date);
	while(s->date!='$'){
		count++;
		r->next=s;
		r=s;
		s=(Node*)malloc(sizeof(Node));
		scanf("%c",&s->date);	
	}
	getchar();
	if(count%2!=0){
		printf("The number of letters you have inputed is not even!\nPlease continue to input a letter:");
	    scanf("%c",&s->date);
		r->next=s;
		r=s;
	}
	r->next=NULL;
	r=L;
	printf("The linklist that you created is:\n");
	while(r->next!=NULL){
		r=r->next;
		printf("%c",r->date);
	}
}

void TransformLinkList(LinkList L){
	Node *r,*t;
	int i,n=0;
	r=L;
	while(r->next!=NULL){
		r=r->next;
		n++;
	}
	t=L->next;
	r=L;
	for(i=0;i<n/4;i++){
		r=t->next;
		t->next=r->next;
		r->next=L->next;
		L->next=r;
		t=t->next;
	}
	t->next=NULL;
	r=L;
	printf("The linklist that has been transformed is:\n");
	while(r->next!=NULL){
		r=r->next;
		printf("%c",r->date);
	}
}

void main(){
	Node *l;
	InitLinkList(&l);
	CreateFromTail(l);
	TransformLinkList(l);
}
