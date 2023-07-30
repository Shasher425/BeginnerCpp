#include <bits/stdc++.h> 
using namespace std; 

void permute(string a, int l, int m) 
{ 
    
    if (l == m) 
        cout<<a<<endl; 
    else
    { 
        for (int i = l; i <= m; i++) 
        { 
            swap(a[l], a[i]); 
            permute(a, l+1, m); 
            swap(a[l], a[i]); 
        } 
    } 
} 
  

int main() 
{ 
    string str;
    cin >> str ;
    
    int n = str.size(); 
    permute(str, 0, n-1); 
    return 0; 
} 
