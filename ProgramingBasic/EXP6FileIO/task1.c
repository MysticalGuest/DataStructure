#include<stdio.h>
struct student{
	long num;
	char name[20];
	float score[3];
}stu[5];
void main(){
	FILE *fp;
	int i,j;
	float sum;
	printf("分别输入这5名学生的学号、姓名、3门课程成绩。\n");
	for(i=0;i<5;i++)
		scanf("%ld%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		fp=fopen("stud.txt","w+");
	for(i=0;i<5;i++)
		fprintf(fp,"%ld\t%s\t%.2f\t%.2f\t%.2f\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	for(i=0;i<3;i++){
		sum=0;
		for(j=0;j<5;j++){
			sum+=stu[j].score[i];
		}
		fprintf(fp,"第%d门课程成绩平均分是：%.2f\n",i+1,sum/5);
	}

}