#include <iostream>
using namespace std;
void leftRotate(int arr[], int size);
main() {
    int size = 9;
    int num;
    int arr[size] = { 1,2,3,4,5,6,7,8,9 };
    cout << "Enter number: ";
    cin >> num;
    for (int i = 0;i < num;i++) {
        leftRotate(arr, size);
    }
    for (int i = 0;i < size;i++) {
        cout << arr[i] << "\t";
    }
}
void leftRotate(int arr[], int size) {
    int number;
    number = arr[0];
    for (int i = 0;i < size - 1;i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = number;
}