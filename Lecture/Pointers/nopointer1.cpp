#include <iostream>

using namespace std;

int main() {
    int num1 = 11;
    int num2 = num1; // this passes the value to num2; A pointer is NOT being used here.

    num1 = 22; // num1 is 22; num2 is 11;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}
