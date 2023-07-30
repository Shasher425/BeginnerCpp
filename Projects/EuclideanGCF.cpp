#include <iostream>

using namespace std;

int gcf(int a, int b){
    while (b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main()
{   int a,b;
    cin>>a>>b;
    
    cout<<gcf(a,b);

    return 0;
}
