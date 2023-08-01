#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int value) {
        q1.push(value);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot perform pop operation.\n";
            return;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot perform top operation.\n";
            return -1;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement);
        swap(q1, q2);
        return topElement;
    }
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
int main() {
    StackUsingQueue myStack;
    cout << "Enter elements to push into the stack. Type -1 to stop.\n";
    int value;
    while (true) {
        cout << "Enter an element: ";
        cin >> value;
        if (value == -1) {
            break;
        }
        myStack.push(value);
    }
    cout << "Popping elements from the stack:\n";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
    return 0;
}
