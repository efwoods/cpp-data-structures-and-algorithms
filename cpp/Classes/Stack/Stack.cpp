#include "Stack.h"
#include <iostream>

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