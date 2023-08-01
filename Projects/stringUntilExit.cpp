#include <iostream>
#include <queue>
#include <string>
 using namespace std;
int main() {
    queue<std::string> myQueue;
    string input;

    cout << "Enter strings to add to the queue. Type 'exit' to stop.\n";

    while (true) {
        cout << "Enter a string: ";
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        myQueue.push(input);
    }

    cout << "The elements in the queue are:\n";

    while (!myQueue.empty()) {
        cout << myQueue.front() << "\n";
        myQueue.pop();
    }

    return 0;
}
