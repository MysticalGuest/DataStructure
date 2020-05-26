#include<stdio.h>
#include<string.h>
#include<Windows.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node, *LinkList;

void InitLinkList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
  Node *r=*L, *s;
  int i=0;
  while(i<10){
    s=(Node*)malloc(sizeof(Node));
    s->data=i;
    r->next=s;
    s->next=NULL;
    r=s;
    i++;
  }
}

/* 求链表长度 */
int listlen(LinkList L){
  int len=0;
  Node *head=L;
  while(head->next!=NULL){
    len++;
    head=head->next;
  }
  return len;
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
  LinkList L;
  int k, i;
  InitLinkList(&L);
  Node *p=L;
  printf("Gives one linked list: \n");
  printList(L);
  printf("Enter a positive integer k to find the penultimate k node in the singly linked list: ");
  scanf("%d", &k);
  for(i=0; i<listlen(L)-k+1; i++){
    p=p->next;
  }
  printf("The penultimate %d-th node is %d\n", k, p->data);
  
  system("pause");
}