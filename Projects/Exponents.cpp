#include <iostream>

using namespace std;

int power(int n, int p){
    if (p==0){
        
        return 1;
     
    }
    int prevP= power(n, p-1);
    return n*prevP;
    
}


int main()
{
    int n,p;
    cin>>n>>p;
    
    cout<<power(n,p)<<endl;

    return power(n,p);
}

