#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <vector> 
#include <algorithm> 

using namespace std; 

// class Node { 
//     public: 
//     int data; 
//     Node* next; 
//     Node(): data(0), next(NULL){}
//     Node(int data): data(data), next(NULL){}
// };

// class linkedList{
//     public: 
//     int size = 0; 
//     Node* head; 
//     linkedList(): head(NULL){}
//     void insertAtHead(int data){ 
//         Node *newNode = new Node(); 
//         newNode->data = data; 
//         newNode->next = head; 
//         head = newNode;
//         size++; 
//     }
//     void print(){ 
//         Node* temp = head; 
//         if (head == NULL){ 
//             cout << "List is empty" << endl; 
//             return; 
//         }
//         while (temp!= NULL){
//             cout << temp->data << " " ;
//             temp = temp->next; 

//         }

//     }
//     Node* PR(Node* head){
//         Node* curr = head; 
//         Node * prev = nullptr; 
//         Node* next = nullptr; 
//         while (curr!= nullptr){
//             next = curr->next; 
//             curr->next = prev; 
//             prev = curr; 
//             curr = next; 
//         }
//         return prev; 

//     }

//     void LR(Node* head){
//         if (!head)return ; 
//         Node* left = head; 
//         Node* right = head; 

//         for (int i{0}; i<size/2; i++){
//             right = right->next; 

//         }
//         for (int i{0}; i<size/2; i++){
//             swap(left->data, right->data);
//             left = left->next;
//             Node* temp = left; 
//             for (int j = 0; j< size- i-2; j++){
//                 temp = temp->next;
//             }
//             right = temp; 
//         }
//     }
// };

// void merge(int A[], int temp[], int left, int mid, int right){
//     int i = left, j = mid+1, k = right; 
//     while (i<=mid && j<=right){
//         temp[k++] = (A[i]<=A[j])? A[i++]:A[j++];
//     }
//     while (i<= mid) temp[k++] = A[i++];
//     while (j<= right) temp[k++] = A[j++];
//     for (i = left; i<=right; i++) A[i] = temp[i];

// }

// void mergeSort(int A[], int temp[], int left, int right){
//     if (left<right){
//         int mid = left + (right - left)/2;
//         mergeSort(A,temp, left, mid-1);
//         mergeSort(A,temp,mid, right); 
//         merge(A, temp, left, mid, right); 
//     }
// }

// // int partition(int A[], int low, int high){ 
// //     int pivot = A[high], i = low - 1; 
// //     for (int j = low; j<high; j++){
// //         if (A[j]<=pivot) swap(A[++i], A[j]);
// //     }
// //     swap(A[i+1], A[high]);
// //     return i+1;
// // }

// int partition(int A[], int low, int high ){
//     int pivot = A[high]; 
//     int i = low - 1; 
//     for (int j = low;j<high; j++){
//         if (A[j]<=pivot) swap(A[++i], A[j]);
//     }
//     swap(A[i+1], A[high]);
//     return i+1;
// }
// void quickSort(int A[], int low, int high){
//     if (low< high){
//         int pi = partition(A, low,high);
//         quickSort(A, low, pi-1);
//         quickSort(A,pi+1, high); 

//     }
// }
// int main () { 
//     srand(time(0)); 
//     int A[500], temp[500];
//     for (int i=0; i<500; i++)A[i] = rand()%1001; 
    
// }

// struct Hash{
//     int bucket; 
//     vector<vector<int>> table; 
//     Hash(int b){
//         this->bucket = b; 
//         table.resize(bucket);
//     }
//     int hashF(int x){ 
//         return x%bucket; 
//     }
//     void insertItem(int key ) { 
//         int index = hashF(key); 
//         table[index].push_back(key); 

//     }

//     void deleteItem(int key){
//         int index = hashF(key); 
//         auto &arr = table[index];
//         auto x = find(arr.begin(), arr.end(), key); 
//         if (x!= arr.end()){
//             arr.erase(x);
//         }

