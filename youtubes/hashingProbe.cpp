#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
using namespace std;
class LinearProbingHashTable {
private:
    vector<int> table;
    int size;
    int collisions;

public:
    LinearProbingHashTable(int m) : size(m), collisions(0) {
        table.resize(size, -1);
    }

    int hashFunction(int key) {
        return (13 * key) % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            collisions++;
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    int getCollisions() {
        return collisions;
    }

    void printTable() {
        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else {
                cout << "Index " << i << ": " << "Empty" << endl;
            }
        }
    }
};

int main() {
    srand(time(0));
    LinearProbingHashTable hashTable(503);
    
    for (int i = 0; i < 500; ++i) {
        int key = rand() % 1001; 
        hashTable.insert(key);
    }

    cout << "Total Collisions: " << hashTable.getCollisions() << endl;
    return 0;
}
