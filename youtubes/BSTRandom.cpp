#include <iostream> 

using namespace std; 

struct Node { 
    Node* left; 
    Node* right; 
    int data;
};

Node* createNode(int data){
    Node* A = new Node(); 
    A->data = data; 
    A->left = A->right = nullptr;
    return A; 
}

Node* insertNode(Node* root, int data){
    if (root == nullptr){
        return createNode(data);
    }
    if (root->data <= data){
        
            root->right = insertNode(root->right, data);
       
    }
    if (root->data > data){
       
            root->left= insertNode(root->left, data);
        
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


int main () { 
    srand(time(0)); 
    Node* A = createNode(5);
    for (int i{0}; i<25; i++){
        A = insertNode(A,rand()%101);
    }
    traverse(A);
    
    cout << endl;
    return 0;
}
