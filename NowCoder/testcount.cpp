#include <iostream>

using namespace std;

unsigned int f(unsigned int n){
    if(n==0||n==1){
        return 1;
    }
    return f(n-1)+f(n-2);
}

void count(int n){
    unsigned int tmp = n-((n>>1)&033333333333)-((n>>2)&011111111111);
    std:cout<<((tmp+(tmp>>3))&030707070707)%63<<std::endl;
}

int testcount()
{
    count(f(7));
    count(f(9));
    return 0;
}
