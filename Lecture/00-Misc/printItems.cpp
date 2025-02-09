# include <iostream>

using namespace std;

/* 
This function is O(n); 
big O is always going to be a straight line. 
It is "proportional";
*/
void printItems(int n){
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
}

/* 
This function runs 2n times.
This is O(n) runtime. 
This indicates the runtime is linear and "proportional" versus exponential.
*/
void printItemsDoubleForLoop(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
    for (int j = 0; j < n; j++) {
        cout << j << endl;
    }
}

int main() {
    printItemsDoubleForLoop(10);
}