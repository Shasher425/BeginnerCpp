#include <iostream>

using namespace std;

void increment(int &a, int incrementBy) {
    a += incrementBy;
}

int main() {
    int a;
    cin >> a;

    int incrementBy;
    cin >> incrementBy;

    increment(a, incrementBy);

    cout << "Result: " << a << endl;

    return 0;
}
