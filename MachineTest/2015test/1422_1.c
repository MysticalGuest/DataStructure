#include <stdio.h>
#include <stdlib.h>

int binary_printf(){
    int a,b,k,i;
    int remainder[30];
    while(1){
        //������һ��remainder���飬�����ռ��̳������õ�������ջ���������
        printf("������һ��ʮ������:  ");
        scanf("%d",&a);
        k=0;
        while(a!=0){
            b=a/2;
            k++;
            remainder[k]=a-b*2;
            a=a/2;
        };
        printf("ת���ɶ���������:  ");
        for (i=k; i>=1; i--)
        {
            printf("%d",remainder[i]);
        }
        printf("\n\n");
    }
    return 0;
}

/*
    ��C�����У���ӡ16���ƿ���ʹ��printf��%x��ʽ��
    ��ӡ����������û���ֳɵĸ�ʽ��ֵ��ֻ�����б�д������ӡ��
    ������һ����ӡ������ֵ�ĺ�����ͨ��λ��������λ�ж϶�����ֵ���������Ӧ��ֵ��
    Ĭ�ϸ�λ0�������
*/
void print_bin(int n)
{
    int l = sizeof(n)*8; //��λ����
    int i=n;
    if(i == 0){
         printf("0");
         return;
    }
    for(i = l-1; i >= 0; i --) //��ȥ��λ0.
    {
        if(n&(1<<i)) break;
    }

    for(;i>=0; i --)
        printf("%d", (n&(1<<i)) != 0);
}
