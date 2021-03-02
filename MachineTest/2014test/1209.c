#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// ��4����������ķ���
int dir_x[]={1, -1, 0, 0}; // ��x����������
int dir_y[]={0, 0, 1, -1}; // ��y����������

int Max[SIZE][SIZE]; // ÿ�������»��������룬��ʼ��Ϊ��Ϊ0

// �ж��Ƿ�Խ��
int out_bounds(int x, int y, int r, int c){
    if(x<0||x>r||y<0||y>c)
        return 1;
    else
        return 0;
}

// �ݹ黬���µ�
int skiing(int area[SIZE][SIZE], int x, int y, int r, int c){
    if(Max[x][y]) // ��Ϊ0���Ǿ��ǽ���ˣ�
        return Max[x][y];
    else{
        for(int i=0; i<4; i++){ // �����4������
            if(!out_bounds(x+dir_x[i], y+dir_y[i], r, c)){ // ���û��Խ��
                if(area[x][y]>area[x+dir_x[i]][y+dir_y[i]]){ // ���Ի���ȥ
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
    printf("��ֱ����������������������\n");
    scanf("%d%d", &row, &column);
    printf("��ֱ���������ĸ߶ȣ�\n");
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            scanf("%d", &area[i][j]);
            //Max[i][j]=0;
            if(highest<area[i][j]){ //��¼��ߵ�ĸ߶ȼ�����
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