//     }
//     double avgChainLength(){
//         int totalLength = 0; 
//         for (int i{0}; i < bucket; i++){
//             totalLength+=table[i].size();
//         }
//         return totalLength/bucket;
//     }
//     void displayHash(){
//         for (int i{0}; i<bucket; i++){
//             cout << i; 
//             for (int x: table[i]){
//                 cout << "-->"<< x; 

//             }
//             cout << endl;
//         }
//     }
// };
// int main() {
//     vector<int> a(500);
//     srand(time(0));
    
//     for (int i = 0; i < 500; i++) {
//         a[i] = rand() % 1001;
//     }
    
//     cout << endl;
    
//     Hash h(101);
    
//     for (int key : a) {
//         h.insertItem(key);
//     }
    
//     h.deleteItem(25);
//     h.displayHash();
    
//     double avgLength = h.avgChainLength();
//     cout << "Average Chain Length: " << avgLength << endl;

//     return 0;
// }


// class LinProbe{
//     private: 
//     vector<int> table; 
//     int size; 
//     int collisions;
//     public: 
//     LinProbe(int m): size(m), collisions(0), size(m){
//         table.resize(size, -1);
//     }; 


// }

// struct Node{
//     Node* left; 
//     Node* right; 
//     int data; 
// };

// Node* createNode(int data) { 
//     Node* A = new Node(); 
//     A->data = data; 
//     A->left = A->right = NULL; 
//     return A; 

// }

// Node* insertNode(Node* root, int data){
//     if (root == nullptr){
//         return createNode(data); 
//     }
//     if (root->data <= data){
//         root->right = insertNode(root->right, data);
//     }
//     if (root->data > data){
//         root->left = insertNode(root->left, data);
//     }
//     return root; 
// }

// void traverse(Node* root){ 
//     while (root!= nullptr){
//         traverse(root->left);
//         cout << root->data << endl;
//         traverse(root->right);
//     }
// }

// Node* searchNode(Node* root, int data){
//     if (root == nullptr ||root->data == data){
//         return root;
//     }
//     if (root->data <= data){
//         return searchNode(root->right,  data);
//     }
//     if (root->data > data){
//         return searchNode(root->left,  data);
//     }
// }

// Node *minValueNode(Node* root){ 
//     Node* currNode = root;
//     while (currNode->left!= nullptr){
//         currNode = currNode->left;
//     }
//     return currNode;
// }

// Node* deleteNode(Node* root, int data){ 
//     if (root == nullptr){
//         return root; 
//     }

//     if (root->data<data){ 
//         root->right = deleteNode(root->right, data);
//     }
//     else if (root->data > data){
//         root->left = deleteNode(root->left, data);
//     }
//     else {
//         if (root->left == nullptr){
//             Node* temp = root->right; 
//             delete root; 
//             return temp;
//         }
//         if (root->right == nullptr){
//             Node* temp = root->left; 
//             delete root; 
//             return temp; 
//         }
//         Node* temp = minValueNode(root->right); 
//         root->data = temp->data; 
//         root->right = deleteNode(root->right , temp->data); 

//     }

// }

void matrixMultiply(int **a, int **b, int **temp, int size, int i, int j, int k) {
    if (i < size) {
        if (j < size) {
            if (k < size) {
                temp[i][j] += a[i][k] * b[k][j];
                matrixMultiply(a, b, temp, size, i, j, k + 1);
            } else {
                matrixMultiply(a, b, temp, size, i, j + 1, 0);
            }
        } else {
            matrixMultiply(a, b, temp, size, i + 1, 0, 0);
        }
    }
}

int main () { 
    srand(time(0)); 
    cout << "Enter a value" << endl;
    int size; 
    cin>> size; 
    int ** A = new int*[size];
    int ** B = new int*[size];
    int ** C = new int*[size];
    for (int i = 0; i<size; ++i){
        A[i] = new int[size]; 
        B[i] = new int[size]; 
        C[i] = new int[size]; 
        for (int j{0}; j<size;++j){
            A[i][j] = rand()%1001;
            B[i][j] = rand()%1001;
            C[i][j] = 0;
        }
    }
    matrixMultiply(A,B,C, size, 0, 0,0);
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            cout << C[x][y] << " ";
        }
        cout << endl;
    }
}