// GFG qustion Remove loop in Linked List
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
         unordered_map<Node *, int> isVisited;
        Node *previous = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            if (isVisited.count(current))
            {
                previous->next = nullptr;
                return;
            }
            isVisited[current] = 1;
            previous = current;
            current = current->next;
        }
        
        
        // code here
    }
};


///////////////////////////////
//for
//      
//      full
//              
//              code
//
//////////////////////////////////


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to detect and remove a loop in the linked list
void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd's cycle detection algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // Loop detected
    }

    // If no loop is found, return
    if (slow != fast) return;

    // Step 2: Find the start of the loop
    slow = head;
    Node* prev = nullptr;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove the loop
    prev->next = nullptr; // Break the cycle
}

// Function to insert a new node at the end
Node* insert(Node* head, int data) {
    if (!head) return new Node(data);

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(data);
    return head;
}

// Function to create a loop in the linked list
void createLoop(Node* head, int pos) {
    if (pos == -1) return;

    Node* loopStart = nullptr;
    Node* temp = head;
    int count = 0;

    while (temp->next) {
        if (count == pos) loopStart = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopStart; // Creating the loop
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code
int main() {
    Node* head = nullptr;
    int n, value, pos;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insert(head, value);
    }

    cout << "Enter the position to create a loop (-1 for no loop): ";
    cin >> pos;

    createLoop(head, pos); // Creating a loop if specified

    removeLoop(head); // Detect and remove the loop

    cout << "Linked List after removing loop:\n";
    printList(head); // Print the modified linked list

    return 0;
}
