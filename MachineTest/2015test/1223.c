#include <stdio.h>
#include <stdlib.h>

int maze()
{
    int N, m, n;
    int dir_x[]={-1, 1, 0, 0}, dir_y[]={0, 0, -1, 1}, dir_index; // �䶯����
    int m_x, n_y; // �˱䶯�������
    char direction;
    printf("�������Թ��Ĺ��N��\n");
    scanf("%d", &N);
    printf("������������λ������m, n��\n");
    scanf("%d%d", &m, &n);
    fflush(stdin); // �Ե��ϸ�����Ļس�
    printf("������Ҫ���Ե�ǰ������\n");
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
