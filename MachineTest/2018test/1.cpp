#include <iostream>

using namespace std;

#define Size 100

int multiply()
{
    int n, result[Size], first, second;
    cout << "Please input the number of each group n: " << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> first >> second;
        result[i]=first * second;
    }
    for(int i=0; i<n; i++){
        cout << result[i] << endl;
    }
    return 0;
}
