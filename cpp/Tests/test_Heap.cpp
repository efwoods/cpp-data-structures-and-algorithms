#include <gtest/gtest.h>
#include <iostream>
#include "../Classes/Heap/Heap.h"

using namespace std;

TEST(HeapTest, Constructor){
    EXPECT_NO_THROW({
        Heap* myHeap = new Heap();
        });
}

TEST(HeapTest, ParentTest){
    // Initialize Heap
    Heap* myHeap = new Heap();

    EXPECT_TRUE(myHeap->parent(1) == 0);
}

TEST(HeapTest, LeftChildTest){
        // Initialize Heap
    Heap* myHeap = new Heap();

    EXPECT_TRUE(myHeap->leftChild(0) == 1);
    EXPECT_TRUE(myHeap->leftChild(1) == 3);

}

TEST(HeapTest, RightChildTest){
    // Initialize Heap
    Heap* myHeap = new Heap();

    EXPECT_TRUE(myHeap->rightChild(0) == 2);
    EXPECT_TRUE(myHeap->rightChild(1) == 4);
}

TEST(HeapTest, Insert) {
    Heap* myHeap = new Heap();
    EXPECT_NO_THROW(myHeap->insert(100));
}

TEST(HeapTest, SwapTest){
    // Initialize Heap
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);

    EXPECT_NO_THROW(myHeap->swap(2, 3));
}

TEST(HeapTest, Remove){
    // Initialize Heap
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);

    EXPECT_TRUE(myHeap->remove() == 100);
}

TEST(HeapTest, SinkDown){
    // Initialize Heap
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);

    EXPECT_NO_THROW(myHeap->sinkDown(0));
}

TEST(HeapTest, MinHeapInsert){
    MinHeap heap;

    // Insert values into the heap
    vector<int> values = {35, 25, 15, 5, 20, 30, 10};
    cout << "Inserting values: ";
    for (int value : values) {
        cout << value << " ";
        heap.insert(value);
        
        // Verify min heap property
        const vector<int>& currentHeap = heap.getHeap();
        bool isValidMinHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++) {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] > currentHeap[left]) {
                isValidMinHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] > currentHeap[right]) {
                isValidMinHeap = false;
                break;
            }
        }

        cout << "\nHeap after insertion: ";
        heap.printHeap();
        EXPECT_TRUE(isValidMinHeap);
        cout << "Min Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
    }

    // Final Heap structure
    cout << "\nFinal Heap Structure: ";
    heap.printHeap();
}

TEST(HeapTest, MinHeapRemoveTest){
        MinHeap heap;

    // Insert values into the heap
    vector<int> valuesToInsert = {35, 25, 15, 5, 20, 30, 10};
    cout << "Inserting values: ";
    for (int value : valuesToInsert) {
        cout << value << " ";
        heap.insert(value);
    }
    cout << "\nInitial Heap: ";
    heap.printHeap();

    // Remove values from the heap and test after each removal
    while (!heap.getHeap().empty()) {
        int removedValue = heap.remove();
        cout << "\nRemoved Value: " << removedValue;
        cout << "\nHeap after removal: ";
        heap.printHeap();

        // Verify min heap property
        const vector<int>& currentHeap = heap.getHeap();
        bool isValidMinHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++) {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] > currentHeap[left]) {
                isValidMinHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] > currentHeap[right]) {
                isValidMinHeap = false;
                break;
            }
        }

        EXPECT_TRUE(isValidMinHeap);
        cout << "\nMin Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
    }

    // Check if heap is empty at the end
    cout << "\nFinal Heap (Should be empty): ";
    heap.printHeap();
}

TEST(HeapTest, MinHeapSinkDownTest){
      MinHeap heap;

    // Insert values into the heap
    vector<int> valuesToInsert = {35, 25, 15, 5, 20, 30, 10};
    cout << "Inserting values: ";
    for (int value : valuesToInsert) {
        cout << value << " ";
        heap.insert(value);
    }
    cout << "\nInitial Heap: ";
    heap.printHeap();

    // Remove values from the heap and test after each removal
    while (!heap.getHeap().empty()) {
        int removedValue = heap.remove();
        cout << "\nRemoved Value: " << removedValue;
        cout << "\nHeap after removal: ";
        heap.printHeap();

        // Verify min heap property
        const vector<int>& currentHeap = heap.getHeap();
        bool isValidMinHeap = true;
        for (size_t i = 0; i < currentHeap.size(); i++) {
            int left = 2 * i + 1;  // Calculating left child index
            int right = 2 * i + 2; // Calculating right child index
            if (left < currentHeap.size() && currentHeap[i] > currentHeap[left]) {
                isValidMinHeap = false;
                break;
            }
            if (right < currentHeap.size() && currentHeap[i] > currentHeap[right]) {
                isValidMinHeap = false;
                break;
            }
        }
        EXPECT_TRUE(isValidMinHeap);
        cout << "\nMin Heap Property Valid? " << (isValidMinHeap ? "Yes" : "No") << "\n";
    }

    // Check if heap is empty at the end
    cout << "\nFinal Heap (Should be empty): ";
    heap.printHeap();
}
