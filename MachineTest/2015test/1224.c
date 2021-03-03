#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int another_maze()
{
    int N, m, n, area[SIZE][SIZE];
    int dir_x[]={-1, 1, 0, 0}, dir_y[]={0, 0, -1, 1}, dir_index; // 变动方向
    int m_x, n_y; // 人变动后的坐标
    int direction;
    printf("请输入迷宫的规格N和地形：\n");
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &area[i][j]);
    printf("请输入人所在位置坐标m, n：\n");
    scanf("%d%d", &m, &n);
    printf("请输入要尝试的前进方向：\n");
    scanf("%d", &direction);
    switch (direction){
        case 0: dir_index=0; // 左
        case 1: dir_index=3; // 下
        case 2: dir_index=1; // 右
        case 3: dir_index=2; // 上
        default: ;
    }
    m_x=m+dir_x[dir_index];
    n_y=n+dir_y[dir_index];
    if(m_x<0||m_x>N-1||n_y<0||n_y>N-1||area[m_x][n_y]==1)
        printf("N\n");
    else
        printf("Y\n");
    return 0;
}
