#include <iostream>

using namespace std;

#define Size 100

class Data{
public:
    int num[Size];
    void sort_nums(int length){ // ʹ�ò�������
        for(int i=1; i<length; i++){ // ��Ϊ�±�0���ѽ��ź�
            int current=num[i], pre=i-1;
            while(num[pre]>current&&pre>=0){
                num[pre+1]=num[pre];
                pre--;
            }
            num[pre+1]=current;
        }
    }
};

int my_sort()
{
    int n, m;
    Data data_array[Size], d;
    cout << "Please input n and m: " << endl;
    cin >> n >> m;
    cout << "Output the number of each group separately: " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> d.num[j];
        }
        d.sort_nums(m);
        data_array[i]=d;
    }
    // ���
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << data_array[i].num[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
