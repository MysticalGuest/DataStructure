#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define BiTSize 50

int i=0;

typedef struct{
	char elem[BiTSize];
}SeqBiTree;

void CreateSeqBiTree(SeqBiTree *bt){
	char ch;
	ch=getchar();
	while(ch!='#'){
		bt->elem[i]=ch;
		i++;
		ch=getchar();
		if(i==BiTSize-1){
			printf("Space is Full!");
			break;
		}
	}
}

void PreOrder(SeqBiTree bt,int j){
	if(bt.elem[j]!=' '&&j<i){
		printf("%c",bt.elem[j]);
		PreOrder(bt,2*j+1);
		PreOrder(bt,2*j+2);
	}
}

void ScanfSeqBiTree(SeqBiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree(Ending with '#'):\n");
	CreateSeqBiTree(bt);
}

void main(){
	SeqBiTree BT;
	ScanfSeqBiTree(&BT);
	printf("The preorder is: ");
	PreOrder(BT,0);
	printf("\n");
	system("pause");
}