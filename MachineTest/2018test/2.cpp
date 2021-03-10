#include <iostream>

using namespace std;

#define Size 100

long int Factorial(int n){
    if(n==1)
        return 1;
    else{
        return n*Factorial(n-1);
    }
}

int factorial_main()
{
    int n, num;
    long int  result[Size];
    cout << "Please input the number of each group n: " << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        result[i]=Factorial(num);
    }
    for(int i=0; i<n; i++){
        cout << result[i] << endl;
    }
    return 0;
}
