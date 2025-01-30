#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int value) {
    Node* newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
}

Node* Queue::getFirst(){
    return first;
}

Node* Queue::getLast(){
    return last;
}

int Queue::getLength(){
    return length;
}

void Queue::printQueue(){
    Node* temp = first;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void Queue::enqueue(int value){
    Node* newNode = new Node(value);
    if (length == 0){
        first = newNode;
        last = newNode;
        length = 1;
    } else {
        last->next = newNode;
        last = newNode;
        length++;
    }
}