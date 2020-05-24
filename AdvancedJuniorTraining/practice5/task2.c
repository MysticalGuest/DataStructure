#include<stdio.h>
#include<string.h>
#include<Windows.h>

typedef struct Node {
	char data;
	struct Node *next;
}Node, *LinkList;

void InitLinkList(LinkList *L, char str[]) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
  Node *r=*L, *s;
  int i=0;
  while(str[i]!='\0'){
    s=(Node*)malloc(sizeof(Node));
    s->data=str[i];
    r->next=s;
    s->next=NULL;
    r=s;
    i++;
  }
}

void printList(LinkList L){
  int i=0;
  Node *r;
  r=L->next;
  while(r!=NULL){
    printf("%c  ", r->data);
    r=r->next;
  }
  printf("\n");
}

void printReversely(LinkList L){
  if(L->next!=NULL){
    printReversely(L->next);
    printf("%c  ", L->next->data);
  }
}

void main(){
  LinkList L;
  /* 初始化 */
  char word[] = {'l', 'o', 'a', 'd', 'i', 'n', 'g', '\0'};
  InitLinkList(&L, word);
  /* 初始化结束 */
  printf("Gives one linked list: \n");
  printList(L);

  printf("Recursively output the value of each node in the linked list from end to end :\n");
  printReversely(L);
  printf("\n");
  
  system("pause");
}