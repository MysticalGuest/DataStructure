#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define LEN sizeof(struct student)

struct student{
	long num;
	char sex;
	int age;
	char name[20];
	struct student *next;
};

struct student *creat(void){
	struct student *head;
	struct student *p1,*p2;
	p1=p2=(struct student *)malloc(LEN);
	// 分别输入每个学生的学号、性别、年龄、姓名。(以输入0结束输入)
	printf("Enter the student ID, gender, age, and name of each student separately. (End input with input 0) \n");
	scanf("%ld,%c,%d,%s", &p1->num, &p1->sex, &p1->age, p1->name);
	printf("2233%d\n", p1->num);
	printf("2233%d\n", p1->sex);
	printf("2233%d\n", p1->age);
	printf("2233%d\n", p1->name);
	head=NULL;
	// while(p1->num!=0){
	// 	if(head==NULL)
	// 		head=p1;
	// 	else
	// 		p2->next=p1;
	// 	p2=p1;
	// 	p1=(struct student *)malloc(LEN);
	// 	scanf("%ld,%c,%d,%s", &p1->num, &p1->sex, &p1->age, p1->name);
	// }
	free(p1);
	p2->next=NULL;
	return(head);
}
void main(){
	struct student *pt;
 	pt=creat();
	while(pt != NULL){
		printf("\nnum:%ld\tname:%s\tsex:%c\tage:%d",pt->num,pt->name,pt->sex,pt->age);
		pt = pt->next;
	}

	system("pause");
}