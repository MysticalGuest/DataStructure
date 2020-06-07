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

char lastChar(LinkList L){
  char c;
  Node *head=L->next;
  while(head!=NULL){
    if(head->next==NULL){
      c=head->data;
    }
    head=head->next;
  }
  return c;
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

void connectList(LinkList *L1, LinkList *L2){
	if(*L1==NULL) return ;
	Node* p=*L1;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=(*L2)->next;
}

LinkList commonSuffix(LinkList L1, LinkList L2){
  Node *p, *q;
  int len1, len2;
  len1=listlen(L1);
  len2=listlen(L2);
  if(lastChar(L1) != lastChar(L2)){
    return NULL;
  }
  else{
    for(p=L1; len1>len2; len1--){
      p=p->next;
    }
    for(q=L2; len2>len1; len2--){
      q=q->next;
    }
    while(p->next != NULL && p->next != q->next){
      p=p->next;
      q=q->next;
    }
    return p->next;
  }
}

void main(){
  LinkList str1, str2, last, locate;
  /* 初始化 */
  char word1[] = {'l', 'o', 'a', 'd', '\0'};
  char word2[] = {'b', 'e', '\0'};
  char suffix[] = {'i','n','g', '\0'};
  InitLinkList(&str1, word1);
  InitLinkList(&str2, word2);
  InitLinkList(&last, suffix);
  connectList(&str1, &last);
  connectList(&str2, &last);
  /* 初始化结束 */
  printf("Gives 2 linked lists: \n");
  printList(str1);
  printList(str2);
  locate = commonSuffix(str1, str2);
  if(locate==NULL)
    printf("The two linked lists have no intersection.\n");
  else
    printf("The intersection of these two linked lists is: %c\n", locate->data);
  
  system("pause");
}