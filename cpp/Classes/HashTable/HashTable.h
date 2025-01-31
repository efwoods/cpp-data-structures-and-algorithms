#pragma once

class Node{
    public:
        int value;
        int key;
        Node* next;
        Node(int key, int value){
            this->key = key;
            this->value = value;
        }
};

class HashTable{
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        ~HashTable();
        void printTable();
};