#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(int A[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = (A[i] <= A[j]) ? A[i++] : A[j++];
    }
    while (i <= mid) temp[k++] = A[i++];
    while (j <= right) temp[k++] = A[j++];
    for (i = left; i <= right; i++) A[i] = temp[i];
}

void mergeSort(int A[], int temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(A, temp, left, mid);
        mergeSort(A, temp, mid + 1, right);
        merge(A, temp, left, mid, right);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) swap(A[++i], A[j]);
    }
    swap(A[i + 1], A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    int A[500], temp[500];

    for (int i = 0; i < 500; i++) A[i] = rand() % 1001;
    mergeSort(A, temp, 0, 499);
    cout << "Sorted array (Merge Sort):\n";
    for (int i = 0; i < 500; i++) cout << A[i] << " ";
    cout << endl;

    for (int i = 0; i < 500; i++) A[i] = rand() % 1001;
    quickSort(A, 0, 499);
    cout << "Sorted array (Quick Sort):\n";
    for (int i = 0; i < 500; i++) cout << A[i] << " ";
    cout << endl;

    return 0;
}