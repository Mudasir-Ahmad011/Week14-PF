#include <iostream>
using namespace std;

main() {
    int number = 10;
    int* p = &number;
    cout << "The value of number is: " << *p << endl;
    cout << "The address of number is: " << p;
}