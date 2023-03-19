#include <iostream>
using namespace std;
void swapNumber(int& number1, int& number2) {
    int temp = number1;
    number1 = number2;
    number2 = temp;
}
main() {
    int number1 = 20;
    int number2 = 30;
    swapNumber(number1, number2);
    cout << "The value of number1 is: " << number1 << endl;
    cout << "The value of number2 is: " << number2;
}