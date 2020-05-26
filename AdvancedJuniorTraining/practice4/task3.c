#include<stdio.h>
#include<string.h>
#include<Windows.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkList;

void InitLinkList(LinkList *L, LinkList *temp) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
  Node *r=*L, *s;
  int i=0;
  while(i<10){
    s=(Node*)malloc(sizeof(Node));
    s->data=i;
    r->next=s;
    s->next=NULL;
    if(i==5){   // 记住一个节点地址
      *temp=r;
    }
    r=s;
    i++;
  }
}

void printList(LinkList L){
  int i=0;
  Node *r;
  r=L->next;
  while(r!=NULL){
    printf("%d  ", r->data);
    r=r->next;
  }
  printf("\n");
}

void main(){
  LinkList L, p;
  int k, i;
  InitLinkList(&L, &p);
  Node *r=L, *s;
  printf("Gives one linked list: \n");
  printList(L);
  printf("And one of the node addresses p: %d\n", p->data);
  
  s=p->next;
  p->data = s->data;
  p->next=s->next;
  free(s);
  printf("The singly linked list after deleting node p is: \n");
  printList(L);
  
  system("pause");
}