// ����������Ӧ��
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	char date;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *bt){
	char ch;
	ch=getchar();
	if(ch==' ')
		(*bt)=NULL;
	else{
		(*bt)=(BiTNode*)malloc(sizeof(BiTNode));
		(*bt)->date=ch;
		CreateBiTree(&((*bt)->LChild));
		CreateBiTree(&((*bt)->RChild));
	}
}

//������������������˫�׽��
BiTNode* Parent(BiTree bt,char x){
	BiTree p;
	if(bt==NULL||bt->date==x)
		return NULL;//�������߸��ڵ�Ϊx������NULL

	if(bt->LChild!=NULL)
		if(bt->LChild->date==x)
			return bt;
	if(bt->RChild!=NULL)
		if(bt->RChild->date==x)
			return bt;//�ҵ�x�Ľ�����˫��

	p=Parent(bt->LChild,x);//������������
	if(p!=NULL)
		return p;//�����������ҵ�������

	p=Parent(bt->RChild,x);//����������û�ҵ���������������
	if(p!=NULL)
		return p;//�����������ҵ�������

	return NULL;//�����������϶�û�ҵ������ؿ�
}

void ScanfBiTree(BiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree:\n");
	CreateBiTree(bt);
}

void main(){
	BiTree BT;
	char ch;
	ScanfBiTree(&BT);
	fflush(stdin);
	printf("Which parent of node do you want to get? : ");
	ch=getchar();
	if(Parent(BT,ch)==NULL)
		printf("It has no parent!\n");
	else
		printf("Its parent is: %c\n",Parent(BT,ch)->date);
}