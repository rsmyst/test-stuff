#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int stackSize;

public:
    Stack() {
        top = nullptr;
        stackSize = 0;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        stackSize++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        stackSize--;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return stackSize;
    }

    void display() {
        Node* current = top;
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;
    int queueSize;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        queueSize = 0;
    }

    void enQueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        queueSize++;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        queueSize--;
        return value;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int size() {
        return queueSize;
    }

    void display() {
        Node* current = front;
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Stack stack;
    Queue queue;

    // Stack operations
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack elements: ";
    stack.display();
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Stack after pop: ";
    stack.display();
    cout << "Stack size: " << stack.size() << endl;

    // Queue operations
    queue.enQueue(10);
    queue.enQueue(20);
    queue.enQueue(30);
    cout << "Queue elements: ";
    queue.display();
    cout << "Dequeued element: " << queue.deQueue() << endl;
    cout << "Queue after dequeue: ";
    queue.display();
    cout << "Queue size: " << queue.size() << endl;

    return 0;
}