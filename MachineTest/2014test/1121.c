#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int monkey_peanuts()
{
    int n, row[SIZE], column[SIZE], x=0, y=0, step=0, i;
    printf("��ֱ����뻨���Ķ��������꣺\n");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("%d: ", i);
        scanf("%d%d", &row[i], &column[i]);
    }
    row[i]=0; column[i]=0; // Ҫ�ص�ԭ��
    /*һ��һ�����鷳�ˣ�Ҫ���ǽ���������ǹ���
    for(i=0; i<n+1; i++){
        while(x!=row[i]||y!=column[i]){
            if(x!=row[i]){ //ÿ��ֻ����һ��������x�����·
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
    for(i=0; i<n+1; i++){ // ����һ���Ӽ������ߵ�·�̸��򵥸���
        step+=labs(row[i]-x);
        step+=labs(column[i]-y);
        x=row[i];
        y=column[i];
    }
    printf("%d", step);
    return 0;
}
