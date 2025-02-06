#pragma once

class Node { 
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value);
        ~LinkedList();
        void append(int value);
        void deleteLast();
        void prepend(int value);
        void deleteFirst();
        Node* get(int index);
        void set(int index, int value);
        void insert(int index, int value);
        void deleteNode(int index);
        void reverse();
        void printList();
        Node* getHead();
        Node* getTail();
        int getLength();
        void bubbleSort();
        void selectionSort();
        void insertionSort();
        void merge(LinkedList& otherList);
};