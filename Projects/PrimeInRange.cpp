#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            cout << i << " is a prime number in the range of your numbers" << endl;
        }
    }

    return 0;
}

