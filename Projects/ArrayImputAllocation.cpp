#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Enter the value of 'a': ";
    cin >> a;

    int *p = new int();
    cout << "Enter the value to be assigned to the dynamic integer: ";
    cin >> *p;

    delete (p);

    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;

    p = new int[size];

    cout << "Enter " << size << " values for the dynamic array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> p[i];
    }

    cout << "Values in the dynamic array are:\n";
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    delete[] p;
    p = nullptr;

    return 0;
}
