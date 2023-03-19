#include <iostream>
using namespace std;
void mergearray(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3);
main() {
    int size1 = 4;
    int size2 = 5;
    int size3 = size1 + size2;
    int arr1[size1] = { 1,2,3,4 };
    int arr2[size2] = { 5,6,7,8,9 };
    int arr3[size3];
    mergearray(arr1, size1, arr2, size2, arr3, size3);
    for (int i = 0;i < size3;i++) {
        cout << arr3[i] << "\t";
    }
}
void mergearray(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3) {
    int i = 0;
    for (;i < size1;i++) {
        arr3[i] = arr1[i];
    }
    for (int j = 0;j < size2;j++) {
        arr3[i + j] = arr2[j];
    }
}