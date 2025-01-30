#include "Stack.h"
#include <iostream>
#include <limits.h>

using namespace std;

Stack::Stack(int value){
    Node* newNode = new Node(value);
    top = newNode;
    height = 1;
}

void Stack::printStack(){
    Node* temp = top;
    while(temp){
        cout << top->value << endl;
        temp = temp->next;
    }
}

Node* Stack::getTop(){
    return top;
}

int Stack::getHeight(){
    return height;
}

void Stack::push(int value){
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    height++;
}

int Stack::pop(){
    if(height == 0){
        return INT_MIN;
    }
    Node* temp = top;
    int poppedValue = top->value;
    top = top->next;
    delete temp;
    height--;
    return poppedValue;
}