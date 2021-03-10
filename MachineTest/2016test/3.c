#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100

typedef struct{
    int edge[3];
    float area;
}Triangle;

float caculate(Triangle t){
    int a=t.edge[0], b=t.edge[1], c=t.edge[2];
    if(a+b>c&&a+c>b&&b+c>a){
        float p=(a+b+c)/2;
        float s=sqrt(p*(p-a)*(p-b)*(p-c));
        return s;
    }
    else
        return 0.00;

}

int caculate_area()
{
    int n;
    Triangle tri[SIZE], temp;
    printf("请输入三角形个数:\n");
    scanf("%d", &n);
    printf("每行分别输入3条边长:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &temp.edge[j]);
        }
        temp.area=caculate(temp);
        tri[i]=temp;
    }
    for(int i=0; i<n; i++){
        printf("%.2f\n", tri[i].area);
    }
    return 0;
}
