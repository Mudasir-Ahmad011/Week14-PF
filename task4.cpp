#include <iostream>
using namespace std;
float averageofarray(int num[], int size) {
    int sum = 0;
    for (int i = 0;i < size;i++) {
        sum = sum + num[i];
    }
    return sum / size;
}
main() {
    int size = 3;
    int num[size] = { 1,2,3 };
    cout << averageofarray(num, size);
}