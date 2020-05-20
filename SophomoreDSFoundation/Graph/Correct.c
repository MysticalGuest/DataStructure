#include<stdio.h>
#include<stdlib.h>

#define BiTSize 50

typedef struct{
	char elem[BiTSize];
}SeqBiTree;

void CreateSeqBiTreeCalculate(SeqBiTree *bt){
	int i=0,j=0,k,sum=0;
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
	while(j<i){
		k=2*j+1;
		if(k<i)
			if(bt->elem[k]!=' ')
				sum++;
		else if(k+1<i)
			if(bt->elem[k]!=' '||bt->elem[k+1]!=' ')
				sum++;
		j++;
	}
	printf("The amount of unleaf is: %d\n",sum);
}

void ScanfSeqBiTree(SeqBiTree *bt){
	printf("Please input some characters(Thereinto 'space' is on behalf of Blank Child) to \nbuild a BiTree(Ending with '#'):\n");
	CreateSeqBiTreeCalculate(bt);
}

void main(){
	SeqBiTree BT;
	ScanfSeqBiTree(&BT);
}