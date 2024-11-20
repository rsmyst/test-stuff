#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hash {
    int bucket; 
    vector<vector<int>> table; 
    
    Hash(int b) {
        this->bucket = b; 
        table.resize(bucket);
    }
    
    int hashFunction(int x) {
        return (11 * x % bucket);
    }
    
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    
    void deleteItem(int key) {
        int index = hashFunction(key);
        auto& bucketList = table[index];
        auto it = find(bucketList.begin(), bucketList.end(), key);
        if (it != bucketList.end()) {
            bucketList.erase(it);
        }
    }
    
    double averageChainLength() {
        int totalLength = 0;
        for (const auto& bucketList : table) {
            totalLength += bucketList.size();
        }
        return static_cast<double>(totalLength) / bucket;
    }
    
    void displayHash() { 
        for (int i = 0; i < bucket; i++) {
            cout << i; 
            for (int x : table[i]) {
                cout << " --> " << x; 
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> a(500);
    srand(time(0));
    
    for (int i = 0; i < 500; i++) {
        a[i] = rand() % 1001;
    }
    
    cout << endl;
    
    Hash h(101);
    
    for (int key : a) {
        h.insertItem(key);
    }
    
    h.deleteItem(25);
    h.displayHash();
    
    double avgLength = h.averageChainLength();
    cout << "Average Chain Length: " << avgLength << endl;

    return 0;
}
