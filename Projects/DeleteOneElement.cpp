#include <iostream>
#include <cstdint>
using namespace std;
struct Node
{
    int data;
    struct Node* nxp;
};
struct Node* XOR(struct Node* a, struct Node* b) {
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}
struct Node* insert(struct Node** head, int value)
{
    if (*head == NULL)
    {
        struct Node* node = new Node;
        node->data = value;
        node->nxp = XOR(NULL, NULL);
        *head = node;
    }
    else
    {
        struct Node* curr = *head;
        struct Node* prev = NULL;
        struct Node* node = new Node;
        curr->nxp = XOR(node, XOR(NULL, curr->nxp));
        node->nxp = XOR(NULL, curr);
        *head = node;
        node->data = value;
    }
    return *head;
}
void printList(struct Node** head)
{
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next;
    while (curr != NULL) {
        cout << curr->data << " ";
        next = XOR(prev, curr->nxp);
        prev = curr;
        curr = next;
    }
}
struct Node* delEnd(struct Node** head)
{
    if (*head == NULL)
        cout << "List is empty";
    else
    {
        struct Node* curr = *head;
        struct Node* prev = NULL;
        struct Node* next;
        while (XOR(curr->nxp, prev) != NULL)
        {
            next = XOR(prev, curr->nxp);
            prev = curr;
            curr = next;
        }
        if (prev != NULL) {
            prev->nxp = XOR(XOR(prev->nxp, curr), NULL);
        }
        else {
            *head = NULL;
        }
        delete(curr);
    }
    return *head;
}
void displayHead(struct Node** head)
{
    if (*head != NULL)
        cout << "Tail: " << (*head)->data << endl;
    else
        cout << "Head is NULL" << endl;
}
bool deleteElement(struct Node** head, int value)
{
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            if (prev != NULL)
                prev->nxp = XOR(XOR(prev->nxp, curr), XOR(prev, curr->nxp));
            else
                *head = XOR(NULL, curr->nxp);
            if (curr->nxp != NULL)
            {
                next = XOR(prev, curr->nxp);
                next->nxp = XOR(XOR(curr, next->nxp), prev);
            }
            delete curr;
            return true;
        }
        next = XOR(prev, curr->nxp);
        prev = curr;
        curr = next;
    }
    return false;
}

int main()
{
    struct Node* head = NULL;
    int n, val;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        insert(&head, val);
    }
    displayHead(&head);
    cout << "Enter the element to delete: ";
    cin >> val;
    if (deleteElement(&head, val))
        cout << "Element " << val << " deleted successfully." << endl;
    else
        cout << "Element not found in the list." << endl;
        displayHead(&head);
    if (head == NULL)
        cout << "List is empty";
    else
        printList(&head);
    return 0;
}
