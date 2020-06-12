#include<stdio.h>
#include<Windows.h>

// 取3的幂
int mod3(int n);
// 对数组进行逆置
int* reverse(int* a, int begin ,int end);
// 求m和k
void findM_k(int n , int* m,int* k);
// 将数组右移
int* rightMove(int* a,int left ,int right ,int inteval);
//在cycle里面进行数组的交换
int* cycle_leader(int* a,int begin,int length,int k);
// 洗牌算法
int* shuffle(int* a,int begin,int length);
// 最后对数组进行2个2个的逆置
void reverse2(int* a,int length);

int main(void){
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    int c[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int *test;
    int m , k , n;
    // n = sizeof(a) / sizeof(a[0]);
    // findM_k( 5 , &m ,&k);
    // n =5;
    // test = rightMove(c , m , m+n-1,m);
    test = shuffle(c,0,sizeof(c)/sizeof(c[0]));
    reverse2(test , sizeof(c)/sizeof(c[0]) );
    for(int i = 0 ; i < sizeof(c)/sizeof(c[0]) ; i++)
        printf("%d\t",test[i]);
    system("pause");
    return 0;
}

int* shuffle(int* a,int begin,int length){
    if(length - begin <= 1)
        return a;
    if(length - begin == 2){
        int temp;
        temp = a[begin];
        a[begin] = a[begin+1];
        a[begin+1] = temp;
        return a;
    }
    int m , k , n ;
    n = (length-begin)/2;
    findM_k(n , &m , &k);
    int *test;
    test = rightMove(a,begin+m,begin+m+n-1,m);
    test = cycle_leader(test,begin,begin+2*m,k);
    shuffle(test , begin+2*m,length);
}


// 找到 2 * m = 3^k - 1 使得 3^k <= 2 * n < 3^(k +1)
void findM_k(int n , int* m,int* k){
    int num = 1;
    while(mod3(num) < 2 * n){
        num++;
    }
    num --;
    (*k) = num;
    (*m) = (mod3(num) - 1) / 2;
}

int mod3(int n){
    int num = 1;
    if(n==0){
        return num;
    }   
    for(int i = 0 ; i < n  ; i++){
        num *= 3;
    }
    return num;
}

int* rightMove(int* a,int left ,int right ,int inteval){
    a = reverse(a,left,right - inteval);

    a = reverse(a,right-inteval+1 , right);

    a = reverse(a,left,right);

    return a;
}


int* reverse(int* a, int begin ,int end){
    for(int i = 0 ; i< (end-begin+1)/2 ; i++){
        int temp = a[begin+i];
        a[begin+i] = a[end-i];
        a[end-i] = temp; 
    }
    return a;
}

// 对数组进行变换
int* cycle_leader(int* a,int begin,int length,int k){
    int mod = length - begin + 1;
    int temp;
    // for(int i = begin ; i<length-begin ;i++)
    //     printf("%d\t",a[i]);
    // printf("\n");
    // for(int i = 0 ; i < k ; i++){
        int from = mod3(i);
        for(int j = 2*from%mod ; j!= from ; j = 2*j%mod){
            temp = a[begin+j-1];
            a[begin+j-1] = a[begin+from-1];
            a[begin+from-1] = temp;
        }
        
    // }
    return a;
}

void reverse2(int* a,int length){
    for(int i = 0 ; i < length/2 ; i+=2){
        int temp = a[i];
        a[i] = a[i+1];
        a[i+1] =temp;
    }
}