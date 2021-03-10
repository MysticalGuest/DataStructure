#include <iostream>

using namespace std;

#define Size 100

long int C(int n, int m){
    // ¹«Ê½
    long int molecule=1, denominator=1;
    int p=n, q=m;
    for(int i=0; i<m; i++){
        molecule = molecule * p;
        p--;
        denominator = denominator * q;
        q--;
    }
    return molecule/denominator;
}

int arrange()
{
    int num, k;
    cout << "Please input n and m: " << endl;
    cin >> num >> k;
    cout << C(num, k) << endl;
    return 0;
}
