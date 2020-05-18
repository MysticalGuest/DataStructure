#include<stdio.h>
#include<Windows.h>

void printaverage(float a[][4]){
	int i, j;
	float ave, sum=0;
  // 五位同学第一、二、三门课的成绩平均分分别是
	printf("The average scores of the five students in the first, second and third courses are: ");
	for(i=1; i<4; i++){
		for(j=0; j<5; j++)
			sum = sum + a[j][i];
		ave = sum/5;
		printf("\t%.2f", ave);
		sum = 0;
	}
	printf("\n");
}

void printfail(float a[][4]){
	int i, j, num1=0, num2=0;
	for(i=0; i<5; i++){
		for(j=1; j<4; j++)
			if(a[i][j] < 60)
				num1 = num1+1;
			if(num1>1){
        // 学号为%.0f的同学有两门以上不及格，其不及格课程的成绩是
				printf("Students with a student number of %.0f have more than two failing grades: ", a[i][0]);
				for(j=1; j<4; j++)
					if(a[i][j]<60)
						printf("\t%.2f", a[i][j]);
          else
            num2 = num2+1;
        num1 = 0;
        printf("\n");
		  }
	}
	if(num2==5)
    // 没有学生有两门以上不及格
		printf("No student has more than two fail.\n");
}
void printname(float a[][4]){
	int i, j;
	float sum=0, ave;
  // 三门课平均成绩在85-90分的学生的学号是：
	printf("The student numbers of students with average grades of 85-90 in the three courses are: ");
	for(i=0; i<5; i++){
		for(j=1; j<4; j++)
			sum = sum+a[i][j];
	ave = sum/3;
	if((ave>85) && (ave<90))
		printf("\t%.0f", a[i][0]);
	sum = 0;
	ave = 0;
	}
	printf("\n");
}

void main(){
	int i, j;
	float s[5][4];
  // 请分别输入五个同学的每门课成绩
	printf("Please enter the scores of each class of five students.\n");
	for(j=0;j<5;j++){
    // 第%d个同学的学号及三门课成绩
		printf("Student ID and results of the three courses of %dth student: \n",j+1);
		for(i=0; i<4; i++)
			scanf("%f", &s[j][i]);
	}
	//printf("第二个同学的学号及三门课成绩：\n");
	//for(i=0;i<4;i++)
	//	scanf("%f",&s[1][i]);
	//printf("第三个同学的学号及三门课成绩：\n");
	//for(i=0;i<4;i++)
	//	scanf("%f",&s[2][i]);
	//printf("第四个同学的学号及三门课成绩：\n");
	//for(i=0;i<4;i++)
	//	scanf("%f",&s[3][i]);
	//printf("第五个同学的学号及三门课成绩：\n");
	//for(i=0;i<4;i++)
	//	scanf("%f",&s[4][i]);
	printaverage(s);
	printfail(s);
	printname(s);

  system("pause");
}
