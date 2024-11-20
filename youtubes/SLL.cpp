#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
};

class linkedList {
public:
    int size = 0;
    Node* head;
    linkedList() : head(NULL) {}

    void insertAthead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void print() {
        Node *temp = head;
        if (head == NULL) {
            cout << "LIST IS EMPTY" << endl;
            return;
        }
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Preverse() {
        head = PR(head);
    }

    void Lreverse() {
        logicalReverse(head);
    }

private:
    Node* PR(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void logicalReverse(Node* head) { 
        if (!head) return;
        Node* left = head; 
        Node* right = head;
        for (int i = 0; i < size - 1; i++) {
            right = right->next;
        }

        for (int i = 0; i < size / 2; i++) {
            swap(left->data, right->data);
            left = left->next;
            Node* temp = left;
            for (int j = 0; j < size - i - 2; j++) {
                temp = temp->next;
            }
            right = temp;
        }
    }
};

int rand_gen() {
    return rand() % 100;
}

int main() {
    linkedList L;
    srand(time(0));
    for (int x = 0; x < 50; x++) {
        L.insertAthead(rand_gen());
    }
    cout << "Elements of the list are: " << endl;
    L.print();
    L.Preverse();
    cout << "Elements of the list after reversal: " << endl;
    L.print();
    L.Lreverse();
    cout << "Elements of the list after logical reversal: " << endl;
    L.print();
    return 0;
}