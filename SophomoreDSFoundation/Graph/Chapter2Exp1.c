#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct{
	int elme[MAXSIZE];
	int last;
}list;

void initList(list *L){
	L->last=-1;
}

void inputList(list *L){
	int n,i;
	printf("Please input the number of integers that you want to set a sequence list\n(Maximum is 100):");
	scanf("%d",&n);
	printf("Please input the integers successively.\n");
	for(i=0;i<n;i++)
		scanf("%d",&L->elme[i]);
	L->last=n-1;
	printf("The sequence that you have set is:");
	for(i=0;i<n;i++)
		printf("%d\t",L->elme[i]);
	printf("\n");
}
void deleteList(list *L){
	int site,num,i,n;
	printf("Where do you want delete integers from:");
	scanf("%d",&site);
	while(site>L->last+1){
		printf("The location than you want to delete is illegal!Please input it again!\n");
		scanf("%d",&site);
	}
	printf("How many integers do you want to delete:");
	scanf("%d",&num);
	while(num>L->last-site+1){
		printf("The number of integers you want to delete is illegal!Please input it again!\n");
		scanf("%d",&num);
	}
	n=L->last-num-site+2;
	for(i=0;i<n;i++)
		L->elme[site+i-1]=L->elme[site+num+i-1];
	L->last=L->last-num;
	printf("The sequence list after deleting is:");
	for(i=0;i<=L->last;i++)
		printf("%d\t",L->elme[i]);
	printf("\n");
}

void main(){
	list l;
	initList(&l);
	inputList(&l);
	deleteList(&l);
}