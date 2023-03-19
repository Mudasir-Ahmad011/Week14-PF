#include <iostream>
using namespace std;
void changeNumber(int num) {
    num++;
    cout << "In function" << num;
}
main() {
    int number = 20;
    changeNumber(number);
    cout << "After function" << number;
}