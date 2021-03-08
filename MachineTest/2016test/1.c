#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct{
    int data[3][3];
    int ave[3];
}Time;

void caculate_ave(Time *time){
    int sum_millisecond=0, ave;
    // 1秒=1000毫秒
    for(int i=0; i<3; i++){
        sum_millisecond+=time->data[i][0]*60000+time->data[i][1]*1000+time->data[i][2];
    }
    ave = sum_millisecond/3;
    //printf("平均：  %d\n", ave);
    int minute=ave/60000;
    //printf("分：  %d\n", minute);
    int second=(ave-minute*60000)/1000;
    //printf("秒：  %d\n", second);
    int millisecond=ave-minute*60000-second*1000;
    //printf("毫秒：  %d\n", millisecond);
    time->ave[0]=minute;
    time->ave[1]=second;
    time->ave[2]=millisecond;
}

int average_time()
{
    int n;
    Time times[SIZE];
    Time time;
    printf("请输入行数:\n");
    scanf("%d", &n);
    printf("每行输入九个整数，表示每圈所用的分，秒，和毫秒:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                scanf("%d", &time.data[j][k]);
            }
        }
        caculate_ave(&time);
        times[i]=time;
    }
    for(int i=0; i<n; i++){
        printf("%d  %d  %d\n", times[i].ave[0], times[i].ave[1], times[i].ave[2]);
    }
    return 0;
}
