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
  Node *r=*L, *s, *temp;
  int i=0;
  while(i<10){
    s=(Node*)malloc(sizeof(Node));
    s->data=i;
    r->next=s;
    s->next=NULL;
    if(i==4){   // 记住一个元素,以助后面成环
      temp=r;
    }
    r=s;
    i++;
  }
  r->next=temp;   // 成环
}


/*
  使用快慢指针判断单链表是否存在环。
  使用slow、fast 2个指针，slow慢指针每次向前走1步，fast快指针每次向前走2步，
  若存在环的话，必定存在某个时候 slow = fast 快慢指针相遇。
  list 带头结点的单链表
  返回值 >0:存在环返回环的位置	0:不存在环
*/
int IsLoopLinkList(LinkList list){
	//空指针
	if(list == NULL){
		return 0;
	}
	//只有头结点,没有元素
	if(list->next == NULL){
		return 0;
	}
	Node* slow = list;
	Node* fast = list;
	int loc = 0;
	while (1){
		if(fast->next == NULL){
			//快指针 到底链表尾结点说明 没有环，此时slow 指向中间结点
			return 0;
		}
		else{
			if (fast->next != NULL && fast->next->next != NULL){
				fast = fast->next->next;
				slow = slow->next;
			}
			else{
				fast = fast->next;
			}
		}
		//某个时刻 快慢指针相遇，说明此处存在环！
		if(slow == fast){
      return 1;
		}
	}
	return 0;
}

void main(){
  LinkList L;
  InitLinkList(&L);
  Node *p=L;
  int i;
  printf("Output this singly linked list of existing rings 20 times: \n");
  for(i=0; i<20; i++){
    p=p->next;
    printf("%d   ", p->data);
  }
  if(IsLoopLinkList(L)){
    printf("\nThere is a ring in this singly linked list.\n");
  }
  else{
    printf("\nThis singly linked list has no rings.\n");
  }
  system("pause");
}