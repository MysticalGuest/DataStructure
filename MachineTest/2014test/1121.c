#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int monkey_peanuts()
{
    int n, row[SIZE], column[SIZE], x=0, y=0, step=0, i;
    printf("请分别输入花生的堆数和坐标：\n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("%d: ", i);
        scanf("%d%d", &row[i], &column[i]);
    }
    row[i]=0; column[i]=0; // 要回到原点
    /*一步一步走麻烦了，要的是结果，而不是过程
    for(i=0; i<n+1; i++){
        while(x!=row[i]||y!=column[i]){
            if(x!=row[i]){ //每次只能走一步，先走x方向的路
                if(x<row[i]){
                    x++;
                    step++;
                }
                else{
                    x--;
                    step++;
                }
            }
            else{
                if(y<column[i]){
                    y++;
                    step++;
                }
                else{
                    y--;
                    step++;
                }
            }
        }
    }*/
    for(i=0; i<n+1; i++){ // 这样一下子计算所走的路程更简单更快
        step+=labs(row[i]-x);
        step+=labs(column[i]-y);
        x=row[i];
        y=column[i];
    }
    printf("%d", step);
    return 0;
}
