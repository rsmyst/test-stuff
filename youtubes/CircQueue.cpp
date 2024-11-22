#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* link;
};

class Queue {
public:
    Node *front, *rear;
    int size;

    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    void enQueue(int value) {
        Node* temp = new Node;
        temp->data = value;
        if (front == nullptr)
            front = temp;
        else
            rear->link = temp;

        rear = temp;
        rear->link = front;
        size += 1;
    }

    int deQueue() {
        if (front == nullptr) {
            cout << "Queue is empty";
            return INT_MIN;
        }

        int value;
        if (front == rear) {
            value = front->data;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            value = temp->data;
            front = front->link;
            rear->link = front;
            delete temp;
        }
        size -= 1;
        return value;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements are: ";
        do {
            cout << temp->data << " ";
            temp = temp->link;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.deQueue();
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.display();
    cout << "Dequeued value: " << q.deQueue() << endl;
    q.display();
    return 0;
}
