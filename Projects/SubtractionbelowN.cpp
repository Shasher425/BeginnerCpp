
#include <iostream>

using namespace std;

int diff(int n){
    
    if (n==0){
        return 0;
        
    }
    
    int prevDiff=diff(n-1);
    return n-prevDiff;
    
}



int main()
{
    int n;
    cin>>n;
    
    cout<<diff(n)<<endl;

    return 0;
}
