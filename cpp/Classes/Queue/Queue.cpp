#include "Queue.h"

using namespace std;

Queue::Queue(int value) {
    Node* newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
}