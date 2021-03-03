#include <stdio.h>
#include <stdlib.h>

int maze()
{
    int N, m, n;
    int dir_x[]={-1, 1, 0, 0}, dir_y[]={0, 0, -1, 1}, dir_index; // 变动方向
    int m_x, n_y; // 人变动后的坐标
    char direction;
    printf("请输入迷宫的规格N：\n");
    scanf("%d", &N);
    printf("请输入人所在位置坐标m, n：\n");
    scanf("%d%d", &m, &n);
    fflush(stdin); // 吃掉上个输入的回车
    printf("请输入要尝试的前进方向：\n");
    scanf("%c", &direction);
    switch (direction){
        case 'w': dir_index=2;
        case 's': dir_index=3;
        case 'a': dir_index=0;
        case 'd': dir_index=1;
        default: ;
    }
    m_x=m+dir_x[dir_index];
    n_y=n+dir_y[dir_index];
    if(m_x<0||m_x>N-1||n_y<0||n_y>N-1)
        printf("N\n");
    else
        printf("Y\n");
    return 0;
}
