#include <iostream>
using namespace std;

int main() {
    int base; 
    cin >> base; 
    
    for (int i = 0; i < base; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

