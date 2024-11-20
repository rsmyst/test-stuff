#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int randomGen(){
    int min = 1;
    int max = 1000;
    return rand() % (max - min + 1) + min;
}

void matrixMultiply(int** a, int** b, int** c, int size, int i, int j, int k){
    if (i < size) {
        if (j < size) {
            if (k < size) {
                c[i][j] += a[i][k] * b[k][j];
                matrixMultiply(a, b, c, size, i, j, k + 1);
            } else {
                matrixMultiply(a, b, c, size, i, j + 1, 0);
            }
        } else {
            matrixMultiply(a, b, c, size, i + 1, 0, 0);
        }
    }
}

int main () {
    srand(time(0)); 
    int size = 0;
    cout << "HI, enter value" << endl;
    cin >> size;

    int** A = new int*[size];
    int** B = new int*[size];
    int** C = new int*[size];
    for (int i = 0; i < size; ++i) {
        A[i] = new int[size];
        B[i] = new int[size];
        C[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            A[i][j] = randomGen();
            B[i][j] = randomGen();
            C[i][j] = 0; 
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