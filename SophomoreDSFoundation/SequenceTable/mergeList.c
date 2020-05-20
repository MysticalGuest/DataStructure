// 非递减顺序表合并
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define MMAXSIZE 100
typedef struct{
	int elem[MAXSIZE];
	int last;
}list;
typedef struct{
	int elem[MMAXSIZE];
	int last;
}alist;

void initlist(list *L){
	L->last=-1;
}
void ainitlist(alist *L){
	L->last=-1;
}
void inputlist(list *L){
	int i=0,e;
	scanf("%d",&e);
	while(e!=-100){
		L->elem[i]=e;
		i++;
		if(i>=10){
			printf("顺序表已满！\n");
			break;
		}
		scanf("%d",&e);
	}
	L->last=i-1;
}
void merge(list *L1,list *L2){
	int i,j,tail,len,m,n;
	if(L1->last+L2->last+2<=MAXSIZE){
		len=L1->last+L2->last+1;
		if(L1->elem[L1->last]<=L2->elem[0])
			for(i=0;i<=L2->last;i++)
				L1->elem[L1->last+i+1]=L2->elem[i];
		else if(L2->elem[L2->last]<=L1->elem[0])
			for(i=0;i<=L1->last;i++){
				L2->elem[L2->last+i+1]=L1->elem[i];
				printf("两个非递减顺序表合并后的非递减顺序表为：\n");
				for(i=0;i<=len;i++)
					printf("%d\t",L2->elem[i]);
			}
		else{
			tail=len;
			m=L1->last;
			n=L2->last;
			for(i=0;i<len;i++){
				if(L1->elem[m]<=L2->elem[n]){
					L1->elem[tail]=L2->elem[n];
					if(n>0)
						n--;
				}
				else{
					L1->elem[tail]=L1->elem[m];
					if(m>0)
						m--;
				}
				tail--;
			}
			if(L2->elem[m]<=L1->elem[n])
				L1->elem[tail]=L2->elem[n];
		}
		L1->last += L2->last;
		printf("两个非递减顺序表合并后的非递减顺序表为：\n");
		for(i=0;i<=len;i++)
			printf("%d\t",L1->elem[i]);
	}
		else{
			alist LC;
			ainitlist(&LC);
			len=L1->last+L2->last+1;
			LC.last=len;
			m=0;
			n=0;
			for(i=0;i<len;i++){
				if(L1->elem[m]<=L2->elem[n]){
					LC.elem[i]=L1->elem[m];
					if(m==L1->last+1)
						break;
					m++;
				}
				else {
					LC.elem[i]=L2->elem[n];
					if(n==L2->last+1)
						break;
					n++;
				}
			}
			if(m<len)
				for(j=m;j<=L1->last;j++){
					LC.elem[i]=L1->elem[j];
					i++;
				}
			if(n<len)
				for(j=n;j<=L2->last;j++){
					LC.elem[i]=L2->elem[j];
					i++;
				}
			printf("两个非递减顺序表合并后的非递减顺序表为：\n");
			for(i=0;i<=len;i++)
				printf("%d\t",LC.elem[i]);
		}
}
void main(){
	list LA,LB;
	initlist(&LA);
	initlist(&LB);
	printf("输入最多10个元素(输入-100结束输入)，建立顺序表LA:\n");
	inputlist(&LA);
	printf("输入最多10个元素(输入-100结束输入)，建立顺序表LB:\n");
	inputlist(&LB);
	merge(&LA,&LB);
}