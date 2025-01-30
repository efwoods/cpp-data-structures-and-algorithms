#pragma once

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value);
        ~DoublyLinkedList();
        void append(int value);
        void deleteLast();
        void prepend(int value);
        void deleteFirst();
        Node* get(int index);
        void set(int index, int value);
        void insert(int index, int value);
        void deleteNode(int index);
        void reverse();
        bool isPalindrome();
        int numSwapsPerSide(int length);
        void swapPairs();
        void printList();
        Node* getHead();
        Node* getTail();
        int getLength();
};