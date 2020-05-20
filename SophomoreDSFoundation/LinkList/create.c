#define _CRT_SECURE_NO_WARNINGS  //scanf等类似的函数已经不太安全
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	char date;
	struct Node *next;
}Node, *LinkList;

void InitLinkList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

void CreateFromTail(LinkList L) {
	printf("Please input even letters to build a linklist (End by inputing '$'):\n");
	Node *s;
	s = (Node*)malloc(sizeof(Node));
	scanf("%c", &s->date);
}
void main() {
	Node *l;
	InitLinkList(&l);
	CreateFromTail(l);
}
