#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        cout << "Element being compared with key: " << arr[i] << endl;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        cout << "Mid Element is: " << arr[mid] << endl;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }
    return -1;
}

void sortArray(int arr[], int size) {
    sort(arr, arr + size);
}


int main() {
    srand(time(0));
    const int size = 100;
    int arrBase[size] = {0};
    for (int i = 0; i < size; i++) {
        arrBase[i] = (rand() % 100) + 1;
    }
    int arrSort[size] = {0};
    copy(arrBase, arrBase + size, arrSort);

    cout << "Original Array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arrBase[i] << " ";
    }
    cout << endl;

    cout << "Sorted Array:" << endl;
    sortArray(arrSort, size);
    for (int i = 0; i < size; i++) {
        cout << arrSort[i] << " ";
    }
    cout << endl;

    int medianIndex = size / 2;
    int medianElement = (size % 2 == 0) ? (arrSort[medianIndex - 1] + arrSort[medianIndex]) / 2 : arrSort[medianIndex];

    cout << "Binary Search for median element in sorted array:" << endl;
    int index = binarySearch(arrSort, 0, size - 1, medianElement);

    cout << "Linear Search for median element in sorted array:" << endl;
    int index2 = linearSearch(arrSort, size, medianElement);

    cout << "Linear Search for median element in original array:" << endl;
    int finalIndex2 = linearSearch(arrBase, size, medianElement);

    cout << "Median element to search for is: " << medianElement << endl;
    cout << "Position of median in sorted array is: " << index << endl;
    cout << "Position of median in original array is: " << finalIndex2 << endl;

    return 0;
}