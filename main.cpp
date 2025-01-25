#include <iostream>
using namespace std;

// Node structure to represent each element of the stack
struct Node {
    int data;
    Node* next;
};

// Stack class with linked list implementation
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor: Initialize the stack to be empty
    Stack() {
        top = nullptr;
    }

    // Destructor: Free all the nodes when the stack is destroyed
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push operation: Add an element to the stack
    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Set the value
        newNode->next = top;        // Point the new node to the current top
        top = newNode;              // Update top to the new node
        cout << value << " pushed to stack." << endl;
    }

    // Pop operation: Remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop an element." << endl;
            return -1; // Return a sentinel value
        } else {
            Node* temp = top;
            int poppedValue = top->data;
            top = top->next; // Move top to the next node
            delete temp;     // Free the memory of the popped node
            return poppedValue;
        }
    }

    // Peek operation: Get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No element to peek." << endl;
            return -1; // Return a sentinel value
        } else {
            return top->data;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            cout << "Stack elements: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Popped element is: " << stack.pop() << endl;

    stack.display();

    return 0;
}
