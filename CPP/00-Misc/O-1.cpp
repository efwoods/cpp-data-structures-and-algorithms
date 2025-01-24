#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;


/*
This operation is O(1) because there is only 1 operation.
*/
int addItems(int n){
    return n + n;
}

int main(){
    srand(time(0));

    // Generate a random number between 1 and 100
    int n = rand() % 100 + 1;
    int value = addItems(n);
    cout << "'value' is: " << value << endl;

}