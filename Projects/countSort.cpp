#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = arr[0], min_val = arr[0];
    for (int num : arr) {
        if (num > max_val)
            max_val = num;
        if (num < min_val)
            min_val = num;
    }

    int range = max_val - min_val + 1;
    vector<int> count(range, 0);

    for (int num : arr)
        count[num - min_val]++;

    int idx = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[idx++] = i + min_val;
            count[i]--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
