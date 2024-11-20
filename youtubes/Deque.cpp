#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class Deque {
    Node* front;
    Node* rear;
    int Size;

public:
    Deque() : front(nullptr), rear(nullptr), Size(0) {}

    void enQueueFront(int data);
    void enQueueRear(int data);
    void deQueueFront();
    void deQueueRear();
    int getFront();
    int getRear();
    int size() { return Size; }
    bool isEmpty() { return front == nullptr; }
    void erase();
    void display();
};

void Deque::enQueueFront(int data) {
    Node* newNode = new Node(data);
    if (isEmpty())
        rear = front = newNode;
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    Size++;
}

void Deque::enQueueRear(int data) {
    Node* newNode = new Node(data);
    if (isEmpty())
        front = rear = newNode;
    else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    Size++;
}

void Deque::deQueueFront() {
    if (isEmpty()) {
        cout << "UnderFlow\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    else
        front->prev = nullptr;
    delete temp;
    Size--;
}

void Deque::deQueueRear() {
    if (isEmpty()) {
        cout << "UnderFlow\n";
        return;
    }
    Node* temp = rear;
    rear = rear->prev;
    if (rear == nullptr)
        front = nullptr;
    else
        rear->next = nullptr;
    delete temp;
    Size--;
}

int Deque::getFront() {
    return isEmpty() ? -1 : front->data;
}

int Deque::getRear() {
    return isEmpty() ? -1 : rear->data;
}

void Deque::erase() {
    while (!isEmpty())
        deQueueFront();
}

void Deque::display() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return;
    }
    Node* current = front;
    cout << "Deque elements: ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Deque dq;

    dq.enQueueRear(5);
    dq.display();

    dq.enQueueRear(10);
    dq.display();

    cout << "Rear end element: " << dq.getRear() << endl;

    dq.deQueueRear();
    cout << "After deleting rear element new rear is: " << dq.getRear() << endl;
    dq.display();

    dq.enQueueFront(15);
    dq.display();

    cout << "Front end element: " << dq.getFront() << endl;
    cout << "Number of elements in Deque: " << dq.size() << endl;

    dq.deQueueFront();
    cout << "After deleting front element new front is: " << dq.getFront() << endl;
    dq.display();

    return 0;
}