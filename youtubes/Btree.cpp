#include <iostream>
using namespace std;

const int ORDER = 3; // Define the order of the B-tree

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

    void splitChild(BTreeNode* x, int i) {
        BTreeNode* y = x->children[i];
        BTreeNode* z = new BTreeNode(y->leaf);
        z->n = ORDER / 2 - 1;

        for (int j = 0; j < ORDER / 2 - 1; j++)
            z->keys[j] = y->keys[j + ORDER / 2];

        if (!y->leaf) {
            for (int j = 0; j < ORDER / 2; j++)
                z->children[j] = y->children[j + ORDER / 2];
        }

        y->n = ORDER / 2 - 1;

        for (int j = x->n; j >= i + 1; j--)
            x->children[j + 1] = x->children[j];

        x->children[i + 1] = z;

        for (int j = x->n - 1; j >= i; j--)
            x->keys[j + 1] = x->keys[j];

        x->keys[i] = y->keys[ORDER / 2 - 1];
        x->n = x->n + 1;
    }

    void insertNonFull(BTreeNode* x, int k) {
        int i = x->n - 1;

        if (x->leaf) {
            while (i >= 0 && k < x->keys[i]) {
                x->keys[i + 1] = x->keys[i];
                i--;
            }

            x->keys[i + 1] = k;
            x->n = x->n + 1;
        } else {
            while (i >= 0 && k < x->keys[i])
                i--;

            i++;
            if (x->children[i]->n == ORDER - 1) {
                splitChild(x, i);

                if (k > x->keys[i])
                    i++;
            }
            insertNonFull(x->children[i], k);
        }
    }

    void traverse(BTreeNode* x) {
        int i;
        for (i = 0; i < x->n; i++) {
            if (!x->leaf)
                traverse(x->children[i]);
            cout << " " << x->keys[i];
        }

        if (!x->leaf)
            traverse(x->children[i]);
    }

    BTreeNode* search(BTreeNode* x, int k) {
        int i = 0;
        while (i < x->n && k > x->keys[i])
            i++;

        if (i < x->n && k == x->keys[i])
            return x;

        if (x->leaf)
            return nullptr;

        return search(x->children[i], k);
    }

public:
    BTree() { root = new BTreeNode(true); }

    void insert(int k) {
        if (root->n == ORDER - 1) {
            BTreeNode* s = new BTreeNode(false);
            s->children[0] = root;
            root = s;
            splitChild(s, 0);
            insertNonFull(s, k);
        } else
            insertNonFull(root, k);
    }

    void traverse() {
        if (root != nullptr)
            traverse(root);
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : search(root, k);
    }
};

int main() {
    BTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed tree is: ";
    t.traverse();
    cout << endl;

    int k = 5;
    (t.search(k) != nullptr) ? cout << k << " is found" << endl
                             : cout << k << " is not found" << endl;

    k = 15;
    (t.search(k) != nullptr) ? cout << k << " is found" << endl
                             : cout << k << " is not found" << endl;

    return 0;
}
