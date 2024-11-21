#include <iostream>
using namespace std;

const int TREE_ORDER = 3; 

struct BTreeNode {
    int *keys;              
    BTreeNode **children;   
    bool isLeaf;           
    int numKeys;           
} *root = NULL, *newNode = NULL, *currentNode = NULL;

BTreeNode* initializeNode() {
    int i;
    newNode = new BTreeNode;
    newNode->keys = new int[TREE_ORDER];
    newNode->children = new BTreeNode *[TREE_ORDER + 1];
    newNode->isLeaf = true;
    newNode->numKeys = 0;
    for (i = 0; i <= TREE_ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void traverseTree(BTreeNode *node) {
    if (node == NULL) {
        return;
    }

    int i;
    for (i = 0; i < node->numKeys; i++) {
        if (!node->isLeaf) {
            traverseTree(node->children[i]);
        }
        cout << " " << node->keys[i];
    }
    if (!node->isLeaf) {
        traverseTree(node->children[i]);
    }
}

void sortKeys(int *keysArray, int numKeys) {
    int i, j, temp;
    for (i = 0; i < numKeys; i++) {
        for (j = i + 1; j < numKeys; j++) {
            if (keysArray[i] > keysArray[j]) {
                temp = keysArray[i];
                keysArray[i] = keysArray[j];
                keysArray[j] = temp;
            }
        }
    }
}

int splitChild(BTreeNode *parent, int childIndex) {
    int midIndex = (TREE_ORDER - 1) / 2;
    int midKey;
    BTreeNode *newChild = initializeNode();
    BTreeNode *child = parent->children[childIndex];
    newChild->isLeaf = child->isLeaf;

    midKey = child->keys[midIndex];
    newChild->numKeys = TREE_ORDER - 1 - midIndex - 1;

    for (int j = 0; j < newChild->numKeys; j++) {
        newChild->keys[j] = child->keys[midIndex + 1 + j];
    }

    if (!child->isLeaf) {
        for (int j = 0; j <= newChild->numKeys; j++) {
            newChild->children[j] = child->children[midIndex + 1 + j];
        }
    }

    child->numKeys = midIndex;

    for (int j = parent->numKeys; j > childIndex; j--) {
        parent->children[j + 1] = parent->children[j];
        parent->keys[j] = parent->keys[j - 1];
    }

    parent->children[childIndex + 1] = newChild;
    parent->keys[childIndex] = midKey;
    parent->numKeys++;

    return midKey;
}

void insertKey(int key) {
    if (!root) {
        root = initializeNode();
        root->keys[0] = key;
        root->numKeys = 1;
    } else {
        BTreeNode *current = root;
        if (current->numKeys == TREE_ORDER - 1) {
            BTreeNode *newRoot = initializeNode();
            newRoot->isLeaf = false;
            newRoot->children[0] = root;
            splitChild(newRoot, 0);
            root = newRoot;
        }

        current = root;
        while (!current->isLeaf) {
            int i = current->numKeys - 1;
            while (i >= 0 && key < current->keys[i]) {
                i--;
            }
            i++;
            if (current->children[i]->numKeys == TREE_ORDER - 1) {
                splitChild(current, i);
                if (key > current->keys[i]) {
                    i++;
                }
            }
            current = current->children[i];
        }

        current->keys[current->numKeys] = key;
        sortKeys(current->keys, current->numKeys + 1);
        current->numKeys++;
    }
}

int main() {
    int n, key;
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the element: ";
        cin >> key;
        insertKey(key);
    }
    cout << "Traversal of constructed B-tree:" << endl;
    traverseTree(root);
    return 0;
}
