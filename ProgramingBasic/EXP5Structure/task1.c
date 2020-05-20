#include<stdio.h>
#include<Windows.h>

struct information{
	long int num;
	char name[20];
	float score[3];
}inf[5];

void main(){
	int i, max=0;
	float ave[3];
	// 从键盘分别输入5个学生的数据信息包括学号、姓名、3门课的成绩
	printf("Enter the data of 5 students from the keyboard, including student number, name, and grades of 3 courses: \n");
	for(i=0; i<5; i++)
		scanf("%ld%s%f%f%f", &inf[i].num, inf[i].name, &inf[i].score[0], &inf[i].score[1], &inf[i].score[2]);
	for(i=0;i<3;i++){
		ave[i]=(inf[0].score[i]+inf[1].score[i]+inf[2].score[i])/3;
		// 第%d门课程的总的平均成绩为
		printf("The overall average grade for %dth course is: %.2f\n", i+1, ave[i]);
	}
	for(i=1; i<5; i++){
		if(ave[max] < ave[i])
			max = i;
	}
	// 最高分的学生的信息：
	printf("Information for the student with the highest score: \
	\nNo.:%ld\
	\nname:%s\
	\nscore:%.2f,%.2f,%.2f\n", inf[max].num,inf[max].name,inf[max].score[0],inf[max].score[1],inf[max].score[2]);

	system("pause");
}