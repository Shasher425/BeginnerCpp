#include <iostream>
using namespace std;
void primeNum(int n) {
    int prime[100] = {0};

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            for (int j = i * 2; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            cout << i << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    primeNum(n);

    return 0;
}

