#pragma once

class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Stack{
    private:
        Node* top;
        int height;

    public:
    Stack(int value);
    void printStack();
    Node* getTop();
    int getHeight();
    void push(int value);
    int pop();
    //queue
    //enqueue
    //deque
};