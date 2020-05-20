#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 6

typedef struct{
	int elem[MAXSIZE];
	int last;
}list;

void initlist(list *L){
	L->last=-1;
}

void scanflist(list *L){
	int i,num;
	printf("输入最多6个数填充顺序表，你想输入的元素的个数是：");
	scanf("%d",&num);
	L->last=num-1;
	for(i=0;i<=L->last;i++)
		scanf("%d",&L->elem[i]);

}

void Locate(list *L,int e){
	int i,j=0;
	for(i=0;i<L->last;i++)
		if(L->elem[i]==e){
			printf("元素%d在顺序表中的位置是%d。\n",e,(i+1));
		    j++;
		}
	if(j==0)
		printf("此顺序表中无%d元素。\n",e);
}

void InsList(list *l){
	int i,elem,site;
	printf("你想在第几个元素后插入一个元素：");
	scanf("%d",&site);
	printf("你想插入的元素是：");
	scanf("%d",&elem);
	if(site!=l->last+1){
		for(i=l->last;i>=site-1;i--)
			l->elem[i+1]=l->elem[i];
		l->elem[site]=elem;
	}
	else
		l->elem[l->last+1]=elem;
	l->last++;	
}

void DelList(list *l){
	int i,site;
	printf("你想删除第几个位置的元素：");
	scanf("%d",&site);
	if(site<=l->last+1){
		for(i=site-1;i<=l->last-site+1;i++)
			l->elem[i]=l->elem[i+1];
		l->last--;
		printf("删除元素后的顺序表为：\n");
		for(i=0;i<=l->last;i++)
			printf("%d\n",l->elem[i]);
	}
	else
		printf("ERROR!插入位置不合法！\n");	
}

void main(){
	int i,e,flag=1,len=1;
	char judge;
	list l;
	initlist(&l);
	scanflist(&l);
	while(flag){
	    printf("请输入你要查找的元素：");
		scanf("%d",&e);
		Locate(&l,e);
		printf("你是否还想继续查找(输入$继续查找,输入其他结束查找)？\n");
		getchar();              /*承接前一个scanf函数的回车，使下一个scanf函数运行*/
	    scanf("%c",&judge);
		if(judge!='$')
			flag=0;
	}
	flag=1;
	while(flag){
		if(l.last+len<=MAXSIZE){
			InsList(&l);
			len++;
		}
		else{
			printf("ERROR!顺序表已满！\n");
			break;
		}
		printf("插入元素后的顺序表为：\n");
		for(i=0;i<=l.last;i++)
			printf("%d\n",l.elem[i]);
		printf("你是否还想继续插入(输入$继续插入,输入其他结束插入)？\n");
		getchar();          
	    scanf("%c",&judge);
		if(judge!='$')
			flag=0;
	}
	flag=1;
	while(flag){
		if(l.last>=0)
			DelList(&l);
		else{
			printf("ERROR!顺序表为空！\n");
			break;
		}
		printf("你是否还想继续插入(输入$继续插入,输入其他结束插入)？\n");
		getchar();          
	    scanf("%c",&judge);
		if(judge!='$')
			flag=0;
	}
}