#include <iostream>
using namespace std;

const int ORDER = 3;

class BTreeNode {
public:
    int keys[ORDER - 1];
    BTreeNode* children[ORDER];
    int n; 
    bool leaf;

    BTreeNode(bool isLeaf = true) : n(0), leaf(isLeaf) {
        for (int i = 0; i < ORDER; i++)
            children[i] = nullptr;
    }
};

class BTree {
private:
    BTreeNode* root;

    void splitChild(BTreeNode* parent, int index) {
        BTreeNode* child = parent->children[index];
        BTreeNode* newNode = new BTreeNode(child->leaf);
        newNode->n = ORDER / 2 - 1;

        for (int j = 0; j < ORDER / 2 - 1; j++)
            newNode->keys[j] = child->keys[j + ORDER / 2];

        if (!child->leaf) {
            for (int j = 0; j < ORDER / 2; j++)
                newNode->children[j] = child->children[j + ORDER / 2];
        }

        child->n = ORDER / 2 - 1;

        for (int j = parent->n; j >= index + 1; j--)
            parent->children[j + 1] = parent->children[j];
        parent->children[index + 1] = newNode;

        for (int j = parent->n - 1; j >= index; j--)
            parent->keys[j + 1] = parent->keys[j];
        parent->keys[index] = child->keys[ORDER / 2 - 1];
        parent->n++;
    }

    void insertNonFull(BTreeNode* node, int key) {
        int i = node->n - 1;

        if (node->leaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->n++;
        } else {
            while (i >= 0 && key < node->keys[i])
                i--;
            i++;

            if (node->children[i]->n == ORDER - 1) {
                splitChild(node, i);
                if (key > node->keys[i])
                    i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    void traverse(BTreeNode* node) {
        for (int i = 0; i < node->n; i++) {
            if (!node->leaf)
                traverse(node->children[i]);
            cout << " " << node->keys[i];
        }

        if (!node->leaf)
            traverse(node->children[node->n]);
    }

    BTreeNode* search(BTreeNode* node, int key) {
        int i = 0;
        while (i < node->n && key > node->keys[i])
            i++;

        if (i < node->n && key == node->keys[i])
            return node;

        if (node->leaf)
            return nullptr;

        return search(node->children[i], key);
    }

public:
    BTree() { root = new BTreeNode(true); }

    void insert(int key) {
        if (root->n == ORDER - 1) {
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->children[0] = root;
            root = newRoot;
            splitChild(root, 0);
            insertNonFull(root, key);
        } else {
            insertNonFull(root, key);
        }
    }

    void traverse() {
        if (root)
            traverse(root);
    }

    BTreeNode* search(int key) {
        return root ? search(root, key) : nullptr;
    }
};

int main() {
    BTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);

    cout << "Tree traversal: ";
    tree.traverse();
    cout << endl;

    int searchKey = 6;
    cout << searchKey << (tree.search(searchKey) ? " found" : " not found") << endl;

    return 0;
}