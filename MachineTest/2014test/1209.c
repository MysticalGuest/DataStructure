#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// 向4个方向延伸的方法
int dir_x[]={1, -1, 0, 0}; // 向x轴左右延伸
int dir_y[]={0, 0, 1, -1}; // 向y轴上下延伸

int Max[SIZE][SIZE]; // 每个点能下滑的最大距离，初始化为都为0

// 判断是否越界
int out_bounds(int x, int y, int r, int c){
    if(x<0||x>r||y<0||y>c)
        return 1;
    else
        return 0;
}

// 递归滑到坡底
int skiing(int area[SIZE][SIZE], int x, int y, int r, int c){
    if(Max[x][y]) // 不为0，那就是结果了？
        return Max[x][y];
    else{
        for(int i=0; i<4; i++){ // 最多有4个方向
            if(!out_bounds(x+dir_x[i], y+dir_y[i], r, c)){ // 如果没有越界
                if(area[x][y]>area[x+dir_x[i]][y+dir_y[i]]){ // 可以滑下去
                    int temp = skiing(area, x+dir_x[i],  y+dir_y[i], r, c);
                    Max[x][y] = Max[x][y] > temp ? Max[x][y] : temp+1;
                }
            }
        }
        return Max[x][y];
    }
}

int ski()
{
    int row, column, area[SIZE][SIZE], highest_x=0, hightest_y=0, highest=0, num;
    printf("请分别输入区域的行数和列数：\n");
    scanf("%d%d", &row, &column);
    printf("请分别输入区域的高度：\n");
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            scanf("%d", &area[i][j]);
            //Max[i][j]=0;
            if(highest<area[i][j]){ //记录最高点的高度及坐标
                highest=area[i][j];
                highest_x=i;
                hightest_y=j;
            }
        }
    }
    //printf("%d,%d,%d\n", highest, highest_x, hightest_y);

    num = skiing(area, highest_x, hightest_y, row, column)+1;
    printf("%d", num);
    return 0;
}
