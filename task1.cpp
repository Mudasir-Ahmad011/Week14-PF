#include <iostream>
using namespace std;

main() {
    int number = 10;
    int* ptr = &number;
    cout << "The address of number: " << ptr;
}