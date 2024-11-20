#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define COUNT 10
struct Node {
    Node* left;
    Node* right;
    int data;
};

Node* createNode(int data) {
    Node* A = new Node();
    A->data = data;
    A->left = A->right = nullptr;
    return A;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (root->data <= data) {
        root->right = insertNode(root->right, data);
    } else {
        root->left = insertNode(root->left, data);
    }
    return root;
}

void traverse(Node* root) {
    if (root != nullptr) {
        traverse(root->left);
        cout << root->data << " ";
        traverse(root->right);
    }
}

Node* searchNode(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return searchNode(root->right, key);
    }
    return searchNode(root->left, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
Node* mirror(Node* root) {
    if (root == nullptr)
        return nullptr;
    
    Node* left = mirror(root->left);
    Node* right = mirror(root->right);
  
    root->left = right;
    root->right = left;
  
    return root;
}
void print2DUtil(Node* root, int space)
{
    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2DUtil(root->right, space);
 
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
 
    print2DUtil(root->left, space);
}
 
void print2D(Node* root)
{
    print2DUtil(root, 0);
}
int main() {
    srand(time(0));
    
    Node* A = nullptr; 
    int X, Y, Z;

    for (int i = 0; i < 25; i++) {
        int value = rand() % 101; 
        A = insertNode(A, value);

        
        if (i == 12) {
            X = value;
        }
        if (i == 13) {
            Y = value; 
        }
        if (i == 14) {
            Z = value;
        }
    }

    cout << "Initial tree: ";
    traverse(A);
    cout << endl;

    cout << "Deleting " << X << ": ";
    A = deleteNode(A, X);
    traverse(A);
    cout << endl;

    cout << "Deleting " << Y << ": ";
    A = deleteNode(A, Y);
    traverse(A);
    cout << endl;

    cout << "Deleting " << Z << ": ";
    A = deleteNode(A, Z);
    traverse(A);
    cout << endl;

    cout << "Final tree: ";
    traverse(A);
    cout << endl;
    
    print2D(A);
    
    A = mirror(A);
    
    cout << "Final Mirror tree : ";
    traverse(A);
    cout << endl;
    print2D(A);
    return 0;
}

