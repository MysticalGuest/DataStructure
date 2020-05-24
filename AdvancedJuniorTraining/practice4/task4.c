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
  // printf("len1: %d   len2: %d\n", len1, len2);
  // printf("len1: %c   len2: %c\n", lastChar(L1), lastChar(L2));
}

LinkList reverse(LinkList L){
  if(L->next == NULL || L->next->next == NULL)  {
    return L;   /*链表为空或只有一个元素则直接返回*/
  }
  Node *r, *p = L->next, *q = L->next->next;
  while(q != NULL){        
    r = q->next;
    q->next = p;
    p = q;
    q = r;
  }
 
  /*此时q指向原始链表最后一个元素，也是逆转后的链表的表头元素*/
  L->next->next = NULL;  /*设置链表尾*/
  L->next = p;           /*调整链表头*/
  return L;
}

LinkList commonSuffix1(LinkList L1, LinkList L2){
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

LinkList commonSuffix2(LinkList L1, LinkList L2){
  Node *p=L1, *q=L2;
  if(L1->next == NULL || L2->next == NULL){   // 空，直接返回
    return NULL;
  }
  // else if(L1->next != L2->next){   // 这里的第一个元素,是原来的最后一个元素
  //   return NULL;    // 不相等直接返回
  // }
  else{
    while(p->next != NULL && q->next != NULL && p->next != q->next){
      p=p->next;
      q=q->next;
    }
    return p->next;
  }
}

void main(){
  LinkList str1, str2, last, locate1, locate2;
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
  locate1 = commonSuffix1(str1, str2);
  printf("The starting position of the common suffix is: %c\n", locate1->data);
  str1 = reverse(str1);
  // str2 = reverse(str2);
  printList(str1);
  printList(str2);
  locate2 = commonSuffix2(str1, str2);
  printf("The starting position of the common suffix is: %c\n", locate2->data);
  
  system("pause");
}