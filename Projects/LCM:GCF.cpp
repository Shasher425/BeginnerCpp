#include <iostream>

using namespace std;

int gcf(int a, int b) {
    if (b == 0)
        return a;
    return gcf(b, a % b);
}


int lcm(int a, int b) {
    int gcfResult = gcf(a, b);
    return (a * b) / gcfResult;
}

int main() {
    int num1, num2;
    
    cout << "";
    cin >> num1 >> num2;
    
    int lcmResult = lcm(num1, num2);
    
    cout << "LCM of " << num1 << " and " << num2 << " is " << lcmResult << endl;
    
    return 0;
}


