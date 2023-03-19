#include <iostream>
using namespace std;
void changenumber(int& number);
main() {
    int number = 20;
    changenumber(number);
    cout << "After function " << number;
}
void changenumber(int& number) {
    number++;
    cout << "In function " << number;
}