#include<stdio.h>

struct student{
	long num;
	float score[4];
}stu[50];

int advancescanf(){
	int i=0;
	printf("Please input every students' Student Number and score of four subjects\n(Maximum 50 students,End by inputing -100)¡£\n");
	while(1){
		scanf("%ld",&stu[i].num);
		if(i>50||stu[i].num==-100)
			break;
		scanf("%f%f%f%f",&stu[i].score[0],&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		i++;
	}
	return i;
}

float totalscore(float a[4]){
	float sum;
	sum=a[0]+a[1]+a[2]+a[3];
	return sum;
}

void sort(float *q[50],int n,int s[50]){
	int i,j,max,t;
	float *temp;
	for(i=0;i<n;i++)
		s[i]=i;
	for(i=0;i<n;i++){
		max=i;
		for(j=i+1;j<n;j++)
			if(*(q+max)<*(q+j))
				max=j;
		if(max!=i){
            temp=q[max];
			q[max]=q[i];
			q[i]=temp;
			t=s[max];
			s[max]=s[i];
			s[i]=t;
		};
		
	}
}

void main(){
	int n,i,j=0,num,seq[50];
	float a,b,ascore[50],*p[50];
	n=advancescanf();
	for(i=0;i<n;i++)
		ascore[i]=totalscore(stu[i].score);
	p[0]=ascore;
	sort(&p[50],n,seq);
	printf("Student Number\tScore of each subject\tAverage scoreTotal scoreRank\n");
	for(i=0;i<n;i++)
		printf("%ld\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n",stu[seq[i]].num,
		stu[seq[i]].score[0],stu[seq[i]].score[1],stu[seq[i]].score[2],stu[seq[i]].score[3],ascore[i]/4,
		ascore[i],i+1);

	printf("Please input the number of subjects(1,2,3,4)£¬procedure will ouput information of students whose score of this subject is above 90 and total score is in the top 3.(End by inputing -100)\n");
	scanf("%d",&num);
	while(1){
		if(num>4||num<1)
			printf("There is no %d subject!Please continue to query.\n",num);
		else{
			for(i=0;i<n;i++)
				if(stu[seq[i]].score[num-1]>=90){
					printf("Student Number\tScore of each subject\tAverage scoreTotal scoreRank\n");
					printf("%ld\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n",
					stu[seq[i]].num,
					stu[seq[i]].score[0],stu[seq[i]].score[1],stu[seq[i]].score[2],stu[seq[i]].score[3],ascore[seq[i]]/4,
					ascore[seq[i]],i+1);
				}
				else
					j++;
			if(j==n)
				printf("There is no student who meets the conditions!\n");
			j=0;
		}
		scanf("%d",&num);
		if(num==-100)
			break;
	}
}