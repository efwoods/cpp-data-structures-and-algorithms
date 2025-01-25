#include <iostream>

using namespace std;

int main(){
    int* num1 = new int(11); // the "new" keyword will allocate space in memory
    int* num2 = num1; // This passes the address of num1, the reference of num1, to num2; to pass the value of num1, dereference the pointer with *num1;

    *num1 = 22;

    cout << "num1 = " << *num1 << endl;
    cout << "num2 = " << *num2 << endl;
}