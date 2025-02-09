#include <iostream>

using namespace std;


/*
Runtime Complexity
The function printItems has two nested loops, each iterating n times. The outer loop runs n times, and for each iteration of the outer loop, the inner loop also runs n times. Therefore, the total number of iterations is n * n, which results in a runtime complexity of O(n^2).

Space Complexity
The space complexity of this function is O(1), which means it uses a constant amount of extra space regardless of the input size n. This is because the function only uses a fixed amount of space for the loop variables i and j, and does not allocate any additional space that depends on n.

In summary:

Runtime Complexity: O(n^2)
Space Complexity: O(1)
*/
void printItems(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }
}


int main() { 

    printItems(10);

}