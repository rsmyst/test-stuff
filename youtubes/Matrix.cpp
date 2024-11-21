#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void matrixMultiply(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& temp, int size, int i, int j, int k) {
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

int main() {
    srand(time(0));
    cout << "Enter a value" << endl;
    int size;
    cin >> size;

    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    vector<vector<int>> C(size, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A[i][j] = rand() % 1001;
            B[i][j] = rand() % 1001;
        }
    }

    matrixMultiply(A, B, C, size, 0, 0, 0);

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            cout << C[x][y] << " ";
        }
        cout << endl;
    }

    return 0;
}